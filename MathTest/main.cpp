#include <cassert>
#include <cstdio>
#include <cmath>

#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "Shapes.h"


int main()
{
	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	assert((vec3{ 0,0,0 } == vec3{ 0,0,0 }));
	assert((vec3{ 1,0,0 } == vec3{ 1,0,0 }));

	assert((vec2{ 1,0 } +vec2{ 1,0 } == vec2{ 2,0 }));

	assert((vec3{ 1,0,0 } +vec3{ 1,0,0 } == vec3{ 2,0,0 }));

	vec3 var = { 4,0,0 };
	var += vec3{ -3,1,1 };

	vec2 N = normal(vec2{ 1,1 });
	assert(N.x == N.y);

	//assert(magnitude(N) == 1);
	assert(normal(N) == N);
	assert((normal(vec2{ 0,1 }) == vec2{ 0,1 }));

	assert(fequals(1, .9999999f));

	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));

	assert(fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), deg2rad(45)));
	assert(fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 })));

	assert((fromAngle(0) == vec2{ 1,0 }));
	assert((fromAngle(deg2rad(90)) == vec2{ 0,1 }));

	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{ 0,0,1 }));

	assert((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }));

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,0,1 };
	vec2 v0 = vec2{ 1,0 };

	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI *-1 == -mI);

	assert(mI * mI == mI);

	assert(transpose(mI) == mI);
	assert(inverse(mI) == mI);

	/*
	vec3 test
		= m_rotate(deg2rad(-90)) * m_translate(10, 0) *
		  m_rotate(deg2rad(45))  * m_translate( 4, 0) *
		  m_rotate(deg2rad(45))  * m_translate(-6, 0) *
		  m_translate(6, 4)	     * vec3 { 0, 0, 1 };

	assert((test == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2), 1 }));
	*/

	vec2 verts[] = { {0,1}, {1,1}, {1,0}, {0,0} };

	Hull myHull(verts, 4);

	assert((myHull.normals[0] == vec2{ 0, 1 }));
	assert((myHull.normals[1] == vec2{ 1, 0 }));
	assert((myHull.normals[2] == vec2{ 0,-1 }));
	assert((myHull.normals[3] == vec2{ -1,0 }));

	assert((myHull.vertices[0] == vec2{ 0, 1 }));
	assert((myHull.vertices[1] == vec2{ 1, 1 }));
	assert((myHull.vertices[2] == vec2{ 1, 0 }));
	assert((myHull.vertices[3] == vec2{ 0, 0 }));

	return 0;
}