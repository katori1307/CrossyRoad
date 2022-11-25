
#include "Vehicle.h"


Vehicle::Vehicle()
{
	mX = 6;
	mY = 5;
	mSpeed = 1;
	moveCount = 0;
}

Vehicle::~Vehicle()
{

}


void Vehicle::Draw()
{
	Console handle;
	int y = mY;
	for (int i = 0; i < 3; i++)
	{
		handle.GotoXY(mX, i + y);
		cout << form[i];
	}
}


void Vehicle::deDraw()
{
	Console handle;
	int y = mY;
	for (int i = 0; i < 3; i++)
	{
		handle.GotoXY(mX, i + y);
		cout << "              ";
	}
}


void Vehicle::Move()
{
	while (1)
	{
		Draw();
		Sleep(100);
		deDraw();
		mX++;
		if (mX + 14 >= 79)
			mX = 6;
	}
}

int Vehicle::getX()
{
	return mX;
}

int Vehicle::getY()
{
	return mY;
}

void Vehicle::setX(int x)
{
	mX = x;
	return;
}

void Vehicle::setY(int y)
{
	mY = y;
	return;
}


void Vehicle::updateMoveCount()
{
	if (moveCount <= 100)
		moveCount++;
	else
		moveCount = 0;
}


bool Vehicle::isTime()
{
	return moveCount != 0;
}


int Vehicle::getMoveCount()
{
	return moveCount;
}


void Vehicle::setMoveCount(int step)
{
	moveCount = step;
}