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

void dialogoakendu(int id) 
{
    int ebentu = 0;
    do 
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_ESCAPE)    
        {
            sgItxi(); //itxi funtzioari deia 
        }
    } while (ebentu != TECLA_SPACE);

    if (ebentu == TECLA_SPACE) //espazioan klik egitean dialogoa kendu 
    {
        irudiaKendu(id);
    }
    irudiakMarraztu();
    pantailaBerriztu();
}

int dialogoapantailaratu(IRUDIA) 
{
    int dialogoapantailan = 0;
    // Pertsonaiareen irudia gainean kargatzeko
    SDL_Delay(300);
    mundu.idDialogo = irudiaKargatu(IRUDIA);
    irudiaMugitu(mundu.idDialogo, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();

    dialogoakendu(mundu.idDialogo);
    dialogoapantailan = 1;

    return dialogoapantailan;
}

void dialogoaJokoaEginda(IRUDIA) 
{
    mundu.idDialogo = irudiaKargatu(IRUDIA);
    irudiaMugitu(mundu.idDialogo, 0, 0);
    irudiakMarraztu();
    pantailaBerriztu();

    dialogoakendu(mundu.idDialogo);
}