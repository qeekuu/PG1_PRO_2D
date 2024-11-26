/**
 * @file Triangle.cpp
 * @brief Implementation file for the Triangle class.
 *
 * The Triangle class provides methods for drawing, filling, and applying transformations
 * (translation, rotation, scaling) to a triangle defined by three vertices.
 */

#include "Triangle.h"
#include "PrimitiveRenderer.h"

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
Triangle::Triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3)
    : r{ r }, g{ g }, b{ b }, a{ a }, point1{ x1, y1 }, point2{ x2, y2 }, point3{ x3, y3 }, xc{ 0 }, yc{ 0 }
{
}

/**
 * @brief Draws the triangle using the PrimitiveRenderer.
 */
void Triangle::draw()
{
    PrimitiveRenderer::draw_triangle(r, g, b, a,
        point1.getCoordinates('X'), point1.getCoordinates('Y'),
        point2.getCoordinates('X'), point2.getCoordinates('Y'),
        point3.getCoordinates('X'), point3.getCoordinates('Y'));
}

/**
 * @brief Fills the triangle with the specified fill color, bounded by the boundary color.
 *
 * The center of the triangle is calculated as the average of its vertices, and the fill operation starts there.
 *
 * @param fillColor The color to fill the triangle.
 * @param boundryColor The color to use for the boundary.
 */
void Triangle::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
    xc = (point1.getCoordinates('X') + point2.getCoordinates('X') + point3.getCoordinates('X')) / 3;
    yc = (point1.getCoordinates('Y') + point2.getCoordinates('Y') + point3.getCoordinates('Y')) / 3;
    PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(), xc, yc, fillColor, boundryColor);
}

/**
 * @brief Translates the triangle by the specified offsets.
 *
 * @param tx Horizontal translation offset.
 * @param ty Vertical translation offset.
 */
void Triangle::translate(int tx, int ty)
{
    point1.setCoordinates(point1.getCoordinates('X') + tx, point1.getCoordinates('Y') - ty);
    point2.setCoordinates(point2.getCoordinates('X') + tx, point2.getCoordinates('Y') - ty);
    point3.setCoordinates(point3.getCoordinates('X') + tx, point3.getCoordinates('Y') - ty);
}

/**
 * @brief Rotates the triangle around its origin by the specified angle.
 *
 * @param alfa Rotation angle in degrees.
 */
void Triangle::rotate(double alfa)
{
    double alfaRad = alfa * M_PI / 180.0;

    for (Point2D* point : { &point1, &point2, &point3 })
    {
        int x1 = point->getCoordinates('X');
        int y1 = point->getCoordinates('Y');
        int x2 = x1 * cos(alfaRad) - y1 * sin(alfaRad);
        int y2 = x1 * sin(alfaRad) + y1 * cos(alfaRad);
        point->setCoordinates(x2, y2);
    }
}

/**
 * @brief Rotates the triangle around a specified point by the specified angle.
 *
 * @param alfa Rotation angle in degrees.
 * @param x X-coordinate of the rotation point.
 * @param y Y-coordinate of the rotation point.
 */
void Triangle::rotatePoint(double alfa, int x, int y)
{
    double alfaRad = alfa * M_PI / 180.0;

    for (Point2D* point : { &point1, &point2, &point3 })
    {
        int x1 = point->getCoordinates('X');
        int y1 = point->getCoordinates('Y');
        int x2 = x + (x1 - x) * cos(alfaRad) - (y1 - y) * sin(alfaRad);
        int y2 = y + (x1 - x) * sin(alfaRad) + (y1 - y) * cos(alfaRad);
        point->setCoordinates(x2, y2);
    }
}

/**
 * @brief Scales the triangle uniformly by the specified factor.
 *
 * @param k Scaling factor (1.0 = no scaling).
 */
void Triangle::scale(double k)
{
    for (Point2D* point : { &point1, &point2, &point3 })
    {
        int x1 = point->getCoordinates('X');
        int y1 = point->getCoordinates('Y');
        int x2 = x1 * k;
        int y2 = y1 * k;
        point->setCoordinates(x2, y2);
    }
}

/**
 * @brief Scales the triangle relative to a specified point by the specified factor.
 *
 * @param k Scaling factor (1.0 = no scaling).
 * @param x X-coordinate of the scaling center.
 * @param y Y-coordinate of the scaling center.
 */
void Triangle::scalePoint(double k, int x, int y)
{
    for (Point2D* point : { &point1, &point2, &point3 })
    {
        int x1 = point->getCoordinates('X');
        int y1 = point->getCoordinates('Y');
        int x2 = x1 * k + (1 - k) * x;
        int y2 = y1 * k + (1 - k) * y;
        point->setCoordinates(x2, y2);
    }
}
