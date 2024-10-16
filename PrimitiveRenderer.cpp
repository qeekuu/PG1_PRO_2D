#include "PrimitiveRenderer.h"
#include <iostream>
#include "Engine.h"
#include <SDL.h>
#include <SDL_rect.h>
#include <math.h>
void PrimitiveRenderer::setWindowColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(Engine::getInstance()->renderer, r, g, b, a);
	SDL_RenderClear(Engine::getInstance()->renderer);
	
}

void PrimitiveRenderer::draw_point(Uint8 r, Uint8 g, Uint8 b, Uint8 a,unsigned int x,unsigned int y)
{
	SDL_SetRenderDrawColor(Engine::getInstance()->renderer, r, g, b, a);
	SDL_RenderDrawPoint(Engine::getInstance()->renderer, x, y);
	
}

void PrimitiveRenderer::draw_rectangle(Uint8 r, Uint8 g,Uint8 b, Uint8 a, unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	SDL_Rect rect = { x, y, width, height };
	SDL_SetRenderDrawColor(Engine::getInstance()->renderer,r,g,b,a);
	SDL_RenderDrawRect(Engine::getInstance()->renderer, &rect);
	
}

void PrimitiveRenderer::draw_triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3)
{
	SDL_SetRenderDrawColor(Engine::getInstance()->renderer, r, g, b, a);
	SDL_RenderDrawLine(Engine::getInstance()->renderer, x1, y1, x2, y2);
	SDL_RenderDrawLine(Engine::getInstance()->renderer, x2, y2, x3, y3);
	SDL_RenderDrawLine(Engine::getInstance()->renderer, x3, y3, x1, y1);
}

void PrimitiveRenderer::draw_line(Uint8 r, Uint8 g, Uint8 b, Uint8 a,  int x1,  int y1,  int x2,  int y2)
{
	int x;
	float dy, dx, y, m;

	dy = abs(y2 - y1);
	dx = abs(x2 - x1);
	m = dy/dx;
	y = y1;
	for (x = x1; x <= x2; x++)
	{
		SDL_SetRenderDrawColor(Engine::getInstance()->renderer, r, g, b, a);
		SDL_RenderDrawPoint(Engine::getInstance()->renderer, x, (int)y + 0.5);
		y += m;
	}
}

void PrimitiveRenderer::render()
{
	SDL_RenderPresent(Engine::getInstance()->renderer);
}