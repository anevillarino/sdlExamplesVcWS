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

#define KOP_ZUHAITZAK_HAZIAK 6

KLIKABLEAK atzera;
POSIZIOA pos;
trofeoak[];

int afrika(void)
{
    int i, idlortu[KOP_ZUHAITZAK_HAZIAK], ebentu = 0, irten = 0, zuhaitzkop = 0;

    KONTINENTEAK afrika = {
          AFRIKA,
          {HAZIA, ZUHAITZA, 0},
          AFRIKA_TROFEOA,
    };

    KLIKABLEAK haziak_zuhaitzak[KOP_ZUHAITZAK_HAZIAK] =
    {
        {245, 925, 245 + (295 - 245), 925 + (951 - 925)},  //[0] hazia1
        {860, 882, 860 + (910 - 860), 882 + (909 - 882)}, //[1] hazia2
        {1537, 872, 1537 + (1587 - 1537), 872 + (899 - 872)}, //[2] hazia3

        {38, 546, 38 + (356 - 38), 546 + (943 - 546)},  //[3] zuhaitza1
        {650, 510, 650 + (968 - 650), 510 + (940 - 510)}, //[4] zuhaitza2
        {1326, 498, 1326 + (1644 - 1326), 498 + (894 - 498)}, //[5] zuhaitza3

    };

    CACHARROS_JUEGOS haziak_zuhaitzak_berria[KOP_ZUHAITZAK_HAZIAK] = {

        {0, HAZIA, haziak_zuhaitzak[0]},
        {0, HAZIA, haziak_zuhaitzak[1]},
        {0, HAZIA, haziak_zuhaitzak[2]},
        {0, ZUHAITZA, haziak_zuhaitzak[3]},
        {0, ZUHAITZA, haziak_zuhaitzak[4]},
        {0, ZUHAITZA, haziak_zuhaitzak[5]},
    };

    //atzeko planoa kargatu
    irudiaKargatu(afrika.idFondoa);
    irudiaMugitu(afrika.idFondoa, 0, 0);

    for (i = 0; i < KOP_ZUHAITZAK_HAZIAK / 2; i++) {
        idlortu[i] = irudiaKargatu(haziak_zuhaitzak_berria[i].irudiarenHelbidea);
        irudiaMugitu(idlortu[i], haziak_zuhaitzak_berria[i].posizioa.posX, haziak_zuhaitzak_berria[i].posizioa.posY);
    }

    irudiakMarraztu();
    pantailaBerriztu();

    //dialogoa
    dialogoapantailaratu(DIALOGOA1);

    //pantaila honetan gauden bitartean egin beharrekoa
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();

        if (ebentu == SAGU_BOTOIA_EZKERRA) //klik egitean
        {
            pos = saguarenPosizioa();

            //atzera
            if (atzerajoan())
            {
                printf("AurrekopantailaJolastu \n"); //kendu
                jolastu(1); //jolastu funtzioari deia
                irten = -1; //bukletik irtetzeko
            }

            int i;
            for (i = 0; i < KOP_ZUHAITZAK_HAZIAK / 2; i++) {

                if (barruan(haziak_zuhaitzak[i].posX, haziak_zuhaitzak[i].zabalera, haziak_zuhaitzak[i].posY, haziak_zuhaitzak[i].altuera) && (!haziak_zuhaitzak_berria[i].estado)) {

                    printf("%d\n", zuhaitzkop);
                    irudiaKendu(idlortu[i]);
                    int zuhaitzabihurtu = irudiaKargatu(afrika.idElementu[1]);
                    irudiaMugitu(zuhaitzabihurtu, haziak_zuhaitzak_berria[i + KOP_ZUHAITZAK_HAZIAK / 2].posizioa.posX, haziak_zuhaitzak_berria[i + KOP_ZUHAITZAK_HAZIAK / 2].posizioa.posY);
                    haziak_zuhaitzak_berria[i].estado = 1;
                    zuhaitzkop += 1;

                }
            }

            irudiakMarraztu();
            pantailaBerriztu();

            //trofeoa pantailaratzeko
            if (zuhaitzkop == KOP_ZUHAITZAK_HAZIAK / 2)
            {
                int trofeoa = irudiaKargatu(afrika.idTrofeoa);
                irudiaMugitu(trofeoa, 548, 157);
                SDL_Delay(500);
                trofeoak[3] = 1;
            }
            irudiakMarraztu();
            pantailaBerriztu();
        }
        //esc tekla ikututa irten jokotik
        else if (ebentu == TECLA_ESCAPE)
        {
            printf("ItxiEscaperekin \n"); //kendu
            sgItxi(); //itxi funtzioari deia
            irten = -1; //bukletik irtetzeko
        }
    }
    printf("LANDATUTAKO ZUHAITZAK %d \n", zuhaitzkop); //kendu 
    return 0;
}