#include <stdio.h>
#include <SDL2/SDL.h>
#include "include/startup_utils.h"

#if defined(__linux__) // any linux distribution
    #define PLATFORM "linux"
#elif defined(_WIN32) // any windows system
    #define PLATFORM "windows"
#else
    #define PLATFORM "Is not linux or windows"
#endif

SDL_Surface * pic = NULL;

int load_picture() {
	pic = SDL_LoadBMP("IMG-1180.bmp");
	if (pic == NULL) {
		printf("failed load image");
		return -1;
	}
	return 1;
}

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
        TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}

int main(int argc, char *argv[]) {
    puts(PLATFORM);

	if (initSDL() < 0) {
		printf("initSDL failed");
		return -1;
	}

	//Fill the surface white
	SDL_FillRect( window_surface, NULL, SDL_MapRGB( window_surface->format, 0xFF, 0xFF, 0xFF ) );
	
	//Update the surface
	SDL_UpdateWindowSurface( window );
	
	// if (load_picture() == 1) {
	// 	SDL_BlitSurface(pic, NULL, window_surface, NULL);
	// 	SDL_UpdateWindowSurface(window);
	// }

	SDL_Rect rect1, rect2;
    SDL_Renderer *renderer;
    SDL_Texture *texture1, *texture2;
	get_text_and_rect(renderer, 0, 0, "hello", font, &texture1, &rect1);
    get_text_and_rect(renderer, 0, rect1.y + rect1.h, "world", font, &texture2, &rect2);

	int quit = 0;
	SDL_Event ev;
	while (quit == 0) {
		while(SDL_PollEvent(&ev) != 0) {
			// SDL_QUIT is the user hitting the x button on the game window
			if (ev.type == SDL_QUIT) {
				quit = 1;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        /* Use TTF textures. */
        SDL_RenderCopy(renderer, texture1, NULL, &rect1);
        SDL_RenderCopy(renderer, texture2, NULL, &rect2);

        SDL_RenderPresent(renderer);

	}


	// TODO: destroy textures
	TTF_Quit();
	SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
