#pragma once
#include <vector>
#include <string>
#include "Console.h"
//#include "People.h" //syntax error nè
using namespace std;


class Vehicle
{
public:
	const int height = 3;
	const int width = 14;
	int mSpeed;

private:
	int mX, mY;
	vector <string> form;
	
	int moveCount;

public:
	Vehicle();
	~Vehicle();
	
	void Draw();
	void Move();

	int getX();
	int getY();
	void setX(int);
	void setY(int);

	int getMoveCount();
	void setMoveCount(int);
	

	void deDraw();

	void updateMoveCount();
	bool isTime();
		
	

};