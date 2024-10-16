#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include <iostream>

void Point2D::getCoordinates()
{
	std::cout << "X: " << x << std::endl;
	std::cout << "Y: " << y << std::endl;
}

void Point2D::setCoordinates(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
}

void Point2D::drawPoint2D(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x, unsigned int y)
{
	Point2D point;
	point.PrimitiveRenderer::draw_point(r,g,b,a,x,y);
}