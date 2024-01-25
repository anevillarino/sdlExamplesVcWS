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

#define KOP_PANELA_ERROTAK 9
KLIKABLEAK atzera;
POSIZIOA pos;
trofeoak[];

int europa(void)
{
    //FALTAN COSAS
    int i, idlortu[KOP_PANELA_ERROTAK], ebentu = 0, irten = 0, errota_panel_kop = 0;

    KONTINENTEAK europa = {
        EUROPA,
        {EGUZKIPANELA, HAIZEERROTA, 0},
        EUROPA_TROFEOA,
    };
    KLIKABLEAK panelak_errotak[KOP_PANELA_ERROTAK] =
    {
        {206, 420, 206 + (404 - 206), 420 + (765 - 420)}, //[0] Haizeerrota1
        {515, 314, 515 + (715 - 515), 314 + (660 - 314)}, //[1] Haizeerrota2
        {860, 251, 860 + (1078 - 860), 251 + (593 - 251)}, //[2] Haizeerrota3
        {1211, 314, 1211 + (1411 - 1211), 314 + (657 - 314)}, //[3] Haizeerrota4
        {1529, 420, 1529 + (1729 - 1529), 420 + (765 - 420)}, //[4] Haizeerrota45
        {306, 795, 306 + (671 - 306), 795 + (981 - 795)}, //[5] Eguzkipanela1
        {674, 669, 674 + (1028 - 674), 669 + (845 - 669)}, //[6] Eguzkipanela2
        {1055, 711, 1055 + (1415 - 1055), 711 + (888 - 711)}, //[7] Eguzkipanela3
        {1432, 834, 1432 + (1786 - 1432), 834 + (1008 - 834)}, //[7] Eguzkipanela4
    };

    CACHARROS_JUEGOS panelak_errotak_berria[KOP_PANELA_ERROTAK] = {

        {0, HAIZEERROTA, panelak_errotak[0]},
        {0, HAIZEERROTA, panelak_errotak[1]},
        {0, HAIZEERROTA, panelak_errotak[2]},
        {0, HAIZEERROTA, panelak_errotak[3]},
        {0, HAIZEERROTA, panelak_errotak[4]},
        {0, EGUZKIPANELA, panelak_errotak[5]},
        {0, EGUZKIPANELA, panelak_errotak[6]},
        {0, EGUZKIPANELA, panelak_errotak[7]},
        {0, EGUZKIPANELA, panelak_errotak[8]},
    };

    //atzeko planoa kargatu
    irudiaKargatu(europa.idFondoa);
    irudiaMugitu(europa.idFondoa, 0, 0);
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
            for (i = 0; i < KOP_PANELA_ERROTAK; i++) {

                if (barruan(panelak_errotak[i].posX, panelak_errotak[i].zabalera, panelak_errotak[i].posY, panelak_errotak[i].altuera) && (!panelak_errotak_berria[i].estado)) {

                    printf("%d\n", errota_panel_kop);
                    idlortu[i] = irudiaKargatu(panelak_errotak_berria[i].irudiarenHelbidea);
                    irudiaMugitu(idlortu[i], panelak_errotak_berria[i].posizioa.posX, panelak_errotak_berria[i].posizioa.posY);
                    panelak_errotak_berria[i].estado = 1;
                    errota_panel_kop += 1;

                }
            }
            //irudiak pantailaratu
            irudiakMarraztu();
            pantailaBerriztu();

            //trofeoa pantailaratzeko
            if (errota_panel_kop == KOP_PANELA_ERROTAK)
            {
                int trofeoa = irudiaKargatu(europa.idTrofeoa);
                irudiaMugitu(trofeoa, 548, 157);
                SDL_Delay(500);
                trofeoak[2] = 1;
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
    printf("JARRITAKO ELEMENTUAK %d \n", errota_panel_kop); //kendu

    return 0;
}
