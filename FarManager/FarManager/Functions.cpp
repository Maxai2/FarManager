#include "Functions.h"

Functions::Functions(){}

Functions::~Functions(){}

void Functions::line(int x, int y, int length, Colors color, int direction)
{
	COLOR(Colors::CYAN, defaultBackGround);

	COORDS(y, x);
	switch (direction)
	{
		case 6:
			for (int i = 0; i < length; i++)
			{
				if (i == 62 || i == 69 || i == 76)
					cout << (char)193;
				else
					cout << (char)196;
			}
		break;

		case 2:
			for (short i = y; i < y + length; i++)
			{
				COORDS(i, x);
				cout << (char)179;
			}
	}

	COLOR(color, defaultBackGround);
}

void Functions::square()
{
	COORDS(StartCoord::startX, StartCoord::startY);
	COLOR(Colors::CYAN, defaultBackGround);

	for (int i = 0; i < 2; i++)
	{
		cout << (char)201;

		for (int i = 0; i < Console::consoleWidth / 2 - 2; i++)
		{
			if (i == 62 || i == 69 || i == 76)
				cout << (char)209;
			else
				cout << (char)205;
		}

		cout << (char)187;
	}	
	
	for (int i = 0; i < Console::consoleHeight - 2; i++)
	{
		i == 84 ? cout << (char)199 : cout << (char)186;

		for (int j = 0; j < Console::consoleWidth / 2 - 2; j++)
			cout << " ";

		i == 84 ? cout << (char)182 : cout << (char)186;
	}

	for (int i = 0; i < 2; i++)
	{
		cout << (char)200;

		for (int i = 0; i < Console::consoleWidth / 2 - 2; i++)
				cout << (char)205;

		cout << (char)188;
	}

	COLOR(defaultForeGround, defaultBackGround);
}

void Functions::background(){ COLOR(defaultForeGround, Colors::DARKBLUE);}

void Functions::frame()
{
	//CONSOLE_FONT_INFOEX cfi;
	//cfi.cbSize = sizeof(cfi);
	//cfi.nFont = 0;
	//cfi.dwFontSize.X = 0;                   // Width of each character in the font
	//cfi.dwFontSize.Y = Console::fontSize;            // Height
	//cfi.FontFamily = FF_DONTCARE;
	//cfi.FontWeight = FW_NORMAL;
	//wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	COORD bufferSize = { Console::consoleWidth, Console::consoleHeight };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
}

void Functions::head()
{
	background(); frame(); square();

	for (short i = 0; i < 150; i += 85)
	{
		COLOR(Colors::YELLOW, defaultBackGround);
		COORDS(StartCoord::headY, StartCoord::headX + 20 + i);
		cout << "Name";
		line(StartCoord::headX + 62 + i, StartCoord::headY, Console::consoleHeight / 2 - 3, Colors::YELLOW, 2);
		COORDS(StartCoord::headY, StartCoord::headX + 64 + i);
		cout << "Size";
		line(StartCoord::headX + 69 + i, StartCoord::headY, Console::consoleHeight / 2 - 3, Colors::YELLOW, 2);
		COORDS(StartCoord::headY, StartCoord::headX + 71 + i);
		cout << "Type";
		line(StartCoord::headX + 76 + i, StartCoord::headY, Console::consoleHeight / 2 - 3, Colors::YELLOW, 2);
		COORDS(StartCoord::headY, StartCoord::headX + 78 + i);
		cout << "Attr";

		line(StartCoord::headX + i, Console::consoleHeight / 2 - 2, Console::consoleHeight - 7, defaultForeGround, 6);
	}
	
}