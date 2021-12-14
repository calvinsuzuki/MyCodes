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

    STATION *std = Station_create(1, 1, 5.4);

    Station_print( std );

    Station_destroy( &std );

    return 0;
}