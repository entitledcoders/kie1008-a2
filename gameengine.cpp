#include "gameengine.h"
#include "iomanager.h"

void GameEngine::Init()
{
    running = true;
}

void GameEngine::ChangeState(GameState* state)
{
	// remove previous state if available
	if ( !states.empty() ) {
		states.pop();
	}

	// push the new state in
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
		states.top()->Cleanup();
		states.pop();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.top()->Resume();
	}
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

void GameEngine::Draw()
{
	// let the state draw the screen
	states.top()->Draw(this);
}
