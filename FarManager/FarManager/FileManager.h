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
	bool newFolder;
	 
	int count = 0;

	void pathModif(string path);
	void clearPathPlace();
	int lengthPath(string path);
public:
	vector<string> directory;
	bool list = false;
	FileManager(string path); 

	int getCount();
	string getName(int sel);
	string getPath();
	friend void clear(string what);
	int dirCount(string path);

	void showDirectory(int sel, string mode, char rightLeft, string exception = ".", int EndPlusOne = 0);
	void changeDirectory(string dir);
	void makedir();
	void changeName(int num);
	void copyName();
	//void remove(string path);
	//void move();
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