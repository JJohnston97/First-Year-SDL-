#include "CharacterController.h"

Player::Player(SDL_Renderer* _renderer, char* _file, int _w, int _h) :
	Sprite(_renderer, _file, 100, 100, _w, _h)
{



}

void Player::Update()
{
	const Uint8* key = SDL_GetKeyboardState(NULL);

	if (key[SDL_SCANCODE_LEFT])
		position.x -= 5;
	if (key[SDL_SCANCODE_RIGHT])
		position.x += 5;
	if (key[SDL_SCANCODE_UP])
		position.y -= 5;
	if (key[SDL_SCANCODE_DOWN])
		position.y += 5;

}