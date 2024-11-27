#pragma once
#include <iostream>
#include <SDL.h>
#include "PrimitiveRenderer.h"

/**
 * @class Engine
 * @brief The main engine class responsible for initializing and managing the game engine.
 */
class Engine {
public:
    /**
     * @brief Get the singleton instance of the Engine class.
     * @return A pointer to the Engine instance.
     */
    static Engine* getInstance();

    /**
     * @brief Initialize the engine.
     * @return True if initialization was successful, false otherwise.
     */
    bool Init();

    /**
     * @brief Close the engine and release resources.
     */
    void close();

 

    /**
     * @brief Check if the engine is currently running.
     * @return True if the engine is running, false otherwise.
     */
    bool running();

    /**
     * @brief Get the current window size.
     */
    void getWindowSize();

    /**
     * @brief Get the SDL_Renderer instance used by the engine.
     * @return A pointer to the SDL_Renderer instance.
     */
    SDL_Renderer* getRenderer();

    /**
     * @brief Set the window size.
     * @param wiW The width of the window.
     * @param wiH The height of the window.
     */
    void setWindowSize(int wiW, int wiH);

    /**
     * @brief Set the window title.
     * @param title A string representing the new window title.
     */
    void setWindowTitle(const char* title);

    /**
     * @brief Set the running state of the engine.
     * @param quit The new running state. True to stop the engine, false to keep it running.
     */
    void setRunning(bool quit);

private:
    static Engine* instance;        /**< Singleton instance of the Engine class. */
    SDL_Window* window = nullptr;   /**< Pointer to the SDL_Window instance. */
    SDL_Renderer* renderer = nullptr; /**< Pointer to the SDL_Renderer instance. */
    bool isRunning = false;         /**< Indicates whether the engine is running. */
    int windowW = 800;              /**< Width of the window. */
    int windowH = 600;              /**< Height of the window. */
    const char* title = "";         /**< Title of the window. */

    /**
     * @brief Private constructor to prevent direct instantiation.
     */
    Engine() {}
};
