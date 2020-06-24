#ifndef HELPSTATE_HPP
#define HELPSTATE_HPP

#include "state.hpp"

class HelpState : public State
{
public:
    void Init();

    void Pause() {};
    void Resume() {};

    void Draw(StateManager* game);
	void HandleEvents(StateManager* game);
	void Update(StateManager* game);

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
