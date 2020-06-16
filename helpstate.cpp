#include "helpstate.hpp"

HelpState HelpState::m_HelpState;

void HelpState::Init()
{
    clearScreen();
    currentPage = 1;
}

void HelpState::Draw(GameEngine* game)
{
    clearScreen();
    gotoxy(10,0);
    cout << "Help (" << currentPage << "/" << page << ")" << endl;
}

void HelpState::HandleEvents(GameEngine* game)
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

void HelpState::Update(GameEngine* game)
{
    // Limits currentPage to available pages.
    if(currentPage < 1) { currentPage=1; }
    if(currentPage > page) { currentPage=page; }
}
