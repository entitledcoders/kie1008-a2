#include <iostream>
#include <stdlib.h>
#include "iomanager.hpp"
#include "gameengine.hpp"
#include "menustate.hpp"

using namespace std;

int main()
{
    GameEngine game;
    IOManager io;

    game.Init();                                    // Sets run mode to true
    game.ChangeState( MenuState::Instance() );      // Enter introduction

    io.clearScreen();

    while( game.Running() )
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    io.clearScreen();

    return 0;
}
