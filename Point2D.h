#pragma once
#include "PrimitiveRenderer.h"
#include <iostream>

class Point2D : public PrimitiveRenderer
{
public:
	void getCoordinates();
	void setCoordinates(unsigned int x, unsigned int y);
	void drawPoint2D(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x, unsigned int y);
private:
	int x, y;
};

