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
#include "soinu_efektuak.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <math.h>

#define KOP_ZABORRAK 9


/* ------- ALDAGAI GLOBALAK -------*/
KLIKABLEAK atzera;
POSIZIOA pos; 
dirua, erreproduzitu;
trofeoak[];


/* --------------------------- OZEANIAN GERTATU BEHARREKOAK -----------------------------------*/
int ozeania(void)
{
    /* ------------- ALDAGAIAK DEKLARATU ---------------*/
    int i, idlortu[KOP_ZABORRAK], ebentu = 0, irten = 0, zaborkop = 0, dirualdaketa = 0;
    srand(time(NULL));

    /* ----------- STRUCT-EI BALIOAK EMAN --------------*/
    KONTINENTEAK ozeania = 
    {
           OZEANIA,
           {BOTELLA, PAJITA, PLASTIKOA},
           OZEANIA_TROFEOA,
    };

    KLIKABLEAK zaborrak[KOP_ZABORRAK] =
    {   
        {560, 400, 193, 143},  //[0] botella1
        {1300, 166, 193, 143}, //[1] botella2
        {1258, 781, 193, 143}, //[2] botella3
     
        {176, 177, 205, 120}, //[3] pajita1
        {681, 733, 205, 120}, //[4] pajita2 
        {947, 880, 205, 120}, //[5] pajita3
     
        {242, 717, 279, 246}, //[6] plastikoa1
        {807, 84, 279, 246}, //[7] plastikoa2
        {1574, 349, 279, 246}, //[8] plastikoa3
    };

    //KLIKABLEAK zaborrak[KOP_ZABORRAK] =
    //{
    //    {0, 0, 193, 143},  //[0] botella1
    //    {0, 0, 193, 143}, //[1] botella2
    //    {0, 0, 193, 143}, //[2] botella3

    //    {0, 0, 205, 120}, //[3] pajita1
    //    {0, 0, 205, 120}, //[4] pajita2
    //    {0, 0, 205, 120}, //[5] pajita3

    //    {0, 0, 279, 246}, //[6] plastikoa1
    //    {0, 0, 279, 246}, //[7] plastikoa2
    //    {0, 0, 279, 246}, //[8] plastikoa3
    //};

    //for (int i = 0; i < KOP_ZABORRAK; i++) {

    //    zaborrak[i].posX = rand() % (SCREEN_WIDTH - zaborrak[i].zabalera);
    //    zaborrak[i].posY = rand() % (SCREEN_HEIGHT - zaborrak[i].altuera);
    //}





    JOKOKO_ELEMENTUAK zaborrak_berria[KOP_ZABORRAK] =
    {
        {0, BOTELLA, zaborrak[0]},
        {0, BOTELLA, zaborrak[1]},
        {0, BOTELLA, zaborrak[2]},
        {0, PAJITA, zaborrak[3]},
        {0, PAJITA, zaborrak[4]},
        {0, PAJITA, zaborrak[5]},
        {0, PLASTIKOA, zaborrak[6]},
        {0, PLASTIKOA, zaborrak[7]},
        {0, PLASTIKOA, zaborrak[8]},
    };


    /* ------------- ATZEKO PLANOA/FONDOA ETA ZABORRAK --------------*/
    //ATZEKO PLANOA
    irudiaKargatu(ozeania.idFondoa); 
    irudiaMugitu(ozeania.idFondoa, 0, 0);

    //ZABORRAK
    for (i = 0; i < KOP_ZABORRAK; i++) 
    {
        idlortu[i] = irudiaKargatu(zaborrak_berria[i].irudiarenHelbidea);
        irudiaMugitu(idlortu[i], zaborrak_berria[i].posizioa.posX, zaborrak_berria[i].posizioa.posY);
    }

    irudiakMarraztu();
    pantailaBerriztu();



    /* ------------------- MUSIKA --------------------*/
    musikaJarri(erreproduzitu, MUSIKA_OZEANIA);

    
    /* ------------------ DIALOGOAK -------------------*/
    dialogoapantailaratu(OZEANIA_DIALOGOA);


    /* ------------- ARRATOIAREN KURTSORRA --------------*/
    cursorra(1, SAREA, 122, 126);



    /* ------------- BUKLE BAT, EBENTUAK KONTUAN IZANDA --------------*/
    while (!irten)
    {
        ebentu = ebentuaJasoGertatuBada();

        /* ------ ESCAPE EGITEKO -------*/
        escape(ebentu);


        /* ------- KLIK BAT EGITEAN GERTATU BEHARREKOA -------*/
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            pos = saguarenPosizioa();
            

            /* -------- AURREKO PANTAILARA JOATEKO ---------*/
            atzerajoan(1, 5, dirualdaketa);


            /* ------------ SAREAREN SOINUA -------------*/
            int idSoinuaSarea = loadSound(SAREA_SOINUA);


            /* ------------ ZABORRAK KENTZEKO -------------*/
            for (int i = 0; i < KOP_ZABORRAK; i++) 
            {
                if (barruan(zaborrak[i].posX, zaborrak[i].zabalera, zaborrak[i].posY, zaborrak[i].altuera) && (!zaborrak_berria[i].estado)) 
                {
                    playSound(idSoinuaSarea);
                    SDL_Delay(300);

                    irudiaKendu(idlortu[i]);
                    zaborrak_berria[i].estado = 1;
                    zaborkop += 1;
                    dirua += 70;
                    dirualdaketa += 70;
                }  
            }

            //AZKEN ELEMENTUARI DELAY-A AFEKTATU EZ DEZAN
            irudiakMarraztu();
            pantailaBerriztu();


            /* ------- TROFEOA PANTAILARATU -------*/
            trofeoaren_selloa(zaborkop, KOP_ZABORRAK, 5, ozeania.idTrofeoa);
            
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