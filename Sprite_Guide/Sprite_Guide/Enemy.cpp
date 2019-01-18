#include "Enemy.h"

EnemyMovement::EnemyMovement(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h, int _cellsPerRow, int _cellsPerCol, int _speed) :
	Sprite(_renderer, _file, _x, _y, _w, _h)
{

	cellsInRow = _cellsPerRow;
	cellsInCol = _cellsPerCol;

	currentRow = 0;
	currentCol = 0;

	cellRect.x = 0;
	cellRect.y = 0;
	cellRect.w = _w;
	cellRect.h = _h;

	timer = 0;
	speed = _speed;

}

void EnemyMovement::Update()
{

	timer++;

	if (timer >= speed)		// go onto next cel if need to
	{
		timer = 0;			// resets timer

		currentCol++;		//go to next sprite sheet column
		if (currentCol > cellsInRow - 1) //go back to col 0 if need to
		{

			currentCol = 0;

			currentRow++;  // go to next sprite sheet row
			if (currentRow > cellsInCol - 1) // back to row if need to
			{

				currentRow = 0;

			}

		}



	}

	position.x-=5;
	
	if (position.x < -220)
	{
		position.x = 1100;
	}

}

void EnemyMovement::Draw()
{
	cellRect.x = currentCol * cellRect.w;
	cellRect.y = currentRow * cellRect.h;

	if (image)
		SDL_RenderCopy(renderer, image, &cellRect, &position);

}

