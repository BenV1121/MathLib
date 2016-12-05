#include "SpaceShip.h"
#include "sfwdraw.h"
#include "TractorBeam.h"

SpaceShip::SpaceShip()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	stopAction = 0.0f;
	breakPower = 4.0f;

	// Angles per second
	turnSpeed = 2.0f;

	// Pixels per second
	speed = 400.0f;
	maxSpeed = 800.0f;
}

void SpaceShip::doThrust(float value)
{
	vertThrust += value;
}

void SpaceShip::doTurn(float value)
{
	horzThrust += value;
}

void SpaceShip::doStop(float value)
{
	stopAction += value;
}

void SpaceShip::update(const Transform &trans,
	Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzThrust);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThrust = vertThrust = stopAction = 0;
}

void SpaceShip::doShoot(TractorBeam & tb)
{
	TractorBeam(draw);
}
