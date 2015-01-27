//Engine.cpp

#include "stdafx.h"
#include "Engine.h"
#include "DrawManager.h"
#include "InputManager.h"
#include "State.h"
#include "SoundManager.h"
#include "StateManager.h"
#include "GameState.h"
#include "TextureManager.h"

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
	int width = 1280;
	int height = 720;

	m_draw_manager = new DrawManager();
	if (!m_draw_manager->Initialize(width, height))
		return false;

	m_input_manager = new InputManager();
	m_sound_manager = new SoundManager();
	m_state_manager = new StateManager();
	m_texture_manager = new TextureManager();
	
	System system;
	system.width = width;
	system.height = height;
	system.draw_manager = m_draw_manager;
	system.input_manager = m_input_manager;
	system.sound_manager = m_sound_manager;
	system.texture_manager = m_texture_manager;
	m_state_manager->setState(new GameState(system));

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

	if (m_input_manager)
	{
		delete m_input_manager;
		m_input_manager = nullptr;
	}

	if (m_state_manager)
	{
		delete m_state_manager;
		m_state_manager = nullptr;
	}

	if (m_sound_manager)
	{
		delete m_sound_manager;
		m_sound_manager = nullptr;
	}
}

void Engine::Update()
{
	while (m_running)
	{
		HandleEvents();

		if (!m_state_manager->Update())
		{
			m_running = false;
		}

		m_draw_manager->Clear();
		m_state_manager->Draw();
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