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
erreproduzitu;

int kredituak(void)
{
    //FALTAN COSAS
    int ebentu = 0, irten = 0;

    //atzeko planoa kargatu
    int kredituak_argazkia = irudiaKargatu(KREDITUAK);
    irudiaMugitu(kredituak_argazkia, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();

    //pantaila honetan gauden bitartean egin beharrekoa
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();
        escape(ebentu);

        if (ebentu == SAGU_BOTOIA_EZKERRA) //klik egitean
        {
            pos = saguarenPosizioa();
            //atzera
            atzerajoan(0, 0, 0, 0);

        }
    }
    return 0;
}