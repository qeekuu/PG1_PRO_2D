#include "Rectangle.h"
#include "PrimitiveRenderer.h"

Rectangle::Rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4)
	: r{ r }, g{ g }, b{ b }, a{ a }, point1{ x1,y1 }, point2{ x2, y2 }, point3{ x3, y3 }, point4{ x4, y4 }, xc{0}, yc{0}
{

}

void Rectangle::draw()
{
	PrimitiveRenderer::draw_rectangle(r,g,b,a,point1.getCoordinates('X'), point1.getCoordinates('Y'),
		point2.getCoordinates('X'), point2.getCoordinates('Y'), point3.getCoordinates('X'), point3.getCoordinates('Y'), point4.getCoordinates('X'), point4.getCoordinates('Y'));
}

void Rectangle::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
	//xc,yc - wspolrzedne srodka
	// Obliczanie srodka prostokata
	xc = (point1.getCoordinates('X') + point2.getCoordinates('X') + point3.getCoordinates('X') + point4.getCoordinates('X')) / 4;
	yc = (point1.getCoordinates('Y') + point2.getCoordinates('Y') + point3.getCoordinates('Y') + point4.getCoordinates('Y')) / 4;
	PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),xc,yc,fillColor,boundryColor);
}
