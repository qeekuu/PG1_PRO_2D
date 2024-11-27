/**
 * @file Player.cpp
 * @brief Implementation of the Player class and its functionalities.
 */

#include "Player.h"
#include "DrawableObject.h"
#include "Rectangle.h"
#include "TransformableObject.h"
#include "UpdatableObject.h"
#include "Engine.h"
#include "Input.h"
#include <SDL_stdinc.h>

 /**
  * @brief Constructs a Player object with the given color and position.
  *
  * @param r Red component of the player's rectangle color.
  * @param g Green component of the player's rectangle color.
  * @param b Blue component of the player's rectangle color.
  * @param a Alpha (transparency) component of the player's rectangle color.
  * @param x1, y1 Coordinates of the top-left corner of the rectangle.
  * @param x2, y2 Coordinates of the top-right corner of the rectangle.
  * @param x3, y3 Coordinates of the bottom-right corner of the rectangle.
  * @param x4, y4 Coordinates of the bottom-left corner of the rectangle.
  */
Player::Player(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4)
    : rectangle(r, g, b, a, x1, y1, x2, y2, x3, y3, x4, y4)
{
    direction = IDLE;
    currentFrame = 0;
    spritePath = "rsc\\PLAYER_spritesheet.bmp";

    spriteSheet = bmpSurface(spritePath, Engine::getInstance()->getRenderer(), nullptr); 

    numDirections = 4;
    framesPerDirection = 4;
    int frameWidth = 32;
    int frameHeight = 32;
    int directionMapping[4] = { 3, 2, 1, 0 };

    spriteClips = createSpriteClips(numDirections, framesPerDirection, frameWidth, frameHeight, directionMapping);

    // Initial position
    dstRect = { static_cast<int>(x1), static_cast<int>(y1), frameWidth, frameHeight };
}

/**
 * @brief Destroys the Player object and releases resources.
 */
Player::~Player()
{
    deleteTexture(spriteSheet);
    freeSpriteClips(spriteClips, numDirections);
}

// TransformableObject Methods

/**
 * @brief Translates (moves) the player by a given offset.
 *
 * @param tx Offset along the x-axis.
 * @param ty Offset along the y-axis.
 */
void Player::translate(int tx, int ty) {};

/**
 * @brief Rotates the player by a given angle.
 *
 * @param alfa Angle of rotation in degrees.
 */
void Player::rotate(double alfa) {};

/**
 * @brief Rotates the player around a specific point by a given angle.
 *
 * @param alfa Angle of rotation in degrees.
 * @param x X-coordinate of the rotation point.
 * @param y Y-coordinate of the rotation point.
 */
void Player::rotatePoint(double alfa, int x, int y) {};

/**
 * @brief Scales the player uniformly by a given factor.
 *
 * @param k Scaling factor.
 */
void Player::scale(double k) {};

/**
 * @brief Scales the player around a specific point by a given factor.
 *
 * @param k Scaling factor.
 * @param x X-coordinate of the scaling point.
 * @param y Y-coordinate of the scaling point.
 */
void Player::scalePoint(double k, int x, int y) {};

// DrawableObject Methods

/**
 * @brief Draws the player on the screen.
 */
void Player::draw()
{
    animate();
};

/**
 * @brief Fills the player's rectangle with a specified color and boundary color.
 *
 * @param fillColor Fill color for the rectangle.
 * @param boundryColor Boundary color for the rectangle.
 */
void Player::fill(SDL_Color fillColor, SDL_Color boundryColor) {};

/**
 * @brief Animates the player's sprite based on its current direction and frame.
 */
void Player::animate()
{
    if (direction != IDLE)
        BitmapHandler::animateBMPSprite(Engine::getInstance()->getRenderer(), spriteSheet, spriteClips, numDirections, direction, currentFrame, &dstRect, frameDelay, framesPerDirection);
    else
        SDL_RenderCopy(Engine::getInstance()->getRenderer(), spriteSheet, &spriteClips[DOWN][0], &dstRect);
}

/**
 * @brief Updates the player's position and animation based on input.
 */
void Player::update()
{
    const int spriteSpeed = 5; // Speed of player movement
    int frameCount = 0;
    int previousDirection = IDLE;
    int frame = 0;

    // Default state: player is idle
    direction = IDLE;

    // Move up
    if (Input::getInstances()->getKey(SDL_SCANCODE_W)) {
        dstRect.y = std::max(0, dstRect.y - spriteSpeed); // Prevent moving off-screen
        direction = UP;
    }
    // Move down
    if (Input::getInstances()->getKey(SDL_SCANCODE_S)) {
        dstRect.y = std::min(600 - dstRect.h, dstRect.y + spriteSpeed);
        direction = DOWN;
    }
    // Move left
    if (Input::getInstances()->getKey(SDL_SCANCODE_A)) {
        dstRect.x = std::max(0, dstRect.x - spriteSpeed);
        direction = LEFT;
    }
    // Move right
    if (Input::getInstances()->getKey(SDL_SCANCODE_D)) {
        dstRect.x = std::min(800 - dstRect.w, dstRect.x + spriteSpeed);
        direction = RIGHT;
    }

    // If no movement keys are pressed
    if (!Input::getInstances()->getKey(SDL_SCANCODE_W) &&
        !Input::getInstances()->getKey(SDL_SCANCODE_S) &&
        !Input::getInstances()->getKey(SDL_SCANCODE_A) &&
        !Input::getInstances()->getKey(SDL_SCANCODE_D)) {
        direction = IDLE;
    }

    // Reset frames when direction changes
    if (direction != previousDirection) {
        frameCount = 0;
        frame = 0;
    }
    previousDirection = direction;

    // Update animation frames
    if (direction != IDLE) {
        frameCount++;
        if (frameCount >= frameDelay) {
            frame = (frame + 1) % framesPerDirection; // Cycle animation
            frameCount = 0;
        }
    }
    else {
        frame = 0; // Reset to the initial frame when idle
    }
};
