#include "BitmapHandler.h"

/* Ładowanie bitmapy jako tekstury */
SDL_Texture *bmpSurface(const std::string& filePath, SDL_Renderer *renderer)
{
	SDL_Surface *bmpSurface = SDL_LoadBMP(filePath.c_str());

	if(bmpSurface == nullptr)			
		std::cerr << "SDL_loadBMP error: " << SDL_GetError() << std::endl;
	return nullptr;

	/* Konwersja powierzchni na teksture */
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, bmpSurface);
	SDL_FreeSurface(bmpSurface);

	if(texture == nullptr)
		std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;

}

