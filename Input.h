#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include "Engine.h"
#include <map>
class Input
{
public:
	enum buttonsType
	{
		LEFT_BUTTON = 1,
		RIGHT_BUTTON = 2,
		MIDDLE_BUTTON = 3
	};
	static Input* getInstances();
	void listen();
	bool getKey(SDL_Scancode key);
	bool getButton(buttonsType button);
private:
	const Uint8* Key_State;
	static Input* instance;
	std::map <buttonsType,bool>buttonsState;
	Input();
	void keyE();
};
