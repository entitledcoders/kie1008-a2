#include <stdio.h>
#include "gameengine.hpp"
#include "gamestate.hpp"
#include "menustate.hpp"
#include "iomanager.hpp"

static MenuState m_MenuState;

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
                //game.ChangeState();
                break;

            case HELP:
                //game.ChangeState();
                break;

            case EXIT:
                game->Quit();
            }
        }
}

void MenuState::Update(GameEngine* game)
{
    int ch = io.getInput();
    {
        if(ch == DOWN)
            (this->option++)%3;
        if(ch == UP)
            (this->option--)%3;
    }
}

void MenuState::Draw(GameEngine* game)
{
    io.clearScreen();
    cout << "          EE City Builder         " << endl;
    cout << "               Start              " << endl;
    cout << "               Help               " << endl;
    cout << "               Exit               " << endl;


    io.gotoxy(10,select + 1);
    cout << "->";
}
