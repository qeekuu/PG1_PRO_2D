#include "Input.h"
#include <SDL2/SDL.h>
#include <iostream>
Input::Input()
{
    Key_State = SDL_GetKeyboardState(nullptr);
    buttonsState[LEFT_BUTTON] = false;
    buttonsState[RIGHT_BUTTON] = false;
    buttonsState[MIDDLE_BUTTON] = false;
}
Input* Input::getInstances()
{
    if (!instance)
    {
        instance = new Input;
    }
    return instance;
}
void Input::keyE()
{
    Key_State = SDL_GetKeyboardState(nullptr);
}
bool Input::getKey(SDL_Scancode key)
{
    return (Key_State[key] == 1);
}
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
            //Obsluga dla KEYUP - Dodac
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
Input *Input::instance = nullptr;
