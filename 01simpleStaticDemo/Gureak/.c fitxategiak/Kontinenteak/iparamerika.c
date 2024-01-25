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
trofeoak[];

int iparamerika(agertu)
{
    //FALTAN COSAS
    int ebentu = 0, irten = 0, galderakop = 0, erantzuna = 0, eginda = 0;;

    //atzeko planoa kargatu
    mundu.idIparamerika = irudiaKargatu(IPARAMERIKA);
    irudiaMugitu(mundu.idIparamerika, 0, 0);
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
        }
        //esc tekla ikututa irten jokotik
        if (ebentu == TECLA_ESCAPE)
        {
            printf("ItxiEscaperekin \n"); //kendu
            sgItxi(); //itxi funtzioari deia
            irten = -1; //bukletik irtetzeko
        }

        if (eginda == 0)
        {
            if (galderakop < 3)
            {
                galderak(GALDERA1, 1);
                galderak(GALDERA2, 2);
                galderak(GALDERA3, 3);
                galderakop = 3;
            }
            //trofeoa pantailaratzeko
            if (galderakop == 3)
            {
                mundu.idIparamerikaTrofeoa = irudiaKargatu(IPARAMERIKA_TROFEOA);
                irudiaMugitu(mundu.idIparamerikaTrofeoa, 596, 217);
                //SDL_Delay(500); //jarri egingo dugu? EDO Sleep(2000)            
                irudiakMarraztu();
                pantailaBerriztu();
                trofeoak[0] = 1;
                eginda = 1;
            }

        }
    }


    printf("GALDERAK %d \n", galderakop); //kendu
    return 0;
}

//hau aldatu enbire que esta en un bukle infinit
int galderak(GALDERA, zenbakia)
{
    int ebentu = 0, irten = 0, erantzuna = 0, execlick = 0;

    //argazkia kargatu
    mundu.idGaldera1 = irudiaKargatu(GALDERA);
    irudiaMugitu(mundu.idGaldera1, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();

    while (!irten) {
        ebentu = ebentuaJasoGertatuBada();

        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();

            //atzera
            if (atzerajoan())
            {
                printf("AurrekopantailaJolastu \n"); //kendu
                jolastu(1); //jolastu funtzioari deia
                irten = -1; //bukletik irtetzeko
            }
            //ea erantzun zuzena den ikusi
            if ((pos.x > 752) && (pos.x < 1324) && (pos.y > 525) && (pos.y < 678) && (zenbakia == 1) && (!execlick)) //galdera 1
            {
                printf("Erantzun zuzena \n");
                mundu.idTick = irudiaKargatu(TICK);
                irudiaMugitu(mundu.idTick, 1397, 465);
                irudiakMarraztu();
                pantailaBerriztu();
                erantzuna = 1;
                execlick = 1;
            }

            if ((pos.x > 752) && (pos.x < 1324) && (pos.y > 669) && (pos.y < 836) && (zenbakia == 2) && (!execlick)) //galdera 2
            {
                printf("Erantzun zuzena \n");
                mundu.idTick = irudiaKargatu(TICK);
                irudiaMugitu(mundu.idTick, 1397, 700);
                irudiakMarraztu();
                pantailaBerriztu();
                erantzuna = 1;
                execlick = 1;
            }
            if ((pos.x > 752) && (pos.x < 1324) && (pos.y > 873) && (pos.y < 1049) && (zenbakia == 3) && (!execlick)) //galdera 3
            {
                printf("Erantzun zuzena \n");
                mundu.idTick = irudiaKargatu(TICK);
                irudiaMugitu(mundu.idTick, 1397, 875);
                irudiakMarraztu();
                pantailaBerriztu();
                erantzuna = 1;
                execlick = 1;
            }
            if ((pos.x > 1527) && (pos.x < 1872) && (pos.y > 992) && (pos.y < 1056) && (erantzuna == 1))  //hurrengo galderana
            {
                irudiaKendu(mundu.idTick);
                irudiaKendu(mundu.idGaldera1);
                pantailaBerriztu();
                irten = -1;
            }
        }
        //esc tekla ikututa irten jokotik
        if (ebentu == TECLA_ESCAPE)
        {
            printf("ItxiEscaperekin \n"); //kendu
            sgItxi(); //itxi funtzioari deia
            irten = -1; //bukletik irtetzeko
        }
    }

    return erantzuna;
}