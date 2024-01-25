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

/* ------- ALDAGAI GLOBALAK -------*/
#define KOP_PANELA_ERROTAK 9
KLIKABLEAK atzera;
POSIZIOA pos;
dirua, erreproduzitu;
trofeoak[];


/* --------------------------- EUROPAN GERTATU BEHARREKOAK -----------------------------------*/
int europa(void)
{
    /* ------------- ALDAGAIAK DEKLARATU ---------------*/
    int i, idlortu[KOP_PANELA_ERROTAK], ebentu = 0, irten = 0, errota_panel_kop = 0, dirualdaketa = 0;


    /* ----------- STRUCT-EI BALIOAK EMAN --------------*/
    KONTINENTEAK europa = 
    {
        EUROPA,
        {EGUZKIPANELA, HAIZEERROTA, 0},
        EUROPA_TROFEOA,
    };
    KLIKABLEAK panelak_errotak[KOP_PANELA_ERROTAK] =
    {
        {206, 420, 199, 345}, //[0] Haizeerrota1
        {515, 314, 199, 345}, //[1] Haizeerrota2
        {860, 251, 199, 345}, //[2] Haizeerrota3
        {1211, 314, 199, 345}, //[3] Haizeerrota4
        {1529, 420, 199, 345}, //[4] Haizeerrota45
        {306, 795, 365, 186}, //[5] Eguzkipanela1
        {674, 669, 365, 186}, //[6] Eguzkipanela2
        {1055, 711, 365, 186}, //[7] Eguzkipanela3
        {1432, 834, 365, 186}, //[7] Eguzkipanela4
    };

    JOKOKO_ELEMENTUAK panelak_errotak_berria[KOP_PANELA_ERROTAK] =
    {
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

    /* ------------- ATZEKO PLANOA/FONDOA --------------*/
    irudiaKargatu(europa.idFondoa);
    irudiaMugitu(europa.idFondoa, 0, 0);

    irudiakMarraztu();
    pantailaBerriztu();


    /* ------------------- MUSIKA  --------------------*/
    musikaJarri(erreproduzitu, MUSIKA_EUROPA);



    /* ------------------ DIALOGOAK -------------------*/
    if (dirua <= 1350) 
    {
        dialogoapantailaratu(EZDIRURIK);
        irten = -1;
        jolastu(1);
    }
    else 
    {
        dialogoapantailaratu(EUROPA_DIALOGOA);
    }


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
            atzerajoan(1, 2, dirualdaketa);


            /* ------------ HAIZE ERROTAK ETA EGUZKI PANELAK JARTZEKO -------------*/
            for (int i = 0; i < KOP_PANELA_ERROTAK; i++) 
            {
                if (barruan(panelak_errotak[i].posX, panelak_errotak[i].zabalera, panelak_errotak[i].posY, panelak_errotak[i].altuera) && (!panelak_errotak_berria[i].estado)) 
                {
                    idlortu[i] = irudiaKargatu(panelak_errotak_berria[i].irudiarenHelbidea);
                    irudiaMugitu(idlortu[i], panelak_errotak_berria[i].posizioa.posX, panelak_errotak_berria[i].posizioa.posY);
                    panelak_errotak_berria[i].estado = 1;
                    errota_panel_kop += 1;
                    dirua -= 150;
                    dirualdaketa -= 150;
                }
            }

            //AZKEN ELEMENTUARI DELAY-A AFEKTATU EZ DEZAN
            irudiakMarraztu();
            pantailaBerriztu();


            /* ------- TROFEOA PANTAILARATU -------*/
            trofeoaren_selloa(errota_panel_kop, KOP_PANELA_ERROTAK, 2, europa.idTrofeoa);
            
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
