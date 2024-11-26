/**
 * @file Input.cpp
 * @brief Implementation of the Input class for handling user input.
 */

#include "Input.h"
#include <SDL.h>
#include <iostream>

 /**
  * @brief Constructs the Input object and initializes button states.
  */
Input::Input()
{
    Key_State = SDL_GetKeyboardState(nullptr);
    buttonsState[LEFT_BUTTON] = false;
    buttonsState[RIGHT_BUTTON] = false;
    buttonsState[MIDDLE_BUTTON] = false;
}

/**
 * @brief Gets the singleton instance of the Input class.
 *
 * @return Pointer to the singleton instance.
 */
Input* Input::getInstances()
{
    if (!instance)
    {
        instance = new Input;
    }
    return instance;
}

/**
 * @brief Updates the internal keyboard state.
 *
 * This method refreshes the state of all keys.
 */
void Input::keyE()
{
    Key_State = SDL_GetKeyboardState(nullptr);
}

/**
 * @brief Checks if a specific key is pressed.
 *
 * @param key SDL_Scancode representing the key to check.
 * @return True if the key is pressed, false otherwise.
 */
bool Input::getKey(SDL_Scancode key)
{
    return (Key_State[key] == 1);
}

/**
 * @brief Checks if a specific mouse button is pressed.
 *
 * @param button Enum value representing the mouse button to check.
 * @return True if the button is pressed, false otherwise.
 */
bool Input::getButton(buttonsType button)
{
    if (button == LEFT_BUTTON)
    {
        return buttonsState[LEFT_BUTTON];
    }
    else if (button == RIGHT_BUTTON)
    {
        return buttonsState[RIGHT_BUTTON];
    }
    else if (button == MIDDLE_BUTTON)
    {
        return buttonsState[MIDDLE_BUTTON];
    }
    else
    {
        return false;
    }
}

/**
 * @brief Listens for SDL events and updates input states accordingly.
 *
 * This method handles keyboard and mouse button events, updating their states.
 * It also listens for SDL_QUIT events to signal application termination.
 */
void Input::listen()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
        case SDL_KEYDOWN:
            keyE();
            break;
            // TODO: Add handling for SDL_KEYUP
        case SDL_MOUSEBUTTONDOWN:
            if (e.button.button == SDL_BUTTON_LEFT) {
                buttonsState[LEFT_BUTTON] = true;
            }
            else if (e.button.button == SDL_BUTTON_RIGHT) {
                buttonsState[RIGHT_BUTTON] = true;
            }
            else if (e.button.button == SDL_BUTTON_MIDDLE) {
                buttonsState[MIDDLE_BUTTON] = true;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            if (e.button.button == SDL_BUTTON_LEFT) {
                buttonsState[LEFT_BUTTON] = false;
            }
            else if (e.button.button == SDL_BUTTON_RIGHT) {
                buttonsState[RIGHT_BUTTON] = false;
            }
            else if (e.button.button == SDL_BUTTON_MIDDLE) {
                buttonsState[MIDDLE_BUTTON] = false;
            }
            break;
        case SDL_QUIT:
            Engine::getInstance()->close();
            break;
        }
    }
}

// Initialize the static instance pointer.
Input* Input::instance = nullptr;
