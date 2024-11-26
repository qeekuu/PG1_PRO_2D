/**
 * @file PrimitiveRenderer.h
 * @brief Implementation of rendering primitives for graphical applications using SDL.
 *
 * This file provides the implementation for rendering basic graphical primitives such as
 * points, lines, rectangles, triangles, circles, ellipses, and polygons. It also includes
 * utility methods for boundary fill algorithms and rendering.
 */

#include "PrimitiveRenderer.h"
#include <cmath>
#include <iostream>
#include "Ellipse.h"
#include "Engine.h"
#include <SDL.h>
#include <SDL_rect.h>
#include <math.h>
#include <vector>
#include "Point2D.h"
#include <stack>
#include <utility>

 /**
  * @brief Sets the background color of the rendering window.
  *
  * @param r Red component of the windows color.
  * @param g Green component of the windows color.
  * @param b Blue component of the windows color.
  * @param a Alpha component of the windows color.
  */
void PrimitiveRenderer::setWindowColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
    SDL_RenderClear(Engine::getInstance()->getRenderer());
}

/**
 * @brief Draws a point on the rendering window.
 *
 * @param r Red component of the points color.
 * @param g Green component of the points color.
 * @param b Blue component of the points color.
 * @param a Alpha component of the points color.
 * @param x X-coordinate of the point.
 * @param y Y-coordinate of the point.
 */
void PrimitiveRenderer::draw_point(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x, unsigned int y)
{
    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
    SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), x, y);
}

/**
 * @brief Draws a rectangle using four specified vertices.
 *
 * @param r Red component of the rectangle's.
 * @param g Green component of the rectangle's.
 * @param b Blue component of the rectangle's.
 * @param a Alpha component of the rectangle's.
 * @param x1, y1 Coordinates of the first vertex.
 * @param x2, y2 Coordinates of the second vertex.
 * @param x3, y3 Coordinates of the third vertex.
 * @param x4, y4 Coordinates of the fourth vertex.
 */
void PrimitiveRenderer::draw_rectangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4)
{
    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
    draw_line(r, g, b, a, x1, y1, x2, y2);
    draw_line(r, g, b, a, x2, y2, x3, y3);
    draw_line(r, g, b, a, x3, y3, x4, y4);
    draw_line(r, g, b, a, x4, y4, x1, y1);
}

/**
 * @brief Draws a triangle using three specified vertices.
 *
 * @param r Red component of the triangle's color.
 * @param g Green component of the triangle's color.
 * @param b Blue component of the triangle's color.
 * @param a Alpha component of the triangle's color.
 * @param x1, y1 Coordinates of the first vertex.
 * @param x2, y2 Coordinates of the second vertex.
 * @param x3, y3 Coordinates of the third vertex.
 */
void PrimitiveRenderer::draw_triangle(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3)
{
    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
    draw_line(r, g, b, a, x1, y1, x2, y2);
    draw_line(r, g, b, a, x2, y2, x3, y3);
    draw_line(r, g, b, a, x3, y3, x1, y1);
}

/**
 * @brief Draws a line using the Bresenham algorithm.
 *
 * @param r Red component of the line color.
 * @param g Green component of the line color.
 * @param b Blue component of the line color.
 * @param a Alpha component of the line color.
 * @param x1, y1 Starting coordinates of the line.
 * @param x2, y2 Ending coordinates of the line.
 */
void PrimitiveRenderer::draw_line(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, a);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

/**
 * @brief Draws a circle centered at the specified coordinates.
 *
 * @param r Red component of the circle's color.
 * @param g Green component of the circle's color.
 * @param b Blue component of the circle's color.
 * @param a Alpha component of the circle's color.
 * @param xc, yc Center coordinates of the circle.
 * @param R Radius of the circle.
 */
void PrimitiveRenderer::draw_circle(Uint8 r, Uint8 g, Uint8 b, Uint8 an, int xc, int yc, int R)
{
    float a = 0.0, step;
    int x, y;
    step = 1.0 / R;
    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, an);
    for (a; a < M_PI / 4; a += step)
    {
        x = R * cos(a) + 0.5;
        y = R * sin(a) + 0.5;
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc + y, xc - x);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x, yc - y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x, yc + y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc + y, xc + x);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc - y, xc + x);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x, yc + y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x, yc - y);
        SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), yc - y, xc - x);
    }
}

