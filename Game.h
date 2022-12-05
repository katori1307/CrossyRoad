#pragma once
#pragma comment (lib,"winmm.lib")
#include "Console.h"
#include "People.h"
#include <thread>
#include <Windows.h>
#include <conio.h>
#include "Vehicle.h"
#include <vector>
#include "Helicopter.h"
#include "Animal.h"
#include <fstream>

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
	vector<string> ONE;
	vector<string> TWO;
	vector<string> THREE;
	vector<string> FOUR;
	vector<string> ZERO;
	//int commonSize = 4;
private:
	People P;
	int oldX, oldY;
	Vehicle V;
	Helicopter H;
	Bird B;
	Cat C;
	bool* sound;
	int* lvl = new int;
	bool flag;
	bool flagB;
	bool flagC, flagC2;
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