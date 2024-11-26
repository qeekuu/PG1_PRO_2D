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


/*Animowanie sprite'ów*/
void BitmapHandler::animateBMPSprite(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect** spriteClips, int numDirections, int direction, int& currentFrame, SDL_Rect* dstRect, int frameDelay, const int framesPerDirection) 
{
	static Uint32 lastTime = SDL_GetTicks();

	Uint32 currentTime = SDL_GetTicks();
	if (currentTime > lastTime + frameDelay) {
		currentFrame = (currentFrame + 1) % framesPerDirection;
		lastTime = currentTime;
	}

	if (direction >= 0 && direction < numDirections && spriteClips[direction]) {
		SDL_RenderCopy(renderer, texture, &spriteClips[direction][currentFrame], dstRect);
	}
}



/*Funkcja dzieląca sprite sheet na klatki*/
SDL_Rect** BitmapHandler::createSpriteClips(int numDirections, int framesPerDirection, int frameWidth, int frameHeight, int* directionMapping) 
{
	// Alokacja pamięci dla tablicy wskaźników
	SDL_Rect** spriteClips = new SDL_Rect * [numDirections];

	for (int dir = 0; dir < numDirections; ++dir) {
		spriteClips[dir] = new SDL_Rect[framesPerDirection];

		int mappedDir = directionMapping ? directionMapping[dir] : dir;

		for (int frame = 0; frame < framesPerDirection; ++frame) {
			spriteClips[dir][frame].x = frame * frameWidth;
			spriteClips[dir][frame].y = mappedDir * frameHeight;
			spriteClips[dir][frame].w = frameWidth;
			spriteClips[dir][frame].h = frameHeight;
		}
	}

	return spriteClips;
}

/*Funkcja do czyszczenia pamięci*/
void BitmapHandler::freeSpriteClips(SDL_Rect** spriteClips, int numDirections) {
	for (int dir = 0; dir < numDirections; ++dir) {
		delete[] spriteClips[dir];
	}
	delete[] spriteClips;
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


