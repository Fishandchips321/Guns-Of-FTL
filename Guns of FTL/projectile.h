#pragma once
#include "entity.h"
class projectile :
	public entity
{
public:
	projectile(double x, double y, double r);
	void update();
	void draw();
	~projectile();

	const int shieldDamage = 0, hullDamage = 0;
	double speed;

};

