#pragma once
#include "ShapeObject.h"
#include "Point2D.h"
class Circle : public ShapeObject
{
public:
	Circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int x, unsigned int y, unsigned int R);
	void draw() override;
	void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
	void translate(int tx, int ty) override;
	void rotate(double alfa) override;
	void rotatePoint(double alfa, int x, int y) override;
	void scale(double k) override;
	void scalePoint(double k, int x, int y) override;
private:
	Point2D circleCenter;
	unsigned int R;
	Uint8 r, g, b, an;
};

