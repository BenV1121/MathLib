#include "flops.h"
#include "vec2.h"
#include <cmath>

bool fequals(float lhs, float rhs)
{
	return fabsf(lhs - rhs) <= 0.000001f;
}

float deg2rad(float deg)
{
	return (deg * 3.14) / 180;
}

float rad2deg(float rad)
{
	return (rad * 180) / 3.14;
}

float linearHalf(float x)
{
	return 0.5f*x;
}

float growFast(float x)
{
	return x*x*x;
}

float growSlow(float x)
{
	return 1 - growFast(1 - x);
}

float hardAngle(float x)
{
	if (x <= 0.5)
		return 2 * x;
	else
		return 2 - 2 * x;
}

float bounce(float x)
{
	return abs(cos(x * 10) * (1 - x));
}

float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float parabola(float x)
{
	return (2 * x - 1) * (2 * x - 1);
}

float parabolaShiftX(float x)
{
	return ((2 * x - 1)-1) * (2 * x - 1);
}

float parabolaShiftY(float x)
{
	return parabola(x) + 1;
}

float parabolaWidth(float x)
{
	return parabola(x) * 2;
}

float parabolaFlip(float x)
{
	return 1 - (2 * x - 1) * (2 * x - 1);
}

float lerp(float start, float end, float alpha)
{
	// avoids some issues with floating point error
	return (1 - alpha)*start + (alpha)*end;
	
	// slope intercept form, where alpha is x
	// y = m*x + b
	return alpha*(end - start) + start;
}

float quadBezier(float start, float mid, float end, float alpha)
{
	return lerp(lerp(start, mid, alpha), lerp(mid, end, alpha), alpha);
}

float cubicBezier(float start, float mid1, float mid2, float end, float alpha)
{
	return 0.0f;
}

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float alphasq  = alpha * alpha;
	float alphacub = alphasq * alpha;

	float h00 =  2 * alphacub - 3 * alphasq + 1;
	float h01 = -2 * alphacub + 3 * alphasq;
	float h10 = alphacub - 2 * alphasq + alpha;
	float h11 = alphacub - alphasq;

	float point = h00 * start + h10 * end + h01 * s_tan + h11 * e_tan;

	return point;
}

float cardinalSpline(float start, float mid, float end, float tightness, float alpha)
{
	float s_tan = (mid - start) * tightness,
		  e_tan = (end - mid) * tightness;

	return hermiteSpline(start, s_tan, end, e_tan, alpha);
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);
}



// a. is probably something quadratic
// b. is probably something like a reverse quadratic

// c.
// when x 0 - 0.5 : y = 0 - 1,
// when x 0.5 - 1 : y = 1 - 0

// d. flip

// e. create parabola that arcs from 0 to 0 peaking at y =1 when 0.5x.
