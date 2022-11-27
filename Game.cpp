
#include "Game.h"


void Game::drawCRGameBoard(int x, int y)
{
    Console* handle = new Console;
    handle->TextColor(LIGHT_AQUA);
    //in 2 hàng ngang màn hình game
    for (int i = x; i < Game::BOARD_WIDTH; i++)
    {
        handle->GotoXY(i, y);
        cout << char(61);
        handle->GotoXY(i, Game::BOARD_HEIGHT - 1);
        cout << char(61);
        Sleep(10);
    }

    //in 2 cột dọc màn hình game
    for (int i = y; i < Game::BOARD_HEIGHT; i++)
    {
        handle->GotoXY(x, i);
        cout << char(40);
        handle->GotoXY(Game::BOARD_WIDTH - 1, i);
        cout << char(41);
        Sleep(10);
    }

    handle->TextColor(LIGHT_RED);
    //in 2 hàng ngang màn hình option
    for (int i = 0; i < 34; i++)
    {
        handle->GotoXY(Game::BOARD_WIDTH + 3 + i, y);
        cout << char(61);
        handle->GotoXY(Game::BOARD_WIDTH + 3 + i, Game::BOARD_HEIGHT - 1);
        cout << char(61);
        Sleep(10);
    }

    //in 2 cột dọc màn hình option
    for (int i = y; i < Game::BOARD_HEIGHT; i++)
    {
        handle->GotoXY(Game::BOARD_WIDTH + 3, i);
        cout << char(40);
        handle->GotoXY(Game::BOARD_WIDTH + 3 + 34, i);
        cout << char(41);
        Sleep(10);
    }

    handle->TextColor(LIGHT_AQUA); 
    //4 đường phân cách làn xe
    for (int t = 1; t <= 4; t++)
    {
        handle->GotoXY(x + 1, y + t * 4);
        for (int i = x; i < Game::BOARD_WIDTH - 2; i++)
        {
            cout << char(61);
        }
        Sleep(500);
    }
    string tutorial[] = { "LEVEL ","W,A,S,D to move","ESC to exit","L to load","ESC to exit" };
    int Xtutorial = 83 + (117 - 83 - tutorial[0].size()) / 2;
    int Ytutorial = 4 + 12;
    handle->TextColor(YELLOW);
    for (int i = 0; i < 5; i++)
    {
        handle->GotoXY(Xtutorial, Ytutorial + i);
        cout << tutorial[i];
    }


    handle->GotoXY(Xtutorial + tutorial[0].size(), Ytutorial);
    cout << *lvl;

    vector<string> levelTitle;
    levelTitle.push_back("  _    _____   _____ _    ");
    levelTitle.push_back(" | |  | __\\ \\ / / __| |   ");
    levelTitle.push_back(" | |__| _| \\ V /| _|| |__ ");
    levelTitle.push_back(" |____|___| \\_/ |___|____|");
    for (int i = 0; i < levelTitle.size(); i++)
    {
        handle->GotoXY(83 + (117 - 83 - levelTitle[0].size()) / 2, 4 + 1 + i);
        cout << levelTitle[i];
    }
}


void Game::exitGame(thread* t, bool* IS_RUNNING)
{
    //system("cls");
    *IS_RUNNING = false;
    t->join();

}

void Game::movePeople(int input)
{
    Console handle;
    if (input == 87) //W
        P.Up();
    if (input == 83) //S
        P.Down();
    if (input == 65) //A
        P.Left();
    if (input == 68) //D
        P.Right();
}



