//Engine.cpp

#include "stdafx.h"
#include "Engine.h"
#include "DrawManager.h"

Engine::Engine()
{
	m_running = true;
}

Engine::~Engine()
{

}

bool Engine::Initialize()
{
	int width = 1024;
	int height = 600;

	m_drawmanager = new DrawManager();

	if (!m_drawmanager->Initialize(width, height))
		return false;

	return true;
}

void Engine::ShutDown()
{
	if (m_drawmanager)
	{
		delete m_drawmanager;
		m_drawmanager = nullptr;
	}
}

void Engine::Update()
{
	while (m_running)
	{
		HandleEvents();
	}

	m_drawmanager->Clear();
	//m_drawmanager->Draw();
	m_drawmanager->Present();
}


void Engine::HandleEvents()
{

}