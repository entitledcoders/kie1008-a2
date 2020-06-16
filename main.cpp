#include <iostream>
#include <stdlib.h>
#include "iomanager.hpp"
#include "gameengine.hpp"
#include "menustate.hpp"

using namespace std;

int main()
{
    GameEngine game;

    game.Init();                                    // Sets run mode to true
    game.ChangeState( MenuState::Instance() );      // Enter introduction

    clearscreen();

    while( game.Running() )
    {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    clearscreen();

    return 0;
}
