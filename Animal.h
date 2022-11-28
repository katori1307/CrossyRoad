#pragma once
#include <vector>
#include <iostream>
#include "Console.h"


using namespace std;

class Animal
{
protected:
	int mX, mX2, mX3;
	int mY;
public:
	Animal();
	~Animal();
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	int getX2();
	void setX2(int);
	int getX3();
	void setX3(int);
};



class Bird :public Animal
{
public:
	Bird();
	~Bird();
};


class Cat :public Animal
{
public:
	Cat();
	~Cat();
};





