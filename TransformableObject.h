/**
 * @file TransformableObject.h
 * @brief Declaration of the TransformableObject class, an interface for objects with transformation capabilities.
 *
 * The TransformableObject class provides an abstract interface for objects that
 * can be translated, rotated, and scaled. It serves as a base class for game objects
 * that need these transformation functionalities.
 */

#pragma once

#include "GameObject.h"

 /**
  * @class TransformableObject
  * @brief Abstract base class for transformable objects.
  *
  * This class defines an interface for applying transformations such as translation,
  * rotation, and scaling to objects. It is designed to be inherited by other classes
  * that require these capabilities.
  */
class TransformableObject : virtual public GameObject
{
public:
    /**
     * @brief Translates the object by the specified offsets.
     *
     * @param tx Horizontal translation offset.
     * @param ty Vertical translation offset.
     */
    virtual void translate(int tx, int ty) = 0;

    /**
     * @brief Rotates the object around the origin by the specified angle.
     *
     * @param alfa Rotation angle in radians.
     */
    virtual void rotate(double alfa) = 0;

    /**
     * @brief Rotates the object around a specified point by the specified angle.
     *
     * @param alfa Rotation angle in radians.
     * @param x X-coordinate of the rotation point.
     * @param y Y-coordinate of the rotation point.
     */
    virtual void rotatePoint(double alfa, int x, int y) = 0;

    /**
     * @brief Scales the object uniformly by the specified factor.
     *
     * @param k Scaling factor (1.0 = no scaling).
     */
    virtual void scale(double k) = 0;

    /**
     * @brief Scales the object relative to a specified point by the specified factor.
     *
     * @param k Scaling factor (1.0 = no scaling).
     * @param x X-coordinate of the scaling center.
     * @param y Y-coordinate of the scaling center.
     */
    virtual void scalePoint(double k, int x, int y) = 0;
};
