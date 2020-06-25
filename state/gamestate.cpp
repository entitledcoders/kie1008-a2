#include "gamestate.hpp"
#include <fstream>
#define FACTOR 1       // income factor

GameState GameState::m_GameState;

void GameState::Init()
{
    system("CLS");
    cout << "New(SPACE) / Continue(ENTER)";
    bool flag = true;
    while(flag)
    {
        if(getInput() == ENTER)                 // CONTINUE
        {
            map1.New("map/map1.txt", 24, 20, 1);
            map1.Load();
            plyMoney.load(map1.balance);
            gameTime.start(map1.time);
            flag = false;
            prevDay = gameTime.getGameDay();
        }
        else if(getInput() == SPACE)            // NEW
        {
            map1.New("map/map1.txt", 24, 20, 0);
            map1.Load();
            plyMoney.load(10000);
            gameTime.start(0);
            flag = false;
            prevDay = gameTime.getGameDay();
        }
    }

    row=0;
    col=0;

    system("CLS");
}

void GameState::Draw(StateManager* game)
{
    recursor(3*map1.COL+5, 2);
    cout << "Day: " << gameTime.getGameDay() << endl;
    recursor(3*map1.COL+5, 3);
    plyMoney.showBalance();

    if(OptionState)
    {
        recursor(3*map1.COL+5, 5);
        cout << "----------------------------";
        recursor(3*map1.COL+5, 6);
        cout << "        Unit Options        ";
        recursor(3*map1.COL+5, 7);
        cout << "----------------------------";
        if (map1.unit[row][col]==' ')
        {
            recursor(3*map1.COL+5, 8);
            cout << "     Buy residential area";
            recursor(3*map1.COL+5, 9);
            cout << "     Buy commercial area";
            recursor(3*map1.COL+5, 10);
            cout << "     Buy industrial area";
        }
        else
        {
        recursor(3*map1.COL+5, 8);
        cout << "     Sell               ";
        recursor(3*map1.COL+5, 9);
        cout << "                        ";
        recursor(3*map1.COL+5, 10);
        cout << "                        ";
        }
        recursor(3*map1.COL+7, 8+c);
        cout << "->";
    }

    else
    {
        recursor(0, 0);
        map1.Draw(row, col);
    }
}

void GameState::HandleEvents(StateManager* game)
{
    if(OptionState)
    {
        switch(getInput())
        {
            case UP:    c--;
                        break;
            case DOWN:  c++;
                        break;
            case ESC:   OptionState = false;
                        system("CLS");
                        break;
            case ENTER: if(map1.unit[row][col]==' ')
                        {
                            if(plyMoney.balance>0)
                            {
                                switch(c)
                                    {
                                    case 0: map1.unit[row][col]='a';        // RESIDENTIAL AREA
                                            plyMoney.deductBalance(500);
                                            break;
                                    case 1: map1.unit[row][col]='d';        // COMMERCIAL AREA
                                            plyMoney.deductBalance(800);
                                            break;
                                    case 2: map1.unit[row][col]='g';        // INDUSTRIAL AREA
                                            plyMoney.deductBalance(1000);
                                    }
                            }
                            else
                            {
                                recursor(3*map1.COL+5, 1);
                                textColor(RED);
                                cout << "haha u poor";
                                textColorRestore();
                            }
                        }
                        else
                        {
                            if(map1.unit[row][col]=='a') {plyMoney.addBalance(250);}
                            if(map1.unit[row][col]=='d') {plyMoney.addBalance(400);}
                            if(map1.unit[row][col]=='g') {plyMoney.addBalance(500);}
                            map1.unit[row][col]=' ';
                        }
                        OptionState = false;
                        system("CLS");

        }
    }
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
                    OptionState = true;
                    break;
        case ESC:   map1.Update(gameTime.getRealSeconds(), plyMoney.balance);
                    game->PopState();
                    gameTime.pause();
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
    if(c > 2) {c = 2;}

    if(!gameTime.isRun())
    {
        gameTime.resume();
    }
}

void GameState::income()
{
    int sumfactor = 0;
    for(int i = 0; i<map1.ROW; i++)
    {
        for(int j = 0; j<map1.COL; j++)
        {
            if(map1.unit[i][j]=='a') {sumfactor+=1;}
            if(map1.unit[i][j]=='d') {sumfactor+=3;}
            if(map1.unit[i][j]=='g') {sumfactor+=7;}
        }
    }
    plyMoney.addBalance(sumfactor*FACTOR);
}
