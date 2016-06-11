#pragma once
#include "resources.h"
#include <iostream>
#include "counter.h"
#include "render.h"
#include "entityService.h"
class Game
{
public:
	Game();
	bool init();
	void gameLoop();
	~Game();

private:

	enum class gameStates
	{
		splash,
		play,
		over,
		end
	};

	const int FPS = 60;
	const int screenTicksPerFrame = 1000 / FPS;
	gameStates myGameState;

	void update();
	void eventUpdate();
	void draw();
};

