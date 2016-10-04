#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include <cmath>

using namespace sfw;

void main()
{

	float W = 400, H = 400;
	initContext(W, H);
	float steps = -100;

	vec2 start = { 200, 300 },
		   end = { 900, 800 },
		   mid = { 0,  1100 };

	Transform playerTransform(200,200);
	Rigidbody playerRigidbody;

	while (stepContext())
	{
		float deltaTime = getDeltaTime();

		if (getKey('W')) playerRigidbody.velocity.y += 10.0f;
		if (getKey('S')) playerRigidbody.velocity.y -= 10.0f;
		if (getKey('A')) playerRigidbody.velocity.x -= 10.0f;
		if (getKey('D')) playerRigidbody.velocity.x += 10.0f;

		playerRigidbody.integrate(playerTransform, deltaTime);

		playerTransform.debugDraw();
	}
	
	termContext();
}