#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <stack>

using namespace std;

class State;    // Forward declaration to avoid errors

class StateManager
{
public:
    // Start of program, sets running to true
	void Init() { m_running = true; };

    // Pops old state and pushes new state in (switch)
	void ChangeState(State* state);

	// Push and pop without removing previous state (for in-game menus)
	void PushState(State* state);
	void PopState();

    // Looping the three main processes
    void Draw();
	void HandleEvents();
	void Update();

    // Get running state
	bool Running() { return m_running; }
	// Set running to false when forcing to quit
	void Quit() { m_running = false; }

private:
	// Stack of states
	stack<State*> states;

	// Running state (true/false)
	bool m_running;
};

#endif // STATEMANAGER_HPP
