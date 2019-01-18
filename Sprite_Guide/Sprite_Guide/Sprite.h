#pragma once

#include <SDL.h>

class Sprite
{

public:
	Sprite(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h);					 //Constructor
	~Sprite();																						//Destructor 


	virtual void Draw();

	void SetX(int _x) { position.x = _x; }	
	void SetY(int _y) { position.x = _y; }
	
	int GetX() { return position.x; }
	int GetY() { return position.y; }

	bool isCollidingWith(Sprite* othersprite);

protected:

	SDL_Renderer* renderer;				//Sdl Render using for drawing
	SDL_Texture* image;					//Image used by this sprite

	SDL_Rect position;					//x&y position and width, height of this sprite

};
