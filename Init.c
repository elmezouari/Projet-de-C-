#include "prototypes.h"

int init() {

	int success = 1;

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize. SDL Error : %s\n", SDL_GetError() );
		success = 0;
	} else {
		window = SDL_CreateWindow ("My Fucking Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if ( window == NULL ) {
			printf("Window could not be created. SDL_Error: %s\n", SDL_GetError() );
			success = 0;
		} else {
			screenSurface = SDL_GetWindowSurface ( window );
		}
	}

	return success;
}

int loadMedia() {
	int success = 1;
	scarlett = SDL_LoadBMP	("scarlett.bmp");

	plane = IMG_Load   ("myPlane.png ");
	positionplane.x = screenSurface->w/2 - plane->w/2;
    positionplane.y = screenSurface->h/2 - plane->h/2;

	fire = IMG_Load    ("Fire.png");
    //positionfire.x = positionplane.x;
    //positionfire.y = positionplane.y-10;

    flame = IMG_Load   ("Flame.png ");
    positionflame.x = positionplane.x+7;
    positionflame.y = positionplane.y+22;

    flamebig = IMG_Load   ("FlameBig.png ");
    positionflamebig.x = positionplane.x-7;
    positionflamebig.y = positionplane.y+22;

	if ( scarlett == NULL ) {
		printf( "Unable to load image. SDL Error : %s\n", SDL_GetError() );
		success = 0;
	}
	if ( plane == NULL ) {
		printf( "Unable to load image. SDL Error : %s\n", SDL_GetError() );
		success = 0;
	}
	if ( fire == NULL ) {
		printf( "Unable to load image. SDL Error : %s\n", SDL_GetError() );
		success = 0;
	}
	return success;
}

int close() {
	SDL_FreeSurface( scarlett );
	scarlett = NULL;

	SDL_FreeSurface( plane );
	plane = NULL;

	SDL_FreeSurface( fire );
	fire = NULL;

	SDL_FreeSurface( flame );
	flame = NULL;

	SDL_DestroyWindow ( window );
	window = NULL;

	SDL_Quit();
	return 0;
}
