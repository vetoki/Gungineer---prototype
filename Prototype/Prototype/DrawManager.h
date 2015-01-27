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
	void Draw(sf::Sprite sprite);
	sf::RenderWindow* GetWindow();
	sf::View* GetView();
	void SetView(sf::View view);

private:
	sf::RenderWindow* m_window;
	sf::View* m_view;
};