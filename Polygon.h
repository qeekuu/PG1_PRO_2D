#pragma once
#include "ShapeObject.h"
class Polygon : public ShapeObject
{
public:
	void draw(std::vector<Point2D> points, Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
};

