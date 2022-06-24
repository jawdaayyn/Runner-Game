#ifndef WINDOW
#define WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 360
#define WINDOW_NAME "pewpew"

typedef struct
{
    SDL_Renderer *renderer;
    SDL_Window *window;
} Win;

#endif
