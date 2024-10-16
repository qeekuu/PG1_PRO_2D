#pragma once
#include <iostream>
#include "Engine.h"
#include <SDL.h>
#include <vector>
class PrimitiveRenderer
{
public:
	static void setWindowColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void draw_point(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void draw_rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y, int width, int height);
	void draw_triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a,int x1,int y1,int x2,int y2,int x3,int y3);
	void draw_line(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x1, int y1, int x2, int y2);
	static void render();
};

