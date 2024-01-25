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

#define KOP_KONTINENTEAK 6
#define KOP_BOTOI 5

KLIKABLEAK atzera;
POSIZIOA pos;

//aldagai globalak deklaratu:
int dirua, erreproduzitu;
int trofeoak[KOP_KONTINENTEAK] = { 0, 0, 0, 0, 0, 0 };//[0] iparamerika, [1] hegoamerika, [2] europa, [3] afrika, [4] asia, [5] ozeania

int jolastu(int agertu)
{
    //aldagaiak deklaratu:
    int ebentu = 0, irten = 0, kont_trofeoak = 0;


    void (*kontinenteen_pantailak[KOP_KONTINENTEAK])() = { iparamerika, hegoamerika, europa, afrika, asia, ozeania };
    int trofeoak_eginda_argazkiak[KOP_KONTINENTEAK] = { IPARAMERIKA_EGINDA, HEGOAMERIKA_EGINDA, EUROPA_EGINDA, AFRIKA_EGINDA, ASIA_EGINDA, OZEANIA_EGINDA };

    //struct-ak deklaratu:
    KLIKABLEAK kontinenteak[KOP_KONTINENTEAK] =
    {

     {165, 80, 620, 480}, // [0] ipar amerika
     {335, 570, 430, 467}, // [1] hego amerika
     {875, 290, 305, 240}, // [2] europa
     {825, 535, 320, 355}, // [3] afrika
     {1190, 95, 525, 595}, // [4] asia
     {1470, 740, 280, 200}, // [5] ozeania
    };

    KLIKABLEAK trofeoak_eginda[KOP_KONTINENTEAK] =
    {
        {363, 137},
        {560, 663},
        {937, 340},
        {847, 564},
        {1227, 261},
        {1483, 783},
    };

    KLIKABLEAK botoiak[KOP_BOTOI] = {
    {778, 697, 364, 123}, // [0] hasi jolasten
    {827, 845, 266, 90}, // [1] gida
    {827, 960, 266, 89}, // [2] irten
    {1554, 52, 210, 46}, // [3] kredituak
    {1796, 26, 90, 89} // [4] ezarpenak
    };

    //atzeko planoa kargatu
    textuaGaitu();
    int jolastu_argazkia = irudiaKargatu(JOLASA);
    irudiaMugitu(jolastu_argazkia, 0, 0);

    musikaJarri(erreproduzitu, MUSIKA_MENUA);

    //egindako kontinenteetan trofeoa agertzeko:
    for (int i = 0; i < KOP_KONTINENTEAK; i++)
    {
        if (trofeoak[i])
        {
            int trofeoa = irudiaKargatu(trofeoak_eginda_argazkiak[i]);
            irudiaMugitu(trofeoa, trofeoak_eginda[i].posX, trofeoak_eginda[i].posY);
        }
    }
    irudiakMarraztu();
    pantailaBerriztu();

    //dialogoa
    if (agertu == 0) //joko hasieran 0 izango da eta kontinente bakoitza bukatzean 1 izango da
    {
        dialogoapantailaratu(HASIERA_DIALOGOA1); //dialogoak jarri eta kendu
        dialogoapantailaratu(HASIERA_DIALOGOA2); //dialogoak jarri eta kendu
        agertu = 1; //ikusteko ea agertu behar den edo ez dialogoa
    }

    //pantaila honetan gauden bitartean egin beharrekoa
    while (!irten)
    {
        //trofeo kopurua kontatzeko
        for (int i = 0; i < KOP_KONTINENTEAK; i++)
        {
            kont_trofeoak += trofeoak[i];
        }

        //pantaila honetan gauden bitartean egin beharrekoa
        while (dialogoapantailaratu)
        {
            ebentu = ebentuaJasoGertatuBada();
            escape(ebentu);

            if (ebentu == SAGU_BOTOIA_EZKERRA) //klik egitean saguaren ezkerreko botoiarekin
            {
                pos = saguarenPosizioa();

                //atzeko pantailara joateko
                atzerajoan(0, 0, 0, 1);

                int i = 0;
                while (i < KOP_KONTINENTEAK)
                {
                    if (barruan(kontinenteak[i].posX, kontinenteak[i].zabalera, kontinenteak[i].posY, kontinenteak[i].altuera))
                    {
                        if (trofeoak[i] == 0)
                        {
                            if ((i == 2 && dirua <= 1350) || (i == 3 && dirua <= 150))
                            {
                                dialogoapantailaratu(EZDIRURIK);
                            }
                            else
                            {
                                kontinenteen_pantailak[i]();
                            }
                        }
                        else
                        {
                            dialogoaJokoaEginda(ERREPIKATUTA_DIALOGOA);
                        }
                    }

                    i++;
                }
            }
            //pantailaratzeko:
            trofeoakPantailaratu(kont_trofeoak);

            diruaPantailaratu(dirua);

            pantailaBerriztu();

            irabazi(kont_trofeoak);
            soundsUnload();
        }
    }

    return 0;
}