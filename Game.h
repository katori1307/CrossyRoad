#pragma once
#pragma comment (lib,"winmm.lib")
#include <fstream>
#include <iostream>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "Helicopter.h"
#include "Animal.h"
#include "Console.h"
#include "People.h"
#include "Vehicle.h"


#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

using namespace std;



class Game
{
public:
	static const int BOARD_WIDTH = 110;
	static const int BOARD_HEIGHT = 25;
	static const int SCOREBOARD_WIDTH = 34;
	string gameOver = "GAME OVER!";
	string afterLose = "PRESS Y TO CONTINUE, N TO END";
	string pausing = "GAME PAUSE";
	vector<string> GAMEOVER;
	vector<string> ONE;
	vector<string> TWO;
	vector<string> THREE;
	vector<string> FOUR;
	vector<string> ZERO;
private:
	People P;
	int oldX, oldY;
	Vehicle V;
	Helicopter H;
	Bird B;
	Cat C;
	bool* sound;
	int* lvl = new int;
	bool flagV, flagH; //flag cho vehicle
	bool flagB, flagB2; //flag cho bird
	bool flagC, flagC2; //flag cho cat
	
public:
	Game();
	Game(int* level, bool* sound);
	Game(int* level, bool* sound, int);
	~Game();
	void drawCRGameBoard(int x, int y);
	void exitGame(thread* t, bool* IS_RUNNING);

	void movePeople(int input);

	void Start();
	void drawGame();
	int getLevel();

	void updatePosPeople();

	void updatePosVehicle();
	void updatePosVehicle2();

	void updatePosHeli();
	void updatePosHeli2();

	bool characterIsDead();

	void redLight();
	void greenLight();

	void updatePosBird();
	void updatePosBird2();
	void updatePosBird3();

	void updatePosCat();
	void updatePosCat2();
	void updatePosCat3();

	string saveGame();
	bool loadFileGame(string);
};

void subThread(Game* g, bool* IS_RUNNING, bool* IS_PAUSE, bool* sound);
void Launch();
void startLevel(int* lvl, bool* sound);