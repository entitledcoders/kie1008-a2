#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "gamestate.hpp"

class MenuState : public GameState
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
	int option;
	static MenuState m_MenuState;
};

#endif  // MENUSTATE_HPP
