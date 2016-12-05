#include "SpaceshipController.h"
#include "TractorBeam.h"

#include "sfwdraw.h"

SpaceshipController::SpaceshipController(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT,
	unsigned a_CTR_UP, unsigned a_CTR_DOWN,
	unsigned a_CTR_BREAK, unsigned a_CTR_SHOOT)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_UP;
	CTR_DOWN = a_CTR_DOWN;
	CTR_BREAK = a_CTR_BREAK;
	CTR_SHOOT = a_CTR_SHOOT;
}

void SpaceshipController::update(SpaceShip & ship)
{
	float hInput = 0.0f;
	hInput -= sfw::getKey(CTR_RIGHT);
	hInput += sfw::getKey(CTR_LEFT);

	float vInput = 0.0f;
	vInput += sfw::getKey(CTR_UP);
	vInput -= sfw::getKey(CTR_DOWN);

	float bInput = sfw::getKey(CTR_BREAK);

	ship.doStop(bInput);
	ship.doTurn(hInput);
	ship.doThrust(vInput);

	//TractorBeam tb;
	//tb += sfw::getKey(CTR_SHOOT);
}