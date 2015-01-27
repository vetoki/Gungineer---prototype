// InputManager.h

#pragma once

class InputManager
{
	friend class Engine;

public:
	InputManager();
	~InputManager();

	sf::Keyboard* GetKeyboard();

private:

	sf::Keyboard* m_keyboard;
};