#include "GameState.h"
#include "ObjectCollision.h"

APP_STATE GameState::next()
{
	if (player.health <= 0)
		return ENTER_GAMEOVER;

	return GAME;
}

/////////////////////////////
/// Used to setup/reset values to start the game.
void GameState::play()
{
	player.transform.m_position = vec2{ 200,200 };
	player.transform.m_facing = 0;
	player.isAlive = true;

	asteroid[0].transform.m_position = vec2{ 0,0 };
	asteroid[0].rigidbody.addImpulse(vec2{ 100,100 });
	asteroid[0].rigidbody.addTorque(24);
	asteroid[0].active = true;
	
	asteroid[1].transform.m_position = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -100,-100 });
	asteroid[1].rigidbody.addTorque(-24);
	asteroid[1].active = true;

	asteroid[2].transform.m_position = vec2{ 300,300 };
	asteroid[2].rigidbody.addImpulse(vec2{ -100,-100 });
	asteroid[2].rigidbody.addTorque(-24);
	asteroid[2].active = true;

	asteroid[3].transform.m_position = vec2{ -300,-300 };
	asteroid[3].rigidbody.addImpulse(vec2{ 100,100 });
	asteroid[3].rigidbody.addTorque(24);
	asteroid[3].active = true;

	asteroid[3].transform.m_position = vec2{ 200,-100 };
	asteroid[3].rigidbody.addImpulse(vec2{ -100,100 });
	asteroid[3].rigidbody.addTorque(24);
	asteroid[3].active = true;
}

/////////////////////////////////
// Update, do collision, and any top-level stuff.
// Collision functions would get called here!
void GameState::update(float deltaTime)
{
	player.update    (deltaTime, *this);
	camera.update    (deltaTime, *this);
	tractor.update   (deltaTime, *this);
	projectile.update(deltaTime, *this);

	for (int i = 0; i < MAX_ASTEROIDS; ++i)
		asteroid[i].update(deltaTime, *this);

	for (int i = 0; i < MAX_ASTEROIDS; ++i)
		PlayerAsteroidCollision(player, asteroid[i]);

	for (int i = 0; i < MAX_ASTEROIDS; ++i)
		TractorAsteroidCollision(tractor, asteroid[i]);

	for (int i = 0; i < MAX_ASTEROIDS - 1; ++i)
		for (int j = i + 1; j < MAX_ASTEROIDS; ++j)
			AsteroidCollision(asteroid[i], asteroid[j]);
	
	for (int i = 0; i < MAX_ASTEROIDS; ++i)
		if(projectile.active)
		ProjectileAsteroidCollision(projectile, asteroid[i]);
}

void GameState::draw()
{
	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
	projectile.draw(cam);

	for (int i = 0; i < MAX_ASTEROIDS; ++i)
		asteroid[i].draw(cam);

	tractor.draw(cam);
}