#include "sfwdraw.h"
#include "vec2.h"
#include "flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceShip.h"
#include "SpaceshipController.h"
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

	Transform playerTransform(200, 200);

	Rigidbody playerRigidbody;

	SpaceshipController playerCtrl;
	SpaceShip playerShip;
	

	while (stepContext())
	{
		float deltaTime = getDeltaTime();	

		// Wrap the player's position within the screen bounds
		if (playerTransform.position.x > W)
			playerTransform.position.x = 0.0f;
		else if (playerTransform.position.x < 0.0f)
			playerTransform.position.x = W;

		if (playerTransform.position.y > H)
			playerTransform.position.y = 0.0f;
		else if (playerTransform.position.y < 0.0f)
			playerTransform.position.y = H;

		playerCtrl.update(playerShip);
		playerShip.update(playerRigidbody, deltaTime);
		playerRigidbody.integrate(playerTransform, deltaTime);

		playerTransform.debugDraw();

	}
	
	termContext();
}