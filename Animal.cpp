#include "Animal.h"


Animal::Animal()
{

}

Animal::~Animal()
{
	
}

int Animal::getX()
{
	return mX;
}

void Animal::setX(int x)
{
	mX = x;
}

int Animal::getX2()
{
	return mX2;
}


void Animal::setX2(int x)
{
	mX2 = x;
}

int Animal::getX3()
{
	return mX3;
}

void Animal::setX3(int x)
{
	mX3 = x;
}


int Animal::getY()
{
	return mY;
}

void Animal::setY(int y)
{
	mY = y;
}



Bird::Bird()
{
	mX = mX2 = mX3 = 6;
	mY = 9;
}

Bird::~Bird()
{

}


Cat::Cat()
{
	mX = mX2 = mX3 = 6;
	mY = 17;
}


Cat::~Cat()
{

}







