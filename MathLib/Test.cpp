#include "Test.h"
#include <cmath>
// This is the develop branch.

int doNothing(int x)
{
	return x*x + 2*x + 5;
}

float test_quad(float x)
{
	return x*x + 2 * x - 7;
}

quad_results quad(float a, float b, float c)
{
	quad_results retquad;
	int out_roots;
	float d = b*b - 4 * a*c;
	if		(d  < 0)  retquad.roots = 0;
	else if (d  > 0)  retquad.roots = 2;
	else if (d == 0)  retquad.roots = 1;

	retquad.left_root  = (-b - sqrt(d)) / (2 * a);
	retquad.right_root = (-b + sqrt(d)) / (2 * a);

	return retquad;
}
float lerp(float start, float end, float t)
{
	return start + t*(end - start);
}

float distance(const Point &P1, const Point &P2)
{
	return sqrt((P1.x - P2.x) * 2 + (P1.y - P2.y) * 2);
}

float inner(const Point3D &P1, const Point3D &P2)
{
	return P1.x*P2.x + P1.y*P2.y + P1.z*P2.z;
}

