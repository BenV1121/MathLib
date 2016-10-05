#pragma once

#include "Rigidbody.h"

class SpaceShip
{
	float vertThrust;
	float horzThrust;

	float speed;			// movement speed
	float maxSpeed;

public:

	SpaceShip();

	void doThrust(float value);
	void doTurn(float value);

	void update(Rigidbody &rigidbody, float deltaTime);
};