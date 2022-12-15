#include "Game.h"


void Game::drawCRGameBoard(int x, int y)
{
    Console* handle = new Console;
    handle->TextColor(BLACK);
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
    vector<string> cat;
    cat.push_back("    /\\_/\\           ___");
    cat.push_back("   = o_o =_______    \\ \\ ");
    cat.push_back("   \\ __^      __(  \\.__) )");
    cat.push_back("(@)<_____>__(_____)____/");
    vector<string> owl;
    owl.push_back("   ___     ___");
    owl.push_back("  (o o)   (o o)");
    owl.push_back(" (  V  ) (  V  ) ");
    owl.push_back("/--m-m- /--m-m-");
    for (int i = 0; i < cat.size(); i++)
    {
        handle->TextColor(YELLOW);
        handle->GotoXY(6, 1+i);
        cout << cat[i];
        handle->TextColor(GREEN);
        handle->GotoXY(90, 1+i);
        cout << owl[i];
        handle->GotoXY(40, 1+i);
        cout << owl[i];
    }
    handle->TextColor(RED);
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
    cat.clear();
    cat.push_back("    |\\__/,|   (`\\");
    cat.push_back("  _.|o o  |_   ) )");
    cat.push_back("-(((---(((--------");
    for (int i = 0; i < cat.size(); i++)
    {
        handle->TextColor(YELLOW);
        handle->GotoXY(Game::BOARD_WIDTH + 10, 2 + i);
        cout << cat[i];
    }
    handle->TextColor(BLACK); 
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
    string tutorial[] = { "LEVEL ","W,A,S,D to move","ESC to exit","L to save","P to pause/ unpause","T to load","ESC to exit"};
    int Xtutorial = BOARD_WIDTH + 3 + ((SCOREBOARD_WIDTH - tutorial[4].size()) / 2);
    int Ytutorial = 4 + 12;
    handle->TextColor(PURPLE);
    for (int i = 0; i < 7; i++)
    {
        handle->GotoXY(Xtutorial, Ytutorial + i);
        cout << tutorial[i];
    }
    handle->GotoXY(Xtutorial + tutorial[0].size(), Ytutorial);
    cout << *lvl;
    vector<string> GAMEOVER;
    vector<string> ONE;
    vector<string> TWO;
    vector<string> THREE;
    vector<string> FOUR;
    vector<string> ZERO;
    ONE.push_back(" _ ");
    ONE.push_back("/ |");
    ONE.push_back("| |");
    ONE.push_back("|_|");
    TWO.push_back(" ___ ");
    TWO.push_back("|_  )");
    TWO.push_back(" / / ");
    TWO.push_back("/___|");
    THREE.push_back(" ____");
    THREE.push_back("|__ /");
    THREE.push_back(" |_ \\");
    THREE.push_back("|___/");
    FOUR.push_back(" _ _  ");
    FOUR.push_back("| | | ");
    FOUR.push_back("|_  _|");
    FOUR.push_back("  |_| ");
    ZERO.push_back("  __  ");
    ZERO.push_back(" /  \\ ");
    ZERO.push_back("| () |");
    ZERO.push_back(" \\__/ ");
    
    switch (*lvl)
    {
    case 0:
    {
        for (int i = 0; i < ZERO.size(); i++)
        {
            handle->GotoXY((110 + 3) + 28, 4 + 1 + i);
            cout << ZERO[i];
        }
        break;
    }
    case 1:
    {
        for (int i = 0; i < ONE.size(); i++)
        {
            handle->GotoXY((110 + 3) + 28, 4 + 1 + i);
            cout << ONE[i];
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < TWO.size(); i++)
        {
            handle->GotoXY((110 + 3) + 28, 4 + 1 + i);
            cout << TWO[i];
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < THREE.size(); i++)
        {
            handle->GotoXY((110 + 3) + 28, 4 + 1 + i);
            cout << THREE[i];
        }
        break;
    }
    case 4:
    {
        for (int i = 0; i < FOUR.size(); i++)
        {
            handle->GotoXY((110 + 3) + 28, 4 + 1 + i);
            cout << FOUR[i];
        }
        break;
    }
    default:
        break;
    }
    vector<string> levelTitle;
    levelTitle.push_back("  _    _____   _____ _    ");
    levelTitle.push_back(" | |  | __\\ \\ / / __| |   ");
    levelTitle.push_back(" | |__| _| \\ V /| _|| |__ ");
    levelTitle.push_back(" |____|___| \\_/ |___|____|");
    for (int i = 0; i < levelTitle.size(); i++)
    {
        handle->GotoXY(BOARD_WIDTH + 3 +((SCOREBOARD_WIDTH - levelTitle[0].size()) / 2) - 3, 4 + 1 + i);
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
   /* handle.setconsolecolor(0, 15);
    system("cls");*/

    //Loading
    handle.TextColor(BLUE);
    //handle.setconsolecolor(BLACK, BRIGHT_WHITE);
    string loading = "LOADING~~~";
    handle.GotoXY((consoleWidth - loading.length()) / 2, (consoleHeight - 5) / 2);
    cout << loading << endl;
    handle.GotoXY(consoleWidth / 5 - 2, (consoleHeight - 4) / 2 + 2);
    cout << "|";
    handle.GotoXY(consoleWidth / 5 - 2 + 93, (consoleHeight - 4) / 2 + 2);
    cout << "|";
    for (int i = consoleWidth / 5 - 2; i < consoleWidth * 4 / 5 + 2; i++)
    {
        handle.GotoXY(i, (consoleHeight - 4) / 2 + 1);
        cout << "_";
        handle.GotoXY(i, (consoleHeight - 4) / 2 + 3);
        cout << "_";
    }
    for (int i = consoleWidth / 5; i < consoleWidth * 4 / 5; i++)
    {
        handle.GotoXY(i, (consoleHeight - 4) / 2 + 2);
        cout << "\\";
        Sleep(15);
    }
    
    
    system("cls");

    //Title
    handle.TextColor(RED);
    //handle.setconsolecolor(GREEN, BRIGHT_WHITE);
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
    //handle.TextColor(YELLOW);
    handle.TextColor(BLACK);

    Sleep(500);
    for (int i = 0; i < 5; i++)
    {
        handle.GotoXY((consoleWidth - menu[1].length()) / 2, consoleHeight / 5 + 8 + i);
        cout << menu[i];
    }
    int tempA = (consoleWidth - menu[1].length()) / 2 - 3;
    for (int i = tempA; i < tempA + menu[1].length() + 6; i++)
    {
        handle.GotoXY(i, consoleHeight / 5 + 7);
        cout << "_";
        handle.GotoXY(i, consoleHeight / 5 + 7 + 6);
        cout << "_";
    }
    for (int i = 0; i < 6; i++)
    {
        handle.GotoXY(tempA, consoleHeight / 5 + 8 + i);
        cout << "|";
        handle.GotoXY(tempA + menu[1].length() + 6, consoleHeight / 5 + 8 + i);
        cout << "|";
    }

    vector<string> city;
    city.push_back("                                    +              #####");
    city.push_back("                                   / \\");
    city.push_back("        _____     __________/ o \\/\\_________      _________");
    city.push_back(" _______|    |___|               | | # # #  |____|o o o o  |");
    city.push_back("|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |");
    city.push_back("|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |");
    city.push_back("|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |");
    city.push_back("|__[]___|_||_|__<|____________;;_|_|___/\\___|_.|_|____[]___|");
   /* handle.GotoXY(5, 19);
    cout << "X";*/
    handle.TextColor(GREEN);
    for (int i = 0; i < city.size(); i++)
    {
        handle.GotoXY(0, 14+i);
        cout << city[i];
    }
    for (int i = 0; i < city.size(); i++)
    {
        handle.GotoXY((consoleWidth + menu[1].length()) / 2 + 6, 14 + i);
        cout << city[i];
    }
    handle.TextColor(BLUE);
    vector<string> cloud;
    cloud.push_back("   __   _");
    cloud.push_back(" _(  )_( )_");
    cloud.push_back("(_   _    _)");
    cloud.push_back("  (_) (__)");
    vector<string> b;
    b.push_back("___( o)>");
    b.push_back("\ <_. ) ");
    b.push_back(" `---'  ");
    vector<string> c;
    c.push_back("                                                         _________________________   ");
    c.push_back("                    /\\\\      _____          _____       |   |     |     |    | |  \\  ");
    c.push_back("     ,-----,       /  \\\\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ ");
    c.push_back("  ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\");
    c.push_back(" ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--'  ");
    c.push_back("```````````````````````````````````````````````````````````````````````````````````````````````");
     

    for (int i = 0; i < cloud.size(); i++)
    {
        handle.GotoXY(10, 6 + i);
        cout << cloud[i];
        handle.GotoXY(16, 7 + i);
        cout << cloud[i];
        handle.GotoXY(110, 7 + i);
        cout << cloud[i];
        handle.GotoXY(50, 1 + i);
        cout << cloud[i];
        handle.GotoXY(90, 2 + i);
        cout << cloud[i];
    }
 
    for (int i = 0; i < b.size(); i++)
    {
        handle.GotoXY(30, 2 + i);
        cout << b[i];
        handle.GotoXY(130, 6 + i);
        cout << b[i];
    }
    handle.TextColor(PURPLE);
    for (int i = 0; i < c.size(); i++)
    {
        handle.GotoXY(0, 24 + i);
        cout << c[i];
        handle.GotoXY(55, 24 + i);
        cout << c[i];
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
    handle.TextColor(BLACK);
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
        handle.TextColor(RED);
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
                int xTemp = consoleWidth/2-15;
                for (int i = 0; i < 30; i++)
                {
                    handle.GotoXY(xTemp + i, consoleHeight / 2 - 7);
                    cout << "=";
                    handle.GotoXY(xTemp + i, consoleHeight / 2 - 1);
                    cout << "=";
                }
                for (int i = 0; i < 7; i++)
                {
                    handle.GotoXY(xTemp, consoleHeight / 2 - 7 + i);
                    cout << "(";
                    handle.GotoXY(xTemp + 30, consoleHeight / 2 - 7 + i);
                    cout << ")";
                }
                fstream file;
                file.open("ExistFile.txt");
                int idx = 0;
                while (!file.eof())
                {
                    string str;
                    handle.GotoXY(xTemp + 32, consoleHeight / 2 - 6 + idx);
                    getline(file, str);
                    cout << str;
                    idx++;
                }
                
                

                
                
                
                
                //xử lý sau
                string path;
                handle.GotoXY(consoleWidth / 2 - 10, consoleHeight / 2 - 5);
                cout << "Enter path: \n";
                handle.GotoXY(consoleWidth / 2 - 10 + 12, consoleHeight / 2 - 5); 
                getline(cin, path);
                Game g2(&lvl, &sound, 0);
                if (!g2.loadFileGame(path))
                {
                    while (1)
                    {
                        string temp[] = { "Load game doesnt exist" ,"Press any key to continue" };
                        handle.GotoXY((consoleWidth-temp[0].size()) / 2, consoleHeight / 2 - 4);
                        cout << temp[0];
                        handle.GotoXY((consoleWidth - temp[0].size()) / 2, consoleHeight / 2 - 3);
                        cout << temp[1];
                        int tempInput = toupper(_getch());
                        if (tempInput >= 0 && tempInput <= 127)
                            break;
                    }
                }

                isContinue = true;

                break;
            }
            case 3: //settings: chưa xử lý xong
            {
                //hàm xử lý settings
                system("cls");
                vector<string> aboutUs;
                aboutUs.push_back("========== NHOM 3 ==========");
                aboutUs.push_back("");
                aboutUs.push_back("21127147 _ Vo Anh Quan");
                aboutUs.push_back("");
                aboutUs.push_back("21127365 _ Phan Phuoc Hai Nam");
                aboutUs.push_back("");
                aboutUs.push_back("21127714 _ Vu Phu Truong");
                aboutUs.push_back("");
                aboutUs.push_back("21127641 _ Nguyen Xuan Loc");
                aboutUs.push_back("");
                aboutUs.push_back("Press any key to continue");
                handle.TextColor(BLUE);
                int xTemp = consoleWidth / 2 - 15,yTemp = consoleHeight / 2 - 7;
                for (int i = 0; i < 33; i++)
                {
                    handle.GotoXY(xTemp + i, yTemp);
                    cout << "=";
                    handle.GotoXY(xTemp + i, yTemp+14);
                    cout << "=";
                    handle.GotoXY(xTemp + i, yTemp + 11);
                    cout << "=";
                    
                }
                for (int i = 0; i < 15; i++)
                {
                    handle.GotoXY(xTemp, yTemp + i);
                    cout << "(";
                    handle.GotoXY(xTemp + 33, yTemp + i);
                    cout << ")";
                }
                handle.TextColor(RED);
                for (int i = 0; i < aboutUs.size(); i++)
                {
                    handle.GotoXY(xTemp + 2, yTemp + 2 + i);
                    cout << aboutUs[i];
                }
                while (1)
                {
                    int tempInput = toupper(_getch());
                    if (tempInput >= 0 && tempInput <= 127)
                        break;
                }
                break;
            }
            case 4: //exit
            {
                isStop = true;
                break;
            }
            }

            system("cls");

            handle.TextColor(RED);
            for (int i = 0; i < titleHeight; i++)
            {
                handle.GotoXY((consoleWidth - titleWidth) / 2, consoleHeight / 5 + i);
                cout << title[i];
            }

            handle.TextColor(BLACK);
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
        handle.TextColor(BLACK);   
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
    //flag = false;
    GAMEOVER.push_back("   ___   _   __  __ ___    _____   _____ ___ ");
    GAMEOVER.push_back("  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\");
    GAMEOVER.push_back(" | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /");
    GAMEOVER.push_back("  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\");
    ONE.push_back(" _ ");
    ONE.push_back("/ |");
    ONE.push_back("| |");
    ONE.push_back("|_|");
    TWO.push_back(" ___ ");
    TWO.push_back("|_  )");
    TWO.push_back(" / / ");
    TWO.push_back("/___|");
    THREE.push_back(" ____");
    THREE.push_back("|__ /");
    THREE.push_back(" |_ \\");
    THREE.push_back("|___/");
    FOUR.push_back(" _ _  ");
    FOUR.push_back("| | | ");
    FOUR.push_back("|_  _|");
    FOUR.push_back("  |_| ");
    ZERO.push_back("  __  ");
    ZERO.push_back(" /  \\ ");
    ZERO.push_back("| () |");
    ZERO.push_back(" \\__/ ");
    
}

Game::Game(int* level, bool* sound, int x)
{
    this->lvl = level;
    this->sound = sound;
}

Game::~Game()
{

}

void startLevel(int* lvl, bool* sound)
{
    system("cls");
    Game g(lvl, sound);
    g.Start();
    *lvl = g.getLevel();
}

void Game::Start()
{
    bool isRunning = true;
    bool isPause = false;
    Console handle;

    drawGame();

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
            //xử lý save game
            exitGame(&sThread, &isRunning);
            string path;
            path = saveGame();
            /*handle.GotoXY(0, 0);*/
            
            string option = "Press Y to continue, N to end";
            handle.GotoXY((consoleWidth - option.size()) / 2, 3);
            cout << option;
            //cout << "Press Y to continue, N to end\n";
            while (1)
            {
                int tempInput = toupper(_getch());
                if (tempInput == 89)
                {
                    //loadGameFile();
                    loadFileGame(path);
                }
                else if (tempInput != 78)
                    continue;
                break;
            }
            break;
        }

        if (input == 84)
        {
            //xử lý load game
            exitGame(&sThread, &isRunning);
            drawGame();
            handle.TextColor(BLACK);
            handle.GotoXY(92+30, 11);
            cout << "Enter file name\n";
            string path;
            handle.GotoXY(92+30, 12);
            cout << "Enter path: \n";
            handle.GotoXY(105+30, 12);
            getline(cin, path);
            if (!loadFileGame(path))
            {
                while (1)
                {
                    handle.GotoXY(90+30, 11);
                    cout << "File doesn't exist";
                    handle.GotoXY(90+30, 12);
                    cout << "Press any key to continue";
                    int tempInput = toupper(_getch());
                    if (tempInput >= 0 && tempInput <= 127)
                        break;
                }
            }
            handle.TextColor(BLACK);
            break;
        }

        //user di chuyển nhân vật
        movePeople(input);

        if (P.isFinish()) 
        {
            //xử lý khi user qua màn
            Sleep(100);
            exitGame(&sThread, &isRunning);

            if (*lvl < 4) 
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
    while (*IS_RUNNING && !g->characterIsDead())
    {
        while (*IS_PAUSE);
        g->updatePosVehicle();
        g->updatePosPeople();
        g->updatePosVehicle2();
        g->characterIsDead();
        g->updatePosHeli();
        g->updatePosHeli2();
        g->updatePosBird();
        g->updatePosBird2();
        g->updatePosCat();
        g->updatePosCat2();
        g->updatePosCat3();
        g->updatePosBird3();
        //NHỊP ĐỘ GAME
        //Sleep(100); // sau khi test chỉnh về hàm switch bên dưới
        switch (g->getLevel())
        {
        case 0:
            Sleep(125); 
        case 1:
            Sleep(100);
        case 2:
            Sleep(50);
        case 3:
            Sleep(50);
        case 4:
            Sleep(50);
        case 5:
            Sleep(50);
        }
    }
    //Xử lý khi characterIsDead == true;
    if (g->characterIsDead())
    {
        //xử lý gì đây :)
        system("cls");
        Console handle;
        vector<string> GAMEOVER2;
        handle.TextColor(PURPLE);
        GAMEOVER2.push_back("   ___   _   __  __ ___    _____   _____ ___ ");
        GAMEOVER2.push_back("  / __| /_\\ |  \\/  | __|  / _ \\ \\ / / __| _ \\");
        GAMEOVER2.push_back(" | (_ |/ _ \\| |\\/| | _|  | (_) \\ V /| _||   /");
        GAMEOVER2.push_back("  \\___/_/ \\_\\_|  |_|___|  \\___/ \\_/ |___|_|_\\");
        for (int i = 0; i < GAMEOVER2.size(); i++)
        {
            handle.GotoXY((consoleWidth - GAMEOVER2[0].size()) / 2, 5 + i);
            cout << GAMEOVER2[i];
        }
        vector<string> cloud;
        cloud.push_back("   __   _");
        cloud.push_back(" _(  )_( )_");
        cloud.push_back("(_   _    _)");
        cloud.push_back("  (_) (__)");
        vector<string> bomb;
        bomb.push_back("     _.-^^---....,,--       ");
        bomb.push_back(" _--                  --_  ");
        bomb.push_back("<                        >)");
        bomb.push_back("|                         | ");
        bomb.push_back(" \._                   _./  ");
        bomb.push_back("    ```--. . , ; .--'''       ");
        bomb.push_back("          | |   |             ");
        bomb.push_back("       .-=||  | |=-.   ");
        bomb.push_back("       `-=#$%&%$#=-'   ");
        bomb.push_back("          | ;  :|     ");
        bomb.push_back(" _____.,-#%&$@%#&#~,._____");
        vector<string> mount;
        mount.push_back("          /\\");
        mount.push_back("         /**\\");
        mount.push_back("        /****\\   /\\");
        mount.push_back("       /      \\ /**\\");
        mount.push_back("      /  /\\    /    \\        /\\   /\\  /\\      /\\           /\\/\\/\\  /\\");
        mount.push_back("     /  /  \\  /      \\      /  \\/\\/  \\/  \\  /\\/  \\/\\  /\\  /\\/ / /  \\/  \\");
        mount.push_back("    /  /    \\/ /\\     \\    /    \\ \\  /    \\/ /   /  \\/  \\/  \\  /    \\   \\");
        mount.push_back("   /  /      \\/  \\/\\   \\  /      \\    /   /    \\");
        mount.push_back("__/__/_______/___/__\\___\\__________________________________________________");
        
        for (int i = 0; i < cloud.size(); i++)
        {
            handle.TextColor(BLUE);
            handle.GotoXY(10, 4 + i);
            cout << cloud[i];
            handle.GotoXY(16, 5 + i);
            cout << cloud[i];
            handle.GotoXY(120, 7 + i);
            cout << cloud[i];
            handle.GotoXY(100, 6 + i);
            cout << cloud[i];
        }
        for (int i = 0; i < mount.size(); i++)
        {
            handle.TextColor(GREEN);
            handle.GotoXY(0, 11 + i);
            cout << mount[i];
            handle.GotoXY(mount[6].size(), 11 + i);
            cout << mount[i];
        }
        for (int i = 0; i < bomb.size(); i++)
        {
            handle.TextColor(GRAY);
            handle.GotoXY(20, 17 + i);
            cout << bomb[i];
            handle.GotoXY(60, 17 + i);
            cout << bomb[i];
            handle.GotoXY(100, 17 + i);
            cout << bomb[i];
        }
        handle.TextColor(RED);
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

    handle.TextColor(BLACK);
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

    vector<string> formH;
    formH.push_back("   -----|-----");
    formH.push_back("*>=====[_]L)  ");
    formH.push_back("      -'-`-   ");
    for (int i = 0; i < 3; i++)
    {
        handle.GotoXY(H.getX(), H.getY() + i);
        cout << formH[i];
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

    handle.TextColor(BLACK);
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
    Console handle;
    
    V.updateMoveCount();
    if (V.getMoveCount() <= 15)
    {
        redLight();
        return;
    }
    vector<string> form;
    form.push_back(" __/  |_\\_    ");
    form.push_back("|  _     _``-.");
    form.push_back("'-(_)---(_)--'");
    int vX, vY = V.getY();

    greenLight();

    for (int i = 0; i < 3; i++)
    {
        vX = V.getX(); //
        handle.GotoXY(vX, vY + i);
        cout << "              ";
    }

    V.setX(vX + 1);
    if (V.getX() + form[0].length() >= BOARD_WIDTH - 1)
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
    if (P.isImpact(&V))
        PlaySound(TEXT("Crash.wav"), NULL, SND_FILENAME);
    if(P.isImpactH(&H))
        PlaySound(TEXT("Crash.wav"), NULL, SND_FILENAME);
    if(P.isImpactB(&B))
        PlaySound(TEXT("Duck2.wav"), NULL, SND_FILENAME);
    if(P.isImpactC(&C))
        PlaySound(TEXT("CatMeow.wav"), NULL, SND_FILENAME);
    return P.isDead();
}

void Game::updatePosVehicle2()
{
    if (V.getX() < 40)
    {
        if(flagV==false)
            return;
    }
    else
        flagV = true;
    V.updateMoveCount2();
    if (V.getMoveCount2() <= 15)
        return;
    if (*lvl <= 1)
        return;

    Console handle;
    vector<string> form;
    form.push_back(" __/  |_\\_    ");
    form.push_back("|  _     _``-.");
    form.push_back("'-(_)---(_)--'");
    int vX, vY = V.getY();

    for (int i = 0; i < 3; i++)
    {
        vX = V.getX2();
        handle.GotoXY(vX, vY + i);
        cout << "              ";
    }

    V.setX2(vX + 1);
    if (V.getX2() + form[0].length() >= BOARD_WIDTH - 1)
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
    handle.GotoXY(BOARD_WIDTH - 2, 5);
    handle.TextColor(LIGHT_RED);
    cout << "*";
    handle.GotoXY(BOARD_WIDTH - 2, 13);
    cout << "*";
    handle.TextColor(BLACK);
}

void Game::greenLight()
{
    Console handle;
    handle.GotoXY(BOARD_WIDTH - 2, 5);
    handle.TextColor(LIGHT_GREEN);
    cout << "*";
    handle.GotoXY(BOARD_WIDTH - 2, 13);
    cout << "*";
    handle.TextColor(BLACK);
}

int Game::getLevel()
{
    return *lvl;
}

void Game::updatePosHeli()
{
    Console handle;
    H.updateMoveCount();
    if (H.getMoveCount() <= 15)
    {
        redLight();
        return;
    }
    vector<string> form;
    form.push_back("   -----|-----");
    form.push_back("*>=====[_]L)  ");
    form.push_back("      -'-`-   ");
    int vX, vY = H.getY();
    greenLight();
    for (int i = 0; i < 3; i++)
    {
        vX = H.getX(); //
        handle.GotoXY(vX, vY + i);
        cout << "              ";
    }
    H.setX(vX + 1);
    if (H.getX() + form[0].length() >= BOARD_WIDTH - 1)
        H.setX(6);
    for (int i = 0; i < 3; i++)
    {
        vX = H.getX();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

void Game::updatePosHeli2()
{
    if (H.getX() < 40)
    {
        if (flagH == false)
            return;
    }
    else
        flagH = true;

    H.updateMoveCount2();
    if (H.getMoveCount2() <= 15)
        return;
    if (*lvl < 1)
        return;
    Console handle;
    vector<string> form;
    form.push_back("   -----|-----");
    form.push_back("*>=====[_]L)  ");
    form.push_back("      -'-`-   ");
    int vX, vY = H.getY();

    for (int i = 0; i < 3; i++)
    {
        vX = H.getX2();
        handle.GotoXY(vX, vY + i);
        cout << "              ";
    }
    H.setX2(vX + 1);
    if (H.getX2() + form[0].length() >= BOARD_WIDTH - 1)
        H.setX2(6);
    for (int i = 0; i < 3; i++)
    {
        vX = H.getX2();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

void Game::updatePosBird()
{
    Console handle;
    vector<string> form;
    form.push_back("___( o)>");
    form.push_back("\ <_. ) ");
    form.push_back(" `---'  ");
    int vX, vY = B.getY();
    for (int i = 0; i < 3; i++)
    {
        vX = B.getX();
        handle.GotoXY(vX, vY + i);
        cout << "        ";
    }
    B.setX(vX + 1);
    if (B.getX() + form[0].length() >= BOARD_WIDTH - 1)
        B.setX(6);
    for (int i = 0; i < 3; i++)
    {
        vX = B.getX();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

void Game::updatePosBird2()
{
    if (B.getX() < 40)
    {
        if (flagB == false)
            return;
    }
    else
        flagB = true;
    if (*lvl < 1)
        return;
    Console handle;
    vector<string> form;
    form.push_back("___( o)>");
    form.push_back("\ <_. ) ");
    form.push_back(" `---'  ");
    int vX, vY = B.getY();
    for (int i = 0; i < 3; i++)
    {
        vX = B.getX2();
        handle.GotoXY(vX, vY + i);
        cout << "        ";
    }
    B.setX2(vX + 1);
    if (B.getX2() + form[0].length() >= BOARD_WIDTH - 1)
        B.setX2(6);
    for (int i = 0; i < 3; i++)
    {
        vX = B.getX2();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

void Game::updatePosBird3()
{
    if (B.getX() < 70)
    {
        if (flagB2 == false)
            return;
    }
    else
        flagB2 = true;
    if (*lvl <= 1)
        return;
    Console handle;
    vector<string> form;
    form.push_back("___( o)>");
    form.push_back("\ <_. ) ");
    form.push_back(" `---'  ");
    int vX, vY = B.getY();
    for (int i = 0; i < 3; i++)
    {
        vX = B.getX3();
        handle.GotoXY(vX, vY + i);
        cout << "        ";
    }
    B.setX3(vX + 1);
    if (B.getX3() + form[0].length() >= BOARD_WIDTH - 1)
        B.setX3(6);
    for (int i = 0; i < 3; i++)
    {
        vX = B.getX3();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

void Game::updatePosCat()
{
    Console handle;
    vector<string> form;
    form.push_back(" /\\_/\\ ");
    form.push_back("( o.o )");
    form.push_back(" > ^ < ");
    int vX, vY = C.getY();
    for (int i = 0; i < 3; i++)
    {
        vX = C.getX();
        handle.GotoXY(vX, vY + i);
        cout << "        ";
    }
    C.setX(vX + 1);
    if (C.getX() + form[0].length() >= BOARD_WIDTH - 1)
        C.setX(6);
    for (int i = 0; i < 3; i++)
    {
        vX = C.getX();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

void Game::updatePosCat2()
{
    if (C.getX() < 40)
    {
        if (flagC == false)
            return;
    }
    else
        flagC = true;
    if (*lvl < 1)
        return;
    Console handle;
    vector<string> form;
    form.push_back(" /\\_/\\ ");
    form.push_back("( o.o )");
    form.push_back(" > ^ < ");
    int vX, vY = C.getY();
    for (int i = 0; i < 3; i++)
    {
        vX = C.getX2();
        handle.GotoXY(vX, vY + i);
        cout << "        ";
    }
    C.setX2(vX + 1);
    if (C.getX2() + form[0].length() >= BOARD_WIDTH - 1)
        C.setX2(6);
    for (int i = 0; i < 3; i++)
    {
        vX = C.getX2();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

void Game::updatePosCat3()
{
    if (C.getX() < 60)
    {
        if (flagC2 == false)
            return;
    }
    else
        flagC2 = true;
    if (*lvl <= 1)
        return;
    Console handle;
    vector<string> form;
    form.push_back(" /\\_/\\ ");
    form.push_back("( o.o )");
    form.push_back(" > ^ < ");
    int vX, vY = C.getY();
    for (int i = 0; i < 3; i++)
    {
        vX = C.getX3();
        handle.GotoXY(vX, vY + i);
        cout << "        ";
    }
    C.setX3(vX + 1);
    if (C.getX3() + form[0].length() >= BOARD_WIDTH - 1)
        C.setX3(6);
    for (int i = 0; i < 3; i++)
    {
        vX = C.getX3();
        handle.GotoXY(vX, vY + i);
        cout << form[i];
    }
}

string Game::saveGame()
{
    Console handle;
    drawGame();
    handle.TextColor(PURPLE);
    handle.GotoXY(92+30, 11);
    cout << "Saving\n";
    string path;
    handle.GotoXY(92+30, 12);
    cout << "Enter path: \n";
    handle.GotoXY(105+30, 12);
    getline(cin, path);
    fstream ExistFile;
    ExistFile.open("ExistFile.txt",ios::app);
    ExistFile << path << endl;
    ofstream file;
    file.open(path);
    file << (*lvl);
    file.close();
    handle.TextColor(BLACK);
    return path;
}

//void Game::loadFileGame(string path)
//{
//    ifstream file;
//    file.open(path, ios::binary);
//    if (!file.is_open())
//        return;
//    Game g(lvl, sound);
//    file.read((char*)lvl, sizeof(int));
//    file.close();
//    system("cls");
//    g.Start();
//}

bool Game::loadFileGame(string path) //đang làm
{
    ifstream file;
    file.open(path);
    if (!file.is_open())
        return false;
    Game g(lvl, sound);
    file >> (*lvl);
    system("cls");
    Start();
}