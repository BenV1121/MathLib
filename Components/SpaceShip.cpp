#include "SpaceShip.h"
#include "sfwdraw.h"

using namespace::sfw;

SpaceShip::SpaceShip()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	speed = 10.0f;
	maxSpeed = 1000.0f;
}

void SpaceShip::doThrust(float value)
{
	vertThrust = value;
	//if (getKey('W')) vertThrust += 1;
	//if (getKey('S')) vertThrust -= 1;
}

void SpaceShip::doTurn(float value)
{
	horzThrust = value;
	//if (sfw::getKey('Q')) horzThrust += 1;
	//if (sfw::getKey('E')) horzThrust -= 1;
}

void SpaceShip::update(Rigidbody &rigidbody, float deltaTime)
{
	//doThrust(float value);
	//doTurn(float value);

	rigidbody.velocity.x = horzThrust * speed;
	rigidbody.velocity.y = vertThrust * speed;

	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		vec2 dir = normal(rigidbody.velocity);

		rigidbody.velocity = dir * maxSpeed;
	}

	vertThrust = 0.0f;
	horzThrust = 0.0f;
}

