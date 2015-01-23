//DrawManager

#include "stdafx.h"
#include "DrawManager.h"

DrawManager::DrawManager()
{

}

DrawManager::~DrawManager()
{
	ShutDown();
}

bool DrawManager::Initialize(int width, int height)
{
	m_window = new sf::RenderWindow();
	m_window->create(sf::VideoMode(width, height), "Last Signal - Prototype");
	m_window->clear(sf::Color(0x11, 0x22, 0xFF, 0x44));
	m_window->setFramerateLimit(60);


	if (m_window == nullptr)
	{
		return false;
	}

	return true;
}

void DrawManager::ShutDown()
{
	m_window->close();
	delete m_window;
}

void DrawManager::Clear()
{
	m_window->clear();
}

void DrawManager::Present()
{
	m_window->display();
}

void DrawManager::Draw(sf::Sprite sprite)
{
	m_window->draw(sprite);
}

sf::RenderWindow* DrawManager::GetWindow()
{
	return m_window;
}
