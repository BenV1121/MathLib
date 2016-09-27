#pragma once
struct vec3 { float x, y, z; };

// a + b
vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);

vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float rhs, const vec3 &lhs);
vec3 operator/(const vec3 &lhs, float rhs);
vec3 operator/(float rhs, const vec3 &lhs);

vec3 operator-(const vec3 &v);
vec3 operator+(const vec3 &v);

vec3 &operator+=(vec3 &lhs, const vec3 &rhs);
vec3 &operator-=(vec3 &lhs, const vec3 &rhs);
vec3 &operator/=(vec3 &lhs, const vec3 &rhs);
vec3 &operator*=(vec3 &lhs, const vec3 &rhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);

float magnitude(const vec3 &v);
