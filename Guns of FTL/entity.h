#pragma once
#include "resources.h"
#include "imageService.h"
#include "render.h"
class entity
{
public:
	entity();
	virtual void update();
	virtual void eventUpdate();
	virtual void draw();
	virtual void onCollide(entity* collider);
	virtual bool damage(int amount, entity* damager);
	virtual bool push(int x, int y);

	SDL_Rect entityRect;
	SDL_Texture* entityTexture;
	int xVel, yVel;
	int speed;
	~entity();

protected:
	SDL_Rect drawRect;
};

