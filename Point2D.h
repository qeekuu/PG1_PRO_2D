#pragma once
#include <iostream>

class Point2D
{
public:
	int getCoordinates(char sign);
	void setCoordinates(unsigned int x, unsigned int y);
	Point2D(int x, int y);
private:
	int x, y;
};

