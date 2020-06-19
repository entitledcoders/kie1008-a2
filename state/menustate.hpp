#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "state.hpp"
#include "../manager/timemanager.h"

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

    void Draw(GameEngine* game);
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);

    static MenuState* Instance() {
		return &m_MenuState;
	}

private:
    timemanager timetest;
	int option;
	static MenuState m_MenuState;
};

#endif  // MENUSTATE_HPP
