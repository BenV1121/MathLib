#include "Asteroid.h"

#include "GameState.h"

Asteroid::Asteroid()
{
	vec2 hullvrts[] = { {-1,0}, {0,1}, {1,0} };
	collider = Collider(hullvrts, 3);

	transform.m_scale = vec2{ 4,4 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Asteroid::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 & camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
