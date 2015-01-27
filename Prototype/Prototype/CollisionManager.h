//CollisionMnager

#pragma once

class Collider;

class CollisionManager
{
	static bool CheckBoxes(Collider* lhs, Collider* rhs, int& overlapX, int& overlapY);
	static bool CheckCircles(Collider* lhs, Collider* rhs, int& overlapX, int& overlapY);
	static bool CheckBoxCircle(Collider* lhs, Collider* rhs, int& overlapX, int& overlapY);
};