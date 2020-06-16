#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <vector>

using namespace std;

class GameState;    // Forward declaration to avoid errors

class GameEngine
{
public:
    // Start of program, sets running to true
	void Init() { m_running = true; };

    // Pops old state and pushes new state in (switch)
	void ChangeState(GameState* state);

	// Push and pop without removing previous state (for in-game menus)
	void PushState(GameState* state);
	void PopState();

    // Looping the three main processes
	void HandleEvents();
	void Update();
	void Draw();

    // Get running state
	bool Running() { return m_running; }
	// Set running to false when forcing to quit
	void Quit() { m_running = false; }

private:
	// Stack of states
	vector<GameState*> states;

	// Running state (true/false)
	bool m_running;
};

#endif // GAMEENGINE_HPP
