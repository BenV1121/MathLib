#pragma once

#include "Asteroid.h"
#include "PlayerShip.h"
#include "Projectile.h"
#include "constdecl.h"

void PlayerAsteroidCollision(PlayerShip &player, Asteroid & as);

void AsteroidCollision(Asteroid & as1, Asteroid & as2);

void TractorAsteroidCollision(TractorBeam &tractor, Asteroid &asteroid);

void ProjectileAsteroidCollision(Projectile &projectile, Asteroid &asteroid);