#include <iostream>
#include <vector>
#include <string>
#include "Console.h"

using namespace std;

#define MENU_WIDTH 15
#define MENU_HEIGHT 5

class Menu
{
private:
	int width, height;
	void drawTitle();

public:
	int updateChoice();
	
};


