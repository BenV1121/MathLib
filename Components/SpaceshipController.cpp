#include "SpaceshipController.h"
#include "sfwdraw.h"

using namespace::sfw;

SpaceshipController::SpaceshipController(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT, unsigned a_CTR_UP, unsigned a_CTR_DOWN, unsigned a_CTR_BREAK)
{
	CTR_LEFT = a_CTR_LEFT;
	CTR_RIGHT = a_CTR_RIGHT;
	CTR_UP = a_CTR_UP;
	CTR_DOWN = a_CTR_DOWN;
	CTR_BREAK = a_CTR_BREAK;
}

void SpaceshipController::update(SpaceShip & space)
{
	float hInput = 0.0f;
	hInput -= getKey('A');
	hInput += getKey('D');

	float vInput = 0.0f;
	vInput -= getKey('S');
	vInput += getKey('W');

	space.doTurn  (hInput);
	space.doThrust(vInput);
}
