/**
 * @file AnimatedObject.h
 * @brief Declaration of the AnimatedObject class.
 */

#pragma once
#include "GameObject.h"
#include "BitmapObject.h"

 /**
  * @class AnimatedObject
  * @brief Abstract class representing an object with animation capabilities.
  *
  * AnimatedObject extends the BitmapObject class and introduces a pure virtual
  * function `animate` that must be implemented by any derived class to provide
  * specific animation behavior.
  */
class AnimatedObject : public BitmapObject
{
public:
    /**
     * @brief Pure virtual function for animating the object.
     *
     * This method must be implemented by derived classes to define the animation logic.
     */
    virtual void animate() = 0;

private:
    // No private members are defined for this abstract class.
};
