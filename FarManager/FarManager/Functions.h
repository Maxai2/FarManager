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
	Tilde = 126,
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
#define maxFolderCount 29

#define COLOR(foreground, background) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background * 16 + foreground)
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)col, (short)row })
//#define RAND(min, max) rand() % (max - min + 1) + min

//--------------------------------------------------------------------------------------------------------

class Functions
{
	int realCount = 0;
	int EndPlusOne = 0;

	void line(int x, int y, int length, Colors color, int direction); 
	void square();
	void frame();
	void background();
	friend bool frac(float num);
public:
	int sel = 0;
	bool tilde = false;
	bool tab = false;
	bool enter = false;
	bool F0 = false;
	bool F2 = false;
	bool F3 = false;
	bool F4 = false;
	bool F5 = false;
	bool F6 = false;
	bool F7 = false;
	bool F8 = false;
	Functions();
	~Functions();

//	bool getTab();
//	bool getEnter();
//	void setEnter(bool val);
//	bool getF0();
//	void setF0(bool val);
//	bool getF2();
//	void setF2(bool val);
//	bool getF3();
//	void setF3(bool val);
//	bool getF4();
//	void setF4(bool val);
//	bool getF5();
//	void setF5(bool val);
//	bool getF6();
//	void setF6(bool val);
//	bool getF8();
//	void setF8(bool val);



	void head();
	friend void BytesConv(float size);
	int keyWork(int count);
	void noCursor(bool visible);
	void showContain(string path, string name);
};
