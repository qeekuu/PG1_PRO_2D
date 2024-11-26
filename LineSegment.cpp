/**
 * @file LineSegment.cpp
 * @brief Implementation of the LineSegment class.
 */

#include "LineSegment.h"
#include "Point2D.h"

 /**
  * @brief Constructs a LineSegment object with specified start and end points.
  *
  * @param x X-coordinate of the start point.
  * @param y Y-coordinate of the start point.
  * @param x2 X-coordinate of the end point.
  * @param y2 Y-coordinate of the end point.
  */
LineSegment::LineSegment(int x, int y, int x2, int y2) : point(x, y), point2(x2, y2)
{

}

/**
 * @brief Gets the start point of the line segment.
 *
 * @return Reference to the start Point2D object.
 */
Point2D& LineSegment::getStart()
{
    return point;
}

/**
 * @brief Gets the end point of the line segment.
 *
 * @return Reference to the end Point2D object.
 */
Point2D& LineSegment::getEnd()
{
    return point2;
}
