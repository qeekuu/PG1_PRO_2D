#include "Engine.h"
#include <SDL_scancode.h>
#include <iostream>
#include <SDL.h>
#include "Input.h"
#include "Player.h"

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



Engine* Engine::getInstance() 
{
    if (!instance) 
    {
        instance = new Engine;
    }
    return instance;
}

SDL_Renderer* Engine::getRenderer()
{
    return renderer;
}

bool Engine::running()
{
    return isRunning;
}



void Engine::setRunning(bool quit)
{
    this->isRunning = quit;
}


void Engine::update()
{
}



void Engine::getWindowSize()
{
    std::cout << windowW << std::endl << windowH << std::endl;
}



void Engine::setWindowSize(int wiW, int wiH)
{
    this->windowW = wiW;
    this->windowH = wiH;
    SDL_SetWindowSize(window, windowW, windowH);
}



void Engine::setWindowTitle(const char* title)
{
    this->title = title;
}



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

Engine* Engine::instance = nullptr; 
