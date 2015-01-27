// Collider.h

#pragma once

class Entity;

class Collider
{
public:
	Collider(int x, int y);
	~Collider();

	bool HasParent();
	void SetParent(Entity* parent);
	Entity* GetParent();

	void SetPosition(int x, int y);
	void SetWidthHeight(int width, int height);

	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

	void Refresh();

private:
	Entity* m_parent;
	sf::IntRect m_area;
};