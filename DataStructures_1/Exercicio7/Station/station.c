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
    int origin;
    int destiny;
    float distance;
    STATION *right;
    STATION *below;
};

STATION* Station_create(int origin, int destiny, float distance) {

	STATION *station = (STATION*) malloc( sizeof(STATION) );

	station->origin = origin;
	station->destiny = destiny;
	station->distance = distance;
	station->right = NULL;
	station->below = NULL;

	return station;
}

void Station_setRight(STATION *station, STATION *right) {
	station->right = right;
	return;
}

void Station_setBelow(STATION *station, STATION *below) {
	station->below = below;
	return;
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

void Station_print(STATION *station) {

	printf("Origin: %d\nDestiny: %d\nDistance: %f", station->origin, station->destiny, station->distance);
}

void Station_destroy(STATION **station) {

	if( (*station)->right != NULL ) {
		free( (*station)->right);
	}	
	if( (*station)->below != NULL ) {
		free( (*station)->below);
	}

	free( (*station) );
	*station = NULL;

	return;
}

// void Station_setOrigin(STATION *station, int origin) {
// 	station->origin = origin;
// 	return;
// }

// void Station_setDestiny(STATION *station, int destiny) {
// 	station->destiny = destiny;
// 	return;
// }

// void Station_setDistance(STATION *station, float distance) {
// 	station->distance = distance;
// 	return;
// }



// float Station_getDistance(STATION *station) {
// 	return station_getDistance;
// }