#include "LineSegment.h"
#include "Point2D.h"
LineSegment::LineSegment(int x,int y,int x2,int y2) : point(x,y),point2(x2,y2)
{

}

Point2D& LineSegment::getStart()
{
	return point;
}

Point2D& LineSegment::getEnd()
{
	return point2;
}
