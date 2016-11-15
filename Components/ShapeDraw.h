#pragma once
#include "sfwdraw.h"
#include "Shapes.h"

void drawCircle(const Circle &c,   unsigned color);
void drawAABB  (const AABB   &box, unsigned color);
void drawPlane (const Plane  &P,   unsigned color);
void drawRay   (const Ray    &R,   unsigned color);
void drawHull  (const Hull   &H,   unsigned color);