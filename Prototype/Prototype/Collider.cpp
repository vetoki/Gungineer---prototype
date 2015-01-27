// Collider.cpp

#include "stdafx.h"
#include "Entity.h"
#include "Collider.h"

Collider::Collider(int x, int y)
{
	m_parent = nullptr;
	m_area.left = x;
	m_area.top = y;
	m_area.width = 0;
	m_area.height = 0;
}

Collider::~Collider()
{

}

bool Collider::HasParent()
{
	return m_parent != nullptr;
}

void Collider::SetParent(Entity* parent)
{
	m_parent = parent;
}

Entity* Collider::GetParent()
{
	return m_parent;
}

void Collider::SetPosition(int x, int y)
{
	m_area.left = x;
	m_area.top = y;
}

void Collider::SetWidthHeight(int width, int height)
{
	m_area.width = width;
	m_area.height = height;
}

int Collider::GetX()
{
	return m_area.left;
}

int Collider::GetY()
{
	return m_area.top;
}

int Collider::GetWidth()
{
	return m_area.width;
}

int Collider::GetHeight()
{
	return m_area.height;
}

void Collider::Refresh()
{
	m_area.left = m_parent->GetX();
	m_area.top = m_parent->GetY();
	m_area.width = m_parent->GetSprite()->getTextureRect().width;
	m_area.height = m_parent->GetSprite()->getTextureRect().height;
}
