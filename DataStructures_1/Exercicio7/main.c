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

    int num_of_origins, num_of_destinies;
    int origin, destiny, distance;

    scanf(" %d", &num_of_origins);
    scanf(" %d", &num_of_destinies);

    SPARSE_MATRIX *matrix = SparseMatrix_create( num_of_origins, num_of_destinies );

    for ( int i = 0; i < num_of_destinies; i++ ) {
        
        scanf(" %d", &origin);
        scanf(" %d", &destiny);
        scanf(" %d", &distance);

        SparseMatrix_setStation( matrix, origin-1, destiny-1, distance );
    }

    scanf(" %d", &origin);
    scanf(" %d", &destiny);

    if ( SparseMatrix_pathFinder( matrix, origin-1, destiny-1 ) )
        printf("Existe caminho.\n");
    else 
        printf("Não existe caminho.\n");

    SparseMatrix_destroy( &matrix );

    return 0;
}