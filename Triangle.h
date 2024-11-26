/**
 * @file Triangle.h
 * @brief Declaration of the Triangle class, a specialized shape representing a triangle.
 *
 * The Triangle class extends ShapeObject and provides functionalities to draw,
 * fill, and apply transformations (translation, rotation, scaling) to a triangle.
 */

#pragma once

#include "ShapeObject.h"
#include "Point2D.h"

 /**
  * @class Triangle
  * @brief Represents a triangle as a specialized shape object.
  *
  * This class provides methods to draw, fill, and apply transformations such as
  * translation, rotation, and scaling to a triangle defined by three vertices.
  */
class Triangle : public ShapeObject
{
public:
    /**
     * @brief Constructs a triangle with specified colors and vertices.
     *
     * @param r Red component (0-255).
     * @param g Green component (0-255).
     * @param b Blue component (0-255).
     * @param a Alpha component (0-255).
     * @param x1, y1 Coordinates of the first vertex.
     * @param x2, y2 Coordinates of the second vertex.
     * @param x3, y3 Coordinates of the third vertex.
     */
    Triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3);

    /**
     * @brief Draws the triangle using the provided renderer.
     */
    void draw() override;

    /**
     * @brief Fills the triangle with the specified fill color, bounded by the boundary color.
     *
     * @param fillColor The color to fill the triangle.
     * @param boundryColor The color to use for the boundary.
     */
    void fill(SDL_Color fillColor, SDL_Color boundryColor) override;

    /**
     * @brief Translates the triangle by the specified offsets.
     *
     * @param tx Horizontal translation offset.
     * @param ty Vertical translation offset.
     */
    void translate(int tx, int ty) override;

    /**
     * @brief Rotates the triangle around its origin by the specified angle.
     *
     * @param alfa Rotation angle in radians.
     */
    void rotate(double alfa) override;

    /**
     * @brief Rotates the triangle around a specified point by the specified angle.
     *
     * @param alfa Rotation angle in radians.
     * @param x X-coordinate of the rotation point.
     * @param y Y-coordinate of the rotation point.
     */
    void rotatePoint(double alfa, int x, int y) override;

    /**
     * @brief Scales the triangle uniformly by the specified factor.
     *
     * @param k Scaling factor (1.0 = no scaling).
     */
    void scale(double k) override;

    /**
     * @brief Scales the triangle relative to a specified point by the specified factor.
     *
     * @param k Scaling factor (1.0 = no scaling).
     * @param x X-coordinate of the scaling center.
     * @param y Y-coordinate of the scaling center.
     */
    void scalePoint(double k, int x, int y) override;

private:
    Point2D point1, point2, point3; /**< Vertices of the triangle. */
    Uint8 r, g, b, a; /**< Color components for the triangle. */
    unsigned int xc, yc; /**< Center coordinates of the triangle. */
};
