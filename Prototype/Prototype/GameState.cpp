// GameState.cpp

#include "stdafx.h"
#include "GameState.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "StateManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"

#include "Entity.h"
#include "Player.h"

#include "CollisionManager.h"

GameState::GameState(System& system)
{
	m_systems = system;

	sf::Music* music = m_systems.sound_manager->CreateMusic("../assets/TestMusic.wav");
	music->play();

	sf::Sound* thruster = m_systems.sound_manager->CreateSound("../assets/TestEffect.wav");

	sf::Sprite* sprite = m_systems.sprite_manager->CreateSprite("../assets/Astronaut01.png", 0, 0, 128, 128);
	sf::Keyboard* keyboard = m_systems.input_manager->GetKeyboard();

	Player* player = new Player(sprite, keyboard, m_systems.width, m_systems.height);

	m_entities.push_back(player);

	m_active = false;
}
GameState::~GameState()
{
	Shutdown();
}

void GameState::Shutdown()
{
	for (int i = m_entities.size(); i > 0; i--)
	{
		if (m_entities[i - 1])
		{
			m_systems.sprite_manager->DestroySprite(m_entities[i-1]->GetSprite());
			delete m_entities[i - 1];
		}
	}
	m_entities.clear();
}
bool GameState::Update(float deltatime)
{
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		m_entities[i]->Update(deltatime);
	}

	CollisionChecking();

	return true;
}
void GameState::Draw()
{
	for (int i = 0; i < m_entities.size(); i++)
	{
		if (!m_entities[i]->IsVisible())
			continue;
		sf::Sprite sprite = *m_entities[i]->GetSprite();
		if (m_entities[i])
			m_systems.draw_manager->Draw(sprite);
	}
}
State* GameState::NextState()
{
	return nullptr;
}
void GameState::CollisionChecking()
{

}