#include "PrimitiveRenderer.h"
#include <iostream>
#include "Engine.h"
#include <SDL.h>
#include <SDL_rect.h>
#include <math.h>
void PrimitiveRenderer::setWindowColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
	SDL_RenderClear(Engine::getInstance()->getRenderer());
	
}

void PrimitiveRenderer::draw_point(Uint8 r, Uint8 g, Uint8 b, Uint8 a,unsigned int x,unsigned int y)
{
	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
	SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), x, y);
	
}

void PrimitiveRenderer::draw_rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4)
{
	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(),r,g,b,a);
	draw_line(r, g, b, a, x1, y1, x2, y2);
	draw_line(r, g, b, a, x2, y2, x3, y3);
	draw_line(r, g, b, a, x3, y3, x4, y4);
	draw_line(r, g, b, a, x4, y4, x1, y1);
}

void PrimitiveRenderer::draw_triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3)
{
	SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
	draw_line(r,g,b,a,x1,y1,x2,y2);
	draw_line(r, g, b, a, x2, y2, x3, y3);
	draw_line(r, g, b, a, x3, y3, x1, y1);
}

void PrimitiveRenderer::draw_line(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;  // Kierunek wzrostu x
    int sy = (y1 < y2) ? 1 : -1;  // Kierunek wzrostu y
    int err = dx - dy;            // Ró¿nica b³êdu

    while (true)
    {
        SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), x1, y1);  // Rysujemy punkt

        // Sprawdzamy, czy dotarliœmy do koñca linii
        if (x1 == x2 && y1 == y2) 
        {
            break;
        }

        int e2 = 2 * err;  // Podwajamy b³¹d

        // Sprawdzamy, czy poruszaæ siê w poziomie
        if (e2 > -dy) 
        {
            err -= dy;
            x1 += sx;
        }

        // Sprawdzamy, czy poruszaæ siê w pionie
        if (e2 < dx) 
        {
            err += dx;
            y1 += sy;
        }
    }
}

void PrimitiveRenderer::draw_circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R)
{
    float a = 0.0, step;
    int x, y;
    step = 1.0 / R;
    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, an);
    for (a ; a < M_PI/4; a += step) 
    {
        x =  R * cos(a) + 0.5; 
        y =  R * sin(a) + 0.5; 
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc+y,xc-x);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc+x,yc-y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc+x,yc+y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc+y,xc+x);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc-y,xc+x);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc-x,yc+y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc-x,yc-y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc-y,xc-x);
    }
}

void PrimitiveRenderer::draw_ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R, int R2)
{
    float a = 0.0;
    int x, y;
    float step = M_PI / (4 * std::max(R, R2));  

    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, an);

    for (a = 0; a < M_PI / 2; a += step)  
    {
        x = R * cos(a) + 0.5;  
        y = R2 * sin(a) + 0.5;
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x, yc + y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x, yc + y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x, yc - y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x, yc - y);
    }
}

void PrimitiveRenderer::render()
{
	SDL_RenderPresent(Engine::getInstance()->getRenderer());
}