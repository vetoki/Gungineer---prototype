// StateManager.cpp

#include "stdafx.h"
#include "StateManager.h"
#include "State.h"

StateManager::StateManager()
{
	m_active_state = nullptr;
	m_clock->restart();
	*m_time = m_clock->getElapsedTime();
}
StateManager::~StateManager()
{
	if (m_active_state)
	{
		delete m_active_state;
		m_active_state = nullptr;
	}
}

bool StateManager::Update()
{
	if (!m_active_state)
		return false;

	sf::Time delta = m_clock->restart();
	float deltatime = delta.asSeconds() * 0.001f;

	if (!m_active_state->Update(deltatime))
		return false;

	return true;
}
void StateManager::Draw()
{
	if (!m_active_state)
		return;
	m_active_state->Draw();
}
void StateManager::setState(State* state)
{
	if (m_active_state)
		delete m_active_state;
	m_active_state = state;
}