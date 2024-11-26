/**
 * @file Player.h
 * @brief Declaration of the Player class and its functionalities.
 */

#pragma once
#include "DrawableObject.h"
#include "Rectangle.h"
#include "TransformableObject.h"
#include "UpdatableObject.h"
#include "Point2D.h"
#include "SpriteObject.h"
#include <SDL_stdinc.h>

 /**
  * @class Player
  * @brief Represents a player in the game, inheriting functionalities from UpdatableObject, DrawableObject, TransformableObject, and AnimatedObject.
  *
  * The Player class encapsulates the properties and behaviors of a player, such as drawing, updating, animating, and performing transformations.
  */
class Player : public UpdatableObject, public DrawableObject, public TransformableObject, public AnimatedObject
{
public:
    /**
     * @brief Constructs a Player object with the given color and rectangle coordinates.
     *
     * @param r Red component of the player's rectangle color.
     * @param g Green component of the player's rectangle color.
     * @param b Blue component of the player's rectangle color.
     * @param a Alpha (transparency) component of the player's rectangle color.
     * @param x1, y1 Coordinates of the top-left corner of the rectangle.
     * @param x2, y2 Coordinates of the top-right corner of the rectangle.
     * @param x3, y3 Coordinates of the bottom-right corner of the rectangle.
     * @param x4, y4 Coordinates of the bottom-left corner of the rectangle.
     */
    Player(Uint8 r, Uint8 g, Uint8 b, Uint8 a, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int x3, unsigned int y3, unsigned int x4, unsigned int y4);

    /**
     * @brief Gets the rectangle representing the player.
     *
     * @return Reference to the player's rectangle.
     */
    Rectangle& getRect()
    {
        return rectangle;
    }

    /**
     * @brief Destroys the Player object and releases resources.
     */
    ~Player();

    /**
     * @brief Draws the player on the screen.
     */
    void draw() override;

    /**
     * @brief Updates the player's position and state based on input.
     */
    void update() override;

    /**
     * @brief Animates the player's sprite based on its current state.
     */
    void animate() override;

private:
    Uint8 r, g, b, a; /**< Color components of the player's rectangle. */
    Rectangle rectangle; /**< Rectangle representing the player. */

    /* TransformableObject */

    /**
     * @brief Translates (moves) the player by a given offset.
     *
     * @param tx Offset along the x-axis.
     * @param ty Offset along the y-axis.
     */
    void translate(int tx, int ty) override;

    /**
     * @brief Rotates the player by a given angle relative to the origin.
     *
     * @param alfa Angle of rotation in degrees.
     */
    void rotate(double alfa) override;

    /**
     * @brief Rotates the player around a specific point by a given angle.
     *
     * @param alfa Angle of rotation in degrees.
     * @param x X-coordinate of the rotation point.
     * @param y Y-coordinate of the rotation point.
     */
    void rotatePoint(double alfa, int x, int y) override;

    /**
     * @brief Scales the player uniformly by a given factor.
     *
     * @param k Scaling factor.
     */
    void scale(double k) override;

    /**
     * @brief Scales the player around a specific point by a given factor.
     *
     * @param k Scaling factor.
     * @param x X-coordinate of the scaling point.
     * @param y Y-coordinate of the scaling point.
     */
    void scalePoint(double k, int x, int y) override;

    /* DrawableObject */

    /**
     * @brief Fills the player's rectangle with a specified color and boundary color.
     *
     * @param fillColor Fill color for the rectangle.
     * @param boundryColor Boundary color for the rectangle.
     */
    void fill(SDL_Color fillColor, SDL_Color boundryColor) override;
};