void Launch()
{
    Console handle;
    SetConsoleTitle(L"Crossy Road");
    handle.FixConsoleWindow();
    handle.hideCursor();

    //Loading
    handle.TextColor(LIGHT_AQUA);
    string loading = "Loading~~~";
    handle.GotoXY((consoleWidth - loading.length()) / 2, (consoleHeight - 5) / 2);
    cout << loading << endl;
    for (int i = consoleWidth / 5; i < consoleWidth * 4 / 5; i++)
    {
        handle.GotoXY(i, (consoleHeight - 4) / 2 + 2);
        cout << "*";
        Sleep(15);
    }
    system("cls");

    //Title
    handle.TextColor(LIGHT_YELLOW);
    int titleHeight;
    int titleWidth;
    vector<string> title;
    title.push_back("   ______                              ____                  __");
    title.push_back("  / ____/________  ____________  __   / __ \\____  ____ _____/ /");
    title.push_back(" / /   / ___/ __ \\/ ___/ ___/ / / /  / /_/ / __ \\/ __ `/ __  / ");
    title.push_back("/ /___/ /  / /_/ (__  |__  ) /_/ /  / _, _/ /_/ / /_/ / /_/ /  ");
    title.push_back("\\____/_/   \\____/____/____/\\__, /  /_/ |_|\\____/\\__,_/\\__,_/   ");
    title.push_back("                          /____/                               ");
    titleHeight = title.size();
    titleWidth = title[0].size();
    for (int i = 0; i < titleHeight; i++)
    {
        handle.GotoXY((consoleWidth - titleWidth) / 2, consoleHeight / 5 + i);
        cout << title[i];
    }

    //Menu
    string menu[] = { "1. New game", "2. Continue game", "3. Load game", "4. Settings", "5. Exit" };
    handle.TextColor(YELLOW);

    Sleep(500);
    for (int i = 0; i < 5; i++)
    {
        handle.GotoXY((consoleWidth - menu[1].length()) / 2, consoleHeight / 5 + 8 + i);
        cout << menu[i];
    }


    //Các biến cần chuẩn bị
    int optionX = (consoleWidth - menu[1].length()) / 2;
    int optionY = consoleHeight / 5 + 8;
    int lvl = 0;
    int line = 0;
    bool isContinue = false;
    bool isStop = false;
    bool sound = true;

    Sleep(500);
    handle.GotoXY(optionX, optionY + 8);
    cout << "W,S to control";
    handle.GotoXY(optionX, optionY + 9);
    cout << "Press E to select";

    while (!isStop)
    {
        /*if (!isContinue)
        {
            handle.GotoXY(optionX, optionY);
            handle.TextColor(LIGHT_RED);
            cout << menu[1];

        }*/

        handle.GotoXY(optionX, optionY + line);
        handle.TextColor(LIGHT_RED);
        cout << menu[line];

        int input = toupper(_getch());

        //Nếu user nhấn "E"
        if (input == 69)
        {
            switch (line)
            {
            case 0: //new game;
            {
                lvl = 0;
                //hàm bắt đầu game tại lvl 0;
                startLevel(&lvl, &sound);
                isContinue = true;

                break;
            }
            case 1: //continue
            {
                if (!isContinue)
                {
                    system("cls");
                    cout << "Loadgame doesn't exist";
                    _getch();
                }
                else
                    //hàm bắt đầu game tại lvl x
                    startLevel(&lvl, &sound);
                break;
            }
            case 2: //load game: chưa xử lý xong
            {
                system("cls");
                //xử lý sau
                break;
            }
            case 3: //settings: chưa xử lý xong
            {
                //hàm xử lý settings

                break;
            }

            case 4: //exit
            {
                isStop = true;
                break;
            }
            }

            system("cls");

            handle.TextColor(LIGHT_YELLOW);
            for (int i = 0; i < titleHeight; i++)
            {
                handle.GotoXY((consoleWidth - titleWidth) / 2, consoleHeight / 5 + i);
                cout << title[i];
            }

            handle.TextColor(YELLOW);
            handle.GotoXY(optionX, optionY + 8);
            cout << "W,S to control";
            handle.GotoXY(optionX, optionY + 9);
            cout << "Press E to select";

            for (int i = 0; i < 5; i++)
            {
                handle.GotoXY((consoleWidth - menu[1].length()) / 2, consoleHeight / 5 + 8 + i);
                cout << menu[i];
            }


        }
        //User chưa nhấn "E"
        handle.GotoXY(optionX, optionY + line); //Đổi màu option mà user chưa chọn thành màu bthg
        handle.TextColor(YELLOW);   //haha
        cout << menu[line];

        if (input == 87)
        {
            if (line - 1 != -1)
                line--;
            else
                line = 4;
        }
        else if (input == 83)
        {
            if (line + 1 != 5)
                line++;
            else
                line = 0;
        }

        if (isStop)
            handle.TextColor(BLACK);
    }

}

Game::Game()
{

}

