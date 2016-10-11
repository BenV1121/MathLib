#include "mat2.h"
#include "flops.h"

bool operator ==(const mat2 & A, const mat2 & B)
{
	return A[0] == B[0] && A[1] == B[1];
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return !(A == B);
}

mat2 operator+(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] + B.m[0], A.m[1] + B.m[1],
				 A.m[2] + B.m[2], A.m[3] + B.m[3] };
}

mat2 operator-(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] - B.m[0], A.m[1] - B.m[1],
				 A.m[2] - B.m[2], A.m[3] - B.m[3] };
}

mat2 operator-(const mat2 & A)
{
	return A*-1;
}

mat2 operator*(const mat2 & A, float s)
{
	return A * s;
}

mat2 operator*(float s, const mat2 & A)
{
	return mat2();
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	mat2 At = transpose(A);
	mat2 retval;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			retval[j][i] = dot(At[i], B[j]);

	return retval[0][0] = dot(At[0], B[0]);
}

mat2 operator-(const mat2 & A, const vec2 & V)
{
	return mat2();
}

float determinant(const mat2 & A)
{
	return 0.0f;
}

mat2 inverse(const mat2 & A)
{
	return mat2();
}

vec2 operator*(const mat2 & A, const vec2 & V)
{
	vec2 r;

	r.x = A[0][0] * V.x + A[0][1] * V.x;
	r.y = A[1][0] * V.x + A[1][1] * V.y;

	return r;
}

mat2 mat2Identity()
{
	return mat2{ 1,0,0,1 };
}

mat2 transpose(const mat2 &A)
{
	mat2 retval = A;

	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];

	return A;
}

float mat2::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat2::operator[](unsigned idx)
{
	return mm[idx][idx];
}
