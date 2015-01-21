//Engine.cpp

#include "stdafx.h"
#include "Engine.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "InputManager.h"

Engine::Engine()
{
	m_running = true;
}

Engine::~Engine()
{
	ShutDown();
}

bool Engine::Initialize()
{
	int width = 1024;
	int height = 600;

	m_draw_manager = new DrawManager();
	if (!m_draw_manager->Initialize(width, height))
		return false;

	m_sprite_manager = new SpriteManager();
	m_input_manager = new InputManager();

	m_running = true;
	return m_running;
}

void Engine::ShutDown()
{
	if (m_draw_manager)
	{
		delete m_draw_manager;
		m_draw_manager = nullptr;
	}
}

void Engine::Update()
{
	while (m_running)
	{
		HandleEvents();

		/*if (!m_state_manager->update())
		{
		m_running = false
		}*/

		m_draw_manager->Clear();
		//m_state_manager->Draw();
		m_draw_manager->Present();
	}
}


void Engine::HandleEvents()
{
	sf::RenderWindow* window = m_draw_manager->GetWindow();
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_running = false;
	}

	sf::Keyboard* keyboard = m_input_manager->GetKeyboard();
	
	if (keyboard->isKeyPressed(sf::Keyboard::Escape))
		m_running = false;
}