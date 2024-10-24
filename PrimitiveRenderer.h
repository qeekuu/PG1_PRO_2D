#pragma once
#include <iostream>
#include "Engine.h"
#include <SDL.h>
#include <vector>
class PrimitiveRenderer
{
public:
	static void setWindowColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void draw_point(Uint8 r, Uint8 g, Uint8 b, Uint8 a,unsigned int x, unsigned int y);
	void draw_rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4);
	void draw_triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3);
	void draw_line(Uint8 r, Uint8 g, Uint8 b, Uint8 a,  int x1,  int y1,  int x2,  int y2);
	void draw_circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R);
	void draw_ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R, int R2);
	static void render();
};

