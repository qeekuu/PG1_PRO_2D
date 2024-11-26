/**
 * @file LineSegment.h
 * @brief Declaration of the LineSegment class, representing a line segment defined by two points.
 */

#pragma once
#include "Point2D.h"
#include <iostream>

 /**
  * @class LineSegment
  * @brief Represents a 2D line segment defined by a start and end point.
  *
  * The LineSegment class provides methods to access the start and end points of the segment.
  */
class LineSegment
{
public:
    /**
     * @brief Constructs a LineSegment object with specified start and end points.
     *
     * @param x X-coordinate of the start point.
     * @param y Y-coordinate of the start point.
     * @param x2 X-coordinate of the end point.
     * @param y2 Y-coordinate of the end point.
     */
    LineSegment(int x, int y, int x2, int y2);

    /**
     * @brief Gets the start point of the line segment.
     *
     * @return Reference to the start Point2D object.
     */
    Point2D& getStart();

    /**
     * @brief Gets the end point of the line segment.
     *
     * @return Reference to the end Point2D object.
     */
    Point2D& getEnd();

private:
    Point2D point;  /**< Start point of the line segment. */
    Point2D point2; /**< End point of the line segment. */
};
