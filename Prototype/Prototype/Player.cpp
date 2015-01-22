// Player.cpp

#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"

Player::Player(sf::Sprite* sprite, sf::Keyboard* keyboard)
{
	m_sprite = sprite;
	m_keyboard = keyboard;
	m_x = 0.0f;
	m_y = 360.0f;
	m_speed = 0.0f;
	m_direction = 180.0f;
	m_acceleration = 100.0f;
	m_sprite->setPosition(m_x, m_y);
	m_sprite->setOrigin(64, 64);
	m_sprite->setRotation(m_direction);
}
Player::~Player()
{

}
void Player::Update(float deltatime)
{
	if (m_keyboard->isKeyPressed(sf::Keyboard::Key::A))
		m_key_a = true;
	if (m_keyboard->isKeyPressed(sf::Keyboard::Key::D))
		m_key_d = true;

	if (!m_keyboard->isKeyPressed(sf::Keyboard::Key::A))
		m_key_a = false;
	if (!m_keyboard->isKeyPressed(sf::Keyboard::Key::D))
		m_key_d = false;

	if (m_key_a && m_key_d)
	{
		m_speed += m_acceleration * deltatime;
	}
	else if (m_key_a)
	{
		m_direction -= m_acceleration * -1000.0f * deltatime;
		m_sprite->setRotation(m_direction);
	}
	else if (m_key_d)
	{
		m_direction += m_acceleration * -1000.0f * deltatime;
		m_sprite->setRotation(m_direction);
	}
	if (m_direction >= 360.0f)
		m_direction = 0.0f;
	if (m_direction < 0.0f)
		m_direction = 359.9f;
	
	if (!m_key_a && !m_key_d && m_speed > 0.0f)
	{
		m_speed -= m_acceleration * deltatime;
	}
	else if (m_speed <= 0.0f)
		m_speed = 0.0f;
	
	/*float d_x = 0.0f;
	float d_y = 0.0f;
	if (m_speed != 0.0f)
	{
		d_x = sin(m_direction) * (deltatime / m_speed) * 500.0f;
		d_y = cos(m_direction) * (deltatime / m_speed) * 500.0f;
	}

	m_x += d_x;
	m_y += d_y;

	std::cout << m_x << ", " << m_y << ", " << m_direction << std::endl;*/

	m_x += m_speed;

	//std::cout << m_direction << std::endl;
	m_sprite->setPosition(m_x, m_y);
}
sf::Sprite* Player::GetSprite()
{
	return m_sprite;
}
float Player::GetX()
{
	return m_x;
}
float Player::GetY()
{
	return m_y;
}
bool Player::IsVisible()
{
	return true;
}
EEntityType Player::GetType()
{
	return ENTITY_PLAYER;
}