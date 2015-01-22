// Player.cpp

#include "stdafx.h"
#include "Player.h"

Player::Player(sf::Sprite* sprite, sf::Keyboard* keyboard)
{
	m_sprite = sprite;
	m_keyboard = keyboard;
	m_x = 0.0f;
	m_y = 0.0f;
	m_sprite->setPosition(m_x, m_y);
}
Player::~Player()
{

}
void Player::Update(float deltatime)
{

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