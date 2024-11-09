#pragma once
#include "ShapeObject.h"
#include "Point2D.h"
class Rectangle : public ShapeObject
{
	public:
		Rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4);
		void draw() override;
		void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
	private:
		Point2D point1, point2, point3, point4;
		Uint8 r, g, b, a;
		unsigned int xc, yc;
};

