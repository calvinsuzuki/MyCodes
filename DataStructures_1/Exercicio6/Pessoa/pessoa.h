/** 
 * Exercicio 6 - Conta bancaria continuacao
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#ifndef PESSOA_H
#define PESSOA_H

#include "../Util/Util.h"

typedef struct pessoa_ PESSOA;

/*
 *  Inicializa PESSOA
 */
PESSOA* pessoa_create ( char *CPF, char *nome, char *idade, char *saldo );

void pessoa_imprimir(PESSOA *pessoa);

/*
 *  Recebe o TAD de Pessoa e imprime seu CPF
 */
void pessoa_imprimir_cpf( PESSOA *pessoa);

/*
 *  Recebe dois TADs de Pessoa e compara seus CPF e retorna o 'strcmp' do resultado
 */
int pessoa_CPF_compare( PESSOA* p1, PESSOA* p2 );

/*
 *  Retorna o CPF de um objeto pessoa
 */
char* pessoa_get_cpf( PESSOA *pessoa );

/*
 *  Libera a memoria alocada pelo TAD de Pessoa
 */
void pessoa_destroy( PESSOA *pessoa );

#endif //PESSOA_H
