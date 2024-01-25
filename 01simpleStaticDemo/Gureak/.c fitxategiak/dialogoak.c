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

void dialogoakendu(int id) {
    int ebentu;
    do {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_ESCAPE)
        {
            printf("ItxiEscaperekin \n"); //kendu
            sgItxi(); //itxi funtzioari deia
        }
    } while (ebentu != TECLA_SPACE);

    if (ebentu == TECLA_SPACE) //espazioan klik egitean dialogoa kendu 
    {
        printf("kenduDialogo \n"); //kendu
        irudiaKendu(id);
    }
    irudiakMarraztu();
    pantailaBerriztu();
}

int dialogoapantailaratu(IRUDIA) {
    int dialogoapantailan = 0;

    // Pertsonaiareen irudia gainean kargatzeko
    SDL_Delay(300);
    mundu.idDialogo1 = irudiaKargatu(IRUDIA);
    irudiaMugitu(mundu.idDialogo1, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();

    dialogoakendu(mundu.idDialogo1);
    dialogoapantailan = 1;

    return dialogoapantailan;
}

void dialogoaJokoaEginda(IRUDIA) {

    mundu.idDialogo1 = irudiaKargatu(IRUDIA);
    irudiaMugitu(mundu.idDialogo1, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();

    dialogoakendu(mundu.idDialogo1);
}