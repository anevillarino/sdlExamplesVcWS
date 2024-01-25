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

int ezarpenak(void)
{
    //FALTAN COSAS
    int ebentu = 0, irten = 0;

    //atzeko planoa kargatu
    mundu.idEzarpenak = irudiaKargatu(EZARPENAK);
    irudiaMugitu(mundu.idEzarpenak, 0, 0);
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
                printf("AurrekopantailaMenua \n"); //kendu
                hasierapantaila(); //hasierako pantaila funtzioari deia
                irten = -1; //bukletik irtetzeko
            }

            //musika
            //musika off
            if ((pos.x > 918) && (pos.x < 1157) && (pos.y > 333) && (pos.y < 502))
            {
                printf("musikaOff \n"); //kendu
                musikaoff(); //musikaoff funtzioari deia
            }
            //musika on
            if ((pos.x > 910) && (pos.x < 1160) && (pos.y > 600) && (pos.y < 835))
            {
                printf("musikaOn \n"); //kendu
                musikaon(); //musikaon funtzioari deia
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

//musika
int musikaoff(void)
{
    musicUnload(); //musika gelditu eta kendu (berez gehiago ez du usten erabiltzen baina desabilitatuta dagoenez Mix_FreeMusic(musika), ahal da gehiagotan erabili)
    return 0;
}

int musikaon(void)
{
    audioInit();
    mundu.idMusika = loadSound(MUSIKA); 
    loadTheMusic(MUSIKA);
    playMusic();
    return 0;
}