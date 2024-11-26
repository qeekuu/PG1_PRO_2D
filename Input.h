/**
 * @file Input.h
 * @brief Declaration of the Input class for handling keyboard and mouse input.
 */

#pragma once
#include <iostream>
#include <SDL.h>
#include "Engine.h"
#include <map>

 /**
  * @class Input
  * @brief Handles user input via keyboard and mouse.
  *
  * The Input class provides methods to check the state of keyboard keys and mouse buttons.
  * It implements a singleton pattern to ensure a single instance across the application.
  */
class Input
{
public:
    /**
     * @enum buttonsType
     * @brief Enum for mouse button types.
     */
    enum buttonsType
    {
        LEFT_BUTTON = 1,   /**< Left mouse button. */
        RIGHT_BUTTON = 2,  /**< Right mouse button. */
        MIDDLE_BUTTON = 3  /**< Middle mouse button. */
    };

    /**
     * @brief Gets the singleton instance of the Input class.
     *
     * @return Pointer to the singleton instance.
     */
    static Input* getInstances();

    /**
     * @brief Listens for SDL events such as keyboard and mouse inputs.
     *
     * This method processes SDL events and updates the internal state of keys and mouse buttons.
     */
    void listen();

    /**
     * @brief Checks if a specific key is pressed.
     *
     * @param key SDL_Scancode representing the key to check.
     * @return True if the key is pressed, false otherwise.
     */
    bool getKey(SDL_Scancode key);

    /**
     * @brief Checks if a specific mouse button is pressed.
     *
     * @param button Enum value representing the mouse button to check.
     * @return True if the button is pressed, false otherwise.
     */
    bool getButton(buttonsType button);

private:
    const Uint8* Key_State; /**< Pointer to the current keyboard state. */
    static Input* instance; /**< Singleton instance of the Input class. */
    std::map<buttonsType, bool> buttonsState; /**< Map to track the state of mouse buttons. */

    /**
     * @brief Private constructor for the Input class.
     *
     * Initializes the keyboard state and sets all mouse buttons to not pressed.
     */
    Input();

    /**
     * @brief Updates the internal keyboard state.
     *
     * This method is called whenever a key event occurs to refresh the key state.
     */
    void keyE();
};
