#define _CRT_SECURE_NO_WARNINGS
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include "dialogoak.h"
#include "ezarpenak.h"
#include "gida.h"
#include "irabazi.h"
#include "irudiak.h"
#include "musika.h"
#include "jolasa.h" 
#include "orokorrak.h"
#include "kredituak.h"
#include "menua.h"
#include "soinu_efektuak.h"
#include "OurTypes.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

KLIKABLEAK atzera; 
POSIZIOA pos;
trofeoak[];
dirua;

void atzerajoan(int pantaila, int n, int dirualdaketa) 
{

    if (barruan(atzera.posX, atzera.zabalera, atzera.posY, atzera.altuera))
    {
        SDL_Cursor* defaultCursor = SDL_GetDefaultCursor();
        SDL_SetCursor(defaultCursor);

        int idSoinuaBotoia = loadSound(BOTOIEN_SOINUA);
        playSound(0, idSoinuaBotoia);
        SDL_Delay(100);

        if ((!trofeoak[n]) && (pantaila == 1))
        {
            dirua -= dirualdaketa;
        }
        if (pantaila == 1) 
        {
            jolastu(1);
        }
        else if (pantaila == 0) 
        {
            hasierapantaila();
        }
    }

    soundsUnload();

}

void trofeoakPantailaratu(int trofeoKop)
{
    char str[128];

    sprintf(str, "%d / 6", trofeoKop);
    textuaIdatzi(920, 45, str);
}

void diruaPantailaratu(int dirua)
{
    char str[128];

    sprintf(str, ": %d", dirua);
    textuaIdatzi(1600, 45, str);
}

//koordenada horietan arratoia dagoen edo ez ikusteko (bai = 1, ez = 0)
int barruan(int posX, int zabalera, int posY, int altuera)
{

    int barruandago = 0;
    pos = saguarenPosizioa(); 
    if ((pos.x > posX) && (pos.x < (posX + zabalera)) && (pos.y > posY) && (pos.y < (posY + altuera)))
    {
        barruandago = 1;
    }
    return barruandago;
}

void escape(ebentua)
{
    if (ebentua == TECLA_ESCAPE)
    {
        sgItxi(); //itxi funtzioari deia
    }
}

void cursorra(int marraztu, const char* argazkia, int posX, int posY) 
{
    if (marraztu) 
    {
        SDL_Surface* cursorSurface = SDL_LoadBMP(argazkia);
        SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, posX, posY);
        SDL_SetCursor(cursor);
        SDL_FreeSurface(cursorSurface);
    }

    else 
    {
        SDL_Cursor* defaultCursor = SDL_GetDefaultCursor();
        SDL_SetCursor(defaultCursor);
    }
}

void trofeoaren_selloa(int kontadorea, int nKont, int n, int trofeoarenIDa) {

    if (kontadorea == nKont)
    {
        int trofeoa = irudiaKargatu(trofeoarenIDa);
        irudiaMugitu(trofeoa, 544, 130);
        SDL_Delay(500);
        trofeoak[n] = 1;
        cursorra(0, 0, 0, 0);
       
    }
}