#pragma once
#include <vector>
#include <string>
#include "Console.h"

using namespace std;

class Helicopter
{
private:
	int mX, mX2;
	int mY;
	int moveCount;
	int moveCount2;
public:
	Helicopter();
	~Helicopter();

	int getX();
	void setX(int);
	int getY();
	void setY(int);
	int getX2();
	void setX2(int);

	int getMoveCount();
	void setMoveCount(int);

	int getMoveCount2();
	void setMoveCount2(int);

	void updateMoveCount2();
	void updateMoveCount();
};