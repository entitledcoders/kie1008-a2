#include <stdio.h>
#include <stdlib.h>
#include "gameengine.hpp"
#include "gamestate.hpp"
#include "menustate.hpp"
#include "iomanager.hpp"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
    this->option = START;
}

void MenuState::HandleEvents(GameEngine* game)
{
    int ch = getInput();
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
    int ch = getInput();
    {
        if(option<0) {option=0;}
        if(option>2) {option=2;}
        if(ch == DOWN) {option++;}
        if(ch == UP) {option--;}
    }
}

void MenuState::Draw(GameEngine* game)
{
    clearscreen();
    cout << "          EE City Builder         " << endl;
    cout << "               Start              " << endl;
    cout << "               Help               " << endl;
    cout << "               Exit               " << endl;


    gotoxy(10, this->option + 1);
    cout << "->";
}
