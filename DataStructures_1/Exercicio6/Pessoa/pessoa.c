/** 
 * Exercicio 6 - Conta bancaria continuacao
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pessoa.h"

static char* copy_string(char *str);

struct pessoa_ 
{
	char *CPF, *nome;
	char *idade, *saldo;
};

/*
 *  Inicializa PESSOA
 */
PESSOA* pessoa_create ( char *CPF, char *nome, char *idade, char *saldo ) {

    PESSOA *pessoa = (PESSOA *) malloc( sizeof(PESSOA) );

    if (pessoa != NULL) { // Verifica se alocacao funcionou

    	pessoa->CPF   = copy_string(CPF);
    	pessoa->nome  = copy_string(nome);
    	pessoa->idade = copy_string(idade);
    	pessoa->saldo = copy_string(saldo);

    	return pessoa;
    }

    return NULL;
}

/*
 *  Recebe o TAD de Pessoa e imprime seu CPF
 */
void pessoa_imprimir_cpf( PESSOA *pessoa) {

	char *CPF = pessoa->CPF;
	boolean zero_a_esquerda = TRUE;

	for ( int i = 0; i < strlen(CPF); i++ ) {
		
		// Evita imprimir zeros a esquerda
		if ( CPF[i] != '0') {

			zero_a_esquerda = FALSE;
		}
		if ( zero_a_esquerda && CPF[i] == '0' ) {

			continue;
		}

		// Compara com a tabela ASCII para imprimir somente numeros
		else if ( CPF[i] > 47 && CPF[i] < 58 ) {
		
			printf("%c", CPF[i]);
		}

	}

	printf("\n");

	return;
}

/*
 *  Recebe dois TADs de Pessoa e compara seus CPF e retorna o 'strcmp' do resultado
 */
int pessoa_CPF_compare( PESSOA* p1, PESSOA* p2) {

	char *CPF1 = p1->CPF, *CPF2 = p2->CPF;

	return (strcmp(CPF1, CPF2));
}

void pessoa_imprimir(PESSOA *pessoa) {

	printf("Conta :: %s\nCPF :: %s\n", pessoa->nome, pessoa->CPF);
	printf("Idade :: %s\nSaldo atual :: R$ %s\n", pessoa->idade, pessoa->saldo);
}

/*
 *  Libera as variaveis de pessoa
 */
void pessoa_destroy( PESSOA *pessoa ) {

	if( pessoa != NULL ) {

		free( pessoa->CPF );
		free( pessoa->nome );
		free( pessoa->idade );
		free( pessoa->saldo );
		free( pessoa );
		pessoa = NULL;
	}
}

/*
 *  Retorna o CPF de um objeto pessoa
 */
char* pessoa_get_cpf( PESSOA *pessoa ) {

	return pessoa->CPF;
}

/*
 *  Copia o conteudo de uma string e libera a sua memoria
 */
static char* copy_string(char *str) {

	// Correcao de memory leak, +1 para incluir o final da string
	char *copy = (char *) malloc( strlen(str) * sizeof(char) + 1);

	// Verifica se a alocacao funcionou
	if( copy == NULL ) {
		printf("\n\nErro ao alocar memoria!\n\n");
		exit(1);		
	}

	strcpy(copy, str);
	
	return copy;
}