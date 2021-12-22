/** 
 * Exercício 7 - Matrizes Esparsas
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#ifndef STATION_H
#define STATION_H

#include "../Util/Util.h"

typedef struct _station STATION;

STATION* Station_create(int origin, int destiny, float distance);

STATION** Station_allocArray( int arraySize );

STATION* Station_setRight(STATION *station, STATION *right);

STATION* Station_setBelow(STATION *station, STATION *below);

STATION* Station_getRight(STATION *station);

STATION* Station_getBelow(STATION *station);

int Station_getOrigin(STATION *station);

int Station_getDestiny(STATION *station);

#endif //STATION_H