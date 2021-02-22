/* ASSUMPTIONS:
    - the display that is returned first from SDL_GetDisplayBounds is the one to use
*/

#include "include/startup_utils.h"

#include <stdio.h>
//#include <SDL2/SDL.h>

//SDL_DisplayMode DM;


int initSDL() {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDL couldnt init. Error: : %s\n", SDL_GetError());
        return -1;
    } else {
        if (! SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("warning: no linear texture filtering");
        }

        // int numdisplays = SDL_GetNumVideoDisplays();
        window_data w;
        // for (int i = 0; i < numdisplays; i++) {
        //     SDL_GetDisplayBounds( i, &w.bounds );
        //     printf("%d, %d, %d, %d\n", w.bounds.h, w.bounds.w, w.bounds.x, w.bounds.y);
        // }
        // make the WINDOW
        int width = get_screen_width();
        int height = get_screen_height();
        SDL_GetDisplayBounds( 0, &w.bounds );
        // printf("%d, %d, %d, %d\n", w.bounds.h, w.bounds.w, w.bounds.x, w.bounds.y);
        // printf("\n height: %d\n", height);
        // printf("\n width: %d\n", width);
        //window = SDL_CreateWindow( "untitled0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
        window = SDL_CreateWindow("untitled", w.bounds.x, 0, w.bounds.w, w.bounds.h, SDL_WINDOW_SHOWN);
		if( window == NULL ) {
            printf("sdl window not created. SDL ERROR: %s\n", SDL_GetError());
            return -1;
        } else {
            renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if (renderer == NULL) {
                printf("%s\n", SDL_GetError());
                return -1;
            } else {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                
                if(TTF_Init() == -1) {
                    printf("ttf init fail\n");
                    //printf("%s\n", TTF_GetError());
                }
            }
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