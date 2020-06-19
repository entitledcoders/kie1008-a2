#include "gameengine.hpp"
#include "menustate.hpp"
#include "iomanager.hpp"

void GameEngine::ChangeState(GameState* state)
{
	// remove current running state (if available)
	if ( !states.empty() ) {
        system("CLS");
        states.pop();
    }

	// push the new state in and run it
	states.push(state);
	states.top()->Init();
}

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.top()->Pause();
	}

	// store and init the new state
	states.push(state);
	states.top()->Init();
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
        system("CLS");
		states.pop();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.top()->Resume();
	}
}

void GameEngine::Draw()
{
	// let the state draw the screen
	states.top()->Draw(this);
}

void GameEngine::HandleEvents()
{
	// let the state handle events
	states.top()->HandleEvents(this);
}

void GameEngine::Update()
{
	// let the state update the game
	states.top()->Update(this);
}
