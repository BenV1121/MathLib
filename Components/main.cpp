#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"

void main()
{
	sfw::initContext();
	Transform trans;

	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 96,32 };

	while (sfw::stepContext())
	{
		trans.facing += sfw::getDeltaTime();
		trans.debugDraw();
	}
	
	sfw::termContext();
}