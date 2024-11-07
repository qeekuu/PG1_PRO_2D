#include "Rectangle.h"
#include "PrimitiveRenderer.h"
void Rectangle::draw(std::vector<Point2D> points, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	PrimitiveRenderer rectangle;
	int x1 = points[0].getCoordinates('X'), 
		x2 = points[1].getCoordinates('X'), 
		x3 = points[2].getCoordinates('X'), 
		x4 = points[3].getCoordinates('X'), 
		y1 = points[0].getCoordinates('Y'),
		y2 = points[1].getCoordinates('Y'),
		y3 = points[2].getCoordinates('Y'),
		y4 = points[3].getCoordinates('Y');
	rectangle.draw_rectangle(r,g,b,a,x1,y1,x2,y2,x3,y3,x4,y4);
}
