#include "GameOverState.h"
#include "sfwdraw.h"

void GameOver::init(int a_font)
{
	font = a_font;
}

void GameOver::play()
{

}

void GameOver::update()
{

}

void GameOver::draw() const
{
	sfw::drawString(font, "GAME OVER", 600, 600, 20, 20);
}
