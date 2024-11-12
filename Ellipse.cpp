#include "Ellipse.h"
#include "PrimitiveRenderer.h"
#include <cmath>
Ellipse::Ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int xc, unsigned int yc, unsigned int R, unsigned int R2) : r{r},g{g},b{b},an{an},ellipseCenter{xc, yc}, R{R}, R2{R2}, rotationAngle{0.0}
{

}
void Ellipse::draw()
{
	PrimitiveRenderer::draw_ellipse(r, g, b, an, rotationAngle, ellipseCenter.getCoordinates('X'), ellipseCenter.getCoordinates('Y'), R, R2);
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
	/* float a = 0.0; */
	
	/* int x = R * cos(a); */
	/* int y = R2 * sin(a); */
	/* int xc = ellipseCenter.getCoordinates('X'); */
	/* int yc = ellipseCenter.getCoordinates('Y'); */

	/* int x2 = x * cos(rotationAngle) - y * sin(rotationAngle); */
	/* int y2 = x * sin(rotationAngle) + y * cos(rotationAngle); */

	/* int x1_point = xc + x; */
	/* int x2_point = xc - x; */
	/* int y1_point = yc + y; */
	/* int y2_point = yc - y; */

	/* ellipseCenter.setCoordinates(x1_point, y1_point); */
	/* ellipseCenter.setCoordinates(x2_point, y1_point); */
	/* ellipseCenter.setCoordinates(x1_point, y2_point); */
	/* ellipseCenter.setCoordinates(x2_point, y2_point); */
	
	rotationAngle +=alfaRad;
	std::cout << "Current rotation angle (radians): " << rotationAngle << std::endl;
}

void Ellipse::rotatePoint(double alfa, int x, int y)
{
	double alfaRad = alfa * M_PI / 180.0;

	int xc = ellipseCenter.getCoordinates('X');
	int yc = ellipseCenter.getCoordinates('Y');
	
	/* rotationAngle += alfaRad; */

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
