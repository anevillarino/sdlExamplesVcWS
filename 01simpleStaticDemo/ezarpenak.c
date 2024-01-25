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
#include "soinu_efektuak.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

/* ------- ALDAGAI GLOBALAK -------*/
KLIKABLEAK atzera; 
POSIZIOA pos; 
erreproduzitu;
int musikaJarri(int erreproduzitu, int MUSIKA);


/* --------------------------- EZARPENETAN GERTATU BEHARREKOAK -----------------------------------*/
int ezarpenak(void)
{
    /* ------------- ALDAGAIAK DEKLARATU ---------------*/
    int ebentu = 0, irten = 0;


    /* ----------- STRUCT-EI BALIOAK EMAN --------------*/
    KLIKABLEAK musika_botoiak[2] = {
        {459, 310, 1004, 294},
        {459, 690, 1004, 292},
    };

    /* ------------- ATZEKO PLANOA/FONDOA --------------*/
    int ezarpenak_argazkia = irudiaKargatu(EZARPENAK);
    irudiaMugitu(ezarpenak_argazkia, 0, 0);

    irudiakMarraztu();
    pantailaBerriztu();


    /* ------------- BUKLE BAT, EBENTUAK KONTUAN IZANDA --------------*/
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();

        /* ------ ESCAPE EGITEKO -------*/
        escape(ebentu);


        /* ------- KLIK BAT EGITEAN GERTATU BEHARREKOA -------*/
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();

            /* ------ AURREKO PANTAILARA JOATEKO -------*/
            atzerajoan(0, 0, 0);


            /* ------------- MUSIKA ETA SOINUAK --------------*/
            int idSoinuaBotoia = loadSound(BOTOIEN_SOINUA);


            /* ------------ MUSIKA ON/OFF BOTOIAK KARGATZEKO -------------*/
            if (barruan(musika_botoiak[0].posX, musika_botoiak[0].zabalera, musika_botoiak[0].posY, musika_botoiak[0].altuera))
            {
                playSound(0, idSoinuaBotoia);
                SDL_Delay(100);

                musikaOff();
                erreproduzitu = 0;
            }

            if (barruan(musika_botoiak[1].posX, musika_botoiak[1].zabalera, musika_botoiak[1].posY, musika_botoiak[1].altuera))
            {
                playSound(0, idSoinuaBotoia);
                SDL_Delay(100);

                musikaOn(MUSIKA_MENUA);
                erreproduzitu = 1;
            }
            
        }
    }

    /* ------- SOINU GUZTIAK DESKARGATU -------*/
    soundsUnload();
    return 0;
}


/* ------- MUSIKA JARRI BEHAR DEN ALA EZ ZEHAZTU -------*/
int musikaJarri(int erreproduzitu, int MUSIKA) 
{
    if (erreproduzitu)
    {
        musikaOn(MUSIKA);
    }
    else
    {
        musikaOff();
    }
    return 0;
}

/* ------- MUSIKA KENTZEKO -------*/
int musikaOff(void)
{
    musicUnload();
    return 0;
}


/* ------- MUSIKA JARTZEKO -------*/
int musikaOn(int MUSIKA)
{
    audioInit();
    loadTheMusic(MUSIKA);
    playMusic(MUSIKA);

    return 0;
}