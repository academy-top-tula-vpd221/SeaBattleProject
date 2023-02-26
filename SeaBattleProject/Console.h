#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;


const char WATER = 176;
const char DESK = 219;

enum KeyCode
{
	ArrowUp = 72,
	ArrowDown = 80,
	ArrowLeft = 75,
	ArrowRight = 77,
	Enter = 13,
	Space = 32,
	Esc = 27
};

enum Colors
{
	Gray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White
};

class Console
{
	HANDLE descriptor;
	COORD coordinate;
	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
public:
	Console()
	{
		descriptor = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	HANDLE& Descriptor() { return descriptor; }

	void Clear()
	{
		system("cls");
	}

	void CursorGoTo(int row, int col)
	{
		coordinate.X = col;
		coordinate.Y = row;
		SetConsoleCursorPosition(descriptor, coordinate);
	}

	void Write(string out)
	{
		cout << out;
	}

	void WriteGoTo(int row, int col, string out)
	{
		CursorGoTo(row, col);
		Write(out);
	}

	void Foreground(Colors color, bool brightness = false)
	{
		GetConsoleScreenBufferInfo(descriptor, &csbInfo);
		int colorBack = csbInfo.wAttributes & (0b1111 << 4);
		int colorFore = color + (brightness ? 8 : 0);
		SetConsoleTextAttribute(descriptor, colorFore | colorBack);
	}

	void Background(Colors color, bool brightness = false)
	{
		GetConsoleScreenBufferInfo(descriptor, &csbInfo);
		int colorFore = csbInfo.wAttributes & 0b1111;
		int colorBack = (color + (brightness ? 8 : 0)) << 4;
		SetConsoleTextAttribute(descriptor, colorFore | colorBack);
	}

	void SetColors(Colors colorBack, bool brightnessBack,
		Colors colorFore, bool brightnessFore)
	{
		Background(colorBack, brightnessBack);
		Foreground(colorFore, brightnessFore);
	}

};

