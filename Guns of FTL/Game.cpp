#include "Game.h"


Game::Game()
{
}

bool Game::init()
{



	return true;
}

void Game::gameLoop()
{
	bool quit = false;
	std::cout << "[INFO]: Entering the game loop" << std::endl;

	counter capTimer;

	counter fpsTimer;
	fpsTimer.start();
	int countedFrames = 0;

	while (!quit && myGameState != gameStates::end)
	{

		capTimer.start();
		SDL_Event e;
		//poll events until the event queue is empty
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
			{
				myGameState = gameStates::end;
			}

			if (e.type >= SDL_USEREVENT)
			{
				std::cout << "user event detected" << std::endl;
			}

			resources::currentEvent = &e;
			eventUpdate();
		}

		//Calculate and correct fps
		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		//output the agerage fps to the console
		//cout << (int)avgFPS << endl;

		//update then draw the game
		update();
		draw();

		//"frame capping"
		int frameTicks = capTimer.getTicks();
		if (frameTicks < screenTicksPerFrame)
		{
			SDL_Delay(screenTicksPerFrame - frameTicks);
		}

		++countedFrames;
	}
}

void Game::update()
{
	switch (myGameState)
	{
	case gameStates::play:
		break;
	case gameStates::splash:
		break;
	case gameStates::end:
		break;
	case gameStates::over:
		break;
	}
	render::update();
	entityService::update();
}

void Game::draw()
{
	switch (myGameState)
	{
	case gameStates::play:
		break;
	case gameStates::splash:
		break;
	case gameStates::end:
		break;
	case gameStates::over:
		break;
	}
	entityService::draw();


	render::drawScreen(); //always at the bottom
}

void Game::eventUpdate()
{
	switch (myGameState)
	{
	case gameStates::play:
		break;
	case gameStates::splash:
		break;
	case gameStates::end:
		break;
	case gameStates::over:
		break;
	}
	render::eventUpdate();
	entityService::eventUpdate();

}

Game::~Game()
{
}
