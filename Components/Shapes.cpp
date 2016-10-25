#include "Shapes.h"
#include "flops.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;

	retval.pos = (T*vec3{ C.pos.x, C.pos.y, 1 }).xy;

	float mX = magnitude(T * vec3{ 0, C.rad, 0 });
	float mY = magnitude(T * vec3{ C.rad, 0, 0 });

	retval.rad;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && fequals(A.rad, B.rad);
}

AABB operator*(const mat3 & T, const AABB & A)
{
	AABB retval = A;

	return retval;
}
/*
Plane operator*(const mat3 & T, const Plane & P)
{
	
}

Ray operator*(const mat3 & T, const Ray & R)
{
	
}

Hull operator*(const mat3 & T, const Hull & H)
{
	
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}
*/