#include <iostream>
#include <stdlib.h>
#include "iomanager.hpp"
#include "gameengine.hpp"
#include "menustate.hpp"

using namespace std;

int main()
{
    // Define game class
    GameEngine game;

    // Initiate game class and get into main menu
    game.Init();                                    // Sets run mode to true
    game.ChangeState( MenuState::Instance() );      // Sets to menu state

    cout << "Press any key to start...";            // To be replaced with intro

    // Starts game looping mechanism
    while( game.Running() )
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    clearScreen();

    return 0;
}
