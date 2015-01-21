//Engine.cpp

#include "stdafx.h"
#include "Engine.h"
#include "DrawManager.h"
#include "SpriteManager.h"

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

	return true;
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
	}

	m_draw_manager->Clear();
	//m_drawmanager->Draw();
	m_draw_manager->Present();
}


void Engine::HandleEvents()
{

}