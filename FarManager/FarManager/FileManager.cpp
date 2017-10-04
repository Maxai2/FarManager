#include "FileManager.h"

//--------------------------------------------------------------------------------------------------------

FileManager::FileManager(string path) { this->path = path; }

//--------------------------------------------------------------------------------------------------------

void FileManager::showDirectory()
{
	COORDS(StartCoord::startY + 2, StartCoord::startX + 1);

	_finddata_t fileinfo;
	int handle = _findfirst(path.c_str(), &fileinfo);
	int find = handle;
	int count = 0, folderCount = 0, fileCount = 0;
	while (find != -1)
	{
		COORDS(StartCoord::startY + 2 + (short)count, StartCoord::startX + 1);

		count++;
		if (fileinfo.attrib & _A_SYSTEM || fileinfo.attrib & _A_HIDDEN)
			COLOR(Colors::LIGHTGREY, defaultBackGround);
		else
		if (fileinfo.attrib & _A_SUBDIR)
			COLOR(Colors::WHITE, defaultBackGround);
		else
		if (fileinfo.attrib & _A_NORMAL)
			COLOR(Colors::BLUE, defaultBackGround);
		else
			COLOR(Colors::GREY, defaultBackGround);

		cout << fileinfo.name << '\n';

		int size = fileinfo.size;
		COORDS(StartCoord::startY + 1 + (short)count, Place::Size + 2);
		if (size == 0)
			cout << "Folder";
		else
			BytesConv(fileinfo.size);
		

		COORDS(StartCoord::startY + 1 + (short)count, Place::Type + 2);

		if (fileinfo.attrib & _A_SUBDIR){ cout << "Direct"; folderCount++; }
		else { cout << " File"; fileCount++; }

		COORDS(StartCoord::startY + 1 + (short)count, Place::Attr + 2);
		string attr;
		if (fileinfo.attrib & _A_SYSTEM) attr += "S";
		if (fileinfo.attrib & _A_NORMAL) attr += "N";
		if (fileinfo.attrib & _A_RDONLY) attr += "R";
		if (fileinfo.attrib & _A_HIDDEN) attr += "H";

		cout << attr;

		find = _findnext(handle, &fileinfo);
	}
	
	COLOR(defaultForeGround, defaultBackGround);

	COORDS(Console::consoleHeight + 100, StartCoord::headX);
	cout << "Folders count: " << folderCount << ", files count: " << fileCount;
	COORDS(Console::consoleHeight + 100, StartCoord::headX);
	cout << " file(s) in folder..." << this->path << "\n\n";

	_findclose(handle);
}
//--------------------------------------------------------------------------------------------------------
