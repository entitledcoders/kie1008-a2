#include "gamestate.hpp"
#include <fstream>

GameState GameState::m_GameState;

void GameState::Init()
{
    system("CLS");
    currentPage = 1;
}

void GameState::Draw(StateManager* game)
{
    recursor(0, 2);
    cout << "   ------------------------------" << endl;
    cout << "            Help (" << currentPage << "/" << page << ")" << endl;
    cout << "   ------------------------------" << endl;
}

void GameState::HandleEvents(StateManager* game)
{
    // Change pages on key input
    switch(getInput())
    {
        case RIGHT: currentPage++;
                        break;
        case LEFT:  currentPage--;
                        break;
        case ESC:   game->PopState();
                        break;
    }
}

void GameState::Update(StateManager* game)
{
    // Limits currentPage to available pages.
    if(currentPage < 1) { currentPage=1; }
    if(currentPage > page) { currentPage=page; }
}


