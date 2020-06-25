#include "gamestate.hpp"
#include <fstream>

GameState GameState::m_GameState;

void GameState::Init()
{
    rowSize = 10;
    colSize = 10;
    gameMap.setSize(rowSize,colSize);

    if(!run)
    {
        ROW = 0;
        COL = 0;
        run = true;
    }

    system("CLS");
}

void GameState::Draw(StateManager* game)
{
    recursor(0, 0);
    gameMap.show();
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
}


