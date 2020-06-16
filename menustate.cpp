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
        switch(getInput())
        {
            case UP:    option--;
                        break;

            case DOWN:  option++;
                        break;

            case ENTER: switch(this->option)
                        {
                        case START: //game.ChangeState();
                                    break;

                        case HELP:  //game.ChangeState();
                                    break;

                        case EXIT:  game->Quit();
                        }
                        break;
        }
}

void MenuState::Update(GameEngine* game)
{
    if(option<0) { option=0; }
    if(option>2) { option=2; }
}

void MenuState::Draw(GameEngine* game)
{
    clearScreen();
    cout << "          EE City Builder         " << endl;
    cout << "               Start              " << endl;
    cout << "               Help               " << endl;
    cout << "               Exit               " << endl;


    gotoxy(10, option + 1);
    cout << "->";
}
