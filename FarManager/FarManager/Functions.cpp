#include "Functions.h"

Functions::Functions(){}

Functions::~Functions(){}

void Functions::line(int x, int y, int length, Colors color, int direction)
{
	COLOR(color, defaultBackGround);

	COORDS(y, x);
	switch (direction)
	{
		case 6:
			for (int i = 0; i < length; i++)
				cout << "-";
		break;

		case 2:
			for (short i = y; i < y + length; i++)
			{
				COORDS(i, x);
				cout << "|";
			}
	}

	COLOR(defaultForeGround, defaultBackGround);
}

void Functions::square()
{
	COORDS(StartCoord::startX, StartCoord::startY);
	cout << (char)201;

	for (int i = 0; i < Console::consoleWidth / 2 - Console::consoleHeight; i++)
		cout << (char)205;

	cout << (char)187;
	
}

void Functions::background(){ COLOR(defaultForeGround, Colors::DARKBLUE);}

void Functions::frame()
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = Console::fontSize;            // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
//	wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	COORD bufferSize = { Console::consoleWidth, Console::consoleHeight };
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
}

void Functions::head()
{
	background(); frame(); square();
//	COORDS(headY, headX);
//	cout << setw(10) << "File: " << "\tSize\tType:\tAttr:";
//	line(headX, headY + 1, 32, Colors::BLUE, 6);


}