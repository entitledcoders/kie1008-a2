#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "state.hpp"
#include "../manager/timemanager.hpp"

enum eMenu
{
    START  = 0,
    HELP   = 1,
    EXIT   = 2,
};

class MenuState : public State
{
public:
    void Init();

    void Pause() {};
    void Resume() {};

    void Draw(StateManager* game);
	void HandleEvents(StateManager* game);
	void Update(StateManager* game);

    static MenuState* Instance() {
		return &m_MenuState;
	}

private:
	int option;
	static MenuState m_MenuState;
};

#endif  // MENUSTATE_HPP
