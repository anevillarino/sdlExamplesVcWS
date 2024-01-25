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

/* ------- ALDAGAI GLOBALAK -------*/
KLIKABLEAK atzera;
POSIZIOA pos;
erreproduzitu;

/* --------------------------- GIDAN GERTATU BEHARREKOAK -----------------------------------*/
int gida(void)
{
    /* ------------- ALDAGAIAK DEKLARATU ---------------*/
    int ebentu = 0, irten = 0;


    /* ------------- ATZEKO PLANOA/FONDOA --------------*/
    int gida_argazkia = irudiaKargatu(GIDA);
    irudiaMugitu(gida_argazkia, 0, 0);

    irudiakMarraztu();
    pantailaBerriztu();


    /* ------------- BUKLE BAT, EBENTUAK KONTUAN IZANDA --------------*/
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();

        /* ------ ESCAPE EGITEKO -------*/
        escape(ebentu);


        /* ------- KLIK BAT EGITEAN GERTATU BEHARREKOA -------*/
        if (ebentu == SAGU_BOTOIA_EZKERRA) //klik egitean
        {
            pos = saguarenPosizioa();

            /* ------ AURREKO PANTAILARA JOATEKO -------*/
            atzerajoan(0, 0, 0);
        }

        if (ebentu == 0) {

            gidapantailaratu(GIDA1);
            gidapantailaratu(GIDA2); //gida pantailaratu eta aurrekoa borratu
            gidapantailaratu(GIDA3); //gida pantailaratu eta aurrekoa borratu
            gidapantailaratu(GIDA4); //gida pantailaratu eta aurrekoa borratu
        }
    }

    return 0;
}


void gidakendu(int id)
{
    int ebentu = 0;

    while (ebentu != TECLA_SPACE) {

        ebentu = ebentuaJasoGertatuBada();

        /* ------ ESCAPE EGITEKO -------*/
        escape(ebentu);


        /* ------- KLIK BAT EGITEAN GERTATU BEHARREKOA -------*/
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            
            /* ------ AURREKO PANTAILARA JOATEKO -------*/
            atzerajoan(0, 0, 0);

        }
    }

    /* -----------  ESPAZIOA SAKATZERAKOAN GERTATU BEHARREKOA -----------*/
    if (ebentu == TECLA_SPACE) 
    {
        irudiaKendu(id);
    }

    irudiakMarraztu();
    pantailaBerriztu();
}

int gidapantailaratu(IRUDIA)
{
    int gida_argazkia = irudiaKargatu(IRUDIA);
    irudiaMugitu(gida_argazkia, 0, 0);

    irudiakMarraztu();
    pantailaBerriztu();

    gidakendu(gida_argazkia);

    return 0;
}