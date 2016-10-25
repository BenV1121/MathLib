#include "SpaceShip.h"
#include "sfwdraw.h"
#include "Rigidbody.h"

using namespace::sfw;

SpaceShip::SpaceShip()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	stopAction = 0;

	breakPower = 1;
	turnSpeed = 1;
	speed = 100.0f;
	maxSpeed = 1000.0f;
}

void SpaceShip::doThrust(float value)
{
	vertThrust += value;
	//if (getKey('W')) vertThrust += 1;
	//if (getKey('S')) vertThrust -= 1;
}

void SpaceShip::doTurn(float value)
{
	horzThrust += value;
	//if (sfw::getKey('Q')) horzThrust += 1;
	//if (sfw::getKey('E')) horzThrust -= 1;
}

void SpaceShip::doStop(float value)
{
	stopAction = value;
}

void SpaceShip::update(const Transform &trans, Rigidbody &rigidbody)
{
	//doThrust(float value);
	//doTurn(float value);

	rigidbody.addForce(trans.getDirection() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThrust = vertThrust = stopAction = 0;
	/*
	horzThrust = vertThrust = 0;

	rigidbody.velocity.x = horzThrust * speed;
	rigidbody.velocity.y = vertThrust * speed;

	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		vec2 dir = normal(rigidbody.velocity);

		rigidbody.velocity = dir * maxSpeed;
	}

	vertThrust = 0.0f;
	horzThrust = 0.0f;
	*/
}

