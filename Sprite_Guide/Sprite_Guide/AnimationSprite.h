#pragma once

#include "Sprite.h"

class AnimationSprite : public Sprite
{

public:
	
	AnimationSprite(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, int _cellsPerRow, int _cellsPerCol, int _speed);

	void Update();
	void Draw() override;

private:

	int cellsInRow;
	int cellsInCol;
	int currentRow;
	int currentCol;


	SDL_Rect cellRect;

	int timer;
	int speed;
};