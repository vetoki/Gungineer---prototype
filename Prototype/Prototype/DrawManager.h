//DrawManager

#pragma once

class DrawManager
{
public:
	DrawManager();
	~DrawManager();
	bool Initialize(int width, int height);
	void ShutDown();
	void Clear();
	void Present();
	void Draw(sf::Sprite* sprite);

private:
	sf::RenderWindow* m_window;
};