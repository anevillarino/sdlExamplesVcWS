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
#include "OurTypes.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

KLIKABLEAK atzera; 
POSIZIOA pos;


void trofeoakPantailaratu(int trofeoKop)
{
    char str[128];

    sprintf(str, "%d / 6", trofeoKop);
    textuaIdatzi(1031, 51, str);
}

//atzera
int atzerajoan() {
    int atzerajoan = 0;

    if ((pos.x > atzera.posX) && (pos.x < atzera.zabalera) && (pos.y > atzera.posY) && (pos.y < atzera.altuera)) {
        atzerajoan = 1;
    }

    return atzerajoan;
}

//koordenada horietan arratoia dagoen edo ez ikusteko (bai = 1, ez = 0)
int barruan(int posX, int zabalera, int posY, int altuera)
{
    int barruandago = 0;
    pos = saguarenPosizioa(); 
    if ((pos.x > posX) && (pos.x < zabalera) && (pos.y > posY) && (pos.y < altuera))
    {
        barruandago = 1;
    }
    else
    {
        barruandago = 0;
    }
    return barruandago;
}