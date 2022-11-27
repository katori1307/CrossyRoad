#include "Helicopter.h"


Helicopter::Helicopter()
{
	mX = mX2 = 6;
	mY = 13;
	moveCount = moveCount2 = 0;
}



Helicopter::~Helicopter()
{

}


int Helicopter::getX()
{
	return mX;
}

void Helicopter::setX(int x)
{
	mX = x;
}

int Helicopter::getX2()
{
	return mX2;
}


void Helicopter::setX2(int x)
{
	mX2 = x;
}

int Helicopter::getY()
{
	return mY;
}

void Helicopter::setY(int y)
{
	mY = y;
}


int Helicopter::getMoveCount()
{
	return moveCount;
}

int Helicopter::getMoveCount2()
{
	return moveCount2;
}

void Helicopter::setMoveCount(int step)
{
	moveCount = step;
}

void Helicopter::setMoveCount2(int step)
{
	moveCount2 = step;
}

void Helicopter::updateMoveCount()
{
	if (moveCount <= 20)
		moveCount++;
	else
		moveCount = 0;
}


void Helicopter::updateMoveCount2()
{
	moveCount2 = moveCount - 1;
	if (moveCount2 <= 20)
		moveCount2++;
	else
		moveCount2 = 0;
}




