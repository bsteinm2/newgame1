#include <stdio.h>
#include <SDL2/SDL.h>
#include "startup_utils.h"

#if defined(__linux__) // any linux distribution
    #define PLATFORM "linux"
#elif defined(_WIN32) // any windows system
    #define PLATFORM "windows"
#else
    #define PLATFORM "Is not linux or windows"
#endif





int main(int argc, char *argv[]) {
    puts(PLATFORM);

	//Screen dimension constants
	const int SCREEN_WIDTH = get_screen_width();
	const int SCREEN_HEIGHT = get_screen_height();

	printf("%d", SCREEN_WIDTH);
	printf("%d", SCREEN_HEIGHT);

    //The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

			//Wait two seconds
			SDL_Delay( 2000 );
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}