#pragma once

#include "mat3.h"

struct Circle 
{
	vec2  pos;
	float rad; 
};

Circle operator*(const mat3   &T, const Circle &C);
bool operator== (const Circle &A, const Circle &B);

struct AABB  
{
	vec2 pos, 
		  he;	// half-extents
				// x = half-width
				// y = half-height

	vec2 min() const; // bottom left corner
	vec2 max() const; // top right corner
};

AABB   operator*(const mat3 &T, const AABB   & Box);


struct Plane
{
	vec2 pos, dir;
};

Plane  operator*(const mat3 &T, const Plane  &   P);

struct Ray   
{
	vec2 pos;

};

Ray    operator*(const mat3 &T, const Ray	 &   R);

struct Hull  
{
	vec2 vertices[16];
	vec2 normals [16];
	unsigned int size;

	Hull(const vec2 * a_vertices, unsigned a_size);

	Hull();
};

bool   operator==(const Hull &A, const Hull &B);

Hull   operator*(const mat3 &T, const Hull   &   H);
