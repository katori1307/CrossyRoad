#pragma once
#include <Windows.h>
#include <iostream>
#include "Console.h"
#include <vector>
#include "Vehicle.h"
#include "Animal.h"
#include "Helicopter.h"


class People
{
public:
	static const int width = 3;
	static const int height = 3;
private:
	int mX, mY;
	int mSpeed;
	bool mDead;
	vector<string> form;
public:
	People();
	~People();
	People(int, int);
	int getX();
	int getY();
	void setX(int);
	void setY(int);

	void Up();
	void Down();
	void Left();
	void Right();

	bool isFinish();
	bool isDead();

	bool isImpact(Vehicle* v);
	bool isImpactH(Helicopter* h);
	bool isImpactB(Bird* b);
	bool isImpactC(Cat* c);
	void reDrawLineWhenMoveUPDOWN();
	void reDrawLineWhenMoveRIGHT();
	void reDrawLineWhenMoveLEFT();
	
	
	




};