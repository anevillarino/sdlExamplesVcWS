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

#define KOP_KARBONODIOXIDOA 13

KLIKABLEAK atzera;
POSIZIOA pos;
dirua, erreproduzitu;
trofeoak[];

int asia(void)
{
    //FALTAN COSAS
    int i, idlortu[KOP_KARBONODIOXIDOA], ebentu = 0, irten = 0, karbonodioxidokop = 0, dirualdaketa=0;

    KONTINENTEAK asia = 
    {
           ASIA,
           {KARBONODIOXIDOA, OXIGENOA, 0},
           ASIA_TROFEOA,
    };

    KLIKABLEAK molekulak[KOP_KARBONODIOXIDOA] =
    {
        {246, 228, 111, 92},  //[0] karbono1
        {655, 269, 111, 92}, //[1] karbono2
        {1247, 219, 111, 92}, //[2] karbono3
        {1535, 120, 111, 92}, //[3] karbono4
        {1685, 252, 111, 92}, //[4] karbono5
        {452, 575, 111, 92}, //[5] karbono6
        {635, 591, 111, 92}, //[6] karbono7
        {462, 744, 111, 92}, //[7] karbono8

        {67, 533, 112, 106}, //[8] oxigeno1
        {1042, 542, 112, 106}, //[9] oxigeno2
        {1457, 561, 112, 106}, //[10] oxigeno3
        {1720, 830, 112, 106}, //[11] oxigeno4
        {1000, 100, 112, 106}, //[12] oxigeno5
    };

    JOKOKO_ELEMENTUAK molekulak_berria[KOP_KARBONODIOXIDOA] =
    { 
        {0, KARBONODIOXIDOA, molekulak[0]},
        {0, KARBONODIOXIDOA, molekulak[1]},
        {0, KARBONODIOXIDOA, molekulak[2]},
        {0, KARBONODIOXIDOA, molekulak[3]},
        {0, KARBONODIOXIDOA, molekulak[4]},
        {0, KARBONODIOXIDOA, molekulak[5]},
        {0, KARBONODIOXIDOA, molekulak[6]},
        {0, KARBONODIOXIDOA, molekulak[7]},
        {0, OXIGENOA, molekulak[8]},
        {0, OXIGENOA, molekulak[9]},
        {0, OXIGENOA, molekulak[10]},
        {0, OXIGENOA, molekulak[11]},
        {0, OXIGENOA, molekulak[12]},
    };

    //atzeko planoa kargatu
    irudiaKargatu(asia.idFondoa);
    irudiaMugitu(asia.idFondoa, 0, 0);

    //musika
    musikaJarri(erreproduzitu, MUSIKA_ASIA);

    //dialogoa
    dialogoapantailaratu(ASIA_DIALOGOA);

    for (i = 0; i < KOP_KARBONODIOXIDOA; i++) 
    {
        idlortu[i] = irudiaKargatu(molekulak_berria[i].irudiarenHelbidea);
        irudiaMugitu(idlortu[i], molekulak_berria[i].posizioa.posX, molekulak_berria[i].posizioa.posY);
    }

    irudiakMarraztu();
    pantailaBerriztu();

    //pantaila honetan gauden bitartean egin beharrekoa
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();
        escape(ebentu);

        if (ebentu == SAGU_BOTOIA_EZKERRA) //klik egitean
        {
            pos = saguarenPosizioa();

            //atzera
            atzerajoan(1, 4, dirualdaketa);

            int i;
            for (i = 0; i <= KOP_KARBONODIOXIDOA - 5; i++) 
            {
                if ((barruan(molekulak[i].posX, molekulak[i].zabalera, molekulak[i].posY, molekulak[i].altuera) && (!molekulak_berria[i].estado)) && (idlortu[i] != asia.idElementu[1])) {

                    int oxigenobihurtu = irudiaKargatu(asia.idElementu[1]);
                    irudiaMugitu(oxigenobihurtu, molekulak_berria[i].posizioa.posX, molekulak_berria[i].posizioa.posY);
                    irudiaKendu(idlortu[i]);
                    molekulak_berria[i].estado = 1;
                    karbonodioxidokop += 1;
                    dirua += 20;
                    dirualdaketa += 20;
                }
            }
            //azken elementuari ez afektatzeko
            irudiakMarraztu();
            pantailaBerriztu();

            //trofeoa pantailaratzeko
            trofeoaren_selloa(karbonodioxidokop, KOP_KARBONODIOXIDOA - 5, 4, asia.idTrofeoa);
            
            irudiakMarraztu();
            pantailaBerriztu();

        }
        diruaPantailaratu(dirua);
        pantailaBerriztu();
        soundsUnload();
    }
    return 0;
}