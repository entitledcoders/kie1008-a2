#ifndef HELPSTATE_HPP
#define HELPSTATE_HPP

#include "states.hpp"
#include "iomanager.hpp"

class HelpState : public State
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
    void loadHelp();

    vector<File> helpPage;
	int currentPage;
	int page = 4;
	static HelpState m_HelpState;
};

#endif // HELPSTATE_HPP
