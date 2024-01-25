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

#define KOP_ZABORRAK 9

KLIKABLEAK atzera;
POSIZIOA pos; 
trofeoak[];

int ozeania(void)
{
    //FALTAN COSAS
    int i, idlortu[KOP_ZABORRAK], ebentu = 0, irten = 0, zaborkop = 0;

    KONTINENTEAK ozeania = 
    {
           OZEANIA, //fondoa
           {BOTELLA, PAJITA, PLASTIKOA}, //elementuak
           OZEANIA_TROFEOA, //trofeoa
    };

    KLIKABLEAK zaborrak[KOP_ZABORRAK] =
    {
        {560, 400, 560 + (753 - 560), 400 + (543 - 400)},  //[0] botella1 (posX, posY, zabalera, altuera)
        {1300, 166, 1300 + (1495 - 1300), 166 + (312 - 166)}, //[1] botella2
        {1258, 781, 1258 + (1454 - 1258), 781 + (922 - 781)}, //[2] botella3
        {176, 177, 176 + (381 - 176), 177 + (297 - 177)}, //[3] pajita1
        {681, 733, 681 + (887 - 681), 733 + (855 - 733)}, //[4] pajita2
        {947, 880, 947 + (1151 - 947), 880 + (999 - 880)}, //[5] pajita3
        {242, 717, 242 + (521 - 242), 717 + (963 - 717)}, //[6] plastikoa1
        {807, 84, 807 + (1086 - 807), 84 + (330 - 84)}, //[7] plastikoa2
        {1574, 349, 1574 + (1850 - 1574), 349 + (594 - 349)}, //[8] plastikoa3
    };

    CACHARROS_JUEGOS zaborrak_berria[KOP_ZABORRAK] = 
    {
        {0, BOTELLA, zaborrak[0]}, //estado, irudia helbidea, posizioa (zaborrak struct-a)
        {0, BOTELLA, zaborrak[1]},
        {0, BOTELLA, zaborrak[2]},
        {0, PAJITA, zaborrak[3]},
        {0, PAJITA, zaborrak[4]},
        {0, PAJITA, zaborrak[5]},
        {0, PLASTIKOA, zaborrak[6]},
        {0, PLASTIKOA, zaborrak[7]},
        {0, PLASTIKOA, zaborrak[8]},
    };

    //atzeko planoa kargatu
    irudiaKargatu(ozeania.idFondoa); //kontinenteak, ozeania, fondoa 
    irudiaMugitu(ozeania.idFondoa, 0, 0);


    //dialogoa
    dialogoapantailaratu(DIALOGOA1);

    //arratoia
    //kargatu sarea irudia
    SDL_Surface* cursorSurface = SDL_LoadBMP(SAREA); 

    //cursorraren ezarpenak
    SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, 122, 126);
    SDL_SetCursor(cursor);


    for (i = 0; i < KOP_ZABORRAK; i++) //i aldatzen joan, hainbat aldin egiteko, kop_zaborrak aldiz
    {
        idlortu[i] = irudiaKargatu(zaborrak_berria[i].irudiarenHelbidea);
        irudiaMugitu(idlortu[i], zaborrak_berria[i].posizioa.posX, zaborrak_berria[i].posizioa.posY);
    }
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
                printf("AurrekopantailaJolastu \n"); //kendu
                SDL_FreeCursor(cursor);
                jolastu(1); //jolastu funtzioari deia
                irten = -1; //bukletik irtetzeko
            }

            //zaborra kendu
            int i;
            for (i = 0; i < KOP_ZABORRAK; i++) 
            {
                if (barruan(zaborrak[i].posX, zaborrak[i].zabalera, zaborrak[i].posY, zaborrak[i].altuera) && (!zaborrak_berria[i].estado)) 
                {
                    printf("%d\n", zaborkop);
                    irudiaKendu(idlortu[i]);
                    zaborrak_berria[i].estado = 1;
                    zaborkop += 1;
                }
            }

            //trofeoa pantailaratzeko
            if (zaborkop == KOP_ZABORRAK)
            {
                int trofeoa = irudiaKargatu(ozeania.idTrofeoa);
                irudiaMugitu(trofeoa, 548, 157);
                SDL_Delay(500);
                trofeoak[5] = 1;
            }
            //irudiak pantailaratu
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
    //desaktibatu cursorra
    SDL_FreeSurface(cursorSurface);
    SDL_FreeCursor(cursor);

    printf("BILDUTAKO ZABORRA %d \n", zaborkop); //kendu
    return 0;
}