#pragma once
#include "Console.h"
#include "People.h"
#include <thread>
#include <Windows.h>
#include <conio.h>
#include "Vehicle.h"
#include <vector>

#define BLACK 0
#define AQUA 3
#define RED 4
#define YELLOW 6
#define GRAY 8
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_YELLOW 14






using namespace std;

//4 goc man hinh option la A(83,4) B(117,4) C(83,24) D(117,24)
//4 goc man hinh game: A(5,4) B(79,4) C(5,24) D(79,24)





class Game
{
public:
	static const int BOARD_WIDTH = 80;
	static const int BOARD_HEIGHT = 25;
	string gameOver = "GAME OVER!";
	string afterLose = "PRESS Y TO CONTINUE, N TO END";
	string pausing = "GAME PAUSE";
	vector<string> GAMEOVER;

private:
	People P;
	int oldX, oldY;
	Vehicle V;
	bool* sound;
	int* lvl = new int;
	
	
	


public:

	Game();
	Game(int* level, bool* sound);
	~Game();
	void drawCRGameBoard(int x, int y);
	void exitGame(thread* t, bool* IS_RUNNING);
	void movePeople(int input);
	void Start();
	void drawGame();
	void updatePosPeople();
	void updatePosVehicle();


	bool characterIsDead();




	
};

void subThread(Game* g, bool* IS_RUNNING, bool* IS_PAUSE, bool* sound);
void Launch();
void startLevel(int* lvl, bool* sound);