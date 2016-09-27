#pragma once

struct vec2 { float x, y; };

// a + b
vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, const vec2 &lhs);
vec2 operator/(const vec2 &lhs, float rhs);
vec2 operator/(float rhs, const vec2 &lhs);

vec2 operator-(const vec2 &v);
vec2 operator+(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator/=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, const vec2 &rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

// component-wise
	// Addition
	// Subtraction

// Expression-Assignment operators
	// +=, -=

// scalar-wise
	// Multiplication
	// Division

// Evaluate the Magnitude

// Unary Negation (multiplying by -1)

// Relational operators
	// equivalence