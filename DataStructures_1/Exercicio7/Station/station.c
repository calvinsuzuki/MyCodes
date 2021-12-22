/** 
 * Exercício 7 - Matrizes Esparsas
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "station.h"

struct _station {
    int origin;  // Row
    int destiny; // Column
    float distance;
    STATION *right;
    STATION *below;
};

/*
 *  Instancia o TAD Sparse_Matrix
 */
STATION* Station_create(int origin, int destiny, float distance) {

	STATION *station = (STATION*) malloc( sizeof(STATION) );

	if (station != NULL) {
		station->origin = origin;
		station->destiny = destiny;
		station->distance = distance;
		station->right = NULL;
		station->below = NULL;	
	}

	return station;
}

/*
 *  Aloca um Array de Stations
 */
STATION** Station_allocArray( int arraySize ) {

	return ( (STATION **) malloc( sizeof(STATION*) * arraySize) );
}

STATION* Station_setRight(STATION *station, STATION *right) {
	station->right = right;
	return station;
}

STATION* Station_setBelow(STATION *station, STATION *below) {
	station->below = below;
	return station;
}

STATION* Station_getRight(STATION *station) {
	return station->right;
}

STATION* Station_getBelow(STATION *station) {
	return station->below;
}

int Station_getOrigin(STATION *station) {
	return station->origin;
}

int Station_getDestiny(STATION *station) {
	return station->destiny;
}