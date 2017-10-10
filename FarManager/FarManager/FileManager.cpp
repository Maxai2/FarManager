#include "FileManager.h"

//--------------------------------------------------------------------------------------------------------

FileManager::FileManager(string path) { this->path = path; }

//--------------------------------------------------------------------------------------------------------

void FileManager::pathModif(string path)
{
	for (int i = 0; i < path.size(); i++)
	{

		if (path[i] == '/')
		{
			cout << '\\';
			i++;
		}
		else
		if (path[i] != '*')
			cout << path[i];
	}
	cout << '>';
}

//--------------------------------------------------------------------------------------------------------

void FileManager::clearPathPlace()
{
	for (int i = 0; i < Console::consoleWidth; i++)
		cout << " ";
}

//--------------------------------------------------------------------------------------------------------

int FileManager::lengthPath(string path) { return path.size(); }

//--------------------------------------------------------------------------------------------------------

int FileManager::dirCount(string path)
{
	_finddata_t fileinfo;
	int handle = _findfirst(path.c_str(), &fileinfo);
	int find = handle, count = 0;

	while (find != -1)
	{
		count++;
		find = _findnext(handle, &fileinfo);
	}

	return count;
}

//--------------------------------------------------------------------------------------------------------

void FileManager::showDirectory(int sel, string mode, char rightLeft, string exception)
{
	if (mode == "show")
	{
		bool check = false;
		string buffer, temppath;
		_finddata_t fileinfo;
		int handle = _findfirst(path.c_str(), &fileinfo);
		this->oldPath = this->path;
		int find = handle;
		int folderCount = 0, fileCount = 0;
		this->count = 0;
		temppath = fileinfo.name;

		while (find != -1)
		{
			if (temppath == exception)
			{
				temppath = "";
				find = _findnext(handle, &fileinfo);
				continue;
			}
			
			if (this->count > 29)
				break;
			else
				rightLeft == 'l' ? COORDS((short)this->count + 2, 76) : COORDS((short)this->count + 2, 1);

			if (this->newFolder) clear("name");
			rightLeft == 'l' ? COORDS((short)this->count + 2, 76) : COORDS((short)this->count + 2, 1);

			if (this->count == sel)
				check = true;

			if (fileinfo.attrib & _A_SYSTEM || fileinfo.attrib & _A_HIDDEN)
			{
				if (check)
					COLOR(Colors::LIGHTGREY, Colors::DARKCYAN);
				else
					COLOR(Colors::CYAN, defaultBackGround);
			}
			else
			if (fileinfo.attrib & _A_SUBDIR)
			{
				if (check)
					COLOR(Colors::WHITE, Colors::DARKCYAN);
				else
					COLOR(Colors::WHITE, defaultBackGround);
			}
			else
			if (fileinfo.attrib & _A_NORMAL)
			{
				if (check)
					COLOR(Colors::BLUE, Colors::DARKCYAN);
				else
					COLOR(Colors::BLUE, defaultBackGround);
			}
			else
			{
				if (check)
					COLOR(Colors::GREY, Colors::DARKCYAN);
				else
					COLOR(Colors::GREY, defaultBackGround);
			}

			buffer = fileinfo.name;
			if (buffer.size() >= 50)
			{
				buffer.erase(buffer.begin() + 50, buffer.end());
				cout << buffer << "..." << '\n';
			}
			else
				cout << fileinfo.name << '\n';

			int size = fileinfo.size;
			rightLeft == 'l' ? COORDS((short)this->count + 2, 76 + Place::Size + 1) : COORDS((short)this->count + 2, Place::Size + 2);
			if (size == 0)
				cout << "Folder";
			else
				BytesConv(fileinfo.size);

			rightLeft == 'l' ? COORDS((short)this->count + 2, 76 + Place::Type + 1) : COORDS((short)this->count + 2, Place::Type + 2);
			if (fileinfo.attrib & _A_SUBDIR)
			{
				if (fileinfo.name != "..")
					folderCount++;

				cout << "Direct"; 
			}
			else { cout << " File"; fileCount++; }

			rightLeft == 'l' ? COORDS((short)this->count + 2, 76 + Place::Attr + 1) : COORDS((short)this->count + 2, Place::Attr + 2);
			string attr;
			if (fileinfo.attrib & _A_SYSTEM) attr += "S";
			if (fileinfo.attrib & _A_NORMAL) attr += "N";
			if (fileinfo.attrib & _A_RDONLY) attr += "R";
			if (fileinfo.attrib & _A_HIDDEN) attr += "H";

			cout << attr;
		
			if (this->willbe)
				directory.push_back(fileinfo.name);

			this->count++;
			check = false;

			find = _findnext(handle, &fileinfo);
		}
	
		this->willbe = false; this->newFolder = false;

		COLOR(Colors::GREEN, defaultBackGround);
		COORDS(33, StartCoord::headX);
		cout << "\t\tFolders count: " << folderCount - 1 << ", files count: " << fileCount;
		COORDS(35, StartCoord::headX);
		clearPathPlace();
		COORDS(35, StartCoord::headX);
		pathModif(this->path);
	
		COLOR(defaultForeGround, defaultBackGround);
		_findclose(handle);
	}
	else
	{
		_finddata_t fileinfo;
		int handle = _findfirst(oldPath.c_str(), &fileinfo);
		int find = handle;
		this->count;
		string tempoldPath = fileinfo.name;

		while (this->count != 0)
		{
			if (tempoldPath == ".")
			{
				tempoldPath = "";
				find = _findnext(handle, &fileinfo);
				continue;
			}

			COORDS((short)this->count + 2, 1);
			clear("name");

			COORDS((short)this->count + 2, Place::Size + 2);
			clear("size");

			COORDS((short)this->count + 2, Place::Type + 2);
			clear("type");

			COORDS((short)this->count + 2, Place::Attr + 2);
			clear("attr");

			directory.pop_back();

			this->count--;
			find = _findnext(handle, &fileinfo);
		}

		this->willbe = true;
		_findclose(handle); 
	}
}
//--------------------------------------------------------------------------------------------------------

