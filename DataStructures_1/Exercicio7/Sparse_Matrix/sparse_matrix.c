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

static boolean pathFinder_recursive( SPARSE_MATRIX *matrix, STATION* station, int destiny);

struct _SparseMatrix {

    STATION **row;
    STATION **column;
    int num_of_rows;
    int num_of_columns;
};

/*
 *  Instancia o TAD Sparse_Matrix
 */
SPARSE_MATRIX *SparseMatrix_create (int num_of_rows, int num_of_columns ) {

    SPARSE_MATRIX *matrix = (SPARSE_MATRIX *) malloc( sizeof(SPARSE_MATRIX) );

    if (matrix != NULL) {

        matrix->num_of_rows = num_of_rows;
        matrix->num_of_columns = num_of_columns;

        matrix->column = Station_allocArray( num_of_columns );
        matrix->row    = Station_allocArray( num_of_rows );

        if (matrix->column != NULL && matrix->row != NULL) {

            for (int i = 0; i < num_of_columns; i++)
                matrix->column[i] = NULL;
            
            for (int i = 0; i < num_of_rows; i++)
                matrix->row[i] = NULL;
        }
    }

    return matrix;
}

/*
 *  Adiciona Stations pelos Rows
 */
boolean SparseMatrix_setStation( SPARSE_MATRIX *matrix, int origin, int destiny, float distance) {

    STATION *station;
    STATION *rowStation;
    STATION *prevRowStation = NULL;

    if( origin > matrix->num_of_rows || destiny > matrix->num_of_columns ) 
        return FALSE; // Row or Columns invalid

    station = Station_create( origin, destiny, distance );

    if ( station == NULL)
        return FALSE; // Allocation error

    rowStation = matrix->row[ origin ];

    boolean isInserted = FALSE;

    while( rowStation != NULL && !isInserted ) {

        if( Station_getDestiny( rowStation ) < destiny ) {

            prevRowStation = rowStation;

            rowStation = Station_getRight( rowStation );
        }
        else {

            if ( prevRowStation == NULL ) 
                matrix->row[ origin ] = station;
            else 
                prevRowStation = Station_setRight( prevRowStation, station );

            station = Station_setRight( station, rowStation );

            isInserted = TRUE;
        }
    }

    if ( rowStation == NULL ) {

        if ( prevRowStation == NULL ) 
            matrix->row[ origin ] = station;
        else 
            prevRowStation = Station_setRight( prevRowStation, station );
    }

    return TRUE;
} 

/*
 *  Funcao verifica se ha um caminho de uma origem ate um destino 
 */
boolean SparseMatrix_pathFinder ( SPARSE_MATRIX *matrix, int origin, int destiny ) {

    if( matrix == NULL)
        return FALSE;

    if ( matrix->row[ origin ] != NULL ) {

        return pathFinder_recursive( matrix, matrix->row[ origin ], destiny);

    }

    return FALSE;
}

/*
 *  Limpa a memoria da matriz
 */
void SparseMatrix_destroy (SPARSE_MATRIX **matrix) {

    for (int i = 0; i < (*matrix)->num_of_rows; i++) {

        if( (*matrix)->row[i] != NULL ) {

            STATION *station = Station_getRight( (*matrix)->row[i] );

            while (station != NULL) {

                STATION *prevStation = station;
                station = Station_getRight( station );

                free( prevStation );
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

/*
 *  Funcao verifica se ha um caminho de uma origem ate um destino recursivamente
 */
static boolean pathFinder_recursive( SPARSE_MATRIX *matrix, STATION* station, int destiny) {

    boolean result = FALSE;

    if( station != NULL ) {

        if( Station_getDestiny( station ) == destiny ) 
            return TRUE;

        // Procura se há o destino na Station à direita
        result = pathFinder_recursive( matrix, Station_getRight(station), destiny );
        
        // Se nao houver, visitar uma outra Cidade à procura do destino
        if ( !result )
            result = pathFinder_recursive( matrix, matrix->row[ Station_getDestiny( station ) ], destiny );
    } 

    return result;
}