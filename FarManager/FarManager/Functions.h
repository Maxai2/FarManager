#pragma once
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

#include "FileManager.h"

//--------------------------------------------------------------------------------------------------------

using namespace std;

//HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

//--------------------------------------------------------------------------------------------------------

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

enum KEY
{
	F2 = 60,
	F3 = 61,
	F4 = 62,
	F5 = 63,
	F6 = 64,
	F7 = 65,
	F8 = 66,
	F10 = 68,
	UP = 72,
	RIGHT = 77,
	DOWN = 80,
	LEFT = 75,
	ENTER = 13
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
//	fontSize = 10,
	consoleWidth = 150,
	consoleHeight = 68
};

enum Place
{
	Size = 54,
	Type = 61,
	Attr = 68
};

//--------------------------------------------------------------------------------------------------------

#define defaultForeGround Colors::GREY
#define defaultBackGround Colors::DARKBLUE


#define COLOR(foreground, background) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background * 16 + foreground)
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)col, (short)row })
//#define RAND(min, max) rand() % (max - min + 1) + min

//--------------------------------------------------------------------------------------------------------

class Functions
{

	void line(int x, int y, int length, Colors color, int direction); 
	void square();
	void frame();
	void background();
	friend bool frac(float num);

public:
	int sel = 0;
	bool enter = false;
	bool F7 = false;

	Functions();
	~Functions();
	void head();
	friend void BytesConv(float size);
	int keyWork(int count);
	void noCursor(bool visible);
};
