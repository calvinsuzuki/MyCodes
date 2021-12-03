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

#define TAM 50

void entrada_pessoa(ARVORE_BINARIA* tree);
void insert_search_remove(ARVORE_BINARIA* tree);

int main() {

    ARVORE_BINARIA *tree = AB_create();
    
    int num_of_input;

    scanf(" %d", &num_of_input );

    for( int i = 0; i < num_of_input; i++) {

        entrada_pessoa(tree);
    }

    insert_search_remove(tree);

    AB_destroy( tree );

	return 0;
}

/*
 *  Recebe os dados de pessoa com a entrada do usuário
 */
void entrada_pessoa(ARVORE_BINARIA* tree) {

    PESSOA* newPessoa;

    char* CPF = (char *) calloc(TAM, sizeof(char) );
    char* nome = (char *) calloc(TAM, sizeof(char) );
    char* idade = (char *) calloc(TAM, sizeof(char) );
    char* saldo = (char *) calloc(TAM, sizeof(char) );

    scanf(" %[^;]%*c", CPF);  //Le até encontrar ';'

    scanf(" %[^;]%*c", nome);

    scanf(" %[^;]%*c", idade);

    scanf(" %[^(\r|\n)]%*c", saldo); //Le até encontrar '\n' ou '\r'

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

    } else if( strcmp(option, "I") == 0 ) {



    } else if( strcmp(option, "R") == 0 ) {

        printf("\nPreorder\n");
        AB_pre_order( tree );
        printf("\n");

    } else {

        printf("Erro! Opcao nao encontrada!");
    }

}