/** 
 * Exercício 7 - Matrizes Esparsas
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util/Util.h"
#include "Sparse_Matrix/sparse_matrix.h"

int main() {

    int num_of_cities, num_of_destinies;
    int origin, destiny, distance;

    scanf(" %d", &num_of_cities);
    scanf(" %d", &num_of_destinies);

    SPARSE_MATRIX *matrix = SparseMatrix_create( num_of_cities, num_of_destinies );

    for ( int i = 0; i < num_of_destinies; i++ ) {
        
        scanf(" %d", &origin);
        scanf(" %d", &destiny);
        scanf(" %d", &distance);

        SparseMatrix_setStation( matrix, origin, destiny, distance );
    }

    SparseMatrix_print( matrix );

    SparseMatrix_destroy( &matrix );

    return 0;
}