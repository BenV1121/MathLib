#pragma once
#include "flops.h"

bool fequals(float lhs, float rjs);

float deg2rad(float deg);
float rad2deg(float rad);

float linearHalf(float x);

float growFast(float x);

float growSlow (float x);

float hardAngle(float x);

float bounce(float x);

float bounceFlip(float x);

float parabola(float x);

float parabolaShiftX(float x);

float parabolaShiftY(float x);

float parabolaWidth(float x);

float parabolaFlip(float x);

float lerp(float start, float end, float alpha);

float quadBezier(float start, float mid, float end, float alpha);

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha);

float cardinalSpline(float start, float mid, float end, float alpha);

float catRomSpline(float start, float mid, float end);