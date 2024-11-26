#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "BitmapHandler.h"

enum Direction {
    RIGHT = 0,
    LEFT = 1,
    UP = 2,
    DOWN = 3,
    IDLE = -1 // Bez ruchu
};

class BitmapObject : public DrawableObject, public TransformableObject, public BitmapHandler
{
public:
	virtual void draw() = 0;

protected:
    SDL_Texture* spriteSheet;          // Tekstura sprite sheet
    SDL_Rect** spriteClips;            // Tablica klatek sprite'ów
    int currentFrame;                  // Aktualna ramka
    int direction;                     // Kierunek ruchu
    const int frameDelay = 100;        // Czas miêdzy klatkami
    int numDirections;                 // Liczba kierunków animacji
    int framesPerDirection;            // Liczba klatek na kierunek
    SDL_Rect dstRect;                  // Pozycja na ekranie
    const char* spritePath;            // œcie¿ka

private:
};

