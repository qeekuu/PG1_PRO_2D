/**
 * @file PrimitiveRenderer.h
 * @brief Declaration of the PrimitiveRenderer class for rendering basic shapes and performing operations on them.
 */

#pragma once
#include <iostream>
#include "Ellipse.h"
#include "Engine.h"
#include <SDL.h>
#include <vector>
#include "Point2D.h"

 /**
  * @class PrimitiveRenderer
  * @brief Provides static methods to render basic shapes (points, rectangles, lines, etc.) and perform geometric operations.
  *
  * The PrimitiveRenderer class includes methods for drawing and filling shapes, as well as performing intersection tests and rendering operations.
  */
class PrimitiveRenderer
{
public:
    /**
     * @brief Sets the window's background color.
     *
     * @param r Red component of the color.
     * @param g Green component of the color.
     * @param b Blue component of the color.
     * @param a Alpha (transparency) component of the color.
     */
    static void setWindowColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    /**
     * @brief Draws a point on the screen at the specified coordinates.
     *
     * @param r Red component of the point's color.
     * @param g Green component of the point's color.
     * @param b Blue component of the point's color.
     * @param a Alpha (transparency) component of the point's color.
     * @param x X-coordinate of the point.
     * @param y Y-coordinate of the point.
     */
    static void draw_point(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x, unsigned int y);

    /**
     * @brief Draws a rectangle on the screen using four corner points.
     *
     * @param r Red component of the rectangle's color.
     * @param g Green component of the rectangle's color.
     * @param b Blue component of the rectangle's color.
     * @param a Alpha (transparency) component of the rectangle's color.
     * @param x1, y1 Coordinates of the first point.
     * @param x2, y2 Coordinates of the second point.
     * @param x3, y3 Coordinates of the third point.
     * @param x4, y4 Coordinates of the fourth point.
     */
    static void draw_rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4);

    /**
     * @brief Draws a triangle on the screen using three points.
     *
     * @param r Red component of the triangle's color.
     * @param g Green component of the triangle's color.
     * @param b Blue component of the triangle's color.
     * @param a Alpha (transparency) component of the triangle's color.
     * @param x1, y1 Coordinates of the first point.
     * @param x2, y2 Coordinates of the second point.
     * @param x3, y3 Coordinates of the third point.
     */
    static void draw_triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3);

    /**
     * @brief Draws a line on the screen between two points.
     *
     * @param r Red component of the line's color.
     * @param g Green component of the line's color.
     * @param b Blue component of the line's color.
     * @param a Alpha (transparency) component of the line's color.
     * @param x1, y1 Coordinates of the first point.
     * @param x2, y2 Coordinates of the second point.
     */
    static void draw_line(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x1, int y1, int x2, int y2);

    /**
     * @brief Draws a circle on the screen with a given center and radius.
     *
     * @param r Red component of the circle's color.
     * @param g Green component of the circle's color.
     * @param b Blue component of the circle's color.
     * @param an Alpha (transparency) component of the circle's color.
     * @param xc X-coordinate of the circle's center.
     * @param yc Y-coordinate of the circle's center.
     * @param R Radius of the circle.
     */
    static void draw_circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R);

    /**
     * @brief Draws an ellipse on the screen with specified center, radii, and rotation.
     *
     * @param r Red component of the ellipse's color.
     * @param g Green component of the ellipse's color.
     * @param b Blue component of the ellipse's color.
     * @param an Alpha (transparency) component of the ellipse's color.
     * @param rotationAngle Rotation angle of the ellipse in degrees.
     * @param xc X-coordinate of the ellipse's center.
     * @param yc Y-coordinate of the ellipse's center.
     * @param R Horizontal radius of the ellipse.
     * @param R2 Vertical radius of the ellipse.
     */
    static void draw_ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, double rotationAngle, int xc, int yc, int R, int R2);

    /**
     * @brief Draws a polygon on the screen based on a list of points.
     *
     * @param r Red component of the polygon's color.
     * @param g Green component of the polygon's color.
     * @param b Blue component of the polygon's color.
     * @param a Alpha (transparency) component of the polygon's color.
     * @param points List of Point2D objects defining the vertices of the polygon.
     */
    static void draw_polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points);

    /**
     * @brief Checks if two line segments intersect.
     *
     * @param point1 First point of the first segment.
     * @param point2 Second point of the first segment.
     * @param point3 First point of the second segment.
     * @param point4 Second point of the second segment.
     * @return True if the segments intersect, false otherwise.
     */
    static bool segmentIntersect(Point2D point1, Point2D point2, Point2D point3, Point2D point4);

    /**
     * @brief Calculates the determinant of a 3x3 matrix.
     *
     * @param mat A 3x3 matrix.
     * @return The determinant of the matrix.
     */
    static int determinant3x3(int mat[3][3]);

    /**
     * @brief Creates an SDL_Color from the specified RGBA components.
     *
     * @param r Red component of the color.
     * @param g Green component of the color.
     * @param b Blue component of the color.
     * @param a Alpha (transparency) component of the color.
     * @return The SDL_Color created from the provided components.
     */
    static SDL_Color fillColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    /**
     * @brief Creates an SDL_Color for the boundary from the specified RGBA components.
     *
     * @param r Red component of the boundary color.
     * @param g Green component of the boundary color.
     * @param b Blue component of the boundary color.
     * @param a Alpha (transparency) component of the boundary color.
     * @return The SDL_Color for the boundary created from the provided components.
     */
    static SDL_Color boundaryColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    /**
     * @brief Performs boundary fill on a given region in the renderer.
     *
     * @param renderer SDL_Renderer used for drawing.
     * @param x X-coordinate of the starting point.
     * @param y Y-coordinate of the starting point.
     * @param fillColor The color to fill the region.
     * @param boundaryColor The color of the boundary.
     */
    static void RiteracyjnyBoundaryFill(SDL_Renderer* renderer, int x, int y, SDL_Color fillColor, SDL_Color boundaryColor);

    /**
     * @brief Renders all the drawn shapes to the screen.
     */
    static void render();
};
