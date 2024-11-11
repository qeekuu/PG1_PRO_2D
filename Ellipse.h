#pragma once
#include "ShapeObject.h"
class Ellipse : public ShapeObject
{
public:
	Ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int xc, unsigned int yc, unsigned int R, unsigned int R2);
	void draw() override;
	void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
	void translate(int tx, int ty) override;
	void rotate(double alfa) override;
	void rotatePoint(double alfa, int x, int y) override;
	void scale(double k) override;
	void scalePoint(double k, int x, int y) override;
private:
	Uint8 r,  g,  b,  an;
	unsigned int R, R2;
	Point2D ellipseCenter;
	double rotationAngle;
};

