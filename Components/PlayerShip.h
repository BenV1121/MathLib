#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "SpaceshipController.h"
#include "SpaceShip.h"

class PlayerShip
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;
	SpaceshipController controller;
	SpaceShip			locomotion;

	int health = 5;
	bool isAlive;
	PlayerShip();

	void update(float deltaTime, class GameState &gs);
	void draw(const mat3 &camera);
	void init(float a_x, char a_up, char a_down, char a_fire, unsigned a_color);
};