#include "Polygon.h"
#include "PrimitiveRenderer.h"
#include "math.h"
Polygon::Polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points) : r{ r }, g{ g }, b{ b }, a{ a },points { points },xc{0},yc{0},A{0}
{
	//A = 0.5 * ( for(int i = 0;i<n-1;i++)
	//			{
	//				xi*yi+1 - x1+1 * yi
	//			} )
	// 
	// xc = 1/(6 * A) * for(int i = 0;i<n-1;i++)
	//					{
	//						(xi + xi+1) * (xi * yi+1 - xi+1 * y1)
	//					}
	// yc = 1/(6 * A) * for(int i = 0;i<n-1;i++)
	//					{
	//						(yi + yi+1) * (xi * yi+1 - xi+1 * y1)
	//					}
	//Obliczanie srodka dowolnego wielokata
	//A - Pole dowolnego wielokata
	for (int i = 1; i < points.size(); i++)
	{
		A += 0.5 * ((points[i - 1].getCoordinates('X') * points[i].getCoordinates('Y')) - (points[i].getCoordinates('X') * points[i - 1].getCoordinates('Y')));
	}
	// Zamkniecie wielokata dodajac ostatni punkt z pierwszym
	A += 0.5 * (points[points.size() - 1].getCoordinates('X') * points[0].getCoordinates('Y')) - (points[0].getCoordinates('X') * points[points.size() - 1].getCoordinates('Y'));
	//pomxc - zmienna pomocnicza do obliczenia xc - srodek x dowolnego wielokata
	//pomyc - zmienna pomocnicza do obliczenia yc - srodek y dowolnego wielokata
	double pomxc = 0;
	double pomyc = 0;
	//Obliczanie pomxc,pomyc zgodznie ze wzorem na srodek dowolnego wielokata
	for (int j = 1; j < points.size(); j++)
	{
		pomxc += (points[j - 1].getCoordinates('X') + points[j].getCoordinates('X')) * ((points[j - 1].getCoordinates('X') * points[j].getCoordinates('Y')) - (points[j].getCoordinates('X') * points[j - 1].getCoordinates('Y')));
		pomyc += (points[j - 1].getCoordinates('Y') + points[j].getCoordinates('Y')) * ((points[j - 1].getCoordinates('X') * points[j].getCoordinates('Y')) - (points[j].getCoordinates('X') * points[j - 1].getCoordinates('Y')));
	}
	// Zamkniecie wilokata obliczajac przedostatni punkt z ostatnim
	pomxc += (points[points.size() - 1].getCoordinates('X') + points[0].getCoordinates('X')) * ((points[points.size() - 1].getCoordinates('X') * points[0].getCoordinates('Y')) - (points[0].getCoordinates('X') * points[points.size() - 1].getCoordinates('Y')));
	pomyc += (points[points.size() - 1].getCoordinates('Y') + points[0].getCoordinates('Y')) * ((points[points.size() - 1].getCoordinates('X') * points[0].getCoordinates('Y')) - (points[0].getCoordinates('X') * points[points.size() - 1].getCoordinates('Y')));
	//xc - srodek x wielokata (obliczone za pomoca wzoru)
	xc = pomxc / (6*A);
	//yc - srodek y wielokata (obliczone za pomoca wozru) 
	yc = pomyc / (6*A);
}

void Polygon::draw()
{
	PrimitiveRenderer::draw_polygon(r,g,b,a,points);

}

void Polygon::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
	PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(),xc,yc,fillColor,boundryColor);
}

void Polygon::translate(int tx, int ty)
{


}

void Polygon::rotate(double alfa)
{


}

void Polygon::rotatePoint(double alfa, int x, int y)
{


}

void Polygon::scale(double k)
{

}

void Polygon::scalePoint(double k, int x, int y)
{


}