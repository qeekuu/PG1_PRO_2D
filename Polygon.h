#pragma once
#include "Point2D.h"
#include "ShapeObject.h"
#include <vector>
class Polygon : public ShapeObject
{
public:
	Polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points);
	void draw() override;
	void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
	void translate(int tx, int ty) override;
	void rotate(double alfa) override;
	void rotatePoint(double alfa, int x, int y) override;
	void scale(double k) override;
	void scalePoint(double k, int x, int y) override;
private:
	Uint8 r, g, b, a;
	double xc, yc, A = 0.0;
	std::vector<Point2D>& points;
	void calculateCenter();
};

