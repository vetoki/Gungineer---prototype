// CollisionManager.cpp

#include "stdafx.h"
#include "CollisionManager.h"
#include "Collider.h"

bool CollisionManager::CheckBoxes(Collider* lhs, Collider* rhs, int& overlapX, int& overlapY)
{
	overlapX = 0;
	overlapY = 0;

	int lhsHalfWidth = lhs->GetWidth() / 2;
	int rhsHalfWidth = rhs->GetWidth() / 2;
	int lhsCenterX = lhs->GetX() + lhsHalfWidth;
	int rhsCenterX = rhs->GetX() + rhsHalfWidth;
	int centerDeltaX = lhsCenterX - rhsCenterX;

	int halfWidth = (lhsHalfWidth + rhsHalfWidth);
	if (abs(centerDeltaX) < halfWidth)
	{
		int lhsHalfHeight = lhs->GetHeight() / 2;
		int rhsHalfHeight = rhs->GetHeight() / 2;
		int lhsCenterY = lhs->GetY() + lhsHalfHeight;
		int rhsCenterY = rhs->GetY() + rhsHalfHeight;
		int centerDeltaY = lhsCenterY - rhsCenterY;

		int halfHeight = (lhsHalfHeight + rhsHalfHeight);
		if (abs(centerDeltaY) < halfHeight)
		{
			int deltaX = halfWidth - abs(centerDeltaX);
			int deltaY = halfHeight - abs(centerDeltaY);

			if (deltaY < deltaX)
			{
				overlapY = deltaY;
				if (centerDeltaY < 0)
					overlapY = -overlapY;
			}
			else if (deltaY > deltaX)
			{
				overlapX = deltaX;
				if (centerDeltaX < 0)
					overlapX = -overlapX;
			}
			else
			{
				if (centerDeltaX < 0)
					overlapX = -deltaX;
				else
					overlapX = deltaX;


				if (centerDeltaY < 0)
					overlapY = -deltaY;
				else
					overlapY = deltaY;

			}
			return true;
		}
	}

	return false;
}

static bool CheckCircles(Collider* lhs, Collider* rhs, int& overlapX, int& overlapY)
{
	overlapX = 0;
	overlapY = 0;

	int lhsradius = lhs->GetWidth() / 2;
	int rhsradius = rhs->GetWidth() / 2;
	int lhsCenterX = lhs->GetX();
	int rhsCenterX = rhs->GetX();
	int centerDeltaX = lhsCenterX - rhsCenterX;

	int radius = (lhsradius + rhsradius);
	if (abs(centerDeltaX) < radius)
	{
		int lhsCenterY = lhs->GetY();
		int rhsCenterY = rhs->GetY();
		int centerDeltaY = lhsCenterY - rhsCenterY;

		if (abs(centerDeltaY) < radius)
		{
			int deltaX = radius - abs(centerDeltaX);
			int deltaY = radius - abs(centerDeltaY);

			if (deltaY < deltaX)
			{
				overlapY = deltaY;
				if (centerDeltaY < 0)
					overlapY = -overlapY;
			}
			else if (deltaY > deltaX)
			{
				overlapX = deltaX;
				if (centerDeltaX < 0)
					overlapX = -overlapX;
			}
			else
			{
				if (centerDeltaX < 0)
					overlapX = -deltaX;
				else
					overlapX = deltaX;


				if (centerDeltaY < 0)
					overlapY = -deltaY;
				else
					overlapY = deltaY;

			}
			return true;
		}
	}
	return false;
}
static bool CheckBoxCircle(Collider* lhs, Collider* rhs, int& overlapX, int& overlapY)
{
	return false;
}