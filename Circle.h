#pragma once
#include "ShapeObject.h"
#include "Point2D.h"
class Circle : public ShapeObject
{
public:
	Circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int x, unsigned int y, unsigned int R);
	void draw() override;
	void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
private:
	Point2D circleCenter;
	unsigned int R;
	Uint8 r, g, b, an;
};