/**
 * @brief Draws an ellipse with specified parameters.
 *
 * @param r Red component of the ellipse color.
 * @param g Green component of the ellipse color.
 * @param b Blue component of the ellipse color.
 * @param an Alpha component of the ellipse color.
 * @param rotationAngle Rotation angle of the ellipse in radians.
 * @param xc X-coordinate of the center of the ellipse.
 * @param yc Y-coordinate of the center of the ellipse.
 * @param R Horizontal radius of the ellipse.
 * @param R2 Vertical radius of the ellipse.
 */
void PrimitiveRenderer::draw_ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, double rotationAngle, int xc, int yc, int R, int R2)
{
    float a = 0.0;
    int x, y;
    float step = M_PI / (4 * std::max(R, R2));  // Resolution of the ellipse drawing.

    SDL_SetRenderDrawColor(Engine::getInstance()->getRenderer(), r, g, b, an);

    for (a = 0; a < 2 * M_PI; a += step)
    {
        x = R * cos(a);
        y = R2 * sin(a);

        if (rotationAngle != 0)
        {
            int x2 = x * cos(rotationAngle) - y * sin(rotationAngle);
            int y2 = x * sin(rotationAngle) + y * cos(rotationAngle);

            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x2, yc + y2);
            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x2, yc + y2);
            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x2, yc - y2);
            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x2, yc - y2);
        }
        else
        {
            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x, yc + y);
            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x, yc + y);
            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc + x, yc - y);
            SDL_RenderDrawPoint(Engine::getInstance()->getRenderer(), xc - x, yc - y);
        }
    }
}

/**
 * @brief Computes the determinant of a 3x3 matrix.
 *
 * @param mat A 3x3 matrix represented as a 2D array.
 * @return int The determinant of the matrix.
 */
int PrimitiveRenderer::determinant3x3(int mat[3][3])
{
    return  mat[0][0] * mat[1][1] * mat[2][2]
        + mat[0][1] * mat[1][2] * mat[2][0]
        + mat[0][2] * mat[1][0] * mat[2][1]
        - mat[0][2] * mat[1][1] * mat[2][0]
        - mat[0][1] * mat[1][0] * mat[2][2]
        - mat[0][0] * mat[1][2] * mat[2][1];
}


/**
 * @brief Checks if two line segments intersect.
 *
 * This function uses the determinant of 3x3 matrices to calculate the orientation of the
 * points and determine whether two segments intersect.
 *
 * @param point1 First endpoint of the first segment.
 * @param point2 Second endpoint of the first segment.
 * @param point3 First endpoint of the second segment.
 * @param point4 Second endpoint of the second segment.
 * @return true if the segments intersect, false otherwise.
 */
