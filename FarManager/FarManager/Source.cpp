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

	//FileManager fm("C://*");
	//FileManager fm("C://Users//Joker//*");
	//FileManager fm("C://Users//Ali//Desktop//New folder//*");
	FileManager fm("C://Users//Mahm_iz81//Documents//*");

	int temp = 0, realCount = 0; 

	while(1)
	{
		if (temp > 29)
		{
			fm.showDirectory(temp, "show", 'r', fm.getName(temp - 1));
			
		}
		else
			fm.showDirectory(temp, "show", 'r'); 

		temp = f.keyWork(fm.getCount());

		if (f.enter)
		{
			fm.changeDirectory(fm.getName(temp));
			fm.showDirectory(temp, "clear", 'r');
			temp = 0; f.sel = 0; f.enter = false;
		}
		else
		if (f.F2)
		{
			f.noCursor(true);
			fm.changeName(temp);
			f.noCursor(false);
			f.F2 = false;
		}
		else
		if (f.F5)
		{
			f.noCursor(true);
			fm.copyName(temp);
			f.noCursor(false);
			f.F5 = false;
		}
		else
		if (f.F7)
		{
			f.noCursor(true);
			fm.makedir();
			f.noCursor(false);
			f.F7 = false;
		}
	}

	system("pause");

}