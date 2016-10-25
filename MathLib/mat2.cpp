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
	return s * A;
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	mat2 At = transpose(A);
	mat2 retval;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			retval.mm[j][i] = dot(At.c[i], B.c[j]);

	return retval;
}

vec2 operator*(const mat2 & A, const vec2 & V)
{
	mat2 At = transpose(A);
	vec2 retval;

	retval[0] = dot(At.c[0], V);
	retval[1] = dot(At.c[1], V);

	return retval;
}

float determinant(const mat2 & A)
{
	return (A.mm[0][0] * A.mm[1][1]) - (A.mm[0][1] * A.mm[1][0]);
}

mat2 inverse(const mat2 & A)
{
	mat2 retval = A;

	retval.m[0] = A.m[0] * A.m[0] + A.m[1];
	retval.m[1] = A.m[1] * A.m[0] + A.m[2];

	mat2 At = transpose(A);

	return retval;
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
