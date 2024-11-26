/**
 * @file Ellipse.h
 * @brief Declaration of the Ellipse class, representing a 2D ellipse with rendering and transformation functionalities.
 */

#pragma once
#include "ShapeObject.h"

 /**
  * @class Ellipse
  * @brief Represents a 2D ellipse with functionalities for rendering and transformations.
  *
  * The Ellipse class provides methods to draw, fill, and transform an ellipse, such as translation, rotation, and scaling.
  */
class Ellipse : public ShapeObject
{
public:
    /**
     * @brief Constructs an Ellipse object with specified color, center position, and radii.
     *
     * @param r Red component of the ellipse's color.
     * @param g Green component of the ellipse's color.
     * @param b Blue component of the ellipse's color.
     * @param an Alpha (transparency) component of the ellipse's color.
     * @param xc X-coordinate of the ellipse's center.
     * @param yc Y-coordinate of the ellipse's center.
     * @param R Horizontal radius (along the x-axis) of the ellipse.
     * @param R2 Vertical radius (along the y-axis) of the ellipse.
     */
    Ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int xc, unsigned int yc, unsigned int R, unsigned int R2);

    /**
     * @brief Draws the ellipse on the screen.
     *
     * This method renders the ellipse's outline using the appropriate rendering functions.
     */
    void draw() override;

    /**
     * @brief Fills the ellipse with a specified color and boundary color.
     *
     * @param fillColor The fill color for the ellipse.
     * @param boundryColor The boundary color for the ellipse.
     */
    void fill(SDL_Color fillColor, SDL_Color boundryColor) override;

    /**
     * @brief Translates (moves) the ellipse by a specified offset.
     *
     * @param tx Offset along the x-axis.
     * @param ty Offset along the y-axis.
     */
    void translate(int tx, int ty) override;

    /**
     * @brief Rotates the ellipse around its center by a specified angle.
     *
     * @param alfa Angle of rotation in degrees.
     */
    void rotate(double alfa) override;

    /**
     * @brief Rotates the ellipse around a specified point by a given angle.
     *
     * @param alfa Angle of rotation in degrees.
     * @param x X-coordinate of the rotation point.
     * @param y Y-coordinate of the rotation point.
     */
    void rotatePoint(double alfa, int x, int y) override;

    /**
     * @brief Scales the ellipse uniformly by a specified factor.
     *
     * @param k Scaling factor. A value greater than 1 enlarges the ellipse, while a value less than 1 shrinks it.
     */
    void scale(double k) override;

    /**
     * @brief Scales the ellipse around a specified point by a given factor.
     *
     * This method adjusts both the ellipse's center position and its radii.
     *
     * @param k Scaling factor. A value greater than 1 enlarges the ellipse, while a value less than 1 shrinks it.
     * @param x X-coordinate of the scaling point.
     * @param y Y-coordinate of the scaling point.
     */
    void scalePoint(double k, int x, int y) override;

private:
    Uint8 r;              /**< Red component of the ellipse's color. */
    Uint8 g;              /**< Green component of the ellipse's color. */
    Uint8 b;              /**< Blue component of the ellipse's color. */
    Uint8 an;             /**< Alpha (transparency) component of the ellipse's color. */
    unsigned int R;       /**< Horizontal radius (along the x-axis) of the ellipse. */
    unsigned int R2;      /**< Vertical radius (along the y-axis) of the ellipse. */
    Point2D ellipseCenter; /**< Center point of the ellipse. */
    double rotationAngle; /**< Current rotation angle of the ellipse in radians. */
};
