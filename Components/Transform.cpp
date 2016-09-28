#include "Transform.h"
#include "sfwdraw.h"

using namespace sfw;

Transform::Transform() : facing(0), position({0,0}), scale({28,8}) // member initialization
{

}

Transform::Transform(float x, float y) : Transform() // ctor chaining
{
	position.x = x;
	position.y = y;
}

vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	drawCircle(position.x, position.y, 48);

	vec2 dirEnd = position + getDirection() * scale.x;
	vec2 upEnd  = position + perp(getDirection()) * scale.y;
}

void Transform::update()
{
	if (getKey(KEY_LEFT))
	{
		position.x -= getDeltaTime() * 200;
	}
	if (getKey(KEY_RIGHT))
	{
		position.x += getDeltaTime() * 200;
	}
	if (getKey(KEY_DOWN))
	{
		position.y -= getDeltaTime() * 200;
	}
	if (getKey(KEY_UP))
	{
		position.y += getDeltaTime() * 200;
	}

	if (position.y <0)
	{
		position.y = 600;
	}

	if (position.y > 600)
	{
		position.y = -0;
	}

	if (position.x <0)
	{
		position.x = 800;
	}

	if (position.x > 800)
	{
		position.x = -0;
	}
}
