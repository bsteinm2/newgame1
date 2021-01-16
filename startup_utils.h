#ifndef STARTUP_UTILS_H
# define STARTUP_UTILS_H

#include <SDL2/SDL.h>

SDL_DisplayMode DM;
	
int get_screen_width() {
    SDL_GetCurrentDisplayMode(0, &DM);
    return DM.w;
}

int get_screen_height() {
    SDL_GetCurrentDisplayMode(0, &DM);
    return DM.h;
}


#endif