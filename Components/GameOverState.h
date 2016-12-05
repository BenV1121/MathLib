#pragma once

#include "constdecl.h"

class GameOver
{
	int font;

public:
	void init(int a_font);
	void play();
	void update();
	void draw() const;

};