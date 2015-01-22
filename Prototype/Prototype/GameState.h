// GameState.h

#pragma once

#include "State.h"

class Entity;

class GameState : public State
{
public:
	GameState(System& system);
	~GameState();

	void Shutdown();
	bool Update(float deltatime);
	void Draw();
	State* NextState();

private:
	void CollisionChecking();

	System m_systems;
	std::vector<Entity*> m_entities;

	bool m_active;
};