 /**
 * @file Point2D.cpp
 * @brief Implementation of the Point2D class, representing a point in 2D space.
 */

#include "Point2D.h"
#include <iostream>

 /**
  * @brief Constructs a Point2D object with specified x and y coordinates.
  *
  * @param x Initial x-coordinate of the point.
  * @param y Initial y-coordinate of the point.
  */
Point2D::Point2D(unsigned int x, unsigned int y) : x{ x }, y{ y }
{

}

/**
 * @brief Retrieves the x or y coordinate based on the specified character.
 *
 * @param sign Character indicating which coordinate to retrieve ('X' for x-coordinate, 'Y' for y-coordinate).
 * @return The value of the requested coordinate. Returns -1 if the sign is invalid.
 */
int Point2D::getCoordinates(char sign)
{
    switch (sign)
    {
    case 'X':
        return x;
        break;
    case 'Y':
        return y;
        break;
    default:
        return -1;
        break;
    }
}

/**
 * @brief Sets the x and y coordinates of the point.
 *
 * @param x New x-coordinate of the point.
 * @param y New y-coordinate of the point.
 */
void Point2D::setCoordinates(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;
}

/**
 * @brief Sets the x-coordinate of the point.
 *
 * @param x New x-coordinate of the point.
 */
void Point2D::setCoordinatesX(unsigned int x)
{
    this->x = x;
}

/**
 * @brief Sets the y-coordinate of the point.
 *
 * @param y New y-coordinate of the point.
 */
void Point2D::setCoordinatesY(unsigned int y)
{
    this->y = y;
}
