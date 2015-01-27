// Player.cpp

#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "StateManager.h"
 
#include "SoundManager.h"
#include "TextureManager.h"

Player::Player(System &system)
{	
	sf::Texture* texture = system.texture_manager->CreateTexture("../assets/Astronaut_02.png");
	m_sprite = new sf::Sprite;
	m_sprite->setTexture(*texture);
	m_sprite->setTextureRect(sf::IntRect(0, 0, 128, 180));
	m_sprites.push_back(m_sprite);

	texture = system.texture_manager->CreateTexture("../assets/Thruster_Left2.png");
	m_thruster_l = new sf::Sprite;
	m_thruster_l->setTexture(*texture);
	m_thruster_l->setTextureRect(sf::IntRect(0, 0, 128, 180));
	m_sprites.push_back(m_thruster_l);

	texture = system.texture_manager->CreateTexture("../assets/Thruster_Right2.png");
	m_thruster_r = new sf::Sprite;
	m_thruster_r->setTexture(*texture);
	m_thruster_r->setTextureRect(sf::IntRect(0, 0, 128, 180));
	m_sprites.push_back(m_thruster_r);

	m_keyboard = system.input_manager->GetKeyboard();
	
	m_thruster = system.sound_manager->CreateSound("../assets/TestEffect2.wav");

	m_screen_width = system.width;
	m_screen_height = system.height;
	m_x = m_screen_width / 2;
	m_y = m_screen_height / 2;
	m_speed = 0.0f;
	m_direction = 180.0f;
	m_angle = 180.0f;
	m_acceleration = 100.0f;
	m_sprite->setPosition(m_x, m_y);
	m_sprite->setOrigin(64, 90);
	m_sprite->setRotation(m_direction);

	m_thruster_l->setPosition(m_x, m_y);
	m_thruster_l->setOrigin(64, 90);
	m_thruster_l->setRotation(m_direction);
	m_thruster_l->setColor(sf::Color(255, 255, 255, 255));

	m_thruster_r->setPosition(m_x, m_y);
	m_thruster_r->setOrigin(64, 90);
	m_thruster_r->setRotation(m_direction);
	m_thruster_r->setColor(sf::Color(255, 255, 255, 255));

	d_x = 0.0f;
	d_y = 0.0f;
}
Player::~Player()
{
	for (int i = m_sprites.size(); i > 0; i--)
	{
		if (m_sprites[i - 1])
			delete m_sprites[i - 1];
	}
}
void Player::Update(float deltatime)
{
	if (m_keyboard->isKeyPressed(sf::Keyboard::Key::A))
	{
		m_key_a = true;
		m_thruster_r->setColor(sf::Color(255, 255, 255, 255));
	}
	if (m_keyboard->isKeyPressed(sf::Keyboard::Key::D))
	{
		m_key_d = true;
		m_thruster_l->setColor(sf::Color(255, 255, 255, 255));
	}

	if (!m_keyboard->isKeyPressed(sf::Keyboard::Key::A))
	{
		m_key_a = false;
		m_thruster_r->setColor(sf::Color(255, 255, 255, 0));
	}
	if (!m_keyboard->isKeyPressed(sf::Keyboard::Key::D))
	{
		m_key_d = false;
		m_thruster_l->setColor(sf::Color(255, 255, 255, 0));
	}

	if (m_key_a && m_key_d)
	{
		m_speed += m_acceleration * deltatime * 100;
		m_angle += (m_direction - m_angle);
	}
	else if (m_key_a)
	{
		m_direction -= m_acceleration * -1000.0f * deltatime;
		m_thruster->play();
	}
	else if (m_key_d)
	{
		m_direction += m_acceleration * -1000.0f * deltatime;
		m_thruster->play();
	}
	if (m_direction >= 360.0f)
		m_direction = 0.0f;
	if (m_direction < 0.0f)
		m_direction = 359.9f;
	
	if ((!m_key_a || !m_key_d) && m_speed > 0.0f)
	{
		//m_speed -= m_acceleration * deltatime * 10;
	}
	else if (m_speed <= 0.0f)
		m_speed = 0.0f;

	if (m_speed != 0.0f)
	{
		d_x = cos((m_angle+ 90) * (PI / 180)) * m_speed;
		d_y = sin((m_angle+90) * (PI / 180)) * m_speed;
	}

	if (m_x > m_screen_width - 64)
	{
		m_x = m_screen_width - 64.1;
		BounceX();
	}
	else if (m_x < 64.0f)
	{
		m_x = 64.1f;
		BounceX();
	}
	if (m_y > m_screen_height - 64)
	{
		m_y = m_screen_height - 64.1;
		BounceY();
	}
	else if (m_y < 64.0f)
	{
		m_y = 64.1f;
		BounceY();
	}

	m_x += d_x ;
	m_y += d_y ;



	//std::cout << d_x << ", " << d_y << ", " << m_speed << std::endl;

	//std::cout << m_thruster->getStatus() << std::endl;

	m_sprite->setRotation(m_direction);
	m_sprite->setPosition(m_x, m_y);
	m_thruster_l->setRotation(m_direction);
	m_thruster_l->setPosition(m_x, m_y);
	m_thruster_r->setRotation(m_direction);
	m_thruster_r->setPosition(m_x, m_y);
}

void Player::BounceX()
{
	float theta = 180 - m_angle;
	m_angle += 2 * theta;
	d_x = -d_x;
	m_speed *= 0.5f;
}

void Player::BounceY()
{
	float theta = 90 - m_angle;
	m_angle += 2 * theta;
	d_y = -d_y ;
	m_speed *= 0.5f;
}

sf::Sprite* Player::GetSprite()
{
	return m_sprite;
}
std::vector<sf::Sprite*> Player::GetSprites()
{
	return m_sprites;
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