#pragma once
#include "ShapeObject.h"
class Polygon : public ShapeObject
{
public:
	Polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points);
	void draw() override;
	void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
private:
	Uint8 r, g, b, a;
	double xc, yc, A;
	std::vector<Point2D>& points;
};

