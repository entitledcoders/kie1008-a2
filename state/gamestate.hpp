#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "state.hpp"

class GameState : public State
{
public:
    void Init();

    void Pause() {};
    void Resume() {};

    void Draw(StateManager* game);
	void HandleEvents(StateManager* game);
	void Update(StateManager* game);

    static GameState* Instance() {
		return &m_GameState;
	}

private:
	static GameState m_GameState;
};

#endif // GAMESTATE_HPP
