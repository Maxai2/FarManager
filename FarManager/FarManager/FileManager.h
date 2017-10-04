#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>

#include "Functions.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------

class FileManager
{
	string path;
public:
	FileManager(string path);

	void showDirectory();

	//void findFiles(string mask);
	//void changeDirectory(string dir);
	//void remove(string path);
	//void rename(string path, string name);
	//void copy(string oldpath, string newpath);
	//void move()
};

//--------------------------------------------------------------------------------------------------------

//Name:			Size:		Type:		Attr:
//--------------------------------------------
//..
//Folder1		15Mb		dir			NH
//1.txt			123b		file		RS
//--------------------------------------------
//Files: 1	Folders: 1	Size: 15Mb

//FileManager fm("C:\\Windows\\System32\\");
//fm.find("*.txt");
//fm.changeDirectory("Debug");

//string str;
//getline(cin, str);

//rename("text.txt", str.c_str());
//remove(str.c_str());

//mkdir(str.c_str());
//rmdir(str.c_str());