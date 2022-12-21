
#include "People.h"




//4 goc man hinh game: A(5,4) B(79,4) C(5,24) D(79,24)

People::People()
{
	mY = 24-3;
	mX = (5 + 79) / 2;
	mSpeed = 1;
	mDead = false;
	//mState = true;
	form.push_back("~o/");
	form.push_back("/| ");
	form.push_back("/ \\");
}

People::~People()
{

}










void People::Up()
{
	if (mY - 1 <= 4) return;
	mY -= 1;
}


void People::Down()
{
	if (mY + 3 >= 24) return;
	mY += 1;
}

void People::Left()
{
	if (mX - 1 <= 5) return;
	mX -= 1;
}

void People::Right()
{
	if (mX + 3 >= 79 + 30) return; 
	mX += 1;
}




bool People::isFinish()
{
	return mY == 5;
}

bool People::isDead()
{
	return mDead;
}




void People::reDrawLineWhenMoveUPDOWN()
{
	Console handle;
	if (mY > 20)
	{
		for (int i = mX; i < mX+3; i++)
		{
			handle.GotoXY(i, 20);
			cout << "=";
		}
		return;
	}
	if (mY > 16 && mY+2 < 20)
	{
		for (int i = mX; i < mX+3; i++)
		{
			handle.GotoXY(i, 20);
			cout << "=";
			handle.GotoXY(i, 16);
			cout << "=";
		}
		return;
	}
	if (mY > 12 && mY+2 < 16)
	{
		for (int i = mX; i < mX + 3; i++)
		{
			handle.GotoXY(i, 12);
			cout << "=";
			handle.GotoXY(i, 16);
			cout << "=";
		}
		return;
	}
	if (mY > 8 && mY+2 < 12)
	{
		for (int i = mX; i < mX + 3; i++)
		{
			handle.GotoXY(i, 12);
			cout << "=";
			handle.GotoXY(i, 8);
			cout << "=";
		}
		return;
	}
	if (mY > 16 && mY+2 < 20)
	{
		for (int i = mX; i < mX + 3; i++)
		{
			handle.GotoXY(i, 20);
			cout << "=";
			handle.GotoXY(i, 16);
			cout << "=";
		}
		return;
	}
	if (mY > 4 && mY+2 < 8)
	{
		for (int i = mX; i < mX + 3; i++)
		{
			handle.GotoXY(i, 8);
			cout << "=";
		}
		return;
	}
	
}


void People::reDrawLineWhenMoveRIGHT()
{
	int i;
	Console handle;
	for (i = mY; i < mY + 3; i++)
	{
		if (i == 8)
			break;
		if (i == 12)
			break;
		if (i == 16)
			break;
		if (i == 20)
			break;
	}
	handle.GotoXY(mX - 1, i);
	cout << "=";
	return;
}


void People::reDrawLineWhenMoveLEFT()
{
	int i;
	Console handle;
	for (i = mY; i < mY + 3; i++)
	{
		if (i == 8)
			break;
		if (i == 12)
			break;
		if (i == 16)
			break;
		if (i == 20)
			break;
	}
	handle.GotoXY(mX + 3, i);
	cout << "=";
	return;
}

int People::getX()
{
	return mX;
}

int People::getY()
{
	return mY;
}

void People::setX(int X)
{
	this->mX = X;
}

void People::setY(int Y)
{
	this->mY = Y;
}


bool People::isImpact(Vehicle* v)
{
	for(int i=mX;i<mX+3;i++)
		for (int j = mY; j < mY + 3; j++)
		{
			if(i>=v->getX()&&i<=v->getX()+13)
				if (j >= v->getY() && j <= v->getY() + 2)
				{
					mDead = true;
					return true;
				}
			if (i >= v->getX2() && i <= v->getX2() + 13)
				if (j >= v->getY() && j <= v->getY() + 2)
				{
					mDead = true;
					return true;
				}
		}
	return false;
}

bool People::isImpactH(Helicopter* h)
{
	for (int i = mX; i < mX + 3; i++)
		for (int j = mY; j < mY + 3; j++)
		{
			if (i >= h->getX() && i <= h->getX() + 13)
				if (j >= h->getY() && j <= h->getY() + 2)
				{
					mDead = true;
					return true;
				}
			if (i >= h->getX2() && i <= h->getX2() + 13)
				if (j >= h->getY() && j <= h->getY() + 2)
				{
					mDead = true;
					return true;
				}
		}
	return false;
}

bool People::isImpactB(Bird* b)
{
	for (int i = mX; i < mX + 3; i++)
		for (int j = mY; j < mY + 3; j++)
		{
			if (i >= b->getX() && i <= b->getX() + 7)
				if (j >= b->getY() && j <= b->getY() + 2)
				{
					mDead = true;
					return true;
				}
			if (i >= b->getX2() && i <= b->getX2() + 7)
				if (j >= b->getY() && j <= b->getY() + 2)
				{
					mDead = true;
					return true;
				}
		}
	return false;
}


bool People::isImpactC(Cat* c)
{
	for (int i = mX; i < mX + 3; i++)
		for (int j = mY; j < mY + 3; j++)
		{
			if (i >= c->getX() && i <= c->getX() + 6)
				if (j >= c->getY() && j <= c->getY() + 2)
				{
					mDead = true;
					return true;
				}
			if (i >= c->getX2() && i <= c->getX2() + 6)
				if (j >= c->getY() && j <= c->getY() + 2)
				{
					mDead = true;
					return true;
				}
			if (i >= c->getX3() && i <= c->getX3() + 6)
				if (j >= c->getY() && j <= c->getY() + 2)
				{
					mDead = true;
					return true;
				}
		}
	return false;
}