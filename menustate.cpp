#include <stdio.h>
#include "gameengine.h"
#include "gamestate.h"
#include "menustate.h"
#include "iomanager.h"

static MenuState &m_MenuState;

void MenuState::Init()
{
    this->option = START;
}

void MenuState::HandleEvents(GameEngine* game)
{
    IOManager io;
    int ch = io.getInput();
        if(ch == ENTER)
        {
            switch(this->option)
            {
            case START:
                game.ChangeState();
                break;

            case HELP:
                game.ChangeState();
                break;

            case EXIT:
                game.Quit();
            }
        }
}

void MenuState::Update(CGameEngine* game)
{
    int ch = io.getInput();
    {
        if(ch == DOWN)
            (this->option++)%3;
        if(ch == UP)
            (this->option--)%3;
    }
}

void MenuState::Draw(CGameEngine* game)
{
    io.clearScreen();
    cout << "          EE City Builder         " << endl;
    cout << "               Start              " << endl;
    cout << "               Help               " << endl;
    cout << "               Exit               " << endl;


    io.gotoxy(10,select + 1);
    cout << "->";
}
