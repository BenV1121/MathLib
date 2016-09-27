#include <cassert>
#include <cstdio>

#include "Test.h"
#include "vec2.h"
#include "vec3.h"

int main()
{
	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	assert((vec3{ 0,0,0 } == vec3{ 0,0,0 }));
	assert((vec3{ 1,0,0 } == vec3{ 1,0,0 }));

	assert((vec2{ 1,0 } + vec2{ 1,0 } == vec2{ 2,0 }));

	assert((vec3{ 1,0,0 } +vec3{ 1,0,0 } == vec3{ 2,0,0 }));

	vec3 var = {  4,0,0 };
	var += vec3{ -3,1,1 };

	assert((var == vec3{ 1,1,1 }));

	return 0;
}

