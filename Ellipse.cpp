/**
 * @file Ellipse.cpp
 * @brief Implementation of the Ellipse class, representing a 2D ellipse with rendering and transformation capabilities.
 */

#include "Ellipse.h"
#include "PrimitiveRenderer.h"
#include <cmath>

 /**
  * @brief Constructs an Ellipse object with specified color, center position, and radii.
  *
  * @param r Red component of the ellipse's color.
  * @param g Green component of the ellipse's color.
  * @param b Blue component of the ellipse's color.
  * @param an Alpha (transparency) component of the ellipse's color.
  * @param xc X-coordinate of the ellipse's center.
  * @param yc Y-coordinate of the ellipse's center.
  * @param R Radius along the x-axis (horizontal radius).
  * @param R2 Radius along the y-axis (vertical radius).
  */
Ellipse::Ellipse(Uint8 r, Uint8 g, Uint8 b, Uint8 an, unsigned int xc, unsigned int yc, unsigned int R, unsigned int R2)
    : r{ r }, g{ g }, b{ b }, an{ an }, ellipseCenter{ xc, yc }, R{ R }, R2{ R2 }, rotationAngle{ 0.0 }
{

}

/**
 * @brief Draws the ellipse on the screen.
 *
 * Uses the PrimitiveRenderer to render the ellipse with its current properties.
 */
void Ellipse::draw()
{
    PrimitiveRenderer::draw_ellipse(r, g, b, an, rotationAngle, ellipseCenter.getCoordinates('X'), ellipseCenter.getCoordinates('Y'), R, R2);
}

/**
 * @brief Fills the ellipse with a specified color and boundary color.
 *
 * Uses a boundary fill algorithm to fill the ellipse with a color while respecting its boundaries.
 *
 * @param fillColor The fill color for the ellipse.
 * @param boundryColor The boundary color for the ellipse.
 */
void Ellipse::fill(SDL_Color fillColor, SDL_Color boundryColor)
{
    PrimitiveRenderer::RiteracyjnyBoundaryFill(Engine::getInstance()->getRenderer(), ellipseCenter.getCoordinates('X'), ellipseCenter.getCoordinates('Y'), fillColor, boundryColor);
}

/**
 * @brief Translates (moves) the ellipse by a specified offset.
 *
 * @param tx Offset along the x-axis.
 * @param ty Offset along the y-axis.
 */
void Ellipse::translate(int tx, int ty)
{
    ellipseCenter.setCoordinates(ellipseCenter.getCoordinates('X') + tx, ellipseCenter.getCoordinates('Y') - ty);
}

/**
 * @brief Rotates the ellipse around its center by a specified angle.
 *
 * Currently, this function updates the rotation angle in radians but does not modify the ellipse's points.
 *
 * @param alfa Angle of rotation in degrees.
 */
void Ellipse::rotate(double alfa)
{
    double alfaRad = alfa * M_PI / 180.0;
    rotationAngle += alfaRad;
}

/**
 * @brief Rotates the ellipse around a specified point by a given angle.
 *
 * @param alfa Angle of rotation in degrees.
 * @param x X-coordinate of the rotation point.
 * @param y Y-coordinate of the rotation point.
 *
 * @note This function is not yet implemented.
 */
void Ellipse::rotatePoint(double alfa, int x, int y)
{
    // Implementation pending.
}

/**
 * @brief Scales the ellipse uniformly by a specified factor.
 *
 * @param k Scaling factor. A value greater than 1 enlarges the ellipse, while a value less than 1 shrinks it.
 */
void Ellipse::scale(double k)
{
    R *= k;
    R2 *= k;
}

/**
 * @brief Scales the ellipse around a specified point by a given factor.
 *
 * This method adjusts both the ellipse's center position and its radii.
 *
 * @param k Scaling factor. A value greater than 1 enlarges the ellipse, while a value less than 1 shrinks it.
 * @param x X-coordinate of the scaling point.
 * @param y Y-coordinate of the scaling point.
 */
void Ellipse::scalePoint(double k, int x, int y)
{
    int x_point = ellipseCenter.getCoordinates('X');
    int y_point = ellipseCenter.getCoordinates('Y');

    int x2_point = x_point * k + (1 - k) * x;
    int y2_point = y_point * k + (1 - k) * y;

    ellipseCenter.setCoordinates(x2_point, y2_point);
    R *= k;
    R2 *= k;
}
