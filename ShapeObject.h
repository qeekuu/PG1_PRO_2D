/**
 * @file ShapeObject.h
 * @brief Declaration of the ShapeObject class, a base class for drawable and transformable shapes.
 *
 * The ShapeObject class serves as an interface for objects that can be both drawn
 * and transformed. It inherits from DrawableObject and TransformableObject to
 * combine drawing and transformation functionalities.
 */

#pragma once

#include "DrawableObject.h"
#include "TransformableObject.h"

 /**
  * @class ShapeObject
  * @brief Base class for shapes that are drawable and transformable.
  *
  * ShapeObject combines the functionalities of DrawableObject and TransformableObject,
  * providing a unified interface for graphical objects that can be rendered and manipulated.
  */
class ShapeObject : public DrawableObject, public TransformableObject
{
    // The class currently serves as a bridge between DrawableObject and TransformableObject
    // without adding any additional functionality or members.
};
