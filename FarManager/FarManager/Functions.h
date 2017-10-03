#pragma once
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

enum Colors
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKCYAN,
	DARKRED,
	DARKMAGENTA,
	BROWN,
	LIGHTGREY,
	GREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE
};

enum StartCoord
{
	startX = 0,
	startY = 0,
	headX = 1,
	headY = 1
};

enum Console
{
	fontSize = 20,
	consoleWidth = 170,
	consoleHeight = 90
};

#define defaultForeGround Colors::GREY
#define defaultBackGround Colors::DARKBLUE


#define COLOR(foreground, background) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background * 16 + foreground)
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)col, (short)row })
#define RAND(min, max) rand() % (max - min + 1) + min

class Functions
{
	void line(int x, int y, int length, Colors color, int direction);
	void square();
	void frame();
	void background();

public:
	Functions();
	~Functions();
	void head();
};
