#include "Projectile.h"
#include "ShapeDraw.h"
#include "GameState.h"
#include "sfwdraw.h"

void Projectile::init(float b_xpos, float b_ypos, float b_xvel, float b_yvel, float b_rad, unsigned b_steps)
{
	active = false;
	xpos = b_xpos;
	ypos = b_ypos;
	xvel = b_xvel;
	yvel = b_yvel;
	radius = b_rad;
	steps = b_steps;
}

Projectile::Projectile()
{

	vec2 hullvrts[] = { { -1,0 },{ 0,1 },{ 1,0 } };
	collider = Collider(hullvrts, 3);

	transform.m_scale = vec2{ 4,4 };
	rigidbody.drag = 0.0f;
	rigidbody.angularDrag = 0.0f;
	rigidbody.mass = 10;
}

void Projectile::update(float deltaTime, GameState & gs)
{
	rigidbody.integrate(transform, deltaTime);
}

void Projectile::draw(const mat3 & camera)
{
	if (active)
	{
		transform.debugDraw(camera);
		collider.DebugDraw(camera, transform);
		rigidbody.debugDraw(camera, transform);

		sfw::drawCircle(xpos, ypos, radius, steps, RED);
	}
}
