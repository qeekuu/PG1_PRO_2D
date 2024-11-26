/**
 * @file Rectangle.h
 * @brief Declaration of the Rectangle class, a specialized ShapeObject.
 *
 * The Rectangle class represents a quadrilateral with four vertices.
 * It supports various operations such as drawing, filling, translating, rotating, and scaling.
 */

#pragma once

#include "ShapeObject.h"
#include "Point2D.h"

 /**
  * @class Rectangle
  * @brief Represents a rectangle as a specialized shape object.
  */
class Rectangle : public ShapeObject
{
public:
    /**
     * @brief Constructs a rectangle with specified colors and vertices.
     *
     * @param r Red component (0-255).
     * @param g Green component (0-255).
     * @param b Blue component (0-255).
     * @param a Alpha component (0-255).
     * @param x1, y1 Coordinates of the first vertex.
     * @param x2, y2 Coordinates of the second vertex.
     * @param x3, y3 Coordinates of the third vertex.
     * @param x4, y4 Coordinates of the fourth vertex.
     */
    Rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4);

    /**
     * @brief Draws the rectangle using the provided renderer.
     */
    void draw() override;

    /**
     * @brief Fills the rectangle with a specified color, bounded by a boundary color.
     *
     * @param fillColor The fill color for the rectangle.
     * @param boundryColor The boundary color for the rectangle.
     */
    void fill(SDL_Color fillColor, SDL_Color boundryColor) override;

    /**
     * @brief Translates the rectangle by a specified offset.
     *
     * @param tx Horizontal translation offset.
     * @param ty Vertical translation offset.
     */
    void translate(int tx, int ty) override;

    /**
     * @brief Rotates the rectangle around its center by a specified angle.
     *
     * @param alfa Rotation angle in radians.
     */
    void rotate(double alfa) override;

    /**
     * @brief Rotates the rectangle around a specified point by a specified angle.
     *
     * @param alfa Rotation angle in radians.
     * @param x X-coordinate of the rotation point.
     * @param y Y-coordinate of the rotation point.
     */
    void rotatePoint(double alfa, int x, int y) override;

    /**
     * @brief Scales the rectangle uniformly by a specified factor.
     *
     * @param k Scaling factor (1.0 = no scaling).
     */
    void scale(double k) override;

    /**
     * @brief Scales the rectangle relative to a specified point.
     *
     * @param k Scaling factor (1.0 = no scaling).
     * @param x X-coordinate of the scaling center.
     * @param y Y-coordinate of the scaling center.
     */
    void scalePoint(double k, int x, int y) override;

    /**
     * @brief Gets the first vertex of the rectangle.
     *
     * @return Point2D& Reference to the first vertex.
     */
    Point2D& getPoint1();

    /**
     * @brief Gets the second vertex of the rectangle.
     *
     * @return Point2D& Reference to the second vertex.
     */
    Point2D& getPoint2();

    /**
     * @brief Gets the third vertex of the rectangle.
     *
     * @return Point2D& Reference to the third vertex.
     */
    Point2D& getPoint3();

    /**
     * @brief Gets the fourth vertex of the rectangle.
     *
     * @return Point2D& Reference to the fourth vertex.
     */
    Point2D& getPoint4();

private:
    Point2D point1, point2, point3, point4; /**< Vertices of the rectangle. */
    Uint8 r, g, b, a; /**< Color components for the rectangle. */
    unsigned int xc, yc; /**< Center coordinates of the rectangle. */
};
