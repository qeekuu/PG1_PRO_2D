#pragma once
#include "ShapeObject.h"
class Ellipse : public ShapeObject
{
public:
	Ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R, int R2);
	void draw() override;
	void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
private:
	Uint8 r,  g,  b,  an;
	int xc, yc, R, R2;
};

