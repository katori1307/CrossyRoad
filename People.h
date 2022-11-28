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
	static const int width = 1;
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

	void Up(int step);
	void Down(int step);
	void Left(int step);
	void Right(int step);
	
	void Up();
	void Down();
	void Left();
	void Right();



	bool isFinish();
	bool isDead();


	void Draw();
	void deDraw();


	bool isImpact(Vehicle* v);
	bool isImpactH(Helicopter* h);
	bool isImpactB(Bird* b);
	bool isImpactC(Cat* c);
	void reDrawLineWhenMoveUPDOWN();
	void reDrawLineWhenMoveRIGHT();
	void reDrawLineWhenMoveLEFT();
	
	
	




};