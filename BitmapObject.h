/**
 * @file BitmapObject.h
 * @brief Declaration of the BitmapObject class and associated definitions.
 */

#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "BitmapHandler.h"

 /**
  * @enum Direction
  * @brief Enum representing possible movement directions.
  */
enum Direction {
    RIGHT = 0, /**< Moving to the right. */
    LEFT = 1,  /**< Moving to the left. */
    UP = 2,    /**< Moving up. */
    DOWN = 3,  /**< Moving down. */
    IDLE = -1  /**< No movement. */
};

/**
 * @class BitmapObject
 * @brief Base class for objects that can be drawn, transformed, and handle bitmaps.
 *
 * BitmapObject combines functionalities of DrawableObject, TransformableObject,
 * and BitmapHandler to represent graphical objects with sprite-based animations.
 */
class BitmapObject : public DrawableObject, public TransformableObject, public BitmapHandler
{
public:
    /**
     * @brief Pure virtual function for drawing the object.
     *
     * This method must be implemented by derived classes to define the drawing logic.
     */
    virtual void draw() = 0;

protected:
    SDL_Texture* spriteSheet;          /**< Texture for the sprite sheet. */
    SDL_Rect** spriteClips;            /**< Array of rectangles representing sprite frames. */
    int currentFrame;                  /**< Current frame index in the animation. */
    int direction;                     /**< Current movement direction. */
    const int frameDelay = 100;        /**< Time delay between animation frames (in milliseconds). */
    int numDirections;                 /**< Number of animation directions. */
    int framesPerDirection;            /**< Number of frames per direction. */
    SDL_Rect dstRect;                  /**< Destination rectangle for rendering. */
    const char* spritePath;            /**< File path to the sprite sheet. */
};
