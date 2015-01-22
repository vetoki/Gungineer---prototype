// Player.h

#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player(sf::Sprite* sprite, sf::Keyboard* keyboard);
	~Player();
	void Update(float deltatime);
	sf::Sprite* GetSprite();
	//virtual Collider* GetCollider();
	float GetX();
	float GetY();
	bool IsVisible();
	EEntityType GetType();

private:
	sf::Sprite* m_sprite;
	sf::Keyboard* m_keyboard;
	float m_x;
	float m_y;
	float m_speed;
};