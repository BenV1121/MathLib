#pragma once

#include "Transform.h"
#include "vec3.h"

class SpaceshipRenderer
{
public:

	unsigned int color;
	float size;
	SpaceshipRenderer();

	void draw(const mat3& T, const Transform & ship);
};