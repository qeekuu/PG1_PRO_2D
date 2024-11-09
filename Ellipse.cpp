#include "Ellipse.h"
#include "PrimitiveRenderer.h"
Ellipse::Ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int xc, unsigned int yc, unsigned int R, unsigned int R2) : r{r},g{g},b{b},an{an},ellipseCenter{xc, yc}, R{R}, R2{R2}
{

}
void Ellipse::draw()
{
	PrimitiveRenderer::draw_ellipse(r,g,b,an,ellipseCenter.getCoordinates('X'),ellipseCenter.getCoordinates('Y'), R, R2);
}
void Ellipse::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
	PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),ellipseCenter.getCoordinates('X'), ellipseCenter.getCoordinates('Y'), fillColor, boundryColor);
}

void Ellipse::translate(int tx, int ty)
{
	ellipseCenter.setCoordinates(ellipseCenter.getCoordinates('X') + tx, ellipseCenter.getCoordinates('Y') - ty);
}

void Ellipse::rotate(double alfa)
{
	double alfaRad = alfa * M_PI / 180.0;
	
	int x1_point = ellipseCenter.getCoordinates('X');
	int y1_point = ellipseCenter.getCoordinates('Y');
	int x2_point = x1_point * cos(alfaRad) - y1_point * sin(alfaRad);
	int y2_point = x1_point * sin(alfaRad) + y1_point * cos(alfaRad);

	ellipseCenter.setCoordinates(x2_point, y2_point);
}

void Ellipse::rotatePoint(double alfa, int x, int y)
{


}

void Ellipse::scale(double k)
{
	R *= k;
	R2 *= k;
}

void Ellipse::scalePoint(double k, int x, int y)
{
	int x_point = ellipseCenter.getCoordinates('X');
	int y_point = ellipseCenter.getCoordinates('Y');

	int x2_point = x_point * k + (1 - k) * x;
	int y2_point = y_point * k + (1 - k) * y;

	ellipseCenter.setCoordinates(x2_point, y2_point);
	R *= k;
	R2 *= k;
}