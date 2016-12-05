#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class GameState;

class Asteroid
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;

	bool active;

	Asteroid();
	void update(float deltaTime, GameState &gs);
	void draw(const mat3 & camera);
};