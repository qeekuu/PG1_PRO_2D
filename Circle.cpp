#include "Circle.h"
#include "PrimitiveRenderer.h"

Circle::Circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int x, unsigned int y, unsigned int R)
	: r{ r }, g{ g }, b{ b }, an{ an }, circleCenter{ x,y }, R{ R }
{

}

void Circle::draw()
{
	PrimitiveRenderer::draw_circle(r,g,b,an,circleCenter.getCoordinates('X'),circleCenter.getCoordinates('Y'),R);
}

void Circle::fill(SDL_Color fillColor,SDL_Color boundryColor)
{
	PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),circleCenter.getCoordinates('X'),circleCenter.getCoordinates('Y'),fillColor,boundryColor);
}

void Circle::translate(int tx, int ty)
{
	circleCenter.setCoordinates(circleCenter.getCoordinates('X') + tx, circleCenter.getCoordinates('Y') - ty);
}

void Circle::rotate(double alfa)
{
	// ?
	double alfaRad = alfa * M_PI / 180.0;
	
	int x_point = circleCenter.getCoordinates('X') + R * cos(alfaRad);
	int y_point = circleCenter.getCoordinates('Y') + R * sin(alfaRad);
	circleCenter.setCoordinates(x_point, y_point);
}

void Circle::rotatePoint(double alfa, int x, int y)
{
	// ?
	double alfaRad = alfa * M_PI / 180.0;

	int x_point = circleCenter.getCoordinates('X');
	int y_point = circleCenter.getCoordinates('Y');

	int x_rotated = x_point + (x - x_point) * cos(alfaRad) - (y - y_point) * sin(alfaRad);
	int y_rotated = y_point + (x - x_point) * sin(alfaRad) + (y - y_point) * cos(alfaRad);
	circleCenter.setCoordinates(x_rotated, y_rotated);

}

void Circle::scale(double k)
{
	R = R * k;
}

void Circle::scalePoint(double k, int x, int y)
{
	int x_point = circleCenter.getCoordinates('X');
	int y_point = circleCenter.getCoordinates('Y');

	int x2_point = x_point * k + (1 - k) * x;
	int y2_point = y_point * k + (1 - k) * y;

	circleCenter.setCoordinates(x2_point, y2_point);
	R *= k;

}
