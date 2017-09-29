#pragma once
#include <string>
#include <direct.h>
#include <io.h>

using namespace std;

class FileManager
{
	string path;
public:
	FileManager(string path);
	//{
	//	this->path = path;
	//}

	//void showDirectory();

	////Name:			Size:		Type:		Attr:
	////--------------------------------------------
	////..
	////Folder1			15Mb		dir			NH
	////1.txt			123b		file		RS
	////--------------------------------------------
	////Files: 1	Folders: 1	Size: 15Mb

	//void findFiles(string mask);
	//void changeDirectory(string dir);
	//void remove(string path);
	//void rename(string path, string name);
};