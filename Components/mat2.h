#pragma once
#include "vec2.h"

// m[0] == mm[0][0]
// m[1] == mm[0][1]
// m[2] == mm[1][0]
// m[3] == mm[1][1]

union mat2
{
	float m[4];		// single dimensional array
	float mm[2][2];	// multidimensional array
	vec2  c[2];		// columm vectors
};

// mat[unsigned]	: subscr
// mat2 == mat2		: equivalence!
// transpose(mat2)
// mat2 + mat2		: matrix addition
// mat2 - mat2		: matrix subtraction
// -mat2


// mat2 * mat2		:	Matrix multiplied by matrix
// mat2 * vec2		:	Matrix by Vector
// mat2  * float	:	Matrix by Scalar
// float * mat2		:	Scalar by Matrix

// determinant(mat2)
// inverse(mat2)