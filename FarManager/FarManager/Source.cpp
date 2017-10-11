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

	//FileManager fml("C://*");
	//FileManager fml("C://Users//Joker//*");
	//FileManager fml("C://Users//Mahm_iz81//Documents//*");
	FileManager fml("C://Users//Ali//Desktop//New folder//*");
	FileManager fmr("C://*");

	int temp = 0, realCount = 0; 

	fmr.showDirectory(temp, "show", 'r');
	fml.showDirectory(temp, "show", 'l');

	while(1)
	{
		if (temp > 29)
		{
			fml.showDirectory(temp, "show", 'l', fml.getName(temp - 1));
			
		}
		else
		{
			if (f.tab)
				fmr.showDirectory(temp, "show", 'r');
			else
				fml.showDirectory(temp, "show", 'l');
		}

		if (f.tab)
			temp = f.keyWork(fmr.getCount());
		else
			temp = f.keyWork(fml.getCount());

		if (f.enter)
		{
			if (f.tab)
			{
				fmr.changeDirectory(fmr.getName(temp));

				if (fmr.getName(0) != ".")
					fmr.showDirectory(temp, "clear", 'r', fmr.getName(0));
				else
					fmr.showDirectory(temp, "clear", 'r');
			}
			else
			{
				fml.changeDirectory(fml.getName(temp));

				if (fml.getName(0) != ".")
					fml.showDirectory(temp, "clear", 'l', fml.getName(0));
				else
					fml.showDirectory(temp, "clear", 'l');
			}

			temp = 0; f.sel = 0; f.enter = false;
		}
		else
		if (f.F0) exit(0);
		else
		if (f.F2)
		{
			f.noCursor(true);
			fml.changeName(temp);
			f.noCursor(false);
			f.F2 = false;
		}
		else
		if (f.F5)
		{
			//fml.showDirectory(temp, "show", 'r');
			f.F5 = false;
		}
		else
		if (f.F7)
		{
			f.noCursor(true);
			fml.makedir();
			f.noCursor(false);
			f.F7 = false;
		}

	}

	system("pause");

}