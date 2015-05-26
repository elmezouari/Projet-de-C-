#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

int init();
int loadMedia();
int close();

SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Surface* scarlett;
SDL_Surface* plane;
SDL_Surface* fire;
SDL_Surface* flame;
SDL_Surface* flamebig;
SDL_Rect positionplane;
SDL_Rect positionfire;
SDL_Rect positionflame;
SDL_Rect positionflamebig;


#endif
