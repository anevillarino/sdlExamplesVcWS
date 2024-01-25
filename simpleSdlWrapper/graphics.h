#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "SDL.h"

//ez dugu hau erabili: SDL_WINDOW_FULLSCREEN_DESKTOP erabili dugulako
#define SCREEN_WIDTH  0
#define SCREEN_HEIGHT  0


int sgHasieratu();
void sgItxi();//Sin opciones
void arkatzKoloreaEzarri(int red, int green, int blue);
void puntuaMarraztu(int x, int y);
void zuzenaMarraztu(int x1, int y1, int x2, int y2);
void zirkuluaMarraztu(int x, int y, int r);
void pantailaGarbitu();
void pantailaBerriztu();

int irudiaMarraztu(SDL_Texture* texture, SDL_Rect *pDest);

SDL_Renderer* getRenderer(void);

#endif


