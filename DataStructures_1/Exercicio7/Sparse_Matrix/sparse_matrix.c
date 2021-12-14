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

struct _sparseMatrix {

    STATION **row;
    STATION **column;
    int num_of_rows;
    int num_of_columns;
};
// struct matriz_esparsa {
//     CELULA **linhas;
//     CELULA **colunas;
//     int nr_linhas;
//     int nr_colunas;
// };

// MATRIZ_ESPARSA *criar_matriz(int nr_linhas, int nr_colunas) {
//     MATRIZ_ESPARSA *matriz = (MATRIZ_ESPARSA *) malloc(sizeof (MATRIZ_ESPARSA));
//     if (matriz != NULL) {
//         matriz->nr_colunas = nr_colunas;
//         matriz->nr_linhas = nr_linhas;
//         matriz->colunas = (CELULA **) malloc(sizeof (CELULA *) * nr_colunas);
//         matriz->linhas = (CELULA **) malloc(sizeof (CELULA *) * nr_linhas);
//         if (matriz->colunas != NULL && matriz->linhas != NULL) {
//             for (int i = 0; i < nr_colunas; i++) {
//                 matriz->colunas[i] = NULL;
//             }
//             for (int i = 0; i < nr_linhas; i++) {
//                 matriz->linhas[i] = NULL;
//             }
//         }
//     }
//     return matriz;
// }