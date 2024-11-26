#include "Player.h" 
#include "DrawableObject.h"
#include "Rectangle.h"
#include "TransformableObject.h"
#include "UpdatableObject.h"
#include "Engine.h"
#include "Input.h"
#include <SDL_stdinc.h>

Player::Player(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4)
	: rectangle(r, g, b, a, x1, y1, x2, y2, x3, y3, x4, y4)
{
	direction = IDLE;
	currentFrame = 0;
	spritePath = "D:\\Filip\\PGPRO07.11.24\\rsc\\PLAYER_spritesheet.bmp";

	spriteSheet = bmpSurface(spritePath, Engine::getInstance()->getRenderer(), nullptr);

	numDirections = 4;
	framesPerDirection = 4;
	int frameWidth = 32;
	int frameHeight = 32;
	int directionMapping[4] = { 3, 2, 1, 0 };

	spriteClips = createSpriteClips(numDirections, framesPerDirection, frameWidth, frameHeight, directionMapping);

	// Pozycja pocz�tkowa
	dstRect = { static_cast<int>(x1), static_cast<int>(y1), frameWidth, frameHeight };

}

Player::~Player()
{
	deleteTexture(spriteSheet);
	freeSpriteClips(spriteClips, numDirections);
}

/* TransformableObject */
void Player::translate(int tx, int ty){};
void Player::rotate(double alfa){}; 
void Player::rotatePoint(double alfa, int x, int y){};
void Player::scale(double k){};
void Player::scalePoint(double k, int x, int y){};

/* DrawableObject */
void Player::draw()
{
	animate();
};
void Player::fill(SDL_Color fillColor, SDL_Color boundryColor){};

void Player::animate()
{
	if (direction != IDLE)
		BitmapHandler::animateBMPSprite(Engine::getInstance()->getRenderer(), spriteSheet, spriteClips, numDirections, direction, currentFrame, &dstRect, frameDelay, framesPerDirection);
	else
		SDL_RenderCopy(Engine::getInstance()->getRenderer(), spriteSheet, &spriteClips[DOWN][0], &dstRect);

}

void Player::update()
{
    const int spriteSpeed = 5; // Pr�dko�� poruszania gracza
    int frameCount = 0;
    int previousDirection = IDLE;
    int frame = 0;
    bool isJumping = false;       // Informacja, czy kwadrat jest w trakcie skoku
    float velocityY = 0.0f;       // Pr�dko�� pionowa kwadratu
    const float gravity = 0.5f;   // Sta�a grawitacji, dostosuj w zale�no�ci od potrzeb
    const float jumpStrength = -10.0f; // Si�a skoku

    // Domy�lnie gracz stoi w miejscu
    direction = IDLE;

    // Ruch w g�r�
    if (Input::getInstances()->getKey(SDL_SCANCODE_W)) {
        dstRect.y = std::max(0, dstRect.y - spriteSpeed); // Zapobiega wyj�ciu poza ekran
        direction = UP;
    }
    // Ruch w d�
    if (Input::getInstances()->getKey(SDL_SCANCODE_S)) {
        dstRect.y = std::min(600 - dstRect.h, dstRect.y + spriteSpeed);
        direction = DOWN;
    }
    // Ruch w lewo
    if (Input::getInstances()->getKey(SDL_SCANCODE_A)) {
        dstRect.x = std::max(0, dstRect.x - spriteSpeed);
        direction = LEFT;
    }
    // Ruch w prawo
    if (Input::getInstances()->getKey(SDL_SCANCODE_D)) {
        dstRect.x = std::min(800 - dstRect.w, dstRect.x + spriteSpeed);
        direction = RIGHT;
    }

    // Gdy �aden z klawiszy ruchu nie jest wciskany
    if (!Input::getInstances()->getKey(SDL_SCANCODE_W) &&
        !Input::getInstances()->getKey(SDL_SCANCODE_S) &&
        !Input::getInstances()->getKey(SDL_SCANCODE_A) &&
        !Input::getInstances()->getKey(SDL_SCANCODE_D)) {
        direction = IDLE;
    }

    // Resetowanie klatek przy zmianie kierunku
    if (direction != previousDirection) {
        frameCount = 0;
        frame = 0;
    }
    previousDirection = direction;

    // Aktualizacja klatek animacji
    if (direction != IDLE) {
        frameCount++;
        if (frameCount >= frameDelay) {
            frame = (frame + 1) % framesPerDirection; // Cykl animacji
            frameCount = 0;
        }
    }
    else {
        frame = 0; // Ustawienie na pocz�tkow� klatk�, gdy gracz stoi
    }

    // Obs�uga skoku
    if (Input::getInstances()->getKey(SDL_SCANCODE_SPACE) && !isJumping) {
        isJumping = true;
        velocityY = jumpStrength; // Ustawienie pr�dko�ci pocz�tkowej skoku
    }

    // Logika skoku i grawitacji
    if (isJumping) {
        velocityY += gravity; // Dodanie grawitacji
        dstRect.y += velocityY;

        // Sprawdzenie powrotu na ziemi�
        if (dstRect.y >= 290) { // Zak�adamy, �e ziemia jest na wysoko�ci y = 290
            dstRect.y = 290;
            isJumping = false; // Zako�czenie skoku
            velocityY = 0.0f;  // Zerowanie pr�dko�ci
        }
    }
};

