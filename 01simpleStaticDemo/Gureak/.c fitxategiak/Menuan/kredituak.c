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

int kredituak(void)
{
    //FALTAN COSAS
    int ebentu = 0, irten = 0;

    //atzeko planoa kargatu
    mundu.idKredituak = irudiaKargatu(KREDITUAK);
    irudiaMugitu(mundu.idKredituak, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();

    //pantaila honetan gauden bitartean egin beharrekoa
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();

        if (ebentu == SAGU_BOTOIA_EZKERRA) //klik egitean
        {
            pos = saguarenPosizioa();
            //atzera
            if ((pos.x > atzera.posX) && (pos.x < atzera.zabalera) && (pos.y > atzera.posY) && (pos.y < atzera.altuera))
            {
                printf("AurrekopantailaMenua \n"); //kendu
                hasierapantaila(); //hasierako pantaila funtzioari deia
                irten = -1; //bukletik irtetzeko
            }
        }
        //esc tekla ikututa irten jokotik
        else if (ebentu == TECLA_ESCAPE)
        {
            printf("ItxiEscaperekin \n"); //kendu
            sgItxi(); //itxi funtzioari deia
            irten = -1; //bukletik irtetzeko
        }
    }
    return 0;
}