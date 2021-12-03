/** 
 * Exercicio 6 - Conta bancaria continuacao
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include "../Pessoa/pessoa.h"
#include "../Util/Util.h"

typedef struct arvore_ ARVORE_BINARIA;

/*
 *  Inicializa ARVORE_BINARIA
 */
ARVORE_BINARIA* AB_create();

/*
 *  Insere uma pessoa na arvore
 */
boolean AB_insert_pessoa( ARVORE_BINARIA *tree, PESSOA *pessoa );

/*
 *  Imprime os CPFs das pessoas em pre-ordem
 */
void AB_pre_order(ARVORE_BINARIA *tree);

/*
 *  Imprime os CPFs das pessoas em ordem (esq para dir)
 */
void AB_in_order(ARVORE_BINARIA *tree);

/*
 *  Imprime os CPFs das pessoas em pos-ordem
 */
void AB_post_order(ARVORE_BINARIA *tree);

/*
 *  Busca e imprime uma pessoa pelo seu CPF
 */
boolean AB_busca_cpf( ARVORE_BINARIA *tree, char* CPF );

/*
 *  Libera toda a memoria da arvore
 */
void AB_destroy( ARVORE_BINARIA *tree );