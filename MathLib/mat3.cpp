#include "mat3.h"
#include "flops.h"

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

mat3 mat3Identity()
{
	return mat3{ 1,0,0,
				 0,1,0,
				 0,0,1};
}

mat3 transpose(const mat3 & A)
{
	mat3 retval;

	for (unsigned i = 0; i < 3; ++i)
		for (unsigned j = 0; j < 3; ++j)
			retval.mm[i][j] = A.mm[j][i];

	return retval;
}

bool operator==(const mat3 & A, const mat3 & B)
{
	bool retval = true;

	for (int i = 0; i < 3; ++i)
		retval = retval && A[i] == B[i];

		return A[0] == B[0] &&
			   A[1] == B[1] &&
			   A[2] == B[2];
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return !(A == B);
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	mat3 retval;

	for (int i = 0; i < 3; ++i)
		retval[i] = A[i] + B[i];

		return retval;
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return A + -B;
}

mat3 operator-(const mat3 & A)
{
	return A*-1;
}

mat3 operator*(const mat3 & A, float s)
{
	mat3 retval;

	for (int i = 0; i < 3; ++i)
		retval[i] = A[i] * s;

	return retval;
}

mat3 operator*(float s, const mat3 & A)
{
	return A*s;
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	mat3 retval = A;

	retval.m[0] = A.m[0] * B.m[0] + A.m[3] * B.m[1] + A.m[6] * B.m[2];
	retval.m[1] = A.m[1] * B.m[0] + A.m[4] * B.m[1] + A.m[7] * B.m[2];
	retval.m[2] = A.m[2] * B.m[0] + A.m[5] * B.m[1] + A.m[8] * B.m[2];

	retval.m[3] = A.m[0] * B.m[3] + A.m[3] * B.m[4] + A.m[6] * B.m[5];
	retval.m[4] = A.m[1] * B.m[3] + A.m[4] * B.m[4] + A.m[7] * B.m[5];
	retval.m[5] = A.m[2] * B.m[3] + A.m[5] * B.m[4] + A.m[8] * B.m[5];

	retval.m[6] = A.m[0] * B.m[6] + A.m[3] * B.m[7] + A.m[6] * B.m[8];
	retval.m[7] = A.m[1] * B.m[6] + A.m[4] * B.m[7] + A.m[7] * B.m[8];
	retval.m[8] = A.m[2] * B.m[6] + A.m[5] * B.m[7] + A.m[8] * B.m[8];

	mat3 At = transpose(A);

	return retval;
}

// 3x3 * 3x1
vec3 operator*(const mat3 & A, const vec3 & V)
{
	return vec3
	{
		A.m[0] * V.x + A.m[3] * V.y + A.m[6] * V.z,
		A.m[1] * V.x + A.m[4] * V.y + A.m[7] * V.z,
		A.m[2] * V.x + A.m[5] * V.y + A.m[8] * V.z
	};
}

float determinant(const mat3 & A)
{
	return dot(A.c[0], cross(A.c[1], A.c[2]));
}

mat3 inverse(const mat3 & A)
{
	mat3 retval;

	retval[0] = cross(A.c[1], A.c[2]);
	retval[1] = cross(A.c[2], A.c[0]);
	retval[2] = cross(A.c[0], A.c[1]);

	return 1 / determinant(A) * transpose(retval);
}

mat3 scale(float w, float h)
{
	mat3 retval = mat3Identity();
	retval.mm[0][0] = w;
	retval.mm[1][1] = h;
	return retval;
}

mat3 translate(float x, float y)
{
	mat3 retval = mat3Identity();
	retval.mm[2][0] = x;
	retval.mm[2][1] = y;
	return retval;
}

mat3 rotation(float a)
{
	
	vec2 d = fromAngle(a);
	
	mat3 retval = mat3Identity();
	
	retval.c[0].xy = d;
	retval.c[1].xy = -perp(d);

	return retval;
}