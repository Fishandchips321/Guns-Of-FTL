#pragma once
#include "entity.h"
#include "render.h"
class shipEntity : public entity
{
public:
	shipEntity();
	void update();
	void draw();
	~shipEntity();
};

