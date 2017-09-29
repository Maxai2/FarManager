#include "Functions.h"



Functions::Functions()
{
}


Functions::~Functions()
{
}


#include <iostream>

using namespace std;

//void frame(int x, int y, int height, int width, char symbol)
//{
//	COORDS(y, x);
//}

void line(int x, int y, int length, Colors color)
{
	COLOR(color, defaultBackGround);

	for (int i = 0; i < length; i++)
		cout << "-";

	COLOR(defaultColor, defaultBackGround);
}

void head()
{
	COORDS(headY, headX);
	cout << "File:\tSize\tType:\tAttr:";
	line(headX, headY + 1, 32, Colors::BLUE);


}