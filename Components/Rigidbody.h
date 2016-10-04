#pragma once

#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	vec2 velocity; // represents the change3 in position

	void integrate(Transform &trans, float deltaTime);
};