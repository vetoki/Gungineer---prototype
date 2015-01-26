// SplitEnemy.h

#pragma once

#include "Entity.h"
#include "State.h"

class SplitEnemy : public Entity
{
public:
	SplitEnemy(System &system);
	~SplitEnemy();
	void Update(float deltatime);
	sf::Sprite* GetSprite();
	// Collider* GetCollider();
	float GetX();
	float GetY();
	void SetX(int x);
	void SetY(int y);
	bool IsVisible();
	EEntityType GetType();
	int GetHP();
	void SetHP(int damage);
	float GetSplitCounter();
	int GetSplitsRemaining();
	void SetSplits(int remaining);
	int GetScore();
private:
	sf::Sprite* m_sprite;
	float m_x;
	float m_y;
	bool m_visible;
	int m_splits_remaining;
	float m_split_counter;
	int m_hp;
	int m_score;
	int m_screen_width;
	int m_screen_height;
};