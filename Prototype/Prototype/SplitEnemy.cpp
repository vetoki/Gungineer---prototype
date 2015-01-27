// SplitEnemy.cpp

#include "stdafx.h"
#include "SplitEnemy.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "StateManager.h"

#include "SoundManager.h"
#include "TextureManager.h"

SplitEnemy::SplitEnemy(System &system)
{
	sf::Texture* texture = system.texture_manager->CreateTexture("../assets/test.png");
	m_sprite = new sf::Sprite;
	m_sprite->setTexture(*texture);
	m_sprite->setTextureRect(sf::IntRect(0, 0, 128, 128));
	m_sprite->setOrigin(64, 64);

	m_screen_width = system.width;
	m_screen_height = system.height;
	
	m_x = 0.0f;
	m_y = 0.0f;
	m_visible = true;
	m_splits_remaining = 2;
	m_split_counter = 2.0f;
	m_hp = 5;
	m_score = 200;
	
}
SplitEnemy::~SplitEnemy()
{
	if (m_sprite)
		delete m_sprite;
}
void SplitEnemy::Update(float deltatime)
{
	if (m_splits_remaining > 0)
	{
		if (m_split_counter > 0.0f)
		{
			m_split_counter -= deltatime * 1000;
		}
	}
	m_sprite->rotate(5.0 * deltatime * 5000);
	m_sprite->setPosition(m_x, m_y);
	//std::cout << m_split_counter << std::endl;
}
sf::Sprite* SplitEnemy::GetSprite()
{
	return m_sprite;
}
// Collider* SplitEnemy::GetCollider(){}
float SplitEnemy::GetX()
{
	return m_x;
}
float SplitEnemy::GetY()
{
	return m_y;
}
void SplitEnemy::SetX(int x)
{
	m_x = x;
}
void SplitEnemy::SetY(int y)
{
	m_y = y;
}
bool SplitEnemy::IsVisible()
{
	return m_visible;
}
int SplitEnemy::GetHP()
{
	return 0;
}
void SplitEnemy::SetHP(int damage)
{
	m_hp -= damage;
	if (m_hp <= 0)
		m_visible = false;
}
float SplitEnemy::GetSplitCounter()
{
	return m_split_counter;
}
int SplitEnemy::GetSplitsRemaining()
{
	return m_splits_remaining;
}

void SplitEnemy::SetSplits(int remaining)
{
	m_splits_remaining = remaining;
	m_split_counter = 2.0f;
}
int SplitEnemy::GetScore()
{
	return m_score;
}
EEntityType SplitEnemy::GetType()
{
	return ENTITY_SPLIT_ENEMY;
}