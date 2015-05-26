#include "prototypes.h"

int planeSpeed = 3;

int b[5] = {0,0,0,0,0};

int main (int argc, char* args[]) {
	if ( !init() ){
		printf("Failed to initialize.\n");
	} else {
		if ( !loadMedia() ) {
			printf("Failed to load image.\n");
		} else {
			int quit = 0;
			SDL_Event e;

			while ( quit == 0 ) {

				while ( SDL_PollEvent (&e) ) {

					switch(e.type) {

                        case SDL_QUIT:
                        quit = 1;
                        break;

					}
					switch (e.type) {
                        case SDL_KEYDOWN:
                            switch(e.key.keysym.sym) {
                                case SDLK_ESCAPE: quit = 1; break;
                                case SDLK_UP: b[0]=1; break;
                                case SDLK_DOWN: b[1]=1; break;
                                case SDLK_RIGHT: b[2]=1; break;
                                case SDLK_LEFT: b[3]=1; break;
                                case SDLK_SPACE: b[4]=1; break;
                            }
                        break;
                    }
				}

				switch (e.type) {
                    case SDL_KEYUP:
                            switch(e.key.keysym.sym) {
                                case SDLK_UP: b[0]=0; break;
                                case SDLK_DOWN: b[1]=0; break;
                                case SDLK_RIGHT: b[2]=0; break;
                                case SDLK_LEFT: b[3]=0; break;
                                case SDLK_SPACE: b[4]=0; break;
                            }
                        break;
				}

				if (b[0]==1) positionplane.y-=planeSpeed;
				if (b[1]==1) positionplane.y+=planeSpeed;
				if (b[2]==1) positionplane.x+=planeSpeed;
				if (b[3]==1) positionplane.x-=planeSpeed;

				int j = 0;

				if (b[4]==1) {
                        positionfire.x = positionplane.x+16;
                        positionfire.y = positionplane.y-50;
                        SDL_BlitSurface (fire, NULL, screenSurface, &positionfire);
                    while (positionfire.y>-10) {
                        SDL_BlitSurface (fire, NULL, screenSurface, &positionfire);
                        positionfire.y-=10;
                        SDL_UpdateWindowSurface( window );
                        j+=10;
                        SDL_Delay(0.5);                                                         //C'EST DE LA MERDE
                    }
                    positionfire.y+=j;
                    j=0;
				}

				SDL_BlitSurface(scarlett, NULL, screenSurface, NULL);
				SDL_BlitSurface(plane, NULL, screenSurface, &positionplane);
				SDL_UpdateWindowSurface( window );
			}
		}
	}
	close();
	return 0;
}

