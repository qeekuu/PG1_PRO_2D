#include "Point2D.h"
#include <iostream>

Point2D::Point2D(unsigned int x,unsigned  int y) : x{ x }, y{ y }
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
		return -1;
		break;
	}
}

void Point2D::setCoordinates(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
}
