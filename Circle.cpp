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