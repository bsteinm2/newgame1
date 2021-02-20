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

	//Wait two seconds
	SDL_Delay( 2000 );
	
	if (load_picture() == 1) {
		SDL_BlitSurface(pic, NULL, window_surface, NULL);
		SDL_UpdateWindowSurface(window);
		SDL_Delay( 2000 );
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