Game::Game(int* level, bool* sound)
{

    oldX = P.getX();
    oldY = P.getY();
    *lvl = *level;
    flag = false;
    GAMEOVER.push_back("   ___   _   __  __ ___    _____   _____ ___ ");
    GAMEOVER.push_back("  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\");
    GAMEOVER.push_back(" | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /");
    GAMEOVER.push_back("  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\");
}

Game::~Game()
{

}


void startLevel(int* lvl, bool* sound)
{
    system("cls");
    Game g(lvl, sound);
    g.Start();
}


void Game::Start()
{
    bool isRunning = true;
    bool isPause = false;
    Console handle;

    drawGame(); //KHÁC BÀI MẪU


    //biến thread
    thread sThread(subThread, this, &isRunning, &isPause, sound);

    while (1)
    {
        int input = toupper(_getch());

        if (P.isDead())
        {
            // xử lý các thứ
            // thread thoát game

            exitGame(&sThread, &isRunning);

            handle.GotoXY((consoleWidth - afterLose.size()) / 2, consoleHeight / 2 - 3);
            cout << afterLose;


            int tempInput = input;

            while (1)
            {
                if (tempInput == 89) // chữ Y
                    startLevel(lvl, sound);
                else if (tempInput != 78) //input != N
                {

                    tempInput = toupper(_getch());
                    continue;
                }
                break; //Nếu nhập N thì break vòng while gần nhất
            }
            break; //tiếp tục break vòng while lớn 

        }


        // Input = "p"
        if (input == 80)
        {
            isPause = true;
            handle.GotoXY((consoleWidth - pausing.size()) / 2, 3);
            cout << pausing;
            while (1)
            {
                int tmpInput = toupper(_getch());
                if (tmpInput == 80)
                {
                    handle.GotoXY((consoleWidth - pausing.size()) / 2, 3);
                    cout << "            ";
                    isPause = false;
                    break;
                }
            }
        }

        // Input = ESC
        if (input == 27)
        {
            //thread thoát game
            //exitGame(&sThread, &isRunning);
            exitGame(&sThread, &isRunning);
            break;
        }

        //input = L
        if (input == 76)
        {
            //xử lý load game
        }

        //user di chuyển nhân vật
        movePeople(input);

        if (P.isFinish()) // hàm này có vấn đề
        {
            //xử lý khi user qua màn
            Sleep(100);
            exitGame(&sThread, &isRunning);

            if (*lvl < 5)
            {
                ++(*lvl);
                handle.GotoXY(consoleWidth / 3, 1);
                cout << "On to level " << (*lvl) << endl;
                handle.GotoXY(consoleWidth / 3, 2);
                cout << "Press any key to continue";
                int tempInput = toupper(_getch());
                while (1)
                {
                    handle.GotoXY(0, 2);
                    cout << "Press any key to continue";
                    if (input >= 0 && input <= 127)
                        break;
                }
            }
            else
            {
                *lvl = 0;
                handle.GotoXY(consoleWidth / 3, 2);
                cout << "You win. Back to lvl 0";
                int tempInput = toupper(_getch());
                while (1)
                {
                    handle.GotoXY(consoleWidth / 3, 2);
                    cout << "You win. Back to lvl 0";
                    if (input >= 0 && input <= 127)
                        break;
                }
            }

            //_getch();
            startLevel(lvl, sound);
            break;
        }
        Sleep(10);
    }


}


void subThread(Game* g, bool* IS_RUNNING, bool* IS_PAUSE, bool* sound)
{
    
    //chỗ này là sound thread
    int fogCounter = 0;

    bool move = true;
    bool fog = true;


    while (*IS_RUNNING && !g->characterIsDead())
    {
        while (*IS_PAUSE);

        g->updatePosVehicle();
        g->updatePosPeople();
        g->updatePosVehicle2();
        g->characterIsDead();
        
        //NHỊP ĐỘ GAME
        
        switch (g->getLevel())
        {
        case 0:
            Sleep(100);
        case 1:
            Sleep(80);
        }
        

    }

    //Xử lý khi characterIsDead == true;
    if (g->characterIsDead())
    {
        //xử lý gì đây :)
        system("cls");
        Console handle;
        for (int i = 0; i < g->GAMEOVER.size(); i++)
        {
            handle.GotoXY((consoleWidth - g->GAMEOVER[0].size()) / 2, 5 + i);
            cout << g->GAMEOVER[i];
        }

        handle.GotoXY((consoleWidth - g->gameOver.size()) / 2, consoleHeight / 2 -1);
        cout << g->gameOver;
        handle.GotoXY((consoleWidth - g->afterLose.size()) / 2, consoleHeight / 2 - 3);
        cout << g->afterLose;

    }

}


void Game::drawGame()
{
    Console handle;

    //system("cls");

    drawCRGameBoard(5, 4);



    //vẽ người
    vector<string> formP;
    formP.push_back("~o/");
    formP.push_back("/| ");
    formP.push_back("/ \\");

    handle.TextColor(LIGHT_AQUA);
    for (int i = 0; i < 3; i++)
    {
        handle.GotoXY(P.getX(), P.getY() + i);
        cout << formP[i];
    }

    vector<string> formV;
    formV.push_back(" __/  |_\\_    ");
    formV.push_back("|  _     _``-.");
    formV.push_back("'-(_)---(_)--'");
    for (int i = 0; i < 3; i++)
    {
        handle.GotoXY(V.getX(), V.getY() + i);
        cout << formV[i];
    }


}


void Game::updatePosPeople()
{
    Console handle;
    int newX = P.getX();
    int newY = P.getY();

    vector<string> form;
    form.push_back("~o/");
    form.push_back("/| ");
    form.push_back("/ \\");


    handle.TextColor(LIGHT_AQUA);
    for (int i = 0; i < 3; i++)
    {
        handle.GotoXY(oldX, oldY + i);
        cout << "   ";
        handle.GotoXY(newX, newY + i);
        cout << form[i];
    }

    P.reDrawLineWhenMoveLEFT();
    P.reDrawLineWhenMoveRIGHT();
    P.reDrawLineWhenMoveUPDOWN();

    oldX = newX;
    oldY = newY;
}


void Game::updatePosVehicle()
{
    //int stopTime; //Làm kiểu này hàm sleep thay đổi nhịp độ game
    //if (V.getMoveCount() <= 5)
    //{
    //    V.setMoveCount(V.getMoveCount() + 1);
    //    stopTime = 1;
    //}
    //else
    //{
    //    V.setMoveCount(1);
    //    stopTime = 10;

    Console handle;

    V.updateMoveCount();
    if (V.getMoveCount() <= 15)
    {
        redLight();
        return;
    }

    //V.updateMoveCount();
    //switch(*lvl)
    //{
    //case 0:
    //{
    //    if (V.getMoveCount() <= 145)//Số này càng giảm xe chạy càng nhanh
    //    { 
    //        redLight();
    //        return;
    //    }
    //}
    //case 1:
    //{
    //    if (V.getMoveCount() <= 140)
    //    {
    //        redLight();
    //        return;
    //    }
    //}
    //case 2:
    //{
    //    if (V.getMoveCount() <= 135)
    //    {
    //        redLight();
    //        return;
    //    }
    //}
    //case 3:
    //{
    //    if (V.getMoveCount() <= 130)
    //    {
    //        redLight();
    //        return;
    //    }
    //}
    //case 4:
    //{
    //    if (V.getMoveCount() <= 125)
    //    {
    //        redLight();
    //        return;
    //    }
    //}
    //case 5:
    //{
    //    if (V.getMoveCount() <= 120)
    //    {
    //        redLight();
    //        return;
    //    }
    //}
    //}

    
    vector<string> form;
    form.push_back(" __/  |_\\_    ");
    form.push_back("|  _     _``-.");
    form.push_back("'-(_)---(_)--'");
    int vX, vY = V.getY();
    //XE 1
   
    greenLight();

    for (int i = 0; i < 3; i++)
    {
        vX = V.getX(); //
        handle.GotoXY(vX, vY + i);
        cout << "              ";
    }

    V.setX(vX + 1);
    if (V.getX() + 14 >= 79)
        V.setX(6);

    for (int i = 0; i < 3; i++)
    {
        vX = V.getX();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}


bool Game::characterIsDead()
{
    if (P.isDead())
        return true;
    //Hàm xử lý va chạm
    if (P.isImpact(&V));

    return P.isDead();
}


void Game::updatePosVehicle2()
{
    if (V.getX() < 6 + 30)
    {
        if(flag==false)
            return;
    }
    else
        flag = true;


    V.updateMoveCount2();
    if (V.getMoveCount2() <= 15)
        return;

    Console handle;
    vector<string> form;
    form.push_back(" __/  |_\\_    ");
    form.push_back("|  _     _``-.");
    form.push_back("'-(_)---(_)--'");
    int vX, vY = V.getY();

    //XE 1
    for (int i = 0; i < 3; i++)
    {
        vX = V.getX2(); //
        handle.GotoXY(vX, vY + i);
        cout << "              ";
    }

    V.setX2(vX + 1);
    if (V.getX2() + 14 >= 79)
        V.setX2(6);

    for (int i = 0; i < 3; i++)
    {
        vX = V.getX2();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}




void Game::redLight()
{
    Console handle;
    handle.GotoXY(78, 5);
    handle.TextColor(LIGHT_RED);
    cout << "*";
    handle.TextColor(LIGHT_AQUA);
}

void Game::greenLight()
{
    Console handle;
    handle.GotoXY(78, 5);
    handle.TextColor(LIGHT_GREEN);
    cout << "*";
    handle.TextColor(LIGHT_AQUA);
}


int Game::getLevel()
{
    return *lvl;
}