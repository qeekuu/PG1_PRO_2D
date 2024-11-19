#pragma once
#include "GameObject.h"

class AnimatedObject : public GameObject
{
public:
	virtual void animate() = 0;
private:

};

