#pragma once

union vec2 
{ 
	float v[2];

	struct // untagged
	{
		float x, y;
	};

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

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

vec2 normal(const vec2 &v);

float dot(const vec2 &rhs, const vec2 & lhs);
float angleBetween(const vec2 &rhs, const vec2 &lhs);

vec2 perp(const vec2 &v);

float angle(const vec2 &v);

vec2 fromAngle(float a);

vec2 lerp(const vec2 &start, const vec2 &end, float alpha);

vec2 quadBezier(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);

vec2 hermiteSpline(const vec2 &start, const vec2 &s_tan, const vec2 &end, const vec2 &e_tan, float alpha);

vec2 cardinalSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float tightness, float alpha);

vec2 catRomSpline(const vec2 &start, const vec2 &mid, const vec2 &end, float alpha);

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