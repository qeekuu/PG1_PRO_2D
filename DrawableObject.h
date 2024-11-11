#pragma once
#include "GameObject.h"
#include <vector>
#include "Point2D.h"
#include <SDL2/SDL.h>
class DrawableObject : virtual public GameObject
{
public:
	virtual void draw() = 0;
	virtual void fill(SDL_Color fillColor, SDL_Color boundryColor) = 0;
};

