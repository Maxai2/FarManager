#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include <conio.h>

#include "FileManager.h"
#include "Functions.h"

using namespace std;

//https://github.com/facebookarchive/RakNet/blob/master/Source/_FindFirst.h

//--------------------------------------------------------------------------------------------------------

void main() 
{
	Functions f;
	f.head();
	f.noCursor(false);


	FileManager fm("C://*");
	//FileManager fm("C://Users//Joker//*");
	//FileManager fm("C://Users//Ali//Desktop//New folder//*");

	int temp = 0; 

	while(1)
	{
		if (temp > fm.dirCount(fm.getPath()))
		{
			fm.showDirectory(temp, "show", fm.getName(temp - 1));
		}
		else
			fm.showDirectory(temp, "show"); 

		temp = f.keyWork(fm.getCount());

		if (f.enter)
		{
			fm.changeDirectory(fm.getName(temp));
			fm.showDirectory(temp, "clear");
			temp = 0; f.sel = 0; f.enter = false;
		}
		else
		if (f.F7)
		{
			fm.mkdir("asd");
		}
	}

	system("pause");

}