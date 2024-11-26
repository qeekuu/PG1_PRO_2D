/**
 * @file Polygon.cpp
 * @brief Implementation of the Polygon class, representing a 2D polygon with rendering and transformation functionalities.
 */

#include "Point2D.h"
#include "Polygon.h"
#include "PrimitiveRenderer.h"
#include "math.h"
#include <cmath>
#include <vector>

 /**
  * @brief Constructs a Polygon object with specified color and points.
  *
  * @param r Red component of the polygon's color.
  * @param g Green component of the polygon's color.
  * @param b Blue component of the polygon's color.
  * @param a Alpha (transparency) component of the polygon's color.
  * @param points Reference to a vector of Point2D objects defining the vertices of the polygon.
  */
Polygon::Polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points)
    : r{ r }, g{ g }, b{ b }, a{ a }, points{ points }, xc{ 0.0 }, yc{ 0.0 }, A{ 0.0 }
{
    calculateCenter();
}

/**
 * @brief Draws the polygon on the screen.
 */
void Polygon::draw()
{
    PrimitiveRenderer::draw_polygon(r, g, b, a, points);
}

/**
 * @brief Fills the polygon with a specified color and boundary color.
 *
 * @param fillColor The fill color for the polygon.
 * @param boundryColor The boundary color for the polygon.
 */
void Polygon::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
    PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(), xc, yc, fillColor, boundryColor);
}

/**
 * @brief Calculates the geometric center of the polygon.
 */
void Polygon::calculateCenter()
{
    double sumX = 0;
    double sumY = 0;
    for (int i = 0; i < points.size(); i++)
    {
        sumX += points[i].getCoordinates('X');
        sumY += points[i].getCoordinates('Y');
    }
    xc = sumX / points.size();
    yc = sumY / points.size();
}

/**
 * @brief Translates (moves) the polygon by a specified offset.
 *
 * @param tx Offset along the x-axis.
 * @param ty Offset along the y-axis.
 */
void Polygon::translate(int tx, int ty)
{
    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i].getCoordinates('X');
        int y = points[i].getCoordinates('Y');
        int x2 = x + tx;
        int y2 = y + ty;

        points[i].setCoordinates(x2, y2);
    }
    calculateCenter();
}

/**
 * @brief Rotates the polygon around its center by a specified angle.
 *
 * @param alfa Angle of rotation in degrees.
 */
void Polygon::rotate(double alfa)
{
    double alfaRad = alfa * M_PI / 180.0;

    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i].getCoordinates('X');
        int y = points[i].getCoordinates('Y');
        int x2 = x * cos(alfaRad) - y * sin(alfaRad);
        int y2 = x * sin(alfaRad) + y * cos(alfaRad);

        points[i].setCoordinates(x2, y2);
    }
    calculateCenter();
}

/**
 * @brief Rotates the polygon around a specified point by a given angle.
 *
 * @param alfa Angle of rotation in degrees.
 * @param x X-coordinate of the rotation point.
 * @param y Y-coordinate of the rotation point.
 */
void Polygon::rotatePoint(double alfa, int x, int y)
{
    double alfaRad = alfa * M_PI / 180.0;

    for (int i = 0; i < points.size(); i++)
    {
        int x1 = points[i].getCoordinates('X');
        int y1 = points[i].getCoordinates('Y');
        int x2 = x + (x1 - x) * cos(alfaRad) - (y1 - y) * sin(alfaRad);
        int y2 = y + (x1 - x) * sin(alfaRad) + (y1 - y) * cos(alfaRad);

        points[i].setCoordinates(x2, y2);
    }
    calculateCenter();
}

/**
 * @brief Scales the polygon uniformly by a specified factor.
 *
 * @param k Scaling factor. A value greater than 1 enlarges the polygon, while a value less than 1 shrinks it.
 */
void Polygon::scale(double k)
{
    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i].getCoordinates('X');
        int y = points[i].getCoordinates('Y');
        int x2 = x * k;
        int y2 = y * k;

        points[i].setCoordinates(x2, y2);
    }
    calculateCenter();
}

/**
 * @brief Scales the polygon around a specified point by a given factor.
 *
 * @param k Scaling factor. A value greater than 1 enlarges the polygon, while a value less than 1 shrinks it.
 * @param x X-coordinate of the scaling point.
 * @param y Y-coordinate of the scaling point.
 */
void Polygon::scalePoint(double k, int x, int y)
{
    for (int i = 0; i < points.size(); i++)
    {
        int x1 = points[i].getCoordinates('X');
        int y1 = points[i].getCoordinates('Y');
        int x2 = x1 * k + (1 - k) * x;
        int y2 = y1 * k + (1 - k) * y;

        points[i].setCoordinates(x2, y2);
    }
    calculateCenter();
}
