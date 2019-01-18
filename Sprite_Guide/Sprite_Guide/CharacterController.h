#pragma once

#include "Sprite.h"

class Player : public Sprite
{

public:
	
	Player(SDL_Renderer* renderer, char* _file, int _w, int _h);

	void Update();


};