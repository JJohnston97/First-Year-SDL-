#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* _renderer, char* _file, int _x, int _y, int _w, int _h)
{
	SDL_Surface* bmpFile = SDL_LoadBMP(_file);
	image = SDL_CreateTextureFromSurface(_renderer, bmpFile);
	SDL_FreeSurface(bmpFile);
	
	position.x = _x;     //Initial Position & width and height of the sprite
	position.y = _y;	//Based on incoming parameters
	position.w = _w;
	position.h = _h;

	renderer = _renderer;

}

Sprite::~Sprite()  //Destructor function is being called to destory a sprite
{

	if (image)
		SDL_DestroyTexture(image);  //Destory Sprite


}


void Sprite::Draw()
{

	if (image)
		SDL_RenderCopy(renderer, image, NULL, &position);


}

bool Sprite::isCollidingWith(Sprite* otherSprite)
{

	if (otherSprite->position.x > position.x + position.w)
	{
		return false;
	}
	if (otherSprite->position.y > position.y + position.h)
	{
		return false;
	}
	if (otherSprite->position.x + otherSprite-> position.w < position.x)
	{ 
		return false;	
	}
	if (otherSprite->position.y + otherSprite->position.h < position.y)
	{
		return false;
	}

	return true;




}