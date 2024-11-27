#include "Engine.h"
#include <SDL_scancode.h>
#include <iostream>
#include <SDL.h>
#include "Input.h"
#include "Player.h"

/**
 * @brief Initialize the engine.
 * @return True if the engine is initialized successfully, false otherwise.
 */
bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "SDL initialization error: " << SDL_GetError() << std::endl;
        isRunning = false;
    }
    else
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowW, windowH, SDL_WINDOW_RESIZABLE);
        if (window == NULL)
        {
            std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
            isRunning = false;
        }
        else
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL)
            {
                std::cerr << "Renderer creation error: " << SDL_GetError() << std::endl;
                isRunning = false;
            }
            isRunning = true;
        }
    }
    return isRunning;
}

/**
 * @brief Get the singleton instance of the Engine class.
 * @return A pointer to the Engine instance.
 */
Engine* Engine::getInstance()
{
    if (!instance)
    {
        instance = new Engine;
    }
    return instance;
}

/**
 * @brief Get the SDL_Renderer instance used by the engine.
 * @return A pointer to the SDL_Renderer instance.
 */
SDL_Renderer* Engine::getRenderer()
{
    return renderer;
}

/**
 * @brief Check if the engine is currently running.
 * @return True if the engine is running, false otherwise.
 */
bool Engine::running()
{
    return isRunning;
}

/**
 * @brief Set the running state of the engine.
 * @param quit The new running state. True to stop the engine, false to keep it running.
 */
void Engine::setRunning(bool quit)
{
    this->isRunning = quit;
}

/**
 * @brief Update the engine state. This function should be called each frame.
 */
void Engine::update()
{
    // Update logic can be implemented here
}

/**
 * @brief Get the current window size and print it to the console.
 */
void Engine::getWindowSize()
{
    std::cout << windowW << std::endl << windowH << std::endl;
}

/**
 * @brief Set the window size.
 * @param wiW The width of the window.
 * @param wiH The height of the window.
 */
void Engine::setWindowSize(int wiW, int wiH)
{
    this->windowW = wiW;
    this->windowH = wiH;
    SDL_SetWindowSize(window, windowW, windowH);
}

/**
 * @brief Set the window title.
 * @param title A string representing the new window title.
 */
void Engine::setWindowTitle(const char* title)
{
    this->title = title;
}

/**
 * @brief Close the engine, release resources, and destroy the singleton instance.
 */
void Engine::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

// Initialize the singleton instance to nullptr
Engine* Engine::instance = nullptr;
