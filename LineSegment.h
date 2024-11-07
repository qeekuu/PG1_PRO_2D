#pragma once
#include "Point2D.h"
#include <iostream>
class LineSegment
{
public:
	LineSegment(int x, int y, int x2, int y2);
	Point2D& getStart();
	Point2D& getEnd();
private:
	Point2D point,point2;
};


