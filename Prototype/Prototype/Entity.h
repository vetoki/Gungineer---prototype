// Entity.h

#pragma once
enum EEntityType
{
	ENTITY_UNKNOWN,
	ENTITY_PLAYER,
	ENTITY_ENEMY_1,
	ENTITY_ENEMY_2,
};

class Entity
{
public:
	virtual ~Entity() {}
	virtual void Update(float deltatime) = 0;
	virtual sf::Sprite* GetSprite() = 0;
	//virtual Collider* GetCollider() = 0;
	virtual float GetX() = 0;
	virtual float GetY() = 0;
	virtual bool IsVisible() = 0;
	virtual EEntityType GetType() = 0;
};
