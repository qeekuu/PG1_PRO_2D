/**
 * @file Circle.h
 * @brief Declaration of the Circle class, representing a 2D circle.
 */

#pragma once
#include "ShapeObject.h"
#include "Point2D.h"

 /**
  * @class Circle
  * @brief Represents a 2D circle with functionalities for rendering and transformations.
  *
  * The Circle class inherits from ShapeObject and provides methods to draw, fill, and transform
  * a circle object, such as translation, rotation, and scaling.
  */
class Circle : public ShapeObject
{
public:
    /**
     * @brief Constructs a Circle object with specified color, center position, and radius.
     *
     * @param r Red component of the circle's color.
     * @param g Green component of the circle's color.
     * @param b Blue component of the circle's color.
     * @param an Alpha (transparency) component of the circle's color.
     * @param x X-coordinate of the circle's center.
     * @param y Y-coordinate of the circle's center.
     * @param R Radius of the circle.
     */
    Circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int x, unsigned int y, unsigned int R);

    /**
     * @brief Draws the circle on the screen.
     *
     * This method renders the circle's outline using the appropriate rendering functions.
     */
    void draw() override;

    /**
     * @brief Fills the circle with a specified color and boundary color.
     *
     * @param fillColor The fill color for the circle.
     * @param boundryColor The boundary color for the circle.
     */
    void fill(SDL_Color fillColor, SDL_Color boundryColor) override;

    /**
     * @brief Translates (moves) the circle by a specified offset.
     *
     * @param tx Offset along the x-axis.
     * @param ty Offset along the y-axis.
     */
    void translate(int tx, int ty) override;

    /**
     * @brief Rotates the circle's center around the origin by a specified angle.
     *
     * @param alfa Angle of rotation in degrees.
     */
    void rotate(double alfa) override;

    /**
     * @brief Rotates the circle's center around a specified point by a given angle.
     *
     * @param alfa Angle of rotation in degrees.
     * @param x X-coordinate of the rotation point.
     * @param y Y-coordinate of the rotation point.
     */
    void rotatePoint(double alfa, int x, int y) override;

    /**
     * @brief Scales the circle uniformly by a specified factor.
     *
     * @param k Scaling factor. A value greater than 1 enlarges the circle, while a value less than 1 shrinks it.
     */
    void scale(double k) override;

    /**
     * @brief Scales the circle around a specified point by a given factor.
     *
     * This method adjusts both the circle's center position and its radius.
     *
     * @param k Scaling factor. A value greater than 1 enlarges the circle, while a value less than 1 shrinks it.
     * @param x X-coordinate of the scaling point.
     * @param y Y-coordinate of the scaling point.
     */
    void scalePoint(double k, int x, int y) override;

private:
    Point2D circleCenter; /**< Center point of the circle. */
    unsigned int R;       /**< Radius of the circle. */
    Uint8 r;              /**< Red component of the circle's color. */
    Uint8 g;              /**< Green component of the circle's color. */
    Uint8 b;              /**< Blue component of the circle's color. */
    Uint8 an;             /**< Alpha (transparency) component of the circle's color. */
};
