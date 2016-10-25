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
struct Plane
{
	vec2 pos;

};
struct Ray   
{
	vec2 pos;

};
struct Hull  
{
	vec2 pos;

};

AABB   operator*(const mat3 &T, const AABB   & A);
Plane  operator*(const mat3 &T, const Plane  & P);
Ray    operator*(const mat3 &T, const Ray	 & R);
Hull   operator*(const mat3 &T, const Hull   & H);