#pragma once
#include "Geometry.h"

// ½θ»θΈΧ½
class CollisionDetector
{
public:
	CollisionDetector();
	~CollisionDetector();

	bool IsCollision(const Rect& rcA ,const Rect& rcB);
};

