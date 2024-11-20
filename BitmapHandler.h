#pragma once
#include <iostream>
#include <SDL.h>
#include <string>

class BitmapHandler
{
public:
	BitmapHandler();

	/*Tworzenie powierzchni*/
	SDL_Surface* createSurface(int width, int height);

	/* Ładowanie bitmapy jako tekstury z pliku (BMP only)*/
	SDL_Texture *bmpSurface(const char* filePath, SDL_Renderer *renderer, SDL_Rect* pt);

	/*Animowanie sprite'ów*/
	void animateBMPSprite(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect* spriteClips, int numFrames, SDL_Rect* dstRect, int frameDelay);

	/*Funkcja dzieląca sprite sheet na klatki*/
	void createSpriteClips(SDL_Rect* clips, int frameWidth, int frameHeight, int numFrames, int sheetWidth);

	/*Zapisywanie bitmapy do pliku*/
	int saveSurfaceAsBMP(SDL_Surface* surface, const char* filePath);

	/*Kopiowanie bitmapy*/
	int copyBitmapSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);

	/*Usuwanie tekstury*/
	void deleteTexture(SDL_Texture* texture);

	/*Usuwanie powierzchni*/
	void deleteSurface(SDL_Surface* surface);

private:
	
};
