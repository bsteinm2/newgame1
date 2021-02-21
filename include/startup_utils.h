#ifndef STARTUP_UTILS_H
# define STARTUP_UTILS_H

#include <SDL2/SDL.h>

SDL_Window * window;
SDL_Surface * window_surface;
SDL_DisplayMode DM;
//SDL_DisplayMode DM;

typedef struct window_data
{
SDL_Rect bounds;
SDL_Window * window;
} window_data;	

int get_screen_width();
int get_screen_height();
int initSDL();



#endif