/** 
 * Exercício 7 - Matrizes Esparsas
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sparse_matrix.h"

struct _SparseMatrix {

    STATION **row;
    STATION **column;
    int num_of_rows;
    int num_of_columns;
};

SPARSE_MATRIX *SparseMatrix_create (int num_of_rows, int num_of_columns ) {

    SPARSE_MATRIX *matrix = (SPARSE_MATRIX *) malloc( sizeof(SPARSE_MATRIX) );

    if (matrix != NULL) {

        matrix->num_of_rows = num_of_rows;
        matrix->num_of_columns = num_of_columns;

        matrix->column = Station_allocArray( num_of_columns );
        matrix->row    = Station_allocArray( num_of_rows );

        if (matrix->column != NULL && matrix->row != NULL) {

            for (int i = 0; i < num_of_columns; i++) matrix->column[i] = NULL;
            
            for (int i = 0; i < num_of_rows; i++) matrix->row[i] = NULL;
        }
    }

    return matrix;
}

boolean SparseMatrix_setStation( SPARSE_MATRIX *matrix, int origin, int destiny, float distance) {

    STATION *station;
    STATION *columnStation;
    STATION *prevColumnStation = NULL;

    if( origin > matrix->num_of_rows || destiny > matrix->num_of_columns ) 
        return FALSE; // Row or Columns invalid error

    station = Station_create( origin, destiny, distance );

    if ( station == NULL)
        return FALSE; // Allocation error

    columnStation = matrix->column[ destiny ];

    boolean isInserted = FALSE;

    while( columnStation != NULL && !isInserted ) {

        if( Station_getOrigin( columnStation ) < origin ) {

            prevColumnStation = columnStation;

            columnStation = Station_getBelow( columnStation );
        }
        else {

            if ( prevColumnStation == NULL ) 
                matrix->column[ destiny ] = station;
            else 
                Station_setBelow( prevColumnStation, station );

            Station_setBelow( station, columnStation );

            isInserted = TRUE;
        }
    }

    if ( columnStation == NULL ) {

        if ( prevColumnStation == NULL ) 
            matrix->column[ destiny ] = station;
        else 
            Station_setBelow( prevColumnStation, station );
    }

    return TRUE;

}   

void SparseMatrix_print (SPARSE_MATRIX *matrix) {

    for (int i = 0; i < matrix->num_of_columns; i++) {

        if( matrix->column[i] != NULL ) {

            STATION *station = Station_getBelow( matrix->column[i] );

            while (station != NULL) {

                printf("mamaco\n");
                Station_print( station );
                station = Station_getBelow( station );
            }
        }
    }
}

void SparseMatrix_destroy (SPARSE_MATRIX **matrix) {

    for (int i = 0; i < (*matrix)->num_of_rows; i++) {

        if( (*matrix)->row[i] != NULL ) {

            STATION *station = Station_getRight( (*matrix)->row[i] );

            while (station != NULL) {

                STATION *prevStation = station;
                station = Station_getRight( station );

                free(prevStation);
                prevStation = NULL;
            }
        }

        free( (*matrix)->row[i] );
        (*matrix)->row[i] = NULL;
    }

    free((*matrix)->row);
    (*matrix)->row = NULL;

    free((*matrix)->column);
    (*matrix)->column = NULL;

    free((*matrix));
    *matrix = NULL;
}