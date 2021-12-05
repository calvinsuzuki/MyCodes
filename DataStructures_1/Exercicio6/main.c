/** 
 * Exercicio 6 - Conta bancaria continuacao
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util/Util.h"
#include "Arvore_Binaria/arvore_binaria.h"

void entrada_pessoa(ARVORE_BINARIA* tree);
void insert_search_remove(ARVORE_BINARIA* tree);

int main() {

    ARVORE_BINARIA *tree = AB_create();
    
    int num_of_input;

    scanf(" %d%*c", &num_of_input );

    for( int i = 0; i < num_of_input; i++) {

        entrada_pessoa(tree);
    }

    insert_search_remove(tree);

    printf("\n");

    AB_destroy( tree );

	return 0;
}

/*
 *  Recebe os dados de pessoa com a entrada do usuário
 */
void entrada_pessoa(ARVORE_BINARIA* tree) {

    PESSOA* newPessoa;

    char* CPF = readUntil(';'); //Le até encontrar ';'

    char* nome = readUntil(';');

    char* idade = readUntil(';');

    char* saldo = readLine();

    newPessoa = pessoa_create( CPF, nome, idade, saldo );
    AB_insert_pessoa( tree, newPessoa );

    free(CPF);
    free(nome);
    free(idade);
    free(saldo);

    return;
}

/*
 *  Deixa o usuario escolher as acoes de insercao, busca e remocao da arvore
 */
void insert_search_remove(ARVORE_BINARIA* tree) {

    char *option;

    option = readLine();

    if( strcmp(option, "B") == 0 ) {

        char* CPF = readLine();

        AB_busca_cpf( tree, CPF);

        free( CPF );    

    } else if( strcmp(option, "I") == 0 ) {

        entrada_pessoa(tree);
        
        printf("Preorder\n");
        AB_pre_order( tree );
        

    } else if( strcmp(option, "R") == 0 ) {

        char* CPF = readLine();

        AB_remove_cpf( tree, CPF );

        printf("Preorder\n");
        AB_pre_order( tree );

        free( CPF );        
        

    } else {

        printf("Erro! Opcao nao encontrada!");
    }

    free( option );

}