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
	int mX, mX2;
	int mY;
	vector <string> form;
	
	int moveCount;
	int moveCount2;

public:
	Vehicle();
	~Vehicle();
	
	void Draw();
	void Move();
	void deDraw();

	int getX();
	int getY();
	void setX(int);
	void setY(int);

	int getX2();
	void setX2(int);


	int getMoveCount();
	void setMoveCount(int);

	int getMoveCount2();
	void setMoveCount2(int);
	void updateMoveCount2();
	
	void updateMoveCount();
	bool isTime();
		
};





