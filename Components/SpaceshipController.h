#pragma once
#include "SpaceShip.h"

class SpaceshipController
{
public:
	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	SpaceshipController(unsigned a_CTR_LEFT = 'A', unsigned a_CTR_RIGHT = 'D', unsigned a_CTR_UP = 'W', unsigned a_CTR_DOWN = 'S', unsigned a_CTR_BREAK = ' ');

	void update(SpaceShip &space);
};