#pragma once
#include "render.h"
#include "projectile.h"
class shipGun
{
public:
	shipGun();
	void update();
	void draw();
	~shipGun();

	enum gunTypes
	{
		none,
		smallProjectile,
		largeProjectile,
		smallEnergy,
		largeEnergy
	};

	enum hardPointPosition
	{
		none,
		front,
		back,
		left,
		right
	};

	gunTypes type = gunTypes::none;
	hardPointPosition position = hardPointPosition::none;

	int fireRate;

	projectile shot;

	SDL_Rect drawRect;
	double rotation;
};

