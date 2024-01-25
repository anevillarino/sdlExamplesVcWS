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

#define KOP_BOTOI 5

/* ------- ALDAGAI GLOBALAK -------*/
KLIKABLEAK atzera = { 35, 46, 116, 99 };
POSIZIOA pos;
int erreproduzitu = 1;
dirua;
trofeoak[];


/* --------------------------- PROGAMA HASIERATU -----------------------------------*/
int hasieratu(void)
{
    //LEIHOA ZABALDU
    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Ezin da hasieratu: %s \n", SDL_GetError());
        return 0;
    }

    //HASIERA PANTAILA
    hasierapantaila();

    return 0;
}



/* ---------------------------MENUAREN PANTAILA -----------------------------------*/
int hasierapantaila(void)
{
    /* ----------------- ALDAGAIAK DEKLARATU -------------------*/
    int ebentu = 0, irten = 0;
    void (*pantailak[KOP_BOTOI])() = { jolastu, gida, itxi, kredituak, ezarpenak };


    /* ----------- STRUCT-EI BALIOAK EMAN --------------*/
    KLIKABLEAK botoiak[KOP_BOTOI] =
    {
        {778, 697, 364, 123}, // [0] hasi jolasten
        {827, 845, 266, 90}, // [1] gida
        {827, 960, 266, 89}, // [2] irten
        {1555, 53, 209, 45}, // [3] kredituak
        {1798, 26, 89, 89}, // [4] ezarpenak
    };


    /* ------------- ATZEKO PLANOA/FONDOA --------------*/
    int menua_argazkia = irudiaKargatu(MENUA);
    irudiaMugitu(menua_argazkia, 0, 0);

    irudiakMarraztu();
    pantailaBerriztu();



    /* ------------- MUSIKA ETA SOINUAK --------------*/
    musikaJarri(erreproduzitu, MUSIKA_MENUA);
    int idSoinuaBotoia = loadSound(BOTOIEN_SOINUA);



    /* ------------------- MENUAN GERTATU BEHARREKOAK ----------------------*/
    while (!irten)
    {
        dirua = 0;
        ebentu = ebentuaJasoGertatuBada();


        /* ------ ESCAPE EGITEKO -------*/
        escape(ebentu);


        /* ------- TROFEOEN KONTADOREA -------*/
        for (int i = 0; i < 6; i++)
        {
            trofeoak[i] = 0;
        }

        /* ------- GAINETIK PASATZEAN GERTATU BEHARREKOA -------*/
        if (ebentu == SAGU_MUGIMENDUA)
        {
            if (barruan(botoiak[0].posX, botoiak[0].zabalera, botoiak[0].posY, botoiak[0].altuera))
            {
                if (mundu.idHasiJolasten_aldaketa == 0)
                {
                    mundu.idHasiJolasten_aldaketa = irudiaKargatu(HASIJOLASTEN_ALDAKETA);
                }

                irudiaMugitu(mundu.idHasiJolasten_aldaketa, botoiak[0].posX, botoiak[0].posY);
            }
            else
            {
                if (mundu.idHasiJolasten_aldaketa != 0)
                {
                    irudiaKendu(mundu.idHasiJolasten_aldaketa);
                    mundu.idHasiJolasten_aldaketa = 0;
                }
            }

            if (barruan(botoiak[1].posX, botoiak[1].zabalera, botoiak[1].posY, botoiak[1].altuera))
            {
                if (mundu.idGida_aldaketa == 0)
                {
                    mundu.idGida_aldaketa = irudiaKargatu(GIDA_ALDAKETA);
                }

                irudiaMugitu(mundu.idGida_aldaketa, botoiak[1].posX, botoiak[1].posY);
            }
            else
            {
                if (mundu.idGida_aldaketa != 0)
                {
                    irudiaKendu(mundu.idGida_aldaketa);
                    mundu.idGida_aldaketa = 0;
                }
            }

            if (barruan(botoiak[2].posX, botoiak[2].zabalera, botoiak[2].posY, botoiak[2].altuera))
            {
                if (mundu.idIrten_aldaketa == 0)
                {
                    mundu.idIrten_aldaketa = irudiaKargatu(IRTEN_ALDAKETA);
                }

                irudiaMugitu(mundu.idIrten_aldaketa, botoiak[2].posX, botoiak[2].posY);
            }
            else
            {
                if (mundu.idIrten_aldaketa != 0)
                {
                    irudiaKendu(mundu.idIrten_aldaketa);
                    mundu.idIrten_aldaketa = 0;
                }
            }

            if (barruan(botoiak[3].posX, botoiak[3].zabalera, botoiak[3].posY, botoiak[3].altuera))
            {
                if (mundu.idKredituak_aldaketa == 0)
                {
                    mundu.idKredituak_aldaketa = irudiaKargatu(KREDITUAK_ALDAKETA);
                }

                irudiaMugitu(mundu.idKredituak_aldaketa, botoiak[3].posX, botoiak[3].posY);
            }
            else
            {
                if (mundu.idKredituak_aldaketa != 0)
                {
                    irudiaKendu(mundu.idKredituak_aldaketa);
                    mundu.idKredituak_aldaketa = 0;
                }
            }

            if (barruan(botoiak[4].posX, botoiak[4].zabalera, botoiak[4].posY, botoiak[4].altuera))
            {
                if (mundu.idEzarpenak_aldaketa == 0)
                {
                    mundu.idEzarpenak_aldaketa = irudiaKargatu(EZARPENAK_ALDAKETA);
                }

                irudiaMugitu(mundu.idEzarpenak_aldaketa, botoiak[4].posX, botoiak[4].posY);
            }
            else
            {
                if (mundu.idEzarpenak_aldaketa != 0)
                {
                    irudiaKendu(mundu.idEzarpenak_aldaketa);
                    mundu.idEzarpenak_aldaketa = 0;
                }
            }
            irudiakMarraztu();
            pantailaBerriztu();
        }


        /* ------- KLIK BAT EGITEAN GERTATU BEHARREKOA -------*/
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();


            /* ------- BOTOI BATEAN KLIK EGITEAN, DAGOKION PANTAILA IREKI -------*/
            int i = 0;
            while (i < KOP_BOTOI)
            {
                if (barruan(botoiak[i].posX, botoiak[i].zabalera, botoiak[i].posY, botoiak[i].altuera))
                {
                    playSound(idSoinuaBotoia);
                    pantailak[i](0);
                }

                i++;
            }
        }
    }

    /* ------- SOINU GUZTIAK DESKARGATU -------*/
    soundsUnload();

    return 0;
}


/* ------- PROGRAMA ITXI -------*/
int itxi(void)
{
    sgItxi();
    return 0;
}