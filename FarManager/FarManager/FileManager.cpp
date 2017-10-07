#include "FileManager.h"

//--------------------------------------------------------------------------------------------------------


FileManager::FileManager(string path) { this->path = path; }

//--------------------------------------------------------------------------------------------------------

void FileManager::showDirectory(int sel, string mode)
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
			if (temppath == ".")
			{
				temppath = "";
				find = _findnext(handle, &fileinfo);
				continue;
			}
			
			COORDS((short)this->count + 2, 1);

			if (this->count == sel)
				check = true;

			if (fileinfo.attrib & _A_SYSTEM || fileinfo.attrib & _A_HIDDEN)
			{
				if (check)
					COLOR(Colors::LIGHTGREY, Colors::DARKCYAN);
				else
					COLOR(Colors::LIGHTGREY, defaultBackGround);
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
			COORDS((short)this->count + 2, Place::Size + 2);
			if (size == 0)
				cout << "Folder";
			else
				BytesConv(fileinfo.size);
		

			COORDS((short)this->count + 2, Place::Type + 2);
			if (fileinfo.attrib & _A_SUBDIR){ cout << "Direct"; folderCount++; }
			else { cout << " File"; fileCount++; }

			COORDS((short)this->count + 2, Place::Attr + 2);
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
	
		COLOR(defaultForeGround, defaultBackGround);
		this->willbe = false;

		//COORDS(Console::consoleHeight + 100, StartCoord::headX);
		//cout << "Folders count: " << folderCount << ", files count: " << fileCount;
		//COORDS(Console::consoleHeight + 100, StartCoord::headX);
		//cout << " file(s) in folder..." << this->path << "\n\n";
	
		_findclose(handle);
	}
	else
	{
		_finddata_t fileinfo;
		int handle = _findfirst(oldPath.c_str(), &fileinfo);
		int find = handle;
		this->count = 0;
		string tempoldPath = fileinfo.name;

		while (find != -1)
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

			this->count++;
			find = _findnext(handle, &fileinfo);
		}

		this->willbe = true;
		_findclose(handle); 
	}
}
//--------------------------------------------------------------------------------------------------------

int FileManager::getCount()
{
	return this->count;
}

//--------------------------------------------------------------------------------------------------------

string FileManager::getName(int sel)
{
	return this->directory[sel];
}

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

void clear(string what)
{
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