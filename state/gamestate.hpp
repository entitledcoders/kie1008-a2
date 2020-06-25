#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "state.hpp"
#include "../engine/map.hpp"
#include "../manager/timemanager.hpp"

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
    int ROW, COL;
    int rowSize, colSize;
    bool run = false;

    Map gameMap;
    Time gameTime;
	static GameState m_GameState;
};

#endif // GAMESTATE_HPP
