#include "entityService.h"

std::vector<entity* > entityService::entities;

entityService::entityService()
{
}

void entityService::update()
{

	for (size_t i = 0; i < entities.size(); i++)
	{
		entities[i]->update();
	}

	collisionDetection();
}

void entityService::collisionDetection()
{
	//detect collisions between each entity
	//each entity is checked with each other entity only once
	for (size_t x = 0; x < entities.size(); x++)
	{
		for (size_t y = x + 1; y < entities.size() + 1; y++)
		{
			detectCollision(entities[x], entities[y]);
		}
	}
}

void entityService::eventUpdate()
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		entities[i]->eventUpdate();
	}
}

void entityService::draw()
{
	//if the entity is on the screen draw it
	for (size_t i = 0; i < entities.size(); i++) //doesn't count the element at value "size"
	{
		if (entities[i]->entityRect.x + render::xOffset >= 0 && ((entities[i]->entityRect.x + render::xOffset) + entities[i]->entityRect.w) <= render::screenWidth)
		{
			if (entities[i]->entityRect.y + render::yOffset >= 0 && ((entities[i]->entityRect.y + render::yOffset) + entities[i]->entityRect.h) <= render::screenHeight)
			{
				entities[i]->draw();
			}
		}
	}
}

bool entityService::registerEntity(entity* newEnt)
{
	if (newEnt != nullptr)
	{
		entities.push_back(newEnt);

		return true;
	}

	return false;
}

void entityService::detectCollision(entity* entity1, entity* entity2)
{

	if (entity1->entityRect.x >= entity2->entityRect.x && entity1->entityRect.x <= entity2->entityRect.x + entity2->entityRect.w)
	{
		if (entity1->entityRect.y >= entity2->entityRect.y && entity1->entityRect.y <= entity2->entityRect.y + entity2->entityRect.h)
		{
			entity1->onCollide(entity2);
		}
	}

	if (entity2->entityRect.x >= entity1->entityRect.x && entity2->entityRect.x <= entity1->entityRect.x + entity1->entityRect.w)
	{
		if (entity2->entityRect.y >= entity1->entityRect.y && entity2->entityRect.y <= entity1->entityRect.y + entity1->entityRect.h)
		{
			entity2->onCollide(entity1);
		}
	}
}

entityService::~entityService()
{
	for (int x = 0; x > int(entities.size()); x++)
	{
		delete entities[x];
	}
}
