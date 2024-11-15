#pragma once
#include "DrawableObject.h"
#include "Rectangle.h"
#include "TransformableObject.h"
#include "UpdatableObject.h"
#include "Point2D.h"
#include <SDL_stdinc.h>

class Player : public UpdatableObject, public DrawableObject, public TransformableObject
{
public:
	Player(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1,unsigned int x2, unsigned int y2,unsigned int x3, unsigned int y3,unsigned int x4, unsigned int y4);
	Rectangle& getRect()
	{
		return rectangle;
	}
	void draw() override;
private:
	Uint8 r, g, b, a;
	Rectangle rectangle;

	/* TransformableObject */
	void translate(int tx, int ty) override;
	void rotate(double alfa) override; // wzgledem poczatku ukladu
	void rotatePoint(double alfa, int x, int y) override; // wzgledem dowolnego punktu o kat alfa
	void scale(double k) override;
	void scalePoint(double k, int x, int y) override;

	/* DrawableObject */
	void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
	
	/* UpdatableObject */
	void update() override;


};
