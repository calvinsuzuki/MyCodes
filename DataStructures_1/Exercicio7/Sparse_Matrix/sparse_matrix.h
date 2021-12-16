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

SPARSE_MATRIX *SparseMatrix_create(int num_of_rows, int num_of_columns);

boolean SparseMatrix_setStation( SPARSE_MATRIX *matrix, int origin, int destiny, float distance);

void SparseMatrix_print (SPARSE_MATRIX *matrix);

void SparseMatrix_destroy (SPARSE_MATRIX **matrix);

#endif //SPARSE_MATRIX_H
