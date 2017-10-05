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
	f.noCursor(true);

	FileManager fm("C://*");

	int temp = 0;

	while(1)
	{
		fm.showDirectory(temp, "show");
		temp = f.move(fm.getCount());

		if (f.enter)
		{
			fm.changeDirectory(fm.getName(temp));
			fm.showDirectory(temp, "clear");
		}
	}

//	system("pause");

}