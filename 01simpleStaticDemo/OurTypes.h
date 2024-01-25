#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"
typedef enum { JOLASTEN, GALDU, IRABAZII} EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

//ESTO ES UNA TXAPUZA
typedef struct MUNDUA
{
  POSIZIOA pos;
  int idHasiJolasten_aldaketa, idGida_aldaketa, idIrten_aldaketa, idKredituak_aldaketa, idEzarpenak_aldaketa, 
      idMusika, idTick, idGaldera, idIrabazi, idDialogo, idIparamerikaTrofeoa, idIparamerika;

}MUNDUA; 
MUNDUA mundu;

typedef struct KLIKABLEAK_S
{
    int posX;
    int posY;
    int zabalera;
    int altuera;
} KLIKABLEAK;
KLIKABLEAK klikableak;

typedef struct KONTINENTEAK_S
{
    int idFondoa;
    int idElementu[4];
    int idTrofeoa;
} KONTINENTEAK;
KONTINENTEAK kontinenteak;

typedef struct JOKOKO_ELEMENTUAK_S
{
    int estado;
    char irudiarenHelbidea[128];
    KLIKABLEAK posizioa;
} JOKOKO_ELEMENTUAK;

#endif