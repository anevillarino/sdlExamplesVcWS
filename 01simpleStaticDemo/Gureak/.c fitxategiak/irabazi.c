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

POSIZIOA pos; 

//Ondo egin behar da
int irabazi(int kopuru)
{
    int ebentu = 0, irten = 0;

    if (kopuru == 6)
    {
        SDL_Delay(1000);
        printf("IRABAZI DUZU \n"); //kendu
        mundu.idIrabazi = irudiaKargatu(IRABAZI);
        irudiaMugitu(mundu.idIrabazi, 0, 0);
        irudiakMarraztu();
        pantailaBerriztu();

        while (!irten)
        {
            ebentu = ebentuaJasoGertatuBada();

            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                pos = saguarenPosizioa();

                if ((pos.x > 232) && (pos.x < 835) && (pos.y > 846) && (pos.y < 1010))
                {
                    printf("AurrekopantailaMenua \n"); //kendu
                    hasierapantaila(); //hasierako pantaila funtzioari deia 
                    irten = -1; 
                }
                if ((pos.x > 1063) && (pos.x < 1645) && (pos.y > 729) && (pos.y < 975))
                {
                    printf("Irten \n"); //kendu
                    itxi();
                    irten = -1; 
                }
            }
            else if (ebentu == TECLA_ESCAPE)
            {
                printf("ItxiEscaperekin \n"); //kendu
                sgItxi(); //itxi funtzioari deia
                irten = -1; //bukletik irtetzeko
            }
        }

    }
    return 0;
}