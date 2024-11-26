/**
 * @file SpriteObject.h
 * @brief Declaration of the SpriteObject class, a specialized class for animated sprite handling.
 *
 * The SpriteObject class inherits from AnimatedObject, combining animation functionality
 * with the capability to represent bitmap-based graphical objects in 2D environments.
 */

#pragma once

#include "BitmapObject.h"
#include "AnimatedObject.h"

 /**
  * @class SpriteObject
  * @brief Represents an animated sprite in a 2D graphics system.
  *
  * The SpriteObject class builds upon AnimatedObject, enabling graphical objects
  * with bitmap representations to incorporate animations.
  */
class SpriteObject : public AnimatedObject
{
    // Currently, the class serves as a specialized AnimatedObject
    // without adding additional members or functionality.
};
