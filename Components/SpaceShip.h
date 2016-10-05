#pragma once

#include "Rigidbody.h"

class SpaceShip
{
	float vertThrust;
	float horzThrust;
	float stopAction;

	float breakPower;
	float turnSpeed;
	float speed;			// movement speed
	float maxSpeed;

public:

	SpaceShip();

	void doThrust(float value);
	void doTurn(float value);

	void doStop(float value);

	void update(const Transform &trans, Rigidbody &rigidbody);
};