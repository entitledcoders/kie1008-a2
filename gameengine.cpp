#include "gameengine.hpp"
#include "menustate.hpp"
#include "iomanager.hpp"

void GameEngine::ChangeState(GameState* state)
{
	// remove current running state (if available)
	if ( !states.empty() ) { states.pop_back(); }

	// push the new state in and run it
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void GameEngine::HandleEvents()
{
	// let the state handle events
	states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void GameEngine::Draw()
{
	// let the state draw the screen
	states.back()->Draw(this);
}
