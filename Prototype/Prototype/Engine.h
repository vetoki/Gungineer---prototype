//Engine.h

#pragma once

class DrawManager;
class InputManager;
class StateManager;
class SoundManager;
class TextureManager;

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
	InputManager* m_input_manager;
	StateManager* m_state_manager;
	SoundManager* m_sound_manager;
	TextureManager* m_texture_manager;
};