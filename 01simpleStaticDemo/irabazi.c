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
POSIZIOA pos; 


/* --------------------- IRABAZI PANTAILAN GERTATU BEHARREKOAK -----------------------*/
int irabazi(int kopuru)
{
    /* ------------- ALDAGAIAK DEKLARATU ---------------*/
    int ebentu = 0, irten = 0;
    int idSoinuaBotoia = loadSound(BOTOIEN_SOINUA);
    int idSoinuaIrabazi = loadSound(IRABAZI_SOINUA);


    /* ----------- STRUCT-EI BALIOAK EMAN --------------*/
    KLIKABLEAK irabazi_botoiak [2] =
    {
        {706, 381, 501, 159},  //[0] jolastu berriro (posX, posY, zabalera, altuera)
        {706, 624, 501, 167}, //[1] itxi
    };


    /* ----------- KONTINENTE GUZTIEN TROFEOAK LORTUZ GERO GERTATU BEHARREKOA --------------*/
    if (kopuru == 6)
    {
        SDL_Delay(1000);

        /* ------------- ATZEKO PLANOA/FONDOA --------------*/
        int irabazi_fondoa = irudiaKargatu(IRABAZI);
        irudiaMugitu(irabazi_fondoa, 0, 0);

        irudiakMarraztu();
        pantailaBerriztu();


        /* ------------ IRABAZI DUZU SOINUA -------------*/
        playSound(idSoinuaIrabazi);

       
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

                // BERRIRO JOLASTU BOTOIA
                if (barruan(irabazi_botoiak[0].posX, irabazi_botoiak[0].zabalera, irabazi_botoiak[0].posY, irabazi_botoiak[0].altuera))
                {
                    playSound(idSoinuaBotoia);

                    hasierapantaila(); 
                    irten = -1; 
                }

                // JOKOA ITXI BOTOIA
                if (barruan(irabazi_botoiak[1].posX, irabazi_botoiak[1].zabalera, irabazi_botoiak[1].posY, irabazi_botoiak[1].altuera))
                {
                    playSound(idSoinuaBotoia);

                    itxi();
                    irten = -1; 
                }
            }
        }

    }
    return 0;
}