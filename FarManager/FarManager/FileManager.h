#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <vector>
#include <iomanip>
#include <fstream>

#include "Functions.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------

class FileManager
{
	string path;
	string oldPath;
	bool willbe = true;
	bool newFolder;
	 
	int count = 0;

	void clearPathPlace();
public:
	vector<string> directory;
	bool list = false;
	bool notRefresh = false;
	FileManager(string path); 

	void pathModif(string path);
	int getCount();
	string getName(int sel);
	string getPath();
	friend void clear(string what);
	int dirCount(string path);
	int lengthPath(string path);
	void changeRoot();
	bool folderOrNot(string path, string name);

	void showDirectory(int sel, string mode, char rightLeft, string exception = ".", int EndPlusOne = 0);
	void changeDirectory(string dir);
	void makedir(char leftRight);
	void changeName(int num, char leftRight);
	void copyName(string from, string to, string name);
	void removeFileFolder(string path, string name);
	void move(string from, string to, string name);
	void findFiles(string path, string name);
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