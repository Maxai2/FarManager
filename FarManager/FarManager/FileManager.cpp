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
	for (int i = 0; i < Console::consoleWidth / 2; i++)
		cout << " ";
}

//--------------------------------------------------------------------------------------------------------

int FileManager::lengthPath(string path) { return path.size(); }

//--------------------------------------------------------------------------------------------------------

void FileManager::changeRoot()
{
	if (this->path[0] == 'C')
		this->path = "D://*";
	else
		this->path = "C://*";
}

//--------------------------------------------------------------------------------------------------------

bool FileManager::folderOrNot(string path, string name)
{
	_finddata_t fileinfo;
	int handle = _findfirst(path.c_str(), &fileinfo);
	int find = handle;
	
	while (true)
	{
		if (fileinfo.name == name && fileinfo.attrib & _A_SUBDIR)
			return true;

		find = _findnext(handle, &fileinfo);
	}

	_findclose(handle);
	return false;
}

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
//string includeEndSlash(string path)
//{
//	if (path[path.length - 1] != '\\')
//		path += '\\';
//
//	return path;
//}
////--------------------------------------------------------------------------------------------------------
//string excludeEndSlash(string path)
//{
//	if (path[path.length - 1] == '\\')
//		path.erase(path.end() - 1);
//
//	return path;
//}
////--------------------------------------------------------------------------------------------------------
//void getDirectory(vector<F_INFO> &files, string path)
//{
//	files.clear;
//	_finddata_t fileinfo;
//	int done = _findfirst((includeEndSlash(path) + "*").c_str(), &fileinfo);
//
//	while (!done)
//	{
//		if (fileinfo.attrib  & _A_SUBDIR && fileinfo.name == ".")
//		{
//			done = _findnext(handle, &fileinfo);
//			continue;
//		}
//
//
//		F_INFO *f = new F_INFO;
//
//	
//
//		files.push_back(f);
//
//		done = _findnext(handle, &fileinfo);
//	}
//
//}

