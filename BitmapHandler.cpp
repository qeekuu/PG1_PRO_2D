/**
 * @file BitmapHandler.cpp
 * @brief Implementation of the BitmapHandler class for handling bitmap-related operations.
 */

#include "BitmapHandler.h"
#include "Engine.h"

 /**
  * @brief Default constructor for the BitmapHandler class.
  */
BitmapHandler::BitmapHandler() {}

/**
 * @brief Creates an SDL surface with the specified dimensions.
 *
 * @param width Width of the surface.
 * @param height Height of the surface.
 * @return Pointer to the created SDL_Surface or nullptr if creation failed.
 */
SDL_Surface* BitmapHandler::createSurface(int width, int height)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    if (surface == nullptr)
        std::cerr << "Error: Cannot create a surface." << std::endl;

    return surface;
}

/**
 * @brief Loads a BMP file as an SDL texture.
 *
 * @param filePath Path to the BMP file.
 * @param renderer SDL_Renderer used for creating the texture.
 * @param pt Optional SDL_Rect for defining position and size.
 * @return Pointer to the created SDL_Texture or nullptr if loading failed.
 */
SDL_Texture* BitmapHandler::bmpSurface(const char* filePath, SDL_Renderer* renderer, SDL_Rect* pt)
{
    SDL_Surface* bmpSurface = SDL_LoadBMP(filePath);

    if (bmpSurface == nullptr)
    {
        std::cerr << "SDL_LoadBMP error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, bmpSurface);
    SDL_FreeSurface(bmpSurface);

    if (texture == nullptr)
    {
        std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_RenderCopy(renderer, texture, nullptr, pt);
    return texture;
}

/**
 * @brief Animates a BMP sprite by cycling through its frames.
 *
 * @param renderer SDL_Renderer used for rendering.
 * @param texture SDL_Texture of the sprite sheet.
 * @param spriteClips Array of SDL_Rect defining individual frames.
 * @param numDirections Number of animation directions.
 * @param direction Current animation direction.
 * @param currentFrame Reference to the current animation frame index.
 * @param dstRect Destination rectangle for rendering.
 * @param frameDelay Delay between frames in milliseconds.
 * @param framesPerDirection Number of frames per direction.
 */
void BitmapHandler::animateBMPSprite(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect** spriteClips, int numDirections, int direction, int& currentFrame, SDL_Rect* dstRect, int frameDelay, const int framesPerDirection)
{
    static Uint32 lastTime = SDL_GetTicks();
    Uint32 currentTime = SDL_GetTicks();

    if (currentTime > lastTime + frameDelay) {
        currentFrame = (currentFrame + 1) % framesPerDirection;
        lastTime = currentTime;
    }

    if (direction >= 0 && direction < numDirections && spriteClips[direction]) {
        SDL_RenderCopy(renderer, texture, &spriteClips[direction][currentFrame], dstRect);
    }
}

/**
 * @brief Divides a sprite sheet into individual frames.
 *
 * @param numDirections Number of animation directions.
 * @param framesPerDirection Number of frames per direction.
 * @param frameWidth Width of each frame.
 * @param frameHeight Height of each frame.
 * @param directionMapping Optional array for custom direction mapping.
 * @return 2D array of SDL_Rect pointers representing sprite clips.
 */
SDL_Rect** BitmapHandler::createSpriteClips(int numDirections, int framesPerDirection, int frameWidth, int frameHeight, int* directionMapping)
{
    SDL_Rect** spriteClips = new SDL_Rect * [numDirections];

    for (int dir = 0; dir < numDirections; ++dir) {
        spriteClips[dir] = new SDL_Rect[framesPerDirection];

        int mappedDir = directionMapping ? directionMapping[dir] : dir;

        for (int frame = 0; frame < framesPerDirection; ++frame) {
            spriteClips[dir][frame].x = frame * frameWidth;
            spriteClips[dir][frame].y = mappedDir * frameHeight;
            spriteClips[dir][frame].w = frameWidth;
            spriteClips[dir][frame].h = frameHeight;
        }
    }

    return spriteClips;
}

/**
 * @brief Frees memory allocated for sprite clips.
 *
 * @param spriteClips 2D array of SDL_Rect pointers.
 * @param numDirections Number of animation directions.
 */
void BitmapHandler::freeSpriteClips(SDL_Rect** spriteClips, int numDirections)
{
    for (int dir = 0; dir < numDirections; ++dir) {
        delete[] spriteClips[dir];
    }
    delete[] spriteClips;
}

/**
 * @brief Saves an SDL surface to a BMP file.
 *
 * @param surface SDL_Surface to save.
 * @param filePath Path for saving the BMP file.
 * @return 0 on success, or an error code on failure.
 */
int BitmapHandler::saveSurfaceAsBMP(SDL_Surface* surface, const char* filePath)
{
    if (surface == nullptr)
    {
        std::cerr << "Error: Surface is null, cannot save to BMP." << std::endl;
        return -1;
    }

    int result = SDL_SaveBMP(surface, filePath);
    if (result != 0)
    {
        std::cerr << "SDL_SaveBMP error: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "Bitmap saved successfully." << std::endl;
    }
    return result;
}

/**
 * @brief Copies a region of a source surface to a destination surface.
 *
 * @param src Source SDL_Surface.
 * @param srcrect Source rectangle (optional).
 * @param dst Destination SDL_Surface.
 * @param dstrect Destination rectangle (optional).
 * @return 0 on success, or an error code on failure.
 */
int BitmapHandler::copyBitmapSurface(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect)
{
    if (src == nullptr)
    {
        std::cerr << "Error: Source surface does not exist." << std::endl;
        return -1;
    }

    if (dst == nullptr)
    {
        std::cerr << "Error: Destination surface does not exist." << std::endl;
        return -1;
    }

    int result = SDL_BlitSurface(src, srcrect, dst, dstrect);
    if (result != 0)
    {
        std::cerr << "SDL_BlitSurface error: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "Bitmap copied successfully." << std::endl;
    }
    return result;
}

/**
 * @brief Deletes an SDL texture and releases its memory.
 *
 * @param texture SDL_Texture to delete.
 */
void BitmapHandler::deleteTexture(SDL_Texture* texture)
{
    if (texture != nullptr)
        SDL_DestroyTexture(texture);
    texture = nullptr;
}

/**
 * @brief Deletes an SDL surface and releases its memory.
 *
 * @param surface SDL_Surface to delete.
 */
void BitmapHandler::deleteSurface(SDL_Surface* surface)
{
    if (surface != nullptr)
        SDL_FreeSurface(surface);
    surface = nullptr;
}
