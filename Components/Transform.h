#pragma once

#include "vec2.h"

class Transform
{
public:
	Transform();
	Transform(float x, float y);

	vec2 position;
	vec2 scale;
	float facing;

	void func(float param1 = 0.0f, float param2 = 0.0f);

	vec2 getDirection();
	void setDirection(const vec2 &dir);

	void debugDraw();
	void update();
};