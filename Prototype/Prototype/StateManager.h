// StateManager.h

#pragma once

class State;

class StateManager
{
	friend class Engine;

public:
	StateManager();
	~StateManager();

	bool Update();
	void Draw();

private:
	void setState(State* state);

	State* m_active_state;
	sf::Clock* m_clock;
};