#pragma once
#include "Sprite.h"


class ScrollingBackground
{

public:

	ScrollingBackground(SDL_Renderer* _renderer, char* _imagefile, float _speed, int _w, int _h);
	~ScrollingBackground();

	void Update();
	void Draw();


private:

	Sprite* image;    //sprite that the background uses
	float x;		 //current x position 
	float speed;	//Scrolling speed
	int w;			//width of image used


};