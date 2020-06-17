#include <stdlib.h>
#include "iomanager.hpp"
#include "gameengine.hpp"
#include "menustate.hpp"

using namespace std;

int main()
{
    system("COLOR FC");

    // Define game class
    GameEngine game;

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
