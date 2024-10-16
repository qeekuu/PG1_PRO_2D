#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "PrimitiveRenderer.h"
class Engine {
public:
    static Engine* getInstance();
    bool Init();
    void close();
    void update();
    bool running();
    void getWindowSize();
    void setWindowSize(int wiW,int wiH);
    void setWindowTitle(const char* title);
    void setRunning(bool quit);
private:
    friend class PrimitiveRenderer;
    static Engine* instance;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning;
    int windowW = 800;
    int windowH = 600;
    const char* title = "";
    Engine() {}

};

