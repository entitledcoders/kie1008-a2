#ifndef HELPSTATE_HPP
#define HELPSTATE_HPP

#include "gamestate.hpp"

class HelpState : public GameState
{
public:
    void Init();

    void Pause() {};
    void Resume() {};

    void Draw(GameEngine* game);
	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);

    static HelpState* Instance() {
		return &m_HelpState;
	}

private:
	int currentPage;
	int page = 4;
	static HelpState m_HelpState;
};

#endif // HELPSTATE_HPP
