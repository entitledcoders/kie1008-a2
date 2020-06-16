#include "menustate.hpp"
#include "gameengine.hpp"
#include "gamestate.hpp"
#include "iomanager.hpp"

MenuState MenuState::m_MenuState;

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
    IOManager io;
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
    IOManager io;
    io.clearScreen();
    cout << "          EE City Builder         " << endl;
    cout << "               Start              " << endl;
    cout << "               Help               " << endl;
    cout << "               Exit               " << endl;


    io.gotoxy(10, this->option + 1);
    cout << "->";
}
