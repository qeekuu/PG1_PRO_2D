/**
 * @file Point2D.h
 * @brief Declaration of the Point2D class, representing a point in 2D space.
 */

#pragma once
#include <iostream>

 /**
  * @class Point2D
  * @brief Represents a point in 2D space with x and y coordinates.
  *
  * The Point2D class provides methods for retrieving and modifying the coordinates of a 2D point.
  */
class Point2D
{
public:
    /**
     * @brief Retrieves the x or y coordinate based on the specified character.
     *
     * @param sign Character indicating which coordinate to retrieve ('X' for x-coordinate, 'Y' for y-coordinate).
     * @return The value of the requested coordinate.
     */
    int getCoordinates(char sign);

    /**
     * @brief Sets the x and y coordinates of the point.
     *
     * @param x New x-coordinate of the point.
     * @param y New y-coordinate of the point.
     */
    void setCoordinates(unsigned int x, unsigned int y);

    /**
     * @brief Sets the x-coordinate of the point.
     *
     * @param x New x-coordinate of the point.
     */
    void setCoordinatesX(unsigned int x);

    /**
     * @brief Sets the y-coordinate of the point.
     *
     * @param y New y-coordinate of the point.
     */
    void setCoordinatesY(unsigned int y);

    /**
     * @brief Constructs a Point2D object with specified x and y coordinates.
     *
     * @param x Initial x-coordinate of the point.
     * @param y Initial y-coordinate of the point.
     */
    Point2D(unsigned int x, unsigned int y);

private:
    unsigned int x; /**< The x-coordinate of the point. */
    unsigned int y; /**< The y-coordinate of the point. */
};
