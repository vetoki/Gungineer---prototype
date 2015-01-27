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
#include "SplitEnemy.h"

#include "CollisionManager.h"

GameState::GameState(System& system)
{
	m_systems = system;

	sf::Music* music = m_systems.sound_manager->CreateMusic("../assets/TestMusic.wav");
	//music->play();
	
	Player* player = new Player(m_systems);

	m_entities.push_back(player);
	/*
	SplitEnemy* enemy1 = new SplitEnemy(m_systems);
	enemy1->SetX(400);
	enemy1->SetY(200);

	m_entities.push_back(enemy1);
	*/
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
			if (m_entities[i - 1]->GetType() == ENTITY_PLAYER)
			{
				Player* player = static_cast<Player*>(m_entities[i - 1]);
				std::vector<sf::Sprite*> sprites = player->GetSprites();
				for (int j = sprites.size(); j > 0; j--)
				{
					if (sprites[j-1])
						m_systems.sprite_manager->DestroySprite(sprites[j-1]);
				}
				sprites.clear();
			}
			else
			{
				m_systems.sprite_manager->DestroySprite(m_entities[i - 1]->GetSprite());
			}
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
		if (m_entities[i]->GetType() == ENTITY_SPLIT_ENEMY)
		{
			SplitEnemy* enemy = static_cast<SplitEnemy*>(m_entities[i]);
			if (enemy->GetSplitCounter() <= 0.0f)
			{
				SplitEnemy* newEnemy = new SplitEnemy(m_systems);
				newEnemy->SetX(enemy->GetX() + 128);
				newEnemy->SetY(enemy->GetY() + 128);
				newEnemy->SetSplits(enemy->GetSplitsRemaining() - 1);
				enemy->SetSplits(enemy->GetSplitsRemaining() - 1);
				m_entities.push_back(newEnemy);
				i = m_entities.size();
			}
		}
	}

	std::cout << m_entities.size() << std::endl;

	CollisionChecking();

	return true;
}
void GameState::Draw()
{
	for (int i = 0; i < m_entities.size(); i++)
	{
		if (!m_entities[i]->IsVisible())
			continue;
		if (m_entities[i]->GetType() == ENTITY_PLAYER)
		{
			Player* player = static_cast<Player*>(m_entities[i]);
			std::vector<sf::Sprite*> sprites = player->GetSprites();
			for (int i = 0; i < sprites.size(); i++)
			{
				m_systems.draw_manager->Draw(*sprites[i]);
			}
		}
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