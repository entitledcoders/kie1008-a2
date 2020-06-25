#ifndef STATE_HPP
#define STATE_HPP

#include "../manager/statemanager.hpp"
#include "../manager/iomanager.hpp"

class State
{
public:

    // Create all pure virtual functions for states to define on their own
	virtual void Init() = 0;
	virtual void Pause() = 0;
	virtual void Resume() = 0;
    virtual void Draw(StateManager* game) = 0;
	virtual void HandleEvents(StateManager* game) = 0;
	virtual void Update(StateManager* game) = 0;
    // End

	void ChangeState(StateManager* game, State* state) {
		game->ChangeState(state);
	}

protected:
	State() { }
};

#endif // STATE_HPP
