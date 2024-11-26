/**
 * @file BitmapHandler.h
 * @brief Declaration of the BitmapHandler class for handling bitmap-related operations.
 */

#pragma once
#include <iostream>
#include <SDL.h>
#include <string>

 /**
  * @class BitmapHandler
  * @brief Provides utilities for handling bitmaps, including creating, animating, saving, and cleaning up resources.
  */
class BitmapHandler
{
public:
    /**
     * @brief Constructs a BitmapHandler object.
     */
    BitmapHandler();

    /**
     * @brief Creates an SDL surface with the specified dimensions.
     *
     * @param width Width of the surface.
     * @param height Height of the surface.
     * @return Pointer to the created SDL_Surface.
     */
    SDL_Surface* createSurface(int width, int height);

    /**
     * @brief Loads a BMP file as a texture.
     *
     * @param filePath Path to the BMP file.
     * @param renderer SDL_Renderer used to create the texture.
     * @param pt Pointer to an SDL_Rect for defining position and size (optional).
     * @return Pointer to the created SDL_Texture.
     */
    SDL_Texture* bmpSurface(const char* filePath, SDL_Renderer* renderer, SDL_Rect* pt);

    /**
     * @brief Animates a BMP sprite by cycling through its frames.
     *
     * @param renderer SDL_Renderer to render the sprite.
     * @param texture SDL_Texture of the sprite sheet.
     * @param spriteClips Array of SDL_Rect defining individual frames.
     * @param numDirections Number of animation directions.
     * @param direction Current animation direction.
     * @param currentFrame Reference to the current animation frame.
     * @param dstRect Destination rectangle to render the sprite.
     * @param frameDelay Delay between frames.
     * @param framesPerDirection Number of frames in each direction.
     */
    void animateBMPSprite(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect** spriteClips, int numDirections, int direction, int& currentFrame, SDL_Rect* dstRect, int frameDelay, const int framesPerDirection);

    /**
     * @brief Divides a sprite sheet into individual frames.
     *
     * @param numDirections Number of animation directions.
     * @param framesPerDirection Number of frames per direction.
     * @param frameWidth Width of each frame.
     * @param frameHeight Height of each frame.
     * @param directionMapping Optional array to map directions to indices.
     * @return 2D array of SDL_Rect defining the sprite clips.
     */
    SDL_Rect** createSpriteClips(int numDirections, int framesPerDirection, int frameWidth, int frameHeight, int* directionMapping = nullptr);

    /**
     * @brief Frees memory allocated for sprite clips.
     *
     * @param spriteClips 2D array of SDL_Rect defining sprite clips.
     * @param numDirections Number of animation directions.
     */
    void freeSpriteClips(SDL_Rect** spriteClips, int numDirections);

    /**
     * @brief Saves an SDL surface to a BMP file.
     *
     * @param surface SDL_Surface to save.
     * @param filePath Path to save the BMP file.
     * @return 0 on success, or an error code on failure.
     */
    int saveSurfaceAsBMP(SDL_Surface* surface, const char* filePath);

    /**
     * @brief Copies a portion of one bitmap surface to another.
     *
     * @param src Source SDL_Surface.
     * @param srcrect Rectangle defining the source region (optional).
     * @param dst Destination SDL_Surface.
     * @param dstrect Rectangle defining the destination region (optional).
     * @return 0 on success, or an error code on failure.
     */
    int copyBitmapSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);

    /**
     * @brief Deletes an SDL texture and releases its memory.
     *
     * @param texture SDL_Texture to delete.
     */
    void deleteTexture(SDL_Texture* texture);

    /**
     * @brief Deletes an SDL surface and releases its memory.
     *
     * @param surface SDL_Surface to delete.
     */
    void deleteSurface(SDL_Surface* surface);

private:
    // No private members defined for this class.
};
