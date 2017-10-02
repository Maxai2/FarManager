#include "Functions.h"

Functions::Functions()
{
}

//void frame(int x, int y, int height, int width, char symbol)
//{
//	COORDS(y, x);
//}

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

	COLOR(defaultColor, defaultBackGround);
}

void Functions::head()
{
	COORDS(headY, headX);
	cout << std::setw(10) << "File:\tSize\tType:\tAttr:";
	line(headX, headY + 1, 32, Colors::BLUE, 6);


}