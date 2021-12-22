/** 
 * Exercício 7 - Matrizes Esparsas
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include "../Station/station.h"
#include "../Util/Util.h"

typedef struct _SparseMatrix SPARSE_MATRIX;

/*
 *  Instancia o TAD Sparse_Matrix
 */
SPARSE_MATRIX *SparseMatrix_create(int num_of_rows, int num_of_columns);

/*
 *  Adiciona Stations pelos Rows
 */
boolean SparseMatrix_setStation( SPARSE_MATRIX *matrix, int origin, int destiny, float distance);

/*
 *  Funcao verifica se ha um caminho de uma origem ate um destino 
 */
void SparseMatrix_destroy (SPARSE_MATRIX **matrix);

/*
 *  Limpa a memoria da matriz
 */
boolean SparseMatrix_pathFinder ( SPARSE_MATRIX *matrix, int origin, int destiny );

#endif //SPARSE_MATRIX_H
