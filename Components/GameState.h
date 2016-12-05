#pragma once
#include "PlayerShip.h"
#include "Camera.h"
#include "Asteroid.h"
#include "TractorBeam.h"
#include "Projectile.h"
#include "constdecl.h"

const int MAX_ASTEROIDS = 5;

class GameState
{
public:
	PlayerShip player;
	Camera	   camera;
	Asteroid   asteroid[MAX_ASTEROIDS];
	TractorBeam tractor;
	Projectile  projectile;

	APP_STATE next();

	void play();
	void update(float deltaTime);
	void draw();
};