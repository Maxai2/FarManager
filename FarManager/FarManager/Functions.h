#pragma once
#include <Windows.h>
#include <iostream>
#include <direct.h>
#include <iomanip>

using namespace std;

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

#define COLOR(foreground, background) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background * 16 + foreground)
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)col, (short)row })
#define RAND(min, max) rand() % (max - min + 1) + min

#define headX 2
#define headY 2
#define defaultColor	  Colors::GREY
#define defaultBackGround Colors::BLACK

class Functions
{
	void line(int x, int y, int length, Colors color, int direction);

public:
	Functions();
	void head();
};
