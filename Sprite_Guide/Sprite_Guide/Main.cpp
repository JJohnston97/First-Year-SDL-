#include <SDL.h>
#include "Sprite.h"
#include "CharacterController.h"
#include "ScrollingBackground.h"
#include "AnimationSprite.h"
#include "Enemy.h"
#include <iostream>



// function prototypes
void GameLoop(SDL_Window* window, SDL_Renderer* renderer);

int main(int, char**)
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	// try initialising SDL, log error and pause if fail
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << "\n";
		system("pause");
		return 0;
	}

	// try to create the window, log error and pause if fail
	window = SDL_CreateWindow("sprite_guide", 100, 100, 1024, 600, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		system("pause");
		return 0;
	}

	// try to create the renderer, log error and pause if fail
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}

	// this function call goes into the actual game loop
	GameLoop(window, renderer);

	// clean up, free any memeory we have used
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

void GameLoop(SDL_Window* window, SDL_Renderer* renderer)
{
	bool quit = false;
	bool pause = false;
	bool balloonPop = false;
	int BalloonSpawnTimer = 100;
	int score = 0;
	SDL_Event exit;

	//Player* ship = new Player(renderer, "Ship.bmp", 200, 200);
	ScrollingBackground* Background = new ScrollingBackground(renderer, "Sky_Background2.bmp", 2, 1050, 600);
	EnemyMovement* balloon1 = new EnemyMovement(renderer, "Yellow_Balloon.bmp", 1200, 300, 180, 220, 1, 1, 0);
	EnemyMovement* balloon2 = new EnemyMovement(renderer, "Red_Balloon.bmp", 1600, 100, 180, 220, 1, 1, 0);
	AnimationSprite* Bird = new AnimationSprite(renderer, "Birds_Animation.bmp", 190, 100, 83, 74, 4, 1, 0.01f);
	Sprite* PauseMenu = new Sprite(renderer, "Pause.bmp", 0, 0, 1024, 600);
	const Uint8* key = SDL_GetKeyboardState(NULL);
	
	while (!quit) { // this is the main game loop

		score++;
		std::cout << score << std::endl;
		
		while (SDL_PollEvent(&exit)) // allow closing SDL window to quit
		{
			if (key[SDL_SCANCODE_ESCAPE])
				quit = true;
		}


		if (key[SDL_SCANCODE_ESCAPE])
		{
			pause = true;

			SDL_RenderClear(renderer);
			PauseMenu->Draw();
			SDL_RenderPresent(renderer);

			while (pause == true)
			{

				SDL_PumpEvents();

				int MouseX = { 0 };
				int MouseY = { 0 };

				int x = SDL_GetMouseState(&MouseX, &MouseY) & 1;

				if (x == 1)
				{
					if ((MouseX > 370) && (MouseX < 660) && (MouseY > 100) && (MouseY < 180))
					{
						pause = false;
					}

					if ((MouseX > 420) && (MouseX < 620) && (MouseY > 300) && (MouseY < 400))
					{
						exit;
					}
				}
			}
		}

		if (pause == false)
		{

			//First clear the renderer
			SDL_RenderClear(renderer);

			if (!balloonPop && Bird->isCollidingWith(balloon1))
			{
				//--lives;
				delete balloon1;

				balloon1 = NULL;
				balloonPop = true;
			}

			if (!balloonPop && balloon1->GetX() < -200)
			{
				delete balloon1;
				balloon1 = NULL;
				balloonPop = true;
			}

			if (balloonPop)
			{
				BalloonSpawnTimer--;
				if (BalloonSpawnTimer < 0)
				{
					balloon1 = new EnemyMovement(renderer, "Yellow_balloon.bmp", 1200, 300, 180, 220, 1, 1, 0);
					balloonPop = false;
					BalloonSpawnTimer = 100;
				}
			}

			Background->Update();

			if (!balloonPop)
			{
				balloon1->Update();

			}
			
			
			Bird->Update();
			balloon2->Update();
			//ship->Update();

			Background->Draw();

			if (balloon1)
			{
				balloon1->Draw();
			}

			balloon2->Draw();
			Bird->Draw();
			//ship->Draw();

			//Update the screen
			SDL_RenderPresent(renderer);
		}

	}
	delete Background;
	delete Bird;

	if (balloon1)
	{

		delete balloon1;
		delete balloon2;
	}

}

