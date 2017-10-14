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

	//FileManager fml("C://*");
	FileManager fml("D://Joker//Documents//*");
	//FileManager fmr("C://Users//Mahm_iz81//Documents//*");
	//FileManager fml("C://Users//Ali//Desktop//New folder//*");
	//FileManager fml("C://Windows//*");
	FileManager fmr("D://Joker//Desktop//*");

	int temp = 0; 

	fmr.showDirectory(temp, "show", 'r');
	fml.showDirectory(temp, "show", 'l');

	while(1)
	{
		if (temp >= 29)
		{
			fmr.list = true;
			if (f.getTab())
			{
				if (fmr.getName(0) != ".")
					fmr.showDirectory(temp, "clear", 'r');
				else
					fmr.showDirectory(temp, "clear", 'r', fmr.getName(0));

				fml.showDirectory(temp, "list", 'l', fml.getName(temp - 1));
			}
			else
			{
				if (fml.getName(0) != ".")
					fml.showDirectory(temp, "clear", 'l');
				else
					fml.showDirectory(temp, "clear", 'l', fml.getName(0));

				//fml.showDirectory(temp, "list", 'l', fml.getName(temp - 1), f.EndPlusOne);
			}
		}
		else
		{
			fml.list = false;
			if (f.getTab())
				fmr.showDirectory(temp, "show", 'r');
			else
				fml.showDirectory(temp, "show", 'l');
		}

		if (f.getTab())
		{
			temp = f.keyWork(fmr.getCount());
			//f.realCount = fmr.dirCount(fmr.getPath());
		}
		else
		{
			temp = f.keyWork(fml.getCount());
			//f.realCount = fml.dirCount(fml.getPath());
		}

//-----------------------------------------------------------------------------------------

		if (f.enter)
		{
			if (f.getTab())
			{
				fmr.notRefresh = true;
				fmr.changeDirectory(fmr.getName(temp));

				if (fmr.getName(0) != ".")
					fmr.showDirectory(temp, "clear", 'r', fmr.getName(0));
				else
					fmr.showDirectory(temp, "clear", 'r');
				fmr.notRefresh = false;
			}
			else
			{
				fml.notRefresh = true;
				fml.changeDirectory(fml.getName(temp));

				if (fml.getName(0) != ".")
					fml.showDirectory(temp, "clear", 'l', fml.getName(0));
				else
					fml.showDirectory(temp, "clear", 'l');
				fml.notRefresh = false;
			}

			temp = 0; f.sel = 0; f.enter = false;
		}
		else
		if (f.F0) exit(0); // exit
		else
		if (f.F2) // rename
		{
			f.noCursor(true);
			if (f.getTab())
				fmr.changeName(temp);
			else
				fml.changeName(temp);
			f.noCursor(false);
			f.F2 = false;
		}
		else
		if (f.F3) // viewe
		{
			int key = 0;
			system("cls");
			COLOR(Colors::BLACK, Colors::DARKCYAN);
			if (f.getTab())
			{
				fmr.pathModif(fmr.getPath());
				f.showContain(fmr.getPath(), fmr.getName(temp));
			}
			else
			{
				fml.pathModif(fml.getPath());
				f.showContain(fml.getPath(), fml.getName(temp));
			}

			while (key != 27)
			{
				key = _getch();
			}

			f.F3 = false;
			f.head();

			f.getTab() ? fml.showDirectory(temp, "show", 'l') : fmr.showDirectory(temp, "show", 'r');
		}
		else
		if (f.F4) // find
		{
			int key = 0;
			system("cls");
			string mask;

			COORDS(35, f);

			if (f.getTab())
			{
				getline(cin, mask);
				fmr.findFiles(fmr.getPath(), fmr.getName(temp));
			}
			else
			{
				fml.findFiles(fml.getPath(), fml.getName(temp));
			}

			while (key != 27)
			{
				key = _getch();
			}

			f.F4 = false;
			f.head();

			f.getTab() ? fml.showDirectory(temp, "show", 'l') : fmr.showDirectory(temp, "show", 'r'); 
		}
		else
		if (f.F5) // copy
		{
			if (f.getTab())
			{
				fmr.copyName(fmr.getPath(), fml.getPath(), fmr.getName(temp));
				fmr.showDirectory(temp, "clear", 'l');
			}
			else
			{
				fml.copyName(fml.getPath(), fmr.getPath(), fml.getName(temp));
				fml.showDirectory(temp, "clear", 'r');
			}
			f.F5 = false;
		}
		else
		if (f.F6) // move
		{
			if (f.getTab())
				fmr.move(fmr.getPath(), fml.getPath(), fmr.getName(temp));
			else
				fml.move(fml.getPath(), fmr.getPath(), fml.getName(temp));

			fml.showDirectory(temp, "clear", 'l');
			fmr.showDirectory(temp, "clear", 'r');
			f.F6 = false;
		}
		else
		if (f.F7) // makedir
		{
			f.noCursor(true);
			if (f.getTab())
				fmr.makedir();
			else
				fml.makedir();

			f.noCursor(false);
			f.F7 = false;
		}
		else
		if (f.F8) // delete
		{
			if (f.getTab())
			{
				fmr.removeFile(fmr.getPath(), fmr.getName(temp));
				fmr.showDirectory(0, "clear", 'r');
			}
			else
			{
				fml.removeFile(fml.getPath(), fml.getName(temp));
				fml.showDirectory(0, "clear", 'l');
			}
			f.F8 = false;
		}
	}

	system("pause");

}