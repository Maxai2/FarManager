#include "Functions.h"

//--------------------------------------------------------------------------------------------------------

Functions::Functions(){}

//--------------------------------------------------------------------------------------------------------

Functions::~Functions()
{
	COLOR(defaultForeGround, Colors::BLACK);
}

//--------------------------------------------------------------------------------------------------------

void Functions::line(int x, int y, int length, Colors color, int direction)
{
	COLOR(Colors::CYAN, defaultBackGround);

	COORDS(y, x);
	switch (direction)
	{
		case 6:
			for (int i = 0; i < length + 20; i++)
			{
				if (i == Place::Size || i == Place::Type || i == Place::Attr)
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

//--------------------------------------------------------------------------------------------------------

void Functions::square()
{
	COORDS(StartCoord::startX, StartCoord::startY);
	COLOR(Colors::CYAN, defaultBackGround);

	for (int i = 0; i < 2; i++)
	{
		cout << (char)201;

		for (int i = 0; i < Console::consoleWidth / 2 - 2; i++)
		{
			if (i == Place::Size || i == Place::Type || i == Place::Attr)
				cout << (char)209;
			else
				cout << (char)205;
		}

		cout << (char)187;
	}	
	
	for (int i = 0; i < Console::consoleHeight - 2; i++)
	{
		//i == Console::consoleHeight - 5 ? cout << (char)199 : cout << (char)186;
		cout << (char)186;

		for (int j = 0; j < Console::consoleWidth / 2 - 2; j++)
			cout << " ";

		//i == Console::consoleHeight - 5 ? cout << (char)182 : cout << (char)186;
		cout << (char)186;
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

//--------------------------------------------------------------------------------------------------------

void Functions::background(){ COLOR(defaultForeGround, Colors::DARKBLUE);}

//--------------------------------------------------------------------------------------------------------

bool frac(float num)
{
	int temp = 0;

	temp = (int)num;

	if (temp == num)
		return false;
	else
		return true;
}

//--------------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------------

void Functions::head()
{
	background(); frame(); square();

	for (short i = 0; i < Console::consoleWidth; i += Console::consoleWidth / 2)
	{
		COLOR(Colors::YELLOW, defaultBackGround);
		COORDS(StartCoord::headY, StartCoord::headX + 20 + i);
		cout << "Name";
		line(StartCoord::headX + Place::Size + i, StartCoord::headY, Console::consoleHeight / 2 - 3, Colors::YELLOW, 2);
		COORDS(StartCoord::headY, StartCoord::headX + Place::Size + 2 + i);
		cout << "Size";
		line(StartCoord::headX + Place::Type + i, StartCoord::headY, Console::consoleHeight / 2 - 3, Colors::YELLOW, 2);
		COORDS(StartCoord::headY, StartCoord::headX + Place::Type + 2 + i);
		cout << "Type";
		line(StartCoord::headX + Place::Attr + i, StartCoord::headY, Console::consoleHeight / 2 - 3, Colors::YELLOW, 2);
		COORDS(StartCoord::headY, StartCoord::headX + Place::Attr + 1 + i);
		cout << "Attr";

//		line(StartCoord::headX + i, Console::consoleHeight / 2 - 2, Console::consoleHeight / 2, defaultForeGround, 6);
	}

	string fKey[] = {"F2 Rename", "F3 View", "F4 Find", "F5 Copy", "F6 Move", "F7 Mkdir", "F8 Delete", "F10 Exit"};

	COORDS(36, 1);
	int go = 7, arrCount  = 0;
	for (int i = 0; i < 85; i++)
	{
		if (i == go)
		{
			COLOR(Colors::BLACK, Colors::DARKCYAN);
			cout << fKey[arrCount];
			COLOR(defaultForeGround, defaultBackGround);
			go += 10; arrCount++;
		}
		else
			cout << " ";
	}

}

//--------------------------------------------------------------------------------------------------------

int Functions::keyWork(int count)
{
	int key = 0;

	key = _getch();

	if (key == 224)
		key = _getch(); 

	switch (key)	
	{
	case KEY::F2:
		this->enter = true;
		break;
	case KEY::UP:
		if (sel > 0)
			sel--;
		break;
	case KEY::RIGHT:
		sel = count - 1;
		break;
	case KEY::DOWN:
		if (sel < count - 1)
			sel++;
		break;
	case KEY::LEFT:
		sel = 0;
		break;
	case KEY::ENTER:
		this->enter = true;
	}

	return sel;
}

//--------------------------------------------------------------------------------------------------------

void Functions::noCursor(bool visible)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = visible; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

//--------------------------------------------------------------------------------------------------------

void BytesConv(float size)
{
	float tb = 1099511627776;
	float gb = 1073741824;
	float mb = 1048576;
	float kb = 1024;

	float ans = 0;

	if (size >= tb)
	{
		ans = size / tb;

		frac(ans) ? (cout << "~ " << int(ans) << "T") : (cout << " " << ans << "T");
	}
	else if (size >= gb && size < tb)
	{
		ans = size / gb;

		frac(ans) ? (cout << "~ " << int(ans) << "G") : (cout << " " << ans << "G");
	}
	else if (size >= mb && size < gb)
	{
		ans = size / mb;

		frac(ans) ? (cout << "~ " << int(ans) << "M") : (cout << " " << ans << "M");
	}
	else if (size >= kb && size < mb)
	{
		ans = size / kb;

		frac(ans) ? (cout << "~ " << int(ans) << "K") : (cout << " " << ans << "K");
	}
	else
		frac(ans) ? (cout << "~ " << int(ans) << "B") : (cout << " " << ans << "B");
}

