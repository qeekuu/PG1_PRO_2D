#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include <iostream>

Point2D::Point2D(int x, int y) : x{ x }, y{ y }
{

}

int Point2D::getCoordinates(char sign)
{
	switch (sign)
	{
	case 'X':
		return x;
		break;
	case 'Y':
		return y;
		break;
	default:
		break;
	}
}

void Point2D::setCoordinates(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
}
