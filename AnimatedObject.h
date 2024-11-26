#pragma once
#include "GameObject.h"
#include "BitmapObject.h"

class AnimatedObject : public BitmapObject
{
public:
	virtual void animate() = 0;
private:

};

