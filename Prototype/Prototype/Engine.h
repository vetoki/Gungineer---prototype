//Engine.h

#pragma once

class DrawManager;

class Engine
{
public:
	Engine();
	~Engine();

	bool Initialize();
	void ShutDown();
	void Update();

private:
	void HandleEvents();
	bool m_running;
	DrawManager* m_drawmanager;
	sf::Sprite* m_sprite;
};