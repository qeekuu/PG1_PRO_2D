#include "Point2D.h"
#include "Polygon.h"
#include "PrimitiveRenderer.h"
#include "math.h"
#include <cmath>
#include <vector>
Polygon::Polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points) : r{ r }, g{ g }, b{ b }, a{ a },points { points },xc{0.0},yc{0.0},A{0.0}
{
	calculateCenter();
}

void Polygon::draw()
{
	PrimitiveRenderer::draw_polygon(r,g,b,a,points);

}

void Polygon::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
	PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),xc,yc,fillColor,boundryColor);
}

void Polygon::calculateCenter()
{
	double sumX = 0;
	double sumY = 0;
	for (int i = 0; i < points.size(); i++)
	{
		sumX += points[i].getCoordinates('X');
		sumY += points[i].getCoordinates('Y');
	}
	xc = sumX / points.size();
	yc = sumY / points.size();
}

void Polygon::translate(int tx, int ty)
{
	for(int i = 0; i < points.size(); i++)
	{
		int x = points[i].getCoordinates('X');
		int y = points[i].getCoordinates('Y');
		int x2 = x + tx;
		int y2 = y + ty;
		
		// Przesunieie o wektor
		points[i].setCoordinates(x2, y2);
		calculateCenter();
	}
	

}

void Polygon::rotate(double alfa)
{
	double alfaRad = alfa * M_PI / 180.0;

	for(int i = 0; i < points.size(); i++)
	{
		int x = points[i].getCoordinates('X');
		int y = points[i].getCoordinates('Y');
		int x2 = x * cos(alfaRad) - y * sin(alfaRad);
		int y2 = x * sin(alfaRad) + y * cos(alfaRad);
		
		points[i].setCoordinates(x2, y2);

	}
	calculateCenter();
}

void Polygon::rotatePoint(double alfa, int x, int y)
{
	double alfaRad = alfa * M_PI / 180.0;
	
	for(int i = 0; i < points.size(); i++)
	{
		int x1 = points[i].getCoordinates('X');
		int y1 = points[i].getCoordinates('Y');
		int x2 = x + (x1 - x) * cos(alfaRad) - (y1 -y) * sin(alfaRad);
		int y2 = y + (x1 - x) * sin(alfaRad) + (y1 - y) * cos(alfaRad);

		points[i].setCoordinates(x2, y2);
	}
	calculateCenter();
}

void Polygon::scale(double k)
{
	for(int i = 0; i < points.size(); i++)
	{
		int x = points[i].getCoordinates('X');
		int y = points[i].getCoordinates('Y');
		int x2 = x * k;
		int y2 = y * k;

		points[i].setCoordinates(x2, y2);
	}
	calculateCenter();
}

void Polygon::scalePoint(double k, int x, int y)
{
	for(int i = 0; i < points.size(); i++)
	{
		int x1 = points[i].getCoordinates('X');
		int y1 = points[i].getCoordinates('Y');
		int x2 = x1 * k + (1 - k) * x;
		int y2 = y1 * k + (1 - k) * y;

		points[i].setCoordinates(x2, y2);
	}
	calculateCenter();
}
