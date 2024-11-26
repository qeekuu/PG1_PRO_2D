/**
 * @file Circle.cpp
 * @brief Implementation of the Circle class, representing a 2D circle with various transformation and rendering functionalities.
 */

#include "Circle.h"
#include "PrimitiveRenderer.h"

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
Circle::Circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int x, unsigned int y, unsigned int R)
    : r{ r }, g{ g }, b{ b }, an{ an }, circleCenter{ x, y }, R{ R }
{

}

/**
 * @brief Draws the circle on the screen.
 *
 * Uses the PrimitiveRenderer to render the circle's outline.
 */
void Circle::draw()
{
    PrimitiveRenderer::draw_circle(r, g, b, an, circleCenter.getCoordinates('X'), circleCenter.getCoordinates('Y'), R);
}

/**
 * @brief Fills the circle with a specified color and boundary color.
 *
 * Uses the boundary fill algorithm provided by the PrimitiveRenderer.
 *
 * @param fillColor Fill color for the circle.
 * @param boundryColor Boundary color for the circle.
 */
void Circle::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
    PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(), circleCenter.getCoordinates('X'), circleCenter.getCoordinates('Y'), fillColor, boundryColor);
}

/**
 * @brief Translates (moves) the circle by a specified offset.
 *
 * @param tx Offset along the x-axis.
 * @param ty Offset along the y-axis.
 */
void Circle::translate(int tx, int ty)
{
    circleCenter.setCoordinates(circleCenter.getCoordinates('X') + tx, circleCenter.getCoordinates('Y') - ty);
}

/**
 * @brief Rotates the circle's center around the origin by a specified angle.
 *
 * @param alfa Angle of rotation in degrees.
 */
void Circle::rotate(double alfa)
{
    double alfaRad = alfa * M_PI / 180.0;

    int x_point = circleCenter.getCoordinates('X') + R * cos(alfaRad);
    int y_point = circleCenter.getCoordinates('Y') + R * sin(alfaRad);
    circleCenter.setCoordinates(x_point, y_point);
}

/**
 * @brief Rotates the circle's center around a specified point by a given angle.
 *
 * @param alfa Angle of rotation in degrees.
 * @param x X-coordinate of the rotation point.
 * @param y Y-coordinate of the rotation point.
 */
void Circle::rotatePoint(double alfa, int x, int y)
{
    double alfaRad = alfa * M_PI / 180.0;

    int x_point = circleCenter.getCoordinates('X');
    int y_point = circleCenter.getCoordinates('Y');

    int x_rotated = x_point + (x - x_point) * cos(alfaRad) - (y - y_point) * sin(alfaRad);
    int y_rotated = y_point + (x - x_point) * sin(alfaRad) + (y - y_point) * cos(alfaRad);
    circleCenter.setCoordinates(x_rotated, y_rotated);
}

/**
 * @brief Scales the circle uniformly by a specified factor.
 *
 * @param k Scaling factor. A value greater than 1 enlarges the circle, while a value less than 1 shrinks it.
 */
void Circle::scale(double k)
{
    R = R * k;
}

/**
 * @brief Scales the circle around a specified point by a given factor.
 *
 * This method adjusts both the circle's center position and its radius.
 *
 * @param k Scaling factor. A value greater than 1 enlarges the circle, while a value less than 1 shrinks it.
 * @param x X-coordinate of the scaling point.
 * @param y Y-coordinate of the scaling point.
 */
void Circle::scalePoint(double k, int x, int y)
{
    int x_point = circleCenter.getCoordinates('X');
    int y_point = circleCenter.getCoordinates('Y');

    int x2_point = x_point * k + (1 - k) * x;
    int y2_point = y_point * k + (1 - k) * y;

    circleCenter.setCoordinates(x2_point, y2_point);
    R *= k;
}
