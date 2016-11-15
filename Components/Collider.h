#pragma once
#include "Shapes.h"
#include "Transform.h"
#include "collision.h"
#include "Rigidbody.h"

class Collider
{
public:
	AABB box;
	Hull hull;

	Collider();
	Collider(const vec2 *verts, int size);
	void DebugDraw(const mat3 &T, const Transform &trans);
};

CollisionData ColliderCollision(const Transform &AT, const Collider &AC,
								const Transform &BT, const Collider &BC);

CollisionData StaticCollision(Transform &AT, Rigidbody &AR, const Collider &AC,
							  const Transform &BT,						const Collider &BC);

CollisionData DynamicCollisionconst(const Transform &AT, const Rigidbody &AR, const Collider &AC,
									const Transform &BT, const Rigidbody &BR, const Collider &BC);

CollisionData DynamicResolution(Transform & AT, Rigidbody & AR, const Collider & AC,
								Transform & BT, Rigidbody & BR, const Collider & BC, float bounciness);