int FileManager::getCount() { return this->count; }

//--------------------------------------------------------------------------------------------------------

string FileManager::getName(int sel) { return this->directory[sel]; }

//--------------------------------------------------------------------------------------------------------

string FileManager::getPath() { return this->path; }

//--------------------------------------------------------------------------------------------------------

void FileManager::changeDirectory(string dir)
{
	this->path.erase(this->path.end() - 1);

	if (dir == "..")
	{
		this->path.erase(this->path.end() - 2, this->path.end());

		for (int i = this->path.size() - 1; this->path[i] != '/' ; i--)
			this->path.erase(this->path.end() - 1);

		this->path += '*';
	}
	else
		this->path += dir + "//*";
}

//--------------------------------------------------------------------------------------------------------

void FileManager::makedir()
{
	COORDS(35, lengthPath(this->path));
	string newFolder, newPath;
	getline(cin, newFolder);
	newPath = this->path;
	newPath.erase(newPath.end() - 1);
	newPath += newFolder;
	_mkdir(newPath.c_str());
	this->count++;
	this->newFolder = true;
	this->directory.push_back(newFolder);
}

//--------------------------------------------------------------------------------------------------------

void FileManager::changeName(int num)
{
	COORDS(35, lengthPath(this->path));
	string newPath, oldFolder = this->path, str;
	getline(cin, str);
	oldFolder.erase(oldFolder.end() - 1);
	newPath = oldFolder;
	oldFolder += this->getName(num);
	newPath += str;
	rename(oldFolder.c_str(), newPath.c_str());
	this->newFolder = true;
}

//--------------------------------------------------------------------------------------------------------

void FileManager::copyName(int sel)
{
	while (true)
	{
		showDirectory(sel, "show", 'l');
		
	}
	
}

//--------------------------------------------------------------------------------------------------------

void clear(string what)
{
	COLOR(defaultForeGround, defaultBackGround);
	if (what == "name")
	{
		for (int i = 0; i < 54; i++)
			cout << " ";
	}
	else
	if (what == "attr")
	{
		for (int i = 0; i < 4; i++)
			cout << " ";
	}
	else
		for (int i = 0; i < 6; i++)
			cout << " ";

//	COORDS(row, col);
}