#pragma once
#include "Transform.h"
#include "Collider.h"

class GameState;

class Projectile
{
public:
	Transform transform;
	Collider collider;
	Rigidbody rigidbody;

	float xpos, ypos;
	float xvel, yvel;
	float radius;
	unsigned steps;

	bool active;
	bool oneFrame;

	void init(float b_xpos, float b_ypos, float b_xvel, float b_yvel, float b_rad, unsigned b_steps);

	Projectile();

	void update(float deltaTime, class GameState &gs);

	void draw(const mat3 &camera);
};