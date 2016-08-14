#pragma once
#include "shipHardPoint.h"
#include "render.h"
class shipInterior
{
public:
	shipInterior();
	void update();
	void draw();
	~shipInterior();

	shipHardPoint hardPoints[1];
};

