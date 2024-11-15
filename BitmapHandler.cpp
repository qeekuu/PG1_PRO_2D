#include "BitmapHandler.h"
#include "Engine.h"

BitmapHandler::BitmapHandler(){}

/*Tworzenie powierzchni*/
SDL_Surface *BitmapHandler::createSurface(int width, int height)
{
	// Tworzenie powierzchni o głębi koloru 32-bitowej z odpowiednimi maskami kolorów dla kanałów RGBA
	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
	if (surface == nullptr)
		std::cerr << "Error: Cannot creat a surface." << std::endl;

	return surface;
}

/* Ładowanie bitmapy jako tekstury z pliku (BMP only)*/
SDL_Texture *BitmapHandler::bmpSurface(const char* filePath, SDL_Renderer *renderer,SDL_Rect *pt)
{
	SDL_Surface *bmpSurface = SDL_LoadBMP(filePath);

	if (bmpSurface == nullptr)
	{
		std::cerr << "SDL_loadBMP error: " << SDL_GetError() << std::endl;
		return nullptr;
	}
		
	
	/* Konwersja powierzchni na teksture */
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, bmpSurface);
	SDL_FreeSurface(bmpSurface);

	if (texture == nullptr)
	{
		std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
		return nullptr;
	}

	SDL_RenderCopy(renderer, texture, nullptr, pt);
	return texture;
}

/*Zapisywanie bitmapy*/
int BitmapHandler::saveSurfaceAsBMP(SDL_Surface* surface, const char* filePath)
{
	if (surface == nullptr)
	{
		std::cerr << "Error: Surface is equal to null, cannot save to BMP." << std::endl;
		return -1;
	}

	int result = SDL_SaveBMP(surface, filePath);
	if (result != 0)
	{
		std::cerr << "SDL_SaveBMP error: " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "Bitmap saved successfully." << std::endl;
	}
	return result;
}

/*Kopiowanie bitmapy*/

int BitmapHandler::copyBitmapSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect)
{
	if (src == nullptr)
	{
		std::cerr << "Error: Surface does not exist." << std::endl;
		return -1;
	}

	if (dst == nullptr)
	{
		std::cerr << "Error: Destination surdace does not exist" << std::endl;
		return -1;
	}

	int result = SDL_BlitSurface(src, srcrect, dst, dstrect);
	if (result != 0)
	{
		std::cerr << "SDL_BlitSurface error: " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "Bitmap copied successfully." << std::endl;
	}
	return result;
}

/*Usuwanie tekstury*/
void BitmapHandler::deleteTexture(SDL_Texture* texture)
{
	if(texture != nullptr)
		SDL_DestroyTexture(texture);
	texture = nullptr;
}

/*Usuwanie powierzchni*/
void BitmapHandler::deleteSurface(SDL_Surface* surface)
{
	if(surface != nullptr)
		SDL_FreeSurface(surface);
	surface = nullptr;
}


