#include "Player.h" 
#include "DrawableObject.h"
#include "Rectangle.h"
#include "TransformableObject.h"
#include "UpdatableObject.h"
#include <SDL_stdinc.h>

Player::Player(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1,unsigned int x2, unsigned int y2,unsigned int x3, unsigned int y3,unsigned int x4, unsigned int y4) : rectangle(r, g, b, a, x1, y1, x2, y2, x3, y3, x4, y4)
{
			
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
	rectangle.draw();
};
void Player::fill(SDL_Color fillColor, SDL_Color boundryColor){};

/* UpdatableObject */
void Player::update(){};


