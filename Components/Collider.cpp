#include "Collider.h"
#include "ShapeDraw.h"
#include <cmath>

Collider::Collider()
{
}

Collider::Collider(const vec2 * verts, int size)
				: hull(verts, size)
{
	vec2 boxMin = { INFINITY, INFINITY },
		boxMax = { -INFINITY, -INFINITY };

	for (int i = 0; i < size; ++i)
	{
		boxMin = min(boxMin, verts[i]);
		boxMax = max(boxMax, verts[i]);
	}

	box.pos = (boxMin + boxMax) / 2;
}

void Collider::DebugDraw(const mat3 & T, const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();
	drawAABB(glob * box,  0x888888ff);
	drawHull(glob * hull, 0x888888ff);
}

CollisionData ColliderCollision(const Transform & AT, const Collider & AC,
								const Transform & BT, const Collider & BC)
{
	CollisionData retval;

	retval = boxCollision(AT.getGlobalTransform() * AC.box,
		BT.getGlobalTransform() * BC.box);

	// It's likely there is a collision
	if (retval.penetrationDepth >= 0)
		retval = HullCollision(AT.getGlobalTransform() * AC.hull,
							   BT.getGlobalTransform() * BC.hull);

	return retval;
}

CollisionData StaticCollision(Transform & AT, Rigidbody & AR, const Collider & AC, const Transform & BT, const Collider & BC)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);

	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;
		AT.m_position -= MTV;

		AR.velocity = reflect(AR.velocity, results.collisionNormal);
	}

	return results;
}

CollisionData DynamicCollisionconst(const Transform & AT, const Rigidbody & AR, const Collider & AC, const Transform & BT, const Rigidbody &BR, const Collider & BC)
{
	return CollisionData();
}

CollisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC, Transform & BT, Rigidbody & BR, const Collider & BC, float bounciness)
{
	CollisionData results = ColliderCollision(AT, AC, BT, BC);
	if (results.penetrationDepth >= 0)
	{
		vec2 MTV = results.penetrationDepth * results.collisionNormal;

		float am = magnitude(AR.mass * AR.velocity);
		float bm = magnitude(BR.mass * BR.velocity);
		float cm = am + bm;

		AT.m_position -= MTV/2;
		BT.m_position += MTV/2;

		vec2  A = AR.velocity;
		float P = AR.mass;
		vec2  X;

		vec2  B = BR.velocity;
		float Q = BR.mass;
		vec2  Y;

		float E = bounciness;

		X = (A*P + B*Q + -E*(A - B)*Q) / (Q + P);
		Y = E*(A-B) + X;

		AR.velocity = X;
		BR.velocity = Y;
	}
	return results;
}
