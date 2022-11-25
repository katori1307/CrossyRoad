
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


void People::Draw()
{
	Console handle;
	int y = mY;

	for (int i = 0; i < 3; i++)
	{
		handle.GotoXY(mX, y + i);
		cout << form[i];
	}
}

void People::deDraw()
{
	int y = mY;
	Console handle;
	for (int i = 0; i < 3; i++)
	{
		handle.GotoXY(mX, y + i);
		cout << "   ";
	}
}






void People::Up(int step)
{
	if (mY - step <= 4) return;
	Console handle;
	handle.GotoXY(mX, mY);
	deDraw();
	mY -= step;
	handle.GotoXY(mX, mY);
	Draw();
	reDrawLineWhenMoveUPDOWN();
	
}

void People::Down(int step)
{
	if (mY + 3 >= 24) return;
	Console handle;
	handle.GotoXY(mX, mY);
	deDraw();
	mY += step;
	handle.GotoXY(mX, mY);
	Draw();
	reDrawLineWhenMoveUPDOWN();
}

void People::Left(int step)
{
	if (mX - step <= 5) return;
	Console handle;
	handle.GotoXY(mX, mY);
	deDraw();
	mX -= step;
	handle.GotoXY(mX, mY);
	Draw();
	reDrawLineWhenMoveLEFT();
}


void People::Right(int step)
{
	if (mX + 3 >= 79) return;
	Console handle;
	handle.GotoXY(mX, mY);
	deDraw();
	mX += step;
	handle.GotoXY(mX, mY);
	Draw();
	reDrawLineWhenMoveRIGHT();
	
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
	if (mX + 3 >= 79) return;
	mX += 1;
}




bool People::isFinish()
{
	return true;
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


//bool People::isImpact(Vehicle* v)
//{
//
//	//vector<string> pForm;
//	vector<string> vForm;
//	vForm.push_back(" __/  |_\\_    ");
//	vForm.push_back("|  _     _``-.");
//	vForm.push_back("'-(_)---(_)--'");
//
//	vector<string> pForm;
//	pForm.push_back("~o/");
//	pForm.push_back("/| ");
//	pForm.push_back("/ \\");
//
//
//	/*pForm.push_back("~o/");
//	pForm.push_back("/| ");
//	pForm.push_back("/ \\");*/
//
//	for (int i = 0; i < pForm.size(); i++) //width của people
//		for (int j = 0; j < pForm[i].size(); j++) //height của people
//			for (int x = 0; x < vForm.size(); x++) //width của vehicle
//				for (int y = 0; y < vForm[i].size(); y++) //height của vehicle
//				{
//					if (mX + j == v->getX() + y && mY + i == v->getY() + x && pForm[i][j] != ' ' && vForm[i][j] != ' ')
//					{
//						mDead = true;
//						return true;
//					}
//					else
//						return false;
//				}
//}


//bool People::isImpact(Vehicle* v)
//{
//	int tempX = v->getX(); //x của obs
//	int tempY = v->getY(); //y của obs
//
//	int sizeO = 14;
//	int sizeH = 3;
//
//	if (mX == tempX && !((mY + sizeH <= tempY) || (tempY + sizeO <= mY)))
//	{
//		mDead = true;
//		return true;
//	}
//	else
//		return false;
//}


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
		}
	return false;
}