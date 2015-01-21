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
	void SetKeyboard(int key, bool state);

	sf::Keyboard* m_keyboard;
};