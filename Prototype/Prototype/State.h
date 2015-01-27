// State.h

#pragma once

class DrawManager;
class InputManager;
class SoundManager;
class TextureManager;

struct System
{
	int width;
	int height;
	DrawManager* draw_manager;
	InputManager* input_manager;
	SoundManager* sound_manager;
	TextureManager* texture_manager;
};

class State
{
public:
	virtual ~State() {}
	virtual bool Update(float deltatime) = 0;
	virtual void Draw() = 0;
	virtual State* NextState() = 0;
};