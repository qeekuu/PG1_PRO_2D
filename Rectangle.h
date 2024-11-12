#pragma once
#include "ShapeObject.h"
#include "Point2D.h"
class Rectangle : public ShapeObject
{
	public:
		Rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4);
		void draw() override;
		void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
		void translate(int tx, int ty) override;
		void rotate(double alfa) override;
		void rotatePoint(double alfa, int x, int y) override;
		void scale(double k) override;
		void scalePoint(double k, int x, int y) override;
		Point2D& getPoint1()	
		{
			return point1;
		}
		Point2D& getPoint2()	
		{
			return point2;
		}
		Point2D& getPoint3()	
		{
			return point3;
		}
		Point2D& getPoint4()	
		{
			return point4;
		}
	private:
		Point2D point1, point2, point3, point4;
		Uint8 r, g, b, a;
		unsigned int xc, yc;
};

