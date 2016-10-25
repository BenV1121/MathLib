#include "ShapeDraw.h"

void drawCircle(const Circle & C, unsigned color)
{
	sfw::drawCircle(C.pos.x, C.pos.y, C.rad, 12U, WHITE);
}

void drawAABB(const AABB & A, unsigned color)
{
	sfw::drawLine(A.min().x, A.max().y, A.max.x, A.min.y, color);
}

void drawPlane(const Plane & P, unsigned color)
{

}

void drawRay(const Ray & R, unsigned color)
{

}

void drawHull(const Hull & H, unsigned color)
{

}

