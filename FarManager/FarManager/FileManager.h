#pragma once
#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <vector>
#include <iomanip>

#include "Functions.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------

class FileManager
{
	string path;
	string oldPath;
	bool willbe = true;

	vector<string> directory;
	 
	int count = 0;

	void pathModif(string path);
	void clearPathPlace();
public:
	FileManager(string path); 

	int getCount();
	string getName(int sel);
	string getPath();
	friend void clear(string what);
	int dirCount(string path);

	void showDirectory(int sel, string mode, string exception = ".");
	void changeDirectory(string dir);
	void mkdir(string dirName);
	//void remove(string path);
	//void rename(string path, string name);
	//void copy(string oldpath, string newpath);
	//void move()
	//void findFiles(string mask);
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