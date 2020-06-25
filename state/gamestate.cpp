#include "gamestate.hpp"
#include <fstream>

GameState GameState::m_GameState;

void GameState::Init()
{
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
        case ESC:   game->PopState();
                    break;
    }
}

void GameState::Update(StateManager* game)
{

}


