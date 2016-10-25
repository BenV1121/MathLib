#pragma once
#include <cmath>

// Problem a
int doNothing(int x);

// Problem b
float test_quad(float x);

// Note: Create structures whenever you feel they'll help!
struct quad_results
{
	float left_root, right_root;
	int roots; //0, 1, 2
};

quad_results quad(float a, float b, float c);

// Problem c
//float lerp(float start, float end, float t);

// Problem d
struct Point { float x, y; };
float distance(const Point &P1, const Point &P2);

// Problem e
struct Point3D { float x, y, z; };
float inner(const Point3D &P1, const Point3D &P2);
float inner(float x1, float y1, float z1,
	float x2, float y2, float z2);

struct Plane { Point3D abc; float d; };
inline float point_plane_distance(const Plane &pl, const Point3D &pt)
{
	return (inner(pl.abc, pt) + pl.d) / sqrt(pl.abc.x * pl.abc.x
									+ pl.abc.y * pl.abc.y
									+ pl.abc.z * pl.abc.z);
}

inline Point3D bezier(float t,
	const Point3D &p1,
	const Point3D &p2,
	const Point3D &p3,
	const Point3D &p4)
{
	float ot = 1 - t;

	Point3D r;

	r.x = ot*ot*ot*p1.x + 3 * ot*ot*t*p2.x + 3 * ot*t*t*p3.x + t*t*t*p4.x;
	r.y = ot*ot*ot*p1.y + 3 * ot*ot*t*p2.y + 3 * ot*t*t*p3.y + t*t*t*p4.y;
	r.z = ot*ot*ot*p1.z + 3 * ot*ot*t*p2.z + 3 * ot*t*t*p3.z + t*t*t*p4.z;
	// A^3 + 3A^2B + 3AB^2 + B^3

	return r;
}