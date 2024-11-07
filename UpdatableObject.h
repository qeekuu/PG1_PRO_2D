#pragma once
#include "GameObject.h"
class UpdatableObject : public GameObject
{
	public:
	virtual void update() = 0;
};

