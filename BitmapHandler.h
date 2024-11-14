#pragma once
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <string>

class BitmapHandler
{
public:

private:
	/* Ładowanie bitmapy jako tekstury */
	SDL_Texture *bmpSurface(const std::string& filePath, SDL_Renderer *renderer);
};
