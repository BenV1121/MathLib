#include "flops.h"
#include <cmath>

bool fequals(float lhs, float rhs)
{
	return fabsf(lhs - rhs) <= 0.0000001f;
}
