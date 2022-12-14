#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

#define consoleWidth 150
#define consoleHeight 32

using namespace std;

class Console
{

private:
	int width;
	int height;
public:

	void GotoXY(int x, int y);
	void clrscr();
	void FixConsoleWindow();
	void resizeConsole(int width, int height);
	void TextColor(int color);
	void setconsolecolor(int textColor, int bgColor);
	void hideCursor();

};