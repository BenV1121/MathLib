#include <cmath>
#include "vec2.h"
#include "flops.h"


vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x + rhs.x, lhs.y + rhs.y };
}

vec2 operator-(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x * rhs, lhs.y * rhs };
}

vec2 operator*(float rhs, const vec2 & lhs)
{
	return vec2{ rhs * lhs.x, rhs * lhs.y};
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{ lhs.x / rhs, lhs.y / rhs };
}

vec2 operator/(float rhs, const vec2 & lhs)
{
	return vec2{ rhs / lhs.x, rhs / lhs.y };
}

vec2 operator-(const vec2 & v)
{
	return vec2{-v.x, -v.y};
}

vec2 operator+(const vec2 & v)
{
	return vec2{+v.x, +v.y};
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator/=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs.x / rhs, lhs.y / rhs;
}

vec2 & operator*=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs.x * rhs, lhs.y * rhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x, rhs.x)
		&& fequals(lhs.y, rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return lhs.x != rhs.x && lhs.y != rhs.y;
}

float magnitude(const vec2 & v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

vec2 normal(const vec2 & v)
{
	return v/magnitude(v);
}

float dot(const vec2 & rhs, const vec2 & lhs)
{
	return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	return acos(dot(normal(lhs), normal(rhs)));
}

vec2 perp(const vec2 & v)
{
	return {v.y, -v.x};
}

float angle(const vec2 & v)
{
	return atan2f( v.y, v.x );
}

vec2 fromAngle(float a)
{
	return vec2{ cos(a), sin(a) };
}

vec2 lerp(const vec2 & start, const vec2 & end, float alpha)
{
	vec2 retval;
	retval.x = lerp(start.x, end.x, alpha);
	retval.y = lerp(start.y, end.y, alpha);
	return retval;
}

vec2 quadBezier(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha)
{
	vec2 mid1 = lerp(start, mid, alpha), mid2 = lerp(mid, end, alpha);
	return lerp(mid1, mid2, alpha);
}

vec2 hermiteSpline(const vec2 &start, const vec2 &s_tan, const vec2 &end, const vec2 &e_tan, float alpha)
{
	float alphasq = alpha * alpha;
	float alphacub = alphasq * alpha;

	float h00 = 2 * alphacub - 3 * alphasq + 1;
	float h01 = -2 * alphacub + 3 * alphasq;
	float h10 = alphacub - 2 * alphasq + alpha;
	float h11 = alphacub - alphasq;

	vec2 point = h00 * start + h10 * end + h01 * s_tan + h11 * e_tan;

	return point;
}

vec2 cardinalSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float tightness, float alpha)
{
	vec2  s_tan = (mid - start) * tightness,
		  e_tan = (end - mid) * tightness;

	return hermiteSpline(start, s_tan, end, e_tan, alpha);
}

vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha)
{
	return cardinalSpline(start, mid, end, 0.5f, alpha);
}

