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

#define KOP_ZUHAITZAK_HAZIAK 12

/* ------- ALDAGAI GLOBALAK -------*/

KLIKABLEAK atzera;
POSIZIOA pos;
dirua, erreproduzitu;
trofeoak[];


/* --------------------------- AFRIKAN GERTATU BEHARREKOAK -----------------------------------*/
int afrika(void)
{
    /* ------------- ALDAGAIAK DEKLARATU ---------------*/
    int i, idlortu[KOP_ZUHAITZAK_HAZIAK], ebentu = 0, irten = 0, zuhaitzkop = 0, dirualdaketa = 0;


    /* ----------- STRUCT-EI BALIOAK EMAN --------------*/
    KONTINENTEAK afrika =
    {
          AFRIKA,
          {HAZIA, ZUHAITZA1, ZUHAITZA2, ZUHAITZA3},
          AFRIKA_TROFEOA,
    };

    KLIKABLEAK haziak_zuhaitzak[KOP_ZUHAITZAK_HAZIAK] =
    {
        {245, 925, 50, 26},  //[0] hazia1
        {860, 882, 50, 26}, //[1] hazia2
        {1537, 872, 50, 27}, //[2] hazia3

        {222, 843, 89, 109},  //[3] zuhaitza1
        {842, 801, 89, 109}, //[4] zuhaitza1
        {1519, 789, 89, 109}, //[5] zuhaitza1

        {201, 742, 151, 209},  //[6] zuhaitza2
        {815, 702, 151, 209}, //[7] zuhaitza2
        {1510, 690, 151, 209}, //[8] zuhaitza2

        {58, 451, 426, 504},  //[9] zuhaitza3
        {672, 408, 426, 504}, //[10] zuhaitza3
        {1361, 409, 426, 504}, //[11] zuhaitza3
    };

    JOKOKO_ELEMENTUAK haziak_zuhaitzak_berria[KOP_ZUHAITZAK_HAZIAK] =
    {
        {0, HAZIA, haziak_zuhaitzak[0]},
        {0, HAZIA, haziak_zuhaitzak[1]},
        {0, HAZIA, haziak_zuhaitzak[2]},
        {0, ZUHAITZA1, haziak_zuhaitzak[3]},
        {0, ZUHAITZA1, haziak_zuhaitzak[4]},
        {0, ZUHAITZA1, haziak_zuhaitzak[5]},
        {0, ZUHAITZA2, haziak_zuhaitzak[6]},
        {0, ZUHAITZA2, haziak_zuhaitzak[7]},
        {0, ZUHAITZA2, haziak_zuhaitzak[8]},
        {0, ZUHAITZA3, haziak_zuhaitzak[9]},
        {0, ZUHAITZA3, haziak_zuhaitzak[10]},
        {0, ZUHAITZA3, haziak_zuhaitzak[11]},
    };


    /* ------------- ATZEKO PLANOA/FONDOA ETA HAZIAK --------------*/
    irudiaKargatu(afrika.idFondoa);
    irudiaMugitu(afrika.idFondoa, 0, 0);

    for (i = 0; i <= 2; i++)
    {
        idlortu[i] = irudiaKargatu(haziak_zuhaitzak_berria[i].irudiarenHelbidea);
        irudiaMugitu(idlortu[i], haziak_zuhaitzak_berria[i].posizioa.posX, haziak_zuhaitzak_berria[i].posizioa.posY);
    }

    irudiakMarraztu();
    pantailaBerriztu();


    /* ------------------- MUSIKA  --------------------*/
    musikaJarri(erreproduzitu, MUSIKA_AFRIKA);


    /* ------------------ DIALOGOAK -------------------*/
    if (dirua <= 150)
    {
        dialogoapantailaratu(EZDIRURIK);
        irten = -1;
        jolastu(1);
    }
    else
    {
        dialogoapantailaratu(AFRIKA_DIALOGOA);
    }


    /* ------------- ARRATOIAREN KURTSORRA --------------*/
    cursorra(1, REGADERA, 20, 30);



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
            atzerajoan(1, 3, dirualdaketa);


            /* --------- REGADERAREN SOINUA ----------*/
            int idSoinuaRegadera = loadSound(REGADERA_SOINUA);


            /* ---------------------------- ZUHAITZAK HAZTEKO -----------------------------------*/
            int i, z, k, j, abiso = 0, zuhaitza1bihurtu, zuhaitza2bihurtu, zuhaitza3bihurtu;

            for (i = 3; i < KOP_ZUHAITZAK_HAZIAK - 6; i++)
            {
                if (barruan(haziak_zuhaitzak[i].posX, haziak_zuhaitzak[i].zabalera, haziak_zuhaitzak[i].posY, haziak_zuhaitzak[i].altuera) && (!haziak_zuhaitzak_berria[i].estado))
                {
                    z = i;
                    k = i + 3;
                    j = i + 6;
                    playSound(idSoinuaRegadera);
                    SDL_Delay(300);


                    if (abiso == 0)
                    {
                        zuhaitza1bihurtu = irudiaKargatu(afrika.idElementu[1]);
                        irudiaMugitu(zuhaitza1bihurtu, haziak_zuhaitzak_berria[z].posizioa.posX, haziak_zuhaitzak_berria[z].posizioa.posY);
                        abiso = 1;
                    }
                    irudiakMarraztu();
                    pantailaBerriztu();
                    SDL_Delay(500);

                    if (abiso == 1)
                    {
                        zuhaitza2bihurtu = irudiaKargatu(afrika.idElementu[2]);
                        irudiaMugitu(zuhaitza2bihurtu, haziak_zuhaitzak_berria[k].posizioa.posX, haziak_zuhaitzak_berria[k].posizioa.posY);
                        irudiaKendu(zuhaitza1bihurtu);
                        abiso = 2;
                    }
                    irudiakMarraztu();
                    pantailaBerriztu();
                    SDL_Delay(500);

                    if (abiso == 2)
                    {
                        zuhaitza3bihurtu = irudiaKargatu(afrika.idElementu[3]);
                        irudiaMugitu(zuhaitza3bihurtu, haziak_zuhaitzak_berria[j].posizioa.posX, haziak_zuhaitzak_berria[j].posizioa.posY);
                        irudiaKendu(zuhaitza2bihurtu);
                        haziak_zuhaitzak_berria[i].estado = 1;
                        zuhaitzkop += 1;
                        dirua -= 50;
                        dirualdaketa -= 50;
                    }
                    irudiakMarraztu();
                    pantailaBerriztu();
                }
            }

            //AZKEN ELEMENTUARI DELAY-A AFEKTATU EZ DEZAN
            irudiakMarraztu();
            pantailaBerriztu();

            /* ------- TROFEOA PANTAILARATU -------*/
            trofeoaren_selloa(zuhaitzkop, KOP_ZUHAITZAK_HAZIAK / 4, 3, afrika.idTrofeoa);
           
            irudiakMarraztu();
            pantailaBerriztu();
        }

        /* ------- DIRUA PANTAILARATU -------*/
        diruaPantailaratu(dirua);
        pantailaBerriztu();


        /* ------- SOINU GUZTIAK DESKARGATU -------*/
        soundsUnload();
    }
    return 0;
}