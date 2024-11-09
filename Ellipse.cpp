#include "Ellipse.h"
#include "PrimitiveRenderer.h"
Ellipse::Ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R, int R2) : r{r},g{g},b{b},an{an},xc{xc},yc{yc},R{R},R2{R2}
{

}
void Ellipse::draw()
{
	PrimitiveRenderer::draw_ellipse(r,g,b,an,xc,yc,R,R2);
}
void Ellipse::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
	PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),xc,yc,fillColor,boundryColor);
}