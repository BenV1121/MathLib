#include "sfwdraw.h"
#include "GameState.h"
#include "GameOverState.h"

#include <cstdio>

void main()
{
	float SCREEN_WIDTH = 1200, SCREEN_HEIGHT = 1200;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);

	GameState game;
	GameOver over; 

	APP_STATE state = ENTER_GAME;

	while (sfw::stepContext())
	{
		float dt = sfw::getDeltaTime();

		switch (state)
		{
		case ENTER_GAME:
			game.play();
		case GAME:
			game.update(dt);

			game.draw();
			state = game.next();
			break;
		case GAMEOVER:
			over.draw();
			break;
		}
	}
	sfw::termContext();
}