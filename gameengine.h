#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <stack>

using namespace std;

class GameState;

class GameEngine
{
public:

	void Init();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return running; }
	void Quit() { running = false; }

private:
	// the stack of states
	stack<GameState*> states;

	bool running;
};

#endif
