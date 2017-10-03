#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <conio.h>

#include "FileManager.h"
#include "Functions.h"

using namespace std;

//https://github.com/facebookarchive/RakNet/blob/master/Source/_FindFirst.h

void main()
{
	Functions f;
	f.head();
	
	_getch();

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

	////rename("text.txt", str.c_str());
	////remove(str.c_str());

	////mkdir(str.c_str());
	////rmdir(str.c_str());

	//_finddata_t fileinfo;
	//int handle = _findfirst(str.c_str(), &fileinfo);
	//int find = handle;
	//int count = 0;
	//while (find != -1)
	//{
	//	count++;
	//	cout << (fileinfo.attrib & _A_SUBDIR ? "dir " : "file") << '\t';
	//	cout << fileinfo.name << '\n';
	//	find = _findnext(handle, &fileinfo);
	//}
	//cout << "\nInformation: was found " << count;
	//cout << " file(s) in folder..." << str << "\n\n";
	//_findclose(handle);
}