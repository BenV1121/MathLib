#pragma once
#include "vec3.h"

// m[0] == mm[0][0]
// m[1] == mm[0][1]
// m[2] == mm[1][0]
// m[3] == mm[1][1]

union mat3
{
	float m[9];		// single dimensional array
	float mm[3][3];	// multidimensional array
	vec3  c[3];		// columm vectors

	vec3  operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};

mat3 mat3Identity();
mat3 transpose(const mat3 &A);

bool operator==(const mat3 &A, const mat3 &B);
bool operator!=(const mat3 &A, const mat3 &B);

mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A);

mat3 operator*(const mat3 &A, float s);
mat3 operator*(float s, const mat3 &A);
mat3 operator*(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const vec3 &V);

float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

// mat2[unsigned]	: subscr
// mat2 == mat2		: equivalence!
// transpose(mat2)
// mat2 + mat2		: matrix addition
// mat2 - mat2		: matrix subtraction
// -mat2


// mat2 * mat2		:	Matrix multiplied by matrix
// mat2 * vec2		:	Matrix by Vector
// mat2 * float		:	Matrix by Scalar
// float * mat2		:	Scalar by Matrix

// determinant(mat2)
// inverse(mat2)