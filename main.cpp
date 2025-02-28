#include <stdlib.h>
#include "manager/iomanager.hpp"
#include "manager/statemanager.hpp"
#include "state/menustate.hpp"

using namespace std;

int main()
{
    consoleColor(WHITE, DARK_GRAY);

    // Define game class
    StateManager game;

    // Initiate game class and get into main menu
    game.Init();                                    // Sets run mode to true
    game.ChangeState( MenuState::Instance() );      // Sets to menu state

    // Starts game looping mechanism
    while( game.Running() )
    {
        game.Draw();
        game.HandleEvents();
        game.Update();
    }

    system("CLS");

    cout << "Exiting the program...\n\n\n";

    return 0;
}
