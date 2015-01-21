//Engine.h

#pragma once

class DrawManager;
class SpriteManager;
class InputManager;

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
	DrawManager* m_draw_manager;
	SpriteManager* m_sprite_manager;
	InputManager* m_input_manager;
	sf::Sprite* m_sprite;
};