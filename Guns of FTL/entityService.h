#pragma once
#include "entity.h"
#include "resources.h"
#include "render.h"

class entityService
{
public:
	entityService();
	static void update();
	static void eventUpdate();
	static void draw();
	static bool registerEntity(entity* newEnt);
	~entityService();

private:
	static void collisionDetection();
	static void detectCollision(entity* entity1, entity* entity2);
	static std::vector<entity* > entities;
};

