#pragma once
#include <iostream>

class Point2D
{
public:
	int getCoordinates(char sign);
	void setCoordinates(unsigned int x, unsigned int y);
	void setCoordinatesX(unsigned int x);
	void setCoordinatesY(unsigned int y);
	Point2D(unsigned int x,unsigned int y);
private:
	unsigned int x, y;
};