bool PrimitiveRenderer::segmentIntersect(Point2D point1, Point2D point2, Point2D point3, Point2D point4)
{
    int s1[3][3] = { {point1.getCoordinates('X'), point3.getCoordinates('X'), point4.getCoordinates('X')},
                     {point1.getCoordinates('Y'), point3.getCoordinates('Y'), point4.getCoordinates('Y')},
                     {1, 1, 1}
    };

    int s2[3][3] = { {point2.getCoordinates('X'), point3.getCoordinates('X'), point4.getCoordinates('X')},
                     {point2.getCoordinates('Y'), point3.getCoordinates('Y'), point4.getCoordinates('Y')},
                     {1, 1, 1}
    };

    int s3[3][3] = { {point3.getCoordinates('X'), point1.getCoordinates('X'), point2.getCoordinates('X')},
                     {point3.getCoordinates('Y'), point1.getCoordinates('Y'), point2.getCoordinates('Y')},
                     {1, 1, 1}
    };

    int s4[3][3] = { {point4.getCoordinates('X'), point1.getCoordinates('X'), point2.getCoordinates('X')},
                     {point4.getCoordinates('Y'), point1.getCoordinates('Y'), point2.getCoordinates('Y')},
                     {1, 1, 1}
    };

    int detS1 = determinant3x3(s1);
    int detS2 = determinant3x3(s2);
    int detS3 = determinant3x3(s3);
    int detS4 = determinant3x3(s4);

    if ((detS1 < 0 && detS2 > 0 && detS3 > 0 && detS4 < 0) ||
        (detS1 > 0 && detS2 < 0 && detS3 < 0 && detS4 > 0))
    {
        return true;
    }
    else if (detS1 == 0 && detS2 == 0 && detS3 == 0 && detS4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Draws a polygon using a list of points.
 *
 * The function validates if the polygon is simple (no intersecting edges) and
 * then draws its edges using the provided color and alpha parameters.
 *
 * @param r Red component of the polygon's color.
 * @param g Green component of the polygon's color.
 * @param b Blue component of the polygon's color.
 * @param a Alpha component of the polygon's color.
 * @param points Vector of Point2D objects representing the vertices of the polygon.
 */
void PrimitiveRenderer::draw_polygon(Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::vector<Point2D>& points)
{
    for (int i = 0; i < points.size(); i++)
    {
        Point2D& p1 = points[i];
        Point2D& p2 = points[(i + 1) % points.size()];

        for (int j = i + 2; j < points.size(); j++)
        {
            Point2D& p3 = points[j];
            Point2D& p4 = points[(j + 1) % points.size()];

            if (segmentIntersect(p1, p2, p3, p4))
            {
                return; // Abort if the polygon has intersecting edges.
            }
        }
    }

    for (int i = 0; i < points.size() - 1; i++)
    {
        draw_line(r, g, b, a, points[i].getCoordinates('X'), points[i].getCoordinates('Y'),
            points[i + 1].getCoordinates('X'), points[i + 1].getCoordinates('Y'));
    }
    draw_line(r, g, b, a, points.back().getCoordinates('X'), points.back().getCoordinates('Y'),
        points.front().getCoordinates('X'), points.front().getCoordinates('Y'));
}


/**
 * @brief Creates an SDL_Color object representing a fill color.
 *
 * @param r Red component of the fillcolor.
 * @param g Green component of the fillcolor.
 * @param b Blue component of the fillcolor.
 * @param a Alpha component of the fillcolor.
 * @return SDL_Color The SDL_Color object representing the fill color.
 */
SDL_Color PrimitiveRenderer::fillColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Color fillColor = { r, g, b, a };
    return fillColor;
}

/**
 * @brief Creates an SDL_Color object representing a boundary color.
 *
 * @param r Red component of the voundary color.
 * @param g Green component of the voundary color.
 * @param b Blue component of the voundary color.
 * @param a Alpha component of the voundary color.
 * @return SDL_Color The SDL_Color object representing the boundary color.
 */
SDL_Color PrimitiveRenderer::boundaryColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Color boundaryColor = { r, g, b, a };
    return boundaryColor;
}

/**
 * @brief Fills a region using the iterative boundary fill algorithm.
 *
 * This function uses a stack-based iterative approach to fill a closed region
 * with the specified fill color. It stops at the boundary color.
 *
 * @param renderer Pointer to the SDL_Renderer instance.
 * @param x X-coordinate of the starting point.
 * @param y Y-coordinate of the starting point.
 * @param fillColor The fill color to use.
 * @param boundaryColor The boundary color to stop at.
 */
void PrimitiveRenderer::RiteracyjnyBoundaryFill(SDL_Renderer* renderer, int x, int y, SDL_Color fillColor, SDL_Color boundaryColor)
{
    if (renderer == nullptr)
        return;

    SDL_RenderFlush(renderer);
    std::stack<std::pair<int, int>> DSD;
    DSD.push({ x, y });

    int width, height;
    SDL_GetRendererOutputSize(renderer, &width, &height);

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
    SDL_RenderReadPixels(renderer, nullptr, SDL_PIXELFORMAT_RGBA32, surface->pixels, surface->pitch);

    Uint32* pixels = (Uint32*)surface->pixels;
    int pitch = surface->pitch / sizeof(Uint32);

    Uint32 fillColorUint32 = SDL_MapRGBA(surface->format, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
    Uint32 boundaryColorUint32 = SDL_MapRGBA(surface->format, boundaryColor.r, boundaryColor.g, boundaryColor.b, boundaryColor.a);

    while (!DSD.empty())
    {
        auto P = DSD.top();
        DSD.pop();

        int px = P.first;
        int py = P.second;

        if (px < 0 || px >= width || py < 0 || py >= height)
            continue;

        Uint32 currentColor = pixels[py * pitch + px];

        if (currentColor == fillColorUint32 || currentColor == boundaryColorUint32)
            continue;

        pixels[py * pitch + px] = fillColorUint32;

        if (px > 0)
            DSD.push({ px - 1, py }); // West
        if (px < width - 1)
            DSD.push({ px + 1, py }); // East
        if (py > 0)
            DSD.push({ px, py - 1 }); // North
        if (py < height - 1)
            DSD.push({ px, py + 1 }); // South
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_DestroyTexture(texture);
}

/**
 * @brief Presents the rendered content to the screen.
 *
 * This function finalizes the rendering process and displays the contents
 * of the renderer on the screen.
 */
void PrimitiveRenderer::render()
{
    SDL_RenderPresent(Engine::getInstance()->getRenderer());
}

