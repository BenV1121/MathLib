#include "SpaceshipController.h"
#include "sfwdraw.h"

using namespace::sfw;

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
