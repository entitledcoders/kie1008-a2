#include "menustate.hpp"
#include "helpstate.hpp"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
    this->option = START;
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

void MenuState::HandleEvents(GameEngine* game)
{
    // Handle events upon key press
    switch(getInput())
    {
        case UP:    option--;   // Moves cursor up
                    break;

        case DOWN:  option++;   // Moves cursor down
                    break;

        case ENTER: switch(this->option)
                    {
                    case START: //game.ChangeState();
                                break;

                    case HELP:  game->PushState( HelpState::Instance() );
                                break;

                    case EXIT:  game->Quit();
                    }
                    break;
    }
}

void MenuState::Update(GameEngine* game)
{
    // Limits cursor movement to 3 selections.
    if(option<0) { option=0; }
    if(option>2) { option=2; }
}
