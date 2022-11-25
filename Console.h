#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

#define consoleWidth 120
#define consoleHeight 32

using namespace std;

const int Y_START = 0;
const int X_START = 0;



class Console
{

private:
	int width;
	int height;
public:
	Console();
	~Console();

	void GotoXY(int x, int y);
	void clrscr();
	void FixConsoleWindow();
	void resizeConsole(int width, int height);
	void TextColor(int color);
	void hideCursor();

};