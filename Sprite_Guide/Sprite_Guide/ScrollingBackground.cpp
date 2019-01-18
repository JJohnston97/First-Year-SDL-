#include "ScrollingBackground.h"


ScrollingBackground::ScrollingBackground(SDL_Renderer* _renderer, char* _imagefile, float _speed, int _w, int _h)
{

	w = _w;															//store imcoming parameters that well need later
	speed = _speed;
	x = 0;															//start x at 0

	image = new Sprite(_renderer, _imagefile, 0, 0, _w, _h);		//Build the sprite

}

ScrollingBackground::~ScrollingBackground()
{


	delete image;													//Free image variable


}

void ScrollingBackground::Update()
{

	x -= speed;
	if (x < -w)														//Jump back by w if scrolled to far
		x += w;


}

void ScrollingBackground::Draw()
{

	image->SetX((int)x);
	image->Draw();

	image->SetX((int)x + w);
	image->Draw();
}