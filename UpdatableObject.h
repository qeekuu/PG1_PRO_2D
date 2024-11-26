/**
 * @file UpdatableObject.h
 * @brief Declaration of the UpdatableObject class, an interface for objects that can be updated.
 *
 * The UpdatableObject class provides an abstract interface for objects that require
 * regular updates, such as in a game loop or simulation.
 */

#pragma once

#include "GameObject.h"

 /**
  * @class UpdatableObject
  * @brief Abstract base class for objects that support updates.
  *
  * This class defines an interface for objects that need to perform periodic updates.
  * It is designed to be inherited by other classes requiring update functionality.
  */
class UpdatableObject : public GameObject
{
public:
    /**
     * @brief Updates the state of the object.
     *
     * This method is meant to be implemented by derived classes to define specific
     * update behavior. Typically called in a game loop or simulation step.
     */
    virtual void update() = 0;
};
