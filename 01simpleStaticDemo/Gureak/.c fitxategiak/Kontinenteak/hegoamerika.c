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

#define KOP_SUAK 4

KLIKABLEAK atzera;
POSIZIOA pos;
trofeoak[];

int hegoamerika(void)
{
    //FALTAN COSAS
    int i, idlortu[KOP_SUAK], ebentu = 0, irten = 0, suakop = 0;

    KONTINENTEAK hegoamerika = {
        HEGOAMERIKA,
        {SUA2, SUA3, SUA4},
        HEGOAMERIKA_TROFEOA,
    };

    KLIKABLEAK suak[KOP_SUAK] =
    {
        {775, 700, 775 + (979 - 775), 700 + (981 - 700)}, //[0] sua1
        {380, 562, 380 + (584 - 380), 562 + (843 - 562)}, //[1] sua2
        {1600, 650, 1600 + (1811 - 1600), 650 + (896 - 650)}, //[2] sua3 (dcha)
        {565, 582, 565 + (848 - 565), 582 + (719 - 582)}, //[3] sua4 (largo)
    };

    CACHARROS_JUEGOS suak_berria[KOP_SUAK] = {

        {0, SUA2, suak[0]},
        {0, SUA2, suak[1]},
        {0, SUA3, suak[2]},
        {0, SUA4, suak[3]},
    };

    //atzeko planoa kargatu
    irudiaKargatu(hegoamerika.idFondoa);
    irudiaMugitu(hegoamerika.idFondoa, 0, 0);

    //dialogoa
    dialogoapantailaratu(DIALOGOA1);

    //arratoia
    //kargatu sarea irudia
    SDL_Surface* cursorSurface = SDL_LoadBMP(EXTINTOREA);

    //cursorraren ezarpenak
    SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, 122, 126);
    SDL_SetCursor(cursor);

    for (i = 0; i < KOP_SUAK; i++) {
        idlortu[i] = irudiaKargatu(suak_berria[i].irudiarenHelbidea);
        irudiaMugitu(idlortu[i], suak_berria[i].posizioa.posX, suak_berria[i].posizioa.posY);
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
            if (atzerajoan())
            {
                printf("AurrekopantailaJolastu \n"); //kendu
                SDL_FreeCursor(cursor);
                jolastu(1); //jolastu funtzioari deia
                irten = -1; //bukletik irtetzeko
            }

            int i;
            for (i = 0; i < KOP_SUAK; i++) {

                if (barruan(suak[i].posX, suak[i].zabalera, suak[i].posY, suak[i].altuera) && (!suak_berria[i].estado)) {

                    printf("%d\n", suakop);
                    irudiaKendu(idlortu[i]);
                    suak_berria[i].estado = 1;
                    suakop += 1;

                }
            }
            irudiakMarraztu();
            pantailaBerriztu();

            //trofeoa pantailaratzeko
            if (suakop == 4) //su kopurua ipini
            {
                int trofeoa = irudiaKargatu(hegoamerika.idTrofeoa);
                irudiaMugitu(trofeoa, 548, 157);
                SDL_Delay(500);
                trofeoak[1] = 1;
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


    printf("ITZALITAKO SUAK %d \n", suakop); //kendu

    return 0;
}