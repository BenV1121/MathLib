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

AABB operator*(const mat3 & T, const AABB & Box)
{
	AABB retval = Box;
	vec3 tP[4];

	tP[0] = T * vec3{ Box.min().x, Box.min().y, 1 };
	tP[1] = T * vec3{ Box.max().x, Box.max().y, 1 };
	tP[2] = T * vec3{ Box.max().x, Box.min().y, 1 };
	tP[3] = T * vec3{ Box.min().x, Box.max().y, 1 };

	retval.pos = (T * vec3{ Box.pos.x, Box.pos.y, 1 }).xy;

	vec2 minv, maxv;

	for (int i = 1; i < 4; ++i)
	{
		minv = min(minv, tP[i].xy);
		maxv = max(maxv, tP[i].xy);
	}

	retval.pos = (minv + maxv) /2;
	retval.he  = (maxv - minv) /2;

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
*/
vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}
