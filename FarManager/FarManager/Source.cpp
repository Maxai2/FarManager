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

	FileManager fm("C://*");

	fm.showDirectory(0);

	int temp = 0;
	while(1)
	{
		temp = f.move(fm.getCount());
		system("cls");
		fm.showDirectory(0);
		_getch();	
	}


}