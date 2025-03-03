#include "gamestate.hpp"
#include <fstream>
#define FACTOR 1       // income factor
#define TIMEFACTOR 5

GameState GameState::m_GameState;

void GameState::Init()
{
    gameTime.timeSpeed = TIMEFACTOR;
    system("CLS");
    cout << "(SPACE) Start new game\n(ENTER) Continue where you left off";
    bool flag = true;
    while(flag)
    {
        if(getInput() == ENTER)                 // CONTINUE
        {
            map1.New("map/map1.txt", 28, 40, 1);
            map1.Load();
            plyMoney.load(map1.balance);
            gameTime.start(map1.time);
            flag = false;
        }
        else if(getInput() == SPACE)            // NEW
        {
            map1.New("map/map1.txt", 28, 40, 0);
            map1.Load();
            plyMoney.load(10000);
            gameTime.start(0);
            flag = false;
        }
    }

    prevDay = gameTime.getGameDay();

    row=0;
    col=0;

    system("CLS");
}

void GameState::Draw(StateManager* game)
{
    recursor(2*map1.COL+5, 2);
    cout << "Day: " << gameTime.getGameDay() << "\tSpeed: (" << gameTime.timeSpeed/TIMEFACTOR << ")\n";
    recursor(2*map1.COL+5, 3);
    plyMoney.showBalance();

    if(OptionFlag||PauseFlag)
    {
        recursor(2*map1.COL+5, 5);
        cout << "----------------------------";
        recursor(2*map1.COL+5, 6);
        OptionFlag? cout << "        Unit Options        " : cout << "        Pause Menu          ";
        recursor(2*map1.COL+5, 7);
        cout << "----------------------------";
        if(OptionFlag)
        {
            if (map1.unit[row][col]==' ')
            {
                recursor(2*map1.COL+5, 8);
                cout << "     Build roadway       ";
                recursor(2*map1.COL+5, 9);
                cout << "     Buy residential area";
                recursor(2*map1.COL+5, 10);
                cout << "     Buy commercial area";
                recursor(2*map1.COL+5, 11);
                cout << "     Buy industrial area";
            }
            else
            {
            recursor(2*map1.COL+5, 8);
            cout << "     Sell               ";
            }

        }
        else
        {
            recursor(2*map1.COL+26, 2);
            cout << "Paused";
            recursor(2*map1.COL+5, 8);
            cout << "     Speed up time       ";
            recursor(2*map1.COL+5, 9);
            cout << "     Slow down time      ";
            recursor(2*map1.COL+5, 10);
            cout << "     Save current        ";
            recursor(2*map1.COL+5, 11);
            cout << "     Save and Exit       ";
        }
        recursor(2*map1.COL+7, 8+c);
        cout << "->";
    }

    else
    {
        recursor(0, 0);
        map1.Draw(row, col);
    }

    notify();
}

void GameState::HandleEvents(StateManager* game)
{
    if(OptionFlag)
    {
        OptionState();
    }
    else if(PauseFlag)
    {
        gameTime.pause();
        switch(getInput())
            {
                case UP:    c--;
                            break;
                case DOWN:  c++;
                            break;
                case ESC:   PauseFlag = false;
                            clearMenu(2, 13);
                            break;
                case ENTER: switch(c)
                            {
                                case 0: if(gameTime.timeSpeed<3*TIMEFACTOR) {gameTime.timeSpeed+=TIMEFACTOR;}
                                        else notify("Maximum speed reached", 2);
                                        break;
                                case 1: if(gameTime.timeSpeed>0) {gameTime.timeSpeed-=TIMEFACTOR;}
                                        else notify("Minimum speed reached", 2);
                                        break;
                                case 2: map1.Update(gameTime.getRealSeconds(), plyMoney.balance);
                                        notify("Game is saved", 2);
                                        break;
                                case 3: map1.Update(gameTime.getRealSeconds(), plyMoney.balance);
                                        PauseFlag = false;
                                        game->PopState();
                            }
            }
    }
    else
    switch(getInput())
    {
        case RIGHT: col++;
                    break;
        case LEFT:  col--;
                    break;
        case UP:    row--;
                    break;
        case DOWN:  row++;
                    break;
        case ENTER: c = 0;
                    OptionFlag = true;
                    break;
        case ESC:
                    PauseFlag = true;
                    break;
    }

    if(gameTime.getGameDay()>prevDay)
    {
       prevDay=gameTime.getGameDay();
       income();
    }

}

void GameState::Update(StateManager* game)
{
    if(row < 0) { row = 0; }
    if(row > map1.ROW-1) { row = map1.ROW-1; }
    if(col < 0) { col = 0; }
    if(col > map1.COL-1) { col = map1.COL-1; }

    if(c < 0) {c = 0;}
    if(c > 3) {c = 3;}

    if(!gameTime.isRun())
        if(!PauseFlag)
            gameTime.resume();
}

void GameState::notify(string temp, int time)
{
    duration = gameTime.getRealSeconds() + time;
    note = temp;
}

void GameState::notify()
{
    if(gameTime.getRealSeconds() > duration) {note = "                          ";}
    recursor(2*map1.COL+5, 0);
    textColor(LIGHT_RED);
    cout << note;
    textColorRestore();
}

void GameState::OptionState()
{
    switch(getInput())
        {
            case UP:    c--;
                        break;
            case DOWN:  c++;
                        break;
            case ESC:   OptionFlag = false;
                        clearMenu(5, 13);
                        break;
            case ENTER: if(map1.unit[row][col]==' ')
                        {
                            if(plyMoney.balance>0)
                            {
                                switch(c)
                                    {
                                    case 0: purchase(row, col, '0');           // ROAD
                                            break;
                                    case 1: purchase(row, col, 'a');           // RESIDENTIAL AREA
                                            break;
                                    case 2: purchase(row, col, 'd');           // COMMERCIAL AREA
                                            break;
                                    case 3: purchase(row, col, 'g');           // INDUSTRIAL AREA
                                    }
                            }
                            else
                            {
                                notify("You are in debt", 2);
                            }
                        }
                        else
                        {
                            if(map1.unit[row][col]=='a') {plyMoney.addBalance(250);}
                            if(map1.unit[row][col]=='d') {plyMoney.addBalance(400);}
                            if(map1.unit[row][col]=='g') {plyMoney.addBalance(500);}
                            map1.unit[row][col]=' ';
                        }
                        OptionFlag = false;
                        clearMenu(5, 13);

        }
}

void GameState::clearMenu(int from, int to)
{
    for(int i = from; i < to; i++)
    {
        recursor(2*map1.COL+5, i);
        cout << "                             ";
    }
}

void GameState::purchase(int x, int y, char type)
{
    if(type=='0')
    {
        map1.unit[x][y]='0';
        plyMoney.deductBalance(50);
    }
    else if(map1.isRoadside(x, y))
    {
        switch(type)
        {
            case 'a'    : map1.unit[x][y]='a';        // RESIDENTIAL AREA
                        plyMoney.deductBalance(500);
                        break;
            case 'd':     map1.unit[x][y]='d';        // COMMERCIAL AREA
                        plyMoney.deductBalance(800);
                        break;
            case 'g':     map1.unit[x][y]='g';        // INDUSTRIAL AREA
                        plyMoney.deductBalance(1000);
        }
    }
    else
    notify("Please build beside road!", 15);
}

void GameState::income()
{
    int sumfactor = 0;
    sumfactor = map1.sum('a') + 3*map1.sum('d') +7*map1.sum('g');
    plyMoney.addBalance(sumfactor*FACTOR);
}
