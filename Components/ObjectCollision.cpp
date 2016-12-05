#include "ObjectCollision.h"
#include "constdecl.h"

void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData result =
	DynamicResolution(player.transform, player.rigidbody, player.collider,
		as.transform, as.rigidbody, as.collider, 1);

	if (result.penetrationDepth >= 0)
	{
		//player.transform.m_scale *= .9f;
		player.health -= 1;
	}
}

void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicResolution(as1.transform, as1.rigidbody, as1.collider,
					  as2.transform, as2.rigidbody, as2.collider, 0);
}


void TractorAsteroidCollision(TractorBeam &tractor, Asteroid &asteroid)
{
	if (!tractor.isAlive) return;
	// Determine if there is a collision
	CollisionData result =
					ColliderCollision(tractor.transform, tractor.collider,
									  asteroid.transform, asteroid.collider);


	if (result.penetrationDepth >= 0)
	{
		// find the direction between
		vec2 dir = normal(tractor.transform.getGlobalPosition() -
						  asteroid.transform.getGlobalPosition());
		// and add a force to pull the objet toward us.
		asteroid.rigidbody.addForce(dir * 500);
		// If we flip the force, we can push stuff away.
	}
}

void ProjectileAsteroidCollision(Projectile & projectile, Asteroid & asteroid)
{
	CollisionData result =
		DynamicResolution(projectile.transform, projectile.rigidbody, projectile.collider,
			asteroid.transform, asteroid.rigidbody, asteroid.collider, 1);

	if (result.penetrationDepth >= 0)
	{
		asteroid.active = false;
		projectile.active = false;
	}
}
