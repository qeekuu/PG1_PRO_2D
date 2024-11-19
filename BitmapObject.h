#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

class BitmapObject : public DrawableObject, public TransformableObject
{
public:
	virtual void draw() = 0;

private:
};

