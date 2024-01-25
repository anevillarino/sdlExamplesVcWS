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

KLIKABLEAK atzera = { 35, 46, 35 + (151 - 35), 35 + (134 - 35) };
POSIZIOA pos;

#define KOP_BOTOI 5

trofeoIparamerika;
trofeoHegoamerika;
trofeoEuropa;
trofeoAfrika;
trofeoAsia;
trofeoOzeania;

int hasieratu(void)
{
    //leihoa zabaltzeko
    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Ezin da hasieratu: %s \n", SDL_GetError());
        return 0;
    }

    //jokoaren hasierako pantailara deia
    hasierapantaila();

    return 0;
}

//jokoaren hasierako pantailako funtzioa
int hasierapantaila(void)
{
    //FALTAN COSAS
    int ebentu = 0, irten = 0;

    KLIKABLEAK botoiak[KOP_BOTOI] = {

        {778, 697, 778 + (1142 - 778), 697 + (820 - 697)}, // [0] hasi jolasten
        {827, 845, 827 + (1093 - 827), 845 + (935 - 845)}, // [1] gida
        {827, 960, 827 + (1093 - 827), 960 + (1049 - 960)}, // [2] irten
        {1554, 52, 1554 + (1764 - 1554), 52 + (98 - 52)}, // [3] kredituak
        {1796, 26, 1796 + (1886 - 1796), 26 + (115 - 26)}, // [4] ezarpenak
    };

    //atzeko planoa kargatzeko
    mundu.idMenua = irudiaKargatu(MENUA); 
    irudiaMugitu(mundu.idMenua, 0, 0); 
    irudiakMarraztu();
    pantailaBerriztu();

    //pantaila honetan gauden bitartean egin beharrekoa
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa(); 

        /* ZUZENDU EGIN BEHAR DA ERROREAK EMATEN DITU
        if (ebentu == SAGU_MUGIMENDUA)
        {
            if (barruan(botoiak[0].posX, botoiak[0].zabalera, botoiak[0].posY, botoiak[0].altuera))
            {
                if (mundu.idHasiJolasten_aldaketa == -1) // Carga la imagen solo si aún no está cargada
                {
                    mundu.idHasiJolasten_aldaketa = irudiaKargatu(HASIJOLASTEN_ALDAKETA);
                }

                irudiaMugitu(mundu.idHasiJolasten_aldaketa, 778, 697);
            }
            else
            {
                if (mundu.idHasiJolasten_aldaketa != -1) // Descarga la imagen solo si está cargada
                {
                    irudiaKendu(mundu.idHasiJolasten_aldaketa);
                    mundu.idHasiJolasten_aldaketa = -1;
                }
            }

            if (barruan(botoiak[1].posX, botoiak[1].zabalera, botoiak[1].posY, botoiak[1].altuera))
            {
                if (mundu.idGida_aldaketa == -1) // Carga la imagen solo si aún no está cargada
                {
                    mundu.idGida_aldaketa = irudiaKargatu(GIDA_ALDAKETA);
                }

                irudiaMugitu(mundu.idGida_aldaketa, 827, 845);
            }
            else
            {
                if (mundu.idGida_aldaketa != -1) // Descarga la imagen solo si está cargada
                {
                    irudiaKendu(mundu.idGida_aldaketa);
                    mundu.idGida_aldaketa = -1;
                }
            }
            irudiakMarraztu();
            pantailaBerriztu();

        }
        */

        if (ebentu == SAGU_BOTOIA_EZKERRA) //klik egitean
        {
            pos = saguarenPosizioa(); 

            int i = 0;
            while ((i <= KOP_BOTOI)) 
            {
                if (barruan(botoiak[i].posX, botoiak[i].zabalera, botoiak[i].posY, botoiak[i].altuera)) 
                {
                    if (i == 0) 
                    {
                        printf("Jolastu \n"); //kendu
                        trofeoIparamerika = 0, trofeoHegoamerika = 0, trofeoEuropa = 0, trofeoAfrika = 0, trofeoAsia = 0, trofeoOzeania = 0;
                        jolastu(0);
                    }

                    if (i == 1) 
                    {
                        printf("Gida \n"); //kendu
                        gida();
                    }

                    if (i == 2) 
                    {
                        printf("Irten \n"); //kendu
                        itxi();
                    }

                    if (i == 3) 
                    {
                        printf("Kredituak \n"); //kendu
                        kredituak();
                    }

                    if (i == 4) 
                    {
                        printf("Ezarpenak \n"); //kendu
                        ezarpenak();
                    }
                }
                i++;
            }
        }
        //esc tekla ikututa irten jokotik
        else if (ebentu == TECLA_ESCAPE)
        {
            printf("ItxiEscaperekin \n"); //kendu
            sgItxi(); //itxi funtzioari deia
            irten = -1; //bukletik irtetzeko
        }
    }
    return 0;
}

int itxi(void) 
{
    sgItxi(); //itxi funtzioari deia
    return 0;
}