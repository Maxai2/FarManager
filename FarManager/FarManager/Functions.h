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
	F2 = 50,
	F3 = 51,
	F4 = 52,
	F5 = 53,
	F6 = 54,
	F7 = 55,
	F8 = 56,
	F0 = 48,
	TAB = 9,
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
	headXl = 1,
	headY = 1,
	headXr = 76
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
	bool tab = false;
	bool F0 = false;
	bool F2 = false;
	bool F5 = false;
	bool F7 = false;

	Functions();
	~Functions();
	void head();
	friend void BytesConv(float size);
	int keyWork(int count);
	void noCursor(bool visible);
};
