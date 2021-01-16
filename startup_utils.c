#include "include/startup_utils.h"

#include <stdio.h>
//#include <SDL2/SDL.h>

//SDL_DisplayMode DM;

int initSDL() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL couldnt init. Error: : %s\n", SDL_GetError());
        return -1;
    } else {
        // make the WINDOW
        int width = get_screen_width();
        int height = get_screen_height();
        // printf("\n width: %d\n", width);
        window = SDL_CreateWindow( "untitled0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
		if( window == NULL ) {
            printf("sdl window not created");
            return -1;
        } else {
            window_surface = SDL_GetWindowSurface(window);
            return 0;
        }
    }
}
	
int get_screen_width() {
    int should_be_zero = SDL_GetCurrentDisplayMode(0, &DM);
    if (should_be_zero != 0) {
        SDL_Log("SDL Could not get display mode for video display #0: %s", SDL_GetError());
        exit(0);
    } else {
        return DM.w;
    }
    // printf("%d", (int)DM.w);
    // //fflush(stdout);
    // return DM.w;
}

int get_screen_height() {
    int should_be_zero = SDL_GetCurrentDisplayMode(0, &DM);
    if (should_be_zero != 0) {
        SDL_Log("SDL Could not get display mode for video display #0: %s", SDL_GetError());
        exit(0);
    } else {
        return DM.h;
    }
}