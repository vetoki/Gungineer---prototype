// Player.h

#pragma once

#include "Entity.h"
#include "State.h"

class Player : public Entity
{
public:
	Player(System &system);
	~Player();
	void Update(float deltatime);
	sf::Sprite* GetSprite();
	//virtual Collider* GetCollider();
	float GetX();
	float GetY();
	bool IsVisible();
	void BounceX();
	void BounceY();
	EEntityType GetType();

private:
	sf::Sprite* m_sprite;
	sf::Keyboard* m_keyboard;
	float m_x;
	float m_y;
	float m_speed;
	float m_direction;
	float m_angle;
	float m_acceleration;
	bool m_key_a;
	bool m_key_d;
	int m_screen_width;
	int m_screen_height;
	float d_x;
	float d_y;
	sf::Sound* m_thruster;
};