void FileManager::showDirectory(int sel, string mode, char rightLeft, string exception, int EndPlusOne)
{
	if (mode == "show")
	{
		_finddata_t fileinfo;
		int handle = _findfirst(path.c_str(), &fileinfo);

		bool check = false;
		string buffer, temppath;
		this->oldPath = this->path;
		int find = handle;
		int folderCount = 0, fileCount = 0;
		this->count = 0;
		temppath = fileinfo.name;

		if (this->path == "D://*" && handle == -1)	this->path = "C://*";

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
				rightLeft == 'r' ? COORDS((short)this->count + 2, 76) : COORDS((short)this->count + 2, 1);

			if (this->newFolder) clear("name");
				rightLeft == 'r' ? COORDS((short)this->count + 2, 76) : COORDS((short)this->count + 2, 1);

			//if (sel > dirCount(this->path))
			//{
			//	sel = dirCount(this->path);
			//	check = true;
			//}

			if (this->count == sel)	check = true;

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
			rightLeft == 'r' ? COORDS((short)this->count + 2, 76 + Place::Size + 1) : COORDS((short)this->count + 2, Place::Size + 2);
			if (size == 0)
				cout << "Folder";
			else
				BytesConv(fileinfo.size);

			rightLeft == 'r' ? COORDS((short)this->count + 2, 76 + Place::Type + 1) : COORDS((short)this->count + 2, Place::Type + 2);
			if (fileinfo.attrib & _A_SUBDIR)
			{
				if (fileinfo.name != "..")
					folderCount++;

				cout << "Direct"; 
			}
			else { cout << " File"; fileCount++; }

			rightLeft == 'r' ? COORDS((short)this->count + 2, 76 + Place::Attr + 1) : COORDS((short)this->count + 2, Place::Attr + 2);
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


		rightLeft == 'r' ? COORDS(33, StartCoord::headXr) : COORDS(33, StartCoord::headXl);
		clear("fileFilder");
		rightLeft == 'r' ? COORDS(33, StartCoord::headXr) : COORDS(33, StartCoord::headXl);
		COLOR(Colors::GREEN, defaultBackGround);
		cout << "\t\tFolders count: ";
		if (getName(0) != "..")
			cout << folderCount;
		else cout << --folderCount;

		cout << ", files count: " << fileCount;
		rightLeft == 'r' ? COORDS(35, StartCoord::headXr) : COORDS(35, StartCoord::headXl);
		clearPathPlace();
		rightLeft == 'r' ? COORDS(35, StartCoord::headXr) : COORDS(35, StartCoord::headXl);
		pathModif(this->path);
	
		COLOR(defaultForeGround, defaultBackGround);
		_findclose(handle);
	}
	else
	if (mode == "clear")
	{
		_finddata_t fileinfo;
		int handle = _findfirst(oldPath.c_str(), &fileinfo);
		int find = handle;
		string tempoldPath = fileinfo.name;
		short cnt = 0;

		while (true)
		{
			if (tempoldPath == exception)
			{
				tempoldPath = "";
				find = _findnext(handle, &fileinfo);
				continue;
			}

			rightLeft == 'r' ? COORDS(cnt + 2, 76) : COORDS(cnt + 2, 1);
			clear("name");

			rightLeft == 'r' ? COORDS(cnt + 2, 76 + Place::Size + 1) : COORDS(cnt + 2, Place::Size + 2);
			clear("size");

			rightLeft == 'r' ? COORDS(cnt + 2, 76 + Place::Type + 1) : COORDS(cnt + 2, Place::Type + 2);
			clear("type");

			rightLeft == 'r' ? COORDS(cnt + 2, 76 + Place::Attr + 1) : COORDS(cnt + 2, Place::Attr + 2);
			clear("attr");

			if (this->notRefresh)
				directory.pop_back();

			if (cnt == this->count - 1)
				break;
			else
				cnt++;

			find = _findnext(handle, &fileinfo);
		}
		this->count = 0;

		this->willbe = true;
		_findclose(handle); 
	}
	else
	{
		bool check = false;
		_finddata_t fileinfo;
		int handle = _findfirst(path.c_str(), &fileinfo);
		int find = handle;
		string buffer;

		for (int i = 0 + EndPlusOne; i < 29 + EndPlusOne; i++)
		{
			rightLeft == 'r' ? COORDS((short)this->count + 2, 76) : COORDS((short)this->count + 2, 1);

			if (this->newFolder) clear("name");
			rightLeft == 'r' ? COORDS((short)this->count + 2, 76) : COORDS((short)this->count + 2, 1);

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
			rightLeft == 'r' ? COORDS((short)this->count + 2, 76 + Place::Size + 1) : COORDS((short)this->count + 2, Place::Size + 2);
			if (size == 0)
				cout << "Folder";
			else
				BytesConv(fileinfo.size);

			rightLeft == 'r' ? COORDS((short)this->count + 2, 76 + Place::Type + 1) : COORDS((short)this->count + 2, Place::Type + 2);
			if (fileinfo.attrib & _A_SUBDIR)
				cout << "Direct";
			else 
				cout << " File"; 

			rightLeft == 'r' ? COORDS((short)this->count + 2, 76 + Place::Attr + 1) : COORDS((short)this->count + 2, Place::Attr + 2);
			string attr;
			if (fileinfo.attrib & _A_SYSTEM) attr += "S";
			if (fileinfo.attrib & _A_NORMAL) attr += "N";
			if (fileinfo.attrib & _A_RDONLY) attr += "R";
			if (fileinfo.attrib & _A_HIDDEN) attr += "H";

			cout << attr;

			this->count++;
			check = false;

			find = _findnext(handle, &fileinfo);
		}

		COLOR(defaultForeGround, defaultBackGround);
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
	//exit if handle return -1

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

void FileManager::makedir(char leftRight)
{
	COORDS(35, leftRight == 'l' ? (short)lengthPath(this->path) : short(StartCoord::headXr + lengthPath(this->path)));
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

void FileManager::changeName(int num, char leftRight)
{
	COORDS(35, leftRight == 'l' ? (short)lengthPath(this->path) : short(StartCoord::headXr + lengthPath(this->path)));
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
void FileManager::copyName(string from, string to, string name)
{
	from.erase(from.end() - 1);
	to.erase(to.end() - 1);
	string sourcePath, copyPath;
	sourcePath = from + name;
	copyPath = to + name;

	ifstream source(sourcePath, ios::binary);
	ofstream copy(copyPath, ios::binary);
	string buffer;
	while (source)
	{
		getline(source, buffer);
		copy << buffer << endl;
	}
	copy.close();
	source.close();
}

//--------------------------------------------------------------------------------------------------------

void FileManager::removeFileFolder(string path, string name)
{
	bool check = folderOrNot(path, name);

	path.erase(path.end() - 1);
	string buffer;
	buffer = path + name;

	if (check)
		_rmdir(buffer.c_str());
	else
		remove(buffer.c_str());
}

//--------------------------------------------------------------------------------------------------------

void FileManager::move(string from, string to, string name)
{
	static string movePath, sourcePath;
	static bool check = folderOrNot(from, name);
	bool stat = true;

	if (check)
	{
		if (stat)
		{
			from.erase(from.end() - 1);
			sourcePath = from + name;

			to.erase(to.end() - 1);
			movePath = to + name;
			_mkdir(movePath.c_str());
		}

		if (_rmdir(sourcePath.c_str()) == -1)
		{
			_finddata_t fileinfo;
			int handle = _findfirst(path.c_str(), &fileinfo);
			int find = handle;

			stat = false;

		}
	}
	else
	{
		to.erase(to.end() - 1);
		from.erase(from.end() - 1);
		sourcePath = from + name;
		movePath = to + name;

		ifstream sourcePlace(sourcePath, ios::binary);
		ofstream movePlace(movePath, ios::binary);
		string buffer;
		while (sourcePlace)
		{
			getline(sourcePlace, buffer);
			movePlace << buffer << endl;
		}
		sourcePlace.close();
		movePlace.close();

		remove(sourcePath.c_str());
	}
}

//--------------------------------------------------------------------------------------------------------

void FileManager::findFiles(string path, string name)
{
	//if (mask[0] == '*' && mask[mask.size() - 1] == '*')
	//{

	//}
	//else
	//if (mask[0] == '*')
	//{

	//}
	//else
	//if (mask[mask.size() - 1] == '*')
	//{

	//}
	//else
	//{

	//}
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
	if (what == "type" || what == "size")
	{
		for (int i = 0; i < 6; i++)
			cout << " ";
	}
	else
		for (int i = 0; i < 50; i++)
			cout << " ";

//	COORDS(row, col);
}