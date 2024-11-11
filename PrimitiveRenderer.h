#pragma once
#include <iostream>
#include "Engine.h"
#include <SDL2/SDL.h>
#include <vector>
#include "Point2D.h"
class PrimitiveRenderer
{
public:
	static void setWindowColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static void draw_point(Uint8 r, Uint8 g, Uint8 b, Uint8 a,unsigned int x, unsigned int y);
	static void draw_rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4);
	static void draw_triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3);
	static void draw_line(Uint8 r, Uint8 g, Uint8 b, Uint8 a,  int x1,  int y1,  int x2,  int y2);
	static void draw_circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R);
	static void draw_ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R, int R2);
	static void draw_polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points);
	static bool segmentIntersect(Point2D point1,Point2D point2, Point2D point3, Point2D point4);
	static int determinant3x3(int mat[3][3]);
	static SDL_Color fillColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static SDL_Color boundaryColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static void RiteracyjnyBoundaryFill(SDL_Renderer* renderer, int x, int y, SDL_Color fillColor, SDL_Color boundaryColor);
	static void render();
};

