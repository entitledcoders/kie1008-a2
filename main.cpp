#include <iostream>
#include <stdlib.h>
#include "iomanager.h"
#include "gameengine.h"
#include "menustate.h"

using namespace std;

int main()
{
    GameEngine game;
    IOManager io;

    game.Init();                                    // Sets run mode to true
    game.ChangeState( MenuState::Instance() );      // Enter introduction

    io.clearscreen();

    while( game.Running() )
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    io.clearscreen();

    return 0;
}
