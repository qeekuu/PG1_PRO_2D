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

// tx, ty - wektor przesuniecia
void Rectangle::translate(int tx, int ty)
{
	point1.setCoordinates(point1.getCoordinates('X') + tx, point1.getCoordinates('Y') - ty);
	point2.setCoordinates(point2.getCoordinates('X') + tx, point2.getCoordinates('Y') - ty);
	point3.setCoordinates(point3.getCoordinates('X') + tx, point3.getCoordinates('Y') - ty);
	point4.setCoordinates(point4.getCoordinates('X') + tx, point4.getCoordinates('Y') - ty);
}

void Rectangle::rotate(double alfa)
{
	// Przeksztalcenie kata alfa na radiany
	double alfaRad = alfa * M_PI / 180.0;

	int x1_point1 = point1.getCoordinates('X');
	int y1_point1 = point1.getCoordinates('Y');
	int x2_point1 = x1_point1 * cos(alfaRad) - y1_point1 * sin(alfaRad);
	int y2_point1 = x1_point1 * sin(alfaRad) + y1_point1 * cos(alfaRad);
	point1.setCoordinates(x2_point1, y2_point1);

	int x1_point2 = point2.getCoordinates('X');
	int y1_point2 = point2.getCoordinates('Y');
	int x2_point2 = x1_point2 * cos(alfaRad) - y1_point2 * sin(alfaRad);
	int y2_point2 = x1_point2 * sin(alfaRad) + y1_point2 * cos(alfaRad);
	point2.setCoordinates(x2_point2, y2_point2);

	int x1_point3 = point3.getCoordinates('X');
	int y1_point3 = point3.getCoordinates('Y');
	int x2_point3 = x1_point3 * cos(alfaRad) - y1_point3 * sin(alfaRad);
	int y2_point3 = x1_point3 * sin(alfaRad) + y1_point3 * cos(alfaRad);
	point3.setCoordinates(x2_point3, y2_point3);

	int x1_point4 = point4.getCoordinates('X');
	int y1_point4 = point4.getCoordinates('Y');
	int x2_point4 = x1_point4 * cos(alfaRad) - y1_point4 * sin(alfaRad);
	int y2_point4 = x1_point4 * sin(alfaRad) + y1_point4 * cos(alfaRad);
	point4.setCoordinates(x2_point4, y2_point4);

}

void Rectangle::rotatePoint(double alfa, int x, int y)
{
	// Przekszta³cenie alfa na radiany
	double alfaRad = alfa * M_PI / 180.0;

	int x1_point1 = point1.getCoordinates('X');
	int y1_point1 = point1.getCoordinates('Y');
	int x2_point1 = x + (x1_point1 - x) * cos(alfaRad) - (y1_point1 - y) * sin(alfaRad);
	int y2_point1 = y + (x1_point1 - x) * sin(alfaRad) + (y1_point1 - y) * cos(alfaRad);
	point1.setCoordinates(x2_point1, y2_point1);

	int x1_point2 = point2.getCoordinates('X');
	int y1_point2 = point2.getCoordinates('Y');
	int x2_point2 = x + (x1_point2 - x) * cos(alfaRad) - (y1_point2 - y) * sin(alfaRad);
	int y2_point2 = y + (x1_point2 - x) * sin(alfaRad) + (y1_point2 - y) * cos(alfaRad);
	point2.setCoordinates(x2_point2, y2_point2);

	int x1_point3 = point3.getCoordinates('X');
	int y1_point3 = point3.getCoordinates('Y');
	int x2_point3 = x + (x1_point3 - x) * cos(alfaRad) - (y1_point3 - y) * sin(alfaRad);
	int y2_point3 = y + (x1_point3 - x) * sin(alfaRad) + (y1_point3 - y) * cos(alfaRad);
	point3.setCoordinates(x2_point3, y2_point3);

	int x1_point4 = point4.getCoordinates('X');
	int y1_point4 = point4.getCoordinates('Y');
	int x2_point4 = x + (x1_point4 - x) * cos(alfaRad) - (y1_point4 - y) * sin(alfaRad);
	int y2_point4 = y + (x1_point4 - x) * sin(alfaRad) + (y1_point4 - y) * cos(alfaRad);
	point4.setCoordinates(x2_point4, y2_point4);
}

void Rectangle::scale(double k)
{
	int x1_point1 = point1.getCoordinates('X');
	int y1_point1 = point1.getCoordinates('Y');
	int x2_point1 = x1_point1 * k;
	int y2_point1 = y1_point1 * k;
	point1.setCoordinates(x2_point1, y2_point1);

	int x1_point2 = point2.getCoordinates('X');
	int y1_point2 = point2.getCoordinates('Y');
	int x2_point2 = x1_point2 * k;
	int y2_point2 = y1_point2 * k;
	point2.setCoordinates(x2_point2, y2_point2);

	int x1_point3 = point3.getCoordinates('X');
	int y1_point3 = point3.getCoordinates('Y');
	int x2_point3 = x1_point3 * k;
	int y2_point3 = y1_point3 * k;
	point3.setCoordinates(x2_point3, y2_point3);

	int x1_point4 = point4.getCoordinates('X');
	int y1_point4 = point4.getCoordinates('Y');
	int x2_point4 = x1_point4 * k;
	int y2_point4 = y1_point4 * k;
	point4.setCoordinates(x2_point4, y2_point4);
}

void Rectangle::scalePoint(double k, int x, int y)
{
	int x1_point1 = point1.getCoordinates('X');
	int y1_point1 = point1.getCoordinates('Y');
	int x2_point1 = x1_point1 * k + (1 - k) * x;
	int y2_point1 = y1_point1 * k + (1 - k) * y;
	point1.setCoordinates(x2_point1, y2_point1);

	int x1_point2 = point2.getCoordinates('X');
	int y1_point2 = point2.getCoordinates('Y');
	int x2_point2 = x1_point2 * k + (1 - k) * x;
	int y2_point2 = y1_point2 * k + (1 - k) * y;
	point2.setCoordinates(x2_point2, y2_point2);

	int x1_point3 = point3.getCoordinates('X');
	int y1_point3 = point3.getCoordinates('Y');
	int x2_point3 = x1_point3 * k + (1 - k) * x;
	int y2_point3 = y1_point3 * k + (1 - k) * y;
	point3.setCoordinates(x2_point3, y2_point3);

	int x1_point4 = point4.getCoordinates('X');
	int y1_point4 = point4.getCoordinates('Y');
	int x2_point4 = x1_point4 * k + (1 - k) * x;
	int y2_point4 = y1_point4 * k + (1 - k) * y;
	point4.setCoordinates(x2_point4, y2_point4);
}