#pragma once
#include "GameObject.h"
class TransformableObject : virtual public GameObject
{
public:
	virtual void translate(int tx, int ty) = 0;
	virtual void rotate(double alfa) = 0; // wzgledem poczatku ukladu
	virtual void rotatePoint(double alfa, int x, int y) = 0; // wzgledem dowolnego punktu o kat alfa
	virtual void scale(double k) = 0;
	virtual void scalePoint(double k, int x, int y) = 0;

};

