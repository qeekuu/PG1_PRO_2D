/**
 * @file Polygon.h
 * @brief Declaration of the Polygon class, representing a 2D polygon with rendering and transformation functionalities.
 */

#pragma once
#include "Point2D.h"
#include "ShapeObject.h"
#include <vector>

 /**
  * @class Polygon
  * @brief Represents a 2D polygon defined by a list of points, with functionalities for rendering and transformations.
  *
  * The Polygon class provides methods to draw, fill, and transform a polygon, such as translation, rotation, and scaling.
  * It also includes functionality to calculate the center of the polygon.
  */
class Polygon : public ShapeObject
{
public:
    /**
     * @brief Constructs a Polygon object with specified color and points.
     *
     * @param r Red component of the polygon's color.
     * @param g Green component of the polygon's color.
     * @param b Blue component of the polygon's color.
     * @param a Alpha (transparency) component of the polygon's color.
     * @param points Reference to a vector of Point2D objects defining the vertices of the polygon.
     */
    Polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points);

    /**
     * @brief Draws the polygon on the screen.
     *
     * This method renders the polygon's outline using the appropriate rendering functions.
     */
    void draw() override;

    /**
     * @brief Fills the polygon with a specified color and boundary color.
     *
     * @param fillColor The fill color for the polygon.
     * @param boundryColor The boundary color for the polygon.
     */
    void fill(SDL_Color fillColor, SDL_Color boundryColor) override;

    /**
     * @brief Translates (moves) the polygon by a specified offset.
     *
     * @param tx Offset along the x-axis.
     * @param ty Offset along the y-axis.
     */
    void translate(int tx, int ty) override;

    /**
     * @brief Rotates the polygon around its center by a specified angle.
     *
     * @param alfa Angle of rotation in degrees.
     */
    void rotate(double alfa) override;

    /**
     * @brief Rotates the polygon around a specified point by a given angle.
     *
     * @param alfa Angle of rotation in degrees.
     * @param x X-coordinate of the rotation point.
     * @param y Y-coordinate of the rotation point.
     */
    void rotatePoint(double alfa, int x, int y) override;

    /**
     * @brief Scales the polygon uniformly by a specified factor.
     *
     * @param k Scaling factor. A value greater than 1 enlarges the polygon, while a value less than 1 shrinks it.
     */
    void scale(double k) override;

    /**
     * @brief Scales the polygon around a specified point by a given factor.
     *
     * This method adjusts the position of all vertices and scales the polygon accordingly.
     *
     * @param k Scaling factor. A value greater than 1 enlarges the polygon, while a value less than 1 shrinks it.
     * @param x X-coordinate of the scaling point.
     * @param y Y-coordinate of the scaling point.
     */
    void scalePoint(double k, int x, int y) override;

    /**
     * @brief Calculates the geometric center of the polygon.
     *
     * This method computes the center of the polygon based on its vertices.
     */
    void calculateCenter();

private:
    Uint8 r; /**< Red component of the polygon's color. */
    Uint8 g; /**< Green component of the polygon's color. */
    Uint8 b; /**< Blue component of the polygon's color. */
    Uint8 a; /**< Alpha (transparency) component of the polygon's color. */
    double xc; /**< X-coordinate of the polygon's center. */
    double yc; /**< Y-coordinate of the polygon's center. */
    double A = 0.0; /**< Area of the polygon, used for calculating the center. */
    std::vector<Point2D>& points; /**< Reference to a vector of points defining the polygon's vertices. */
};
