#pragma once
#include "GameObject.h"
#include <vector>
#include "Point2D.h"
#include <SDL.h>
class DrawableObject : virtual public GameObject
{
public:
	virtual void draw(std::vector<Point2D> points, Uint8 r, Uint8 g, Uint8 b, Uint8 a) = 0;
};

