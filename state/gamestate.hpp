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

    void notify();
    void notify(string, int);
    void OptionState();
    void clearMenu(int, int);
    void income();
    void purchase(int, int, char);

    bool OptionFlag;
    bool PauseFlag;
    bool run = false;

    int row, col, c;
    int prevDay;
    int duration;

    string note;

	static GameState m_GameState;
};

#endif // GAMESTATE_HPP
