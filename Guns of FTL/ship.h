#pragma once
#include "shipEntity.h"
#include "shipInterior.h"
class ship
{
public:
	ship();
	~ship();
	shipEntity ent;
	shipInterior interior;

	const int maxHP = 0, maxShields = 0;
	int HP, shields;
	double speed;
	double x, y;
	SDL_Rect drawRect, boundRect;
};

