#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "state.hpp"
#include "../manager/timemanager.hpp"
#include "../manager/mapmanager.hpp"
#include "../engine/economy.hpp"

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
    Time gameTime;
    MapManager map1;
    Economy plyMoney;

    void income();

    bool OptionState;
    bool run = false;

    int row, col, c;
    int rowSize, colSize;
    int prevDay;

	static GameState m_GameState;
};

#endif // GAMESTATE_HPP
