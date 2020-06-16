#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "gameengine.hpp"

class GameState
{
public:

    // Create all pure virtual functions for states to define on their own
	virtual void Init() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
	virtual void HandleEvents(GameEngine* game) = 0;
	virtual void Update(GameEngine* game) = 0;
	virtual void Draw(GameEngine* game) = 0;
    // End

	void ChangeState(GameEngine* game, GameState* state) {
		game->ChangeState(state);
	}

protected:
	GameState() { }
};

#endif // GAMESTATE_HPP
