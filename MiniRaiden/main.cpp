#include "SDL\include\SDL.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_CreateWindowAndRenderer(224, 256, 0, &window, &renderer);
	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("title.bmp"));
	SDL_Texture* ship = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("ship.bmp"));
	SDL_Rect r;

	for (;;)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, title, NULL, NULL);
		r = { 0, 0, 26, 33 };
		SDL_RenderCopy(renderer, ship, NULL, &r);

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	return(0);
}