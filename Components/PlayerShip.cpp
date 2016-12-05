#include "PlayerShip.h"
#include "GameState.h"
#include "Projectile.h"

PlayerShip::PlayerShip()
{
	vec2 hullVrts[] = { {0,0},{ -2,-5 },{2,-5} };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, GameState & gs)
{
	controller.update(locomotion);
	locomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);

	if (sfw::getKey('T'))
	{
		gs.tractor.isAlive = true; // reset the beam
		gs.tractor.oneFrame = false;
		// have it look where we are looking
		gs.tractor.transform.m_position = transform.m_position;
		gs.tractor.transform.m_facing = transform.m_facing;
	}
	if (sfw::getKey('X'))
	{
		gs.projectile.active = true;
		
		gs.projectile.transform.m_position = transform.m_position;
		gs.projectile.transform.m_facing = transform.m_facing;
		gs.projectile.rigidbody.velocity = vec2{ 0,0 };
		gs.projectile.rigidbody.addImpulse(transform.getGlobalUp() * 100);
	}
}

void PlayerShip::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
