// Player.cpp

#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"

Player::Player(sf::Sprite* sprite, sf::Keyboard* keyboard)
{
	m_sprite = sprite;
	m_keyboard = keyboard;
	m_x = 100.0f;
	m_y = 100.0f;
	m_speed = 50.0f;
	m_sprite->setPosition(m_x, m_y);
	m_sprite->setOrigin(64, 64);
}
Player::~Player()
{

}
void Player::Update(float deltatime)
{
	if (m_keyboard->isKeyPressed(sf::Keyboard::Key::A))
	{
		m_sprite->rotate(-m_speed * -1000.0f * -deltatime);
	}

	if (m_keyboard->isKeyPressed(sf::Keyboard::Key::D))
	{
		m_sprite->rotate(m_speed * 1000.0f * deltatime);
	}

	if (m_keyboard->isKeyPressed(sf::Keyboard::Key::D) && m_keyboard->isKeyPressed(sf::Keyboard::Key::A))
	{
		m_x += m_speed * 1000.0 * deltatime;
	}

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