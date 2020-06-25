#include "gamestate.hpp"
#include <fstream>

GameState GameState::m_GameState;

void GameState::Init()
{
    rowSize = 20;
    colSize = 20;
    gameMap.setSize(rowSize,colSize);

    if(!run)
    {
        ROW = 0;
        COL = 0;

        gameTime.start();

        run = true;
    }

    system("CLS");
}

void GameState::Draw(StateManager* game)
{
    recursor(0, 0);
    gameMap.show();
    recursor(colSize*3+2,0);
    cout << "Day: " << gameTime.getGameDay() << endl;
}

void GameState::HandleEvents(StateManager* game)
{
    // Change pages on key input
    switch(getInput())
    {
        case RIGHT: COL++;
                    gameMap.emptyTile(ROW,COL-1);
                        break;
        case LEFT:  COL--;
                    gameMap.emptyTile(ROW,COL+1);
                        break;
        case UP:    ROW--;
                    gameMap.emptyTile(ROW+1,COL);
                        break;
        case DOWN:  ROW++;
                    gameMap.emptyTile(ROW-1,COL);
                        break;
        case ESC:   game->PopState();
                    gameTime.pause();
                        break;
    }
}

void GameState::Update(StateManager* game)
{
    if(ROW < 0) { ROW = 0; }
    if(ROW > rowSize-1) { ROW = rowSize-1; }
    if(COL < 0) { COL = 0; }
    if(COL > colSize-1) { COL = colSize-1; }
    gameMap.cursorTile(ROW,COL);

    if(!gameTime.isRun())
    {
        gameTime.resume();
    }
}


