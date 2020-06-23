#include "menustate.hpp"
#include "helpstate.hpp"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
    system("CLS");
    this->option = START;
    timetest.start();
}

void MenuState::Draw(StateManager* game)
{

    recursor(0, 2);
    cout << "   ------------------------------" << endl;
    cout << "          EE City Builder        " << endl;
    cout << "   ------------------------------" << endl;
    cout << "              Start              " << endl;
    cout << "              Help               " << endl;
    cout << "              Exit               " << endl;
    cout << endl;
    cout << "        Seconds passed: " << timetest.getRealSeconds() << endl;

    recursor(10, option + 5);
    cout << " ->";
}

void MenuState::HandleEvents(StateManager* game)
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

void MenuState::Update(StateManager* game)
{
    // Limits cursor movement to 3 selections.
    if(option<0) { option=0; }
    if(option>2) { option=2; }
}
