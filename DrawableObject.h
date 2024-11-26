/**
 * @file DrawableObject.h
 * @brief Declaration of the DrawableObject class.
 */

#pragma once
#include "GameObject.h"
#include <vector>
#include "Point2D.h"
#include <SDL.h>

 /**
  * @class DrawableObject
  * @brief Abstract base class for drawable objects.
  *
  * The DrawableObject class provides an interface for objects that can be drawn and filled.
  * It inherits virtually from the GameObject class.
  */
class DrawableObject : virtual public GameObject
{
public:
    /**
     * @brief Pure virtual method for drawing the object.
     *
     * Derived classes must implement this method to define the drawing logic.
     */
    virtual void draw() = 0;

    /**
     * @brief Pure virtual method for filling the object with a specified color.
     *
     * Derived classes must implement this method to define how the object is filled with a color.
     *
     * @param fillColor The color to fill the object with.
     * @param boundryColor The color to use for the object's boundaries.
     */
    virtual void fill(SDL_Color fillColor, SDL_Color boundryColor) = 0;
};
