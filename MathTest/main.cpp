#include <cassert>
#include <cstdio>

#include "Test.h"
#include "vec2.h"

int main()
{
	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	assert((vec2{ 1,0 } +vec2{ 1,0 } == vec2{ 2,0 }));

	vec2 var = {  4,0 };
	var += vec2{ -3,1 };

	assert((var == vec2{ 1,1 }));

	return 0;
}

