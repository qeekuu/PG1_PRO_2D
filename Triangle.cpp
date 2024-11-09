#include "Triangle.h"
#include "PrimitiveRenderer.h"

Triangle::Triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3)
	: r{ r }, g{ g }, b{ b }, a{ a }, point1{x1, y1}, point2{ x2, y2 }, point3{ x3, y3 }, xc{ 0 }, yc{ 0 }
{

}

void Triangle::draw()
{
	PrimitiveRenderer::draw_triangle(r, g, b, a, point1.getCoordinates('X'), point1.getCoordinates('Y'),
		point2.getCoordinates('X'), point2.getCoordinates('Y'), point3.getCoordinates('X'), point3.getCoordinates('Y'));
}

void Triangle::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
	//xc,yc - wspolrzedne srodek trojkata
	//Obliczanie wspolrzednych srodka trojkata
	xc = (point1.getCoordinates('X') + point2.getCoordinates('X') + point3.getCoordinates('X')) / 3;
	yc = (point1.getCoordinates('Y') + point2.getCoordinates('Y') + point3.getCoordinates('Y')) / 3;
	PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(), xc, yc, fillColor, boundryColor);
}
