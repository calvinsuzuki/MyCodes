/** 
 * Exercicio 6 - Conta bancaria continuacao
 * 
 * Nome: Calvin Suzuki de Camargo 
 * Número USP: 11232420 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore_binaria.h"

typedef struct node_st NODE;

static NODE *AB_node_create(PESSOA *pessoa);
static NODE *AB_insert_node(NODE *root, PESSOA *pessoa);
static NODE *AB_busca_cpf_recursivo(NODE *root, char* CPF);
static void pre_order(NODE *root);
static void in_order(NODE *root);
static void post_order(NODE *root);
static void node_destroy(NODE *node);

struct node_st
{
    PESSOA *pessoa;
    NODE *dir, *esq;
};

struct arvore_ {
    NODE* root;
    int depth;
};

/*
 *  Inicializa ARVORE_BINARIA
 */
ARVORE_BINARIA* AB_create() {

    ARVORE_BINARIA *tree = (ARVORE_BINARIA*) malloc( sizeof(ARVORE_BINARIA) );

    if(tree != NULL) {

        tree->depth = -1;
        tree->root = NULL;
    }

    return tree;
}

/*
 *  Inicializa NODE
 */
static NODE *AB_node_create(PESSOA *pessoa) {

    NODE *node = (NODE*) malloc( sizeof(NODE) );

    node->pessoa = pessoa;
    node->dir = NULL;
    node->esq = NULL;

    return node;
}

/*
 *  Funcao que encontra a posicao recusivamente e insere uma pessoa
 */
static NODE *AB_insert_node(NODE *root, PESSOA *pessoa) {

    // Caso base: node vazio
    if (root == NULL) {

        root = AB_node_create(pessoa);

    }
    else {

        int comp = pessoa_CPF_compare(pessoa, root->pessoa);

        // Se o CPF for menor, envie para a esquerda
        if ( comp < 0 ) {
            root->esq = AB_insert_node(root->esq, pessoa);
        }
        // Se o CPF for maior, envie para a direita
        if ( comp > 0 ) {
            root->dir = AB_insert_node(root->dir, pessoa);   
        }
        // Se o CPF for igual, emita um erro
        if ( comp == 0 ) {

            printf("\n\nErro! Cpf repetido!\n\n");
            exit(1);
        }

    }

    return root;
}

/*
 *  Funcao que encontra a posicao recusivamente e insere uma pessoa
 */
static void *AB_remove_cpf(NODE *root, char *CPF) {

    // Caso base: node vazio
    if (root == NULL) {

        return NULL;
    }
    else {

        int comp = strcmp(CPF, pessoa_get_cpf(root->pessoa) );

        // Se o CPF for menor, procure para a esquerda
        if ( comp < 0 ) {
            AB_remove_cpf(root->esq, CPF);
        }
        // Se o CPF for maior, procure para a direita
        if ( comp > 0 ) {
            AB_remove_cpf(root->dir, CPF);   
        }
        // Se o CPF for igual, remova-o
        if ( comp == 0 ) {
            
            // TODO: Remove node
            // pessoa_destroy( node->pessoa );        
            // free( node );
            // node = NULL;

        }

    }

    return root;
}

static NODE *AB_busca_cpf_recursivo(NODE *root, char* CPF) {

    if (root != NULL) {
        char* CPF_root = pessoa_get_cpf( root->pessoa );
        AB_busca_cpf_recursivo(root->esq, CPF);
        AB_busca_cpf_recursivo(root->dir, CPF);
        if ( strcmp( CPF_root, CPF) == 0 ) {
            pessoa_imprimir( root->pessoa );
        }
    }

    return root;
}

/*
 *  Insere uma pessoa na arvore
 */
boolean AB_insert_pessoa( ARVORE_BINARIA *tree, PESSOA *pessoa ) {

    if( tree != NULL && pessoa != NULL ) {

        tree->root = AB_insert_node( tree->root, pessoa );

        return TRUE;
    }

    return FALSE;
}

/*
 *  Insere uma pessoa na arvore
 */
boolean AB_busca_cpf( ARVORE_BINARIA *tree, char* CPF ) {

    if( tree != NULL && tree->root != NULL ) {

        AB_busca_cpf_recursivo( tree->root, CPF );

        return TRUE;
    }

    return FALSE;
}

/*
 *  Imprime os CPFs das pessoas em pre-ordem
 */
void AB_pre_order(ARVORE_BINARIA *tree) {

    if ( tree != NULL ) {

        pre_order( tree->root );
    }
}

/*
 *  Imprime os CPFs das pessoas em ordem (esq para dir)
 */
void AB_in_order(ARVORE_BINARIA *tree) {

    if ( tree != NULL ) {

        in_order( tree->root );
    }
}

/*
 *  Imprime os CPFs das pessoas em pos-ordem
 */
void AB_post_order(ARVORE_BINARIA *tree) {

    if ( tree != NULL ) {

        post_order( tree->root );
    }
}

/*
 *  Imprime CPF de cada pessoas em pre-ordem recursivamente
 */
static void pre_order(NODE *root) {
    if (root != NULL) {
        pessoa_imprimir_cpf(root->pessoa);
        pre_order(root->esq);
        pre_order(root->dir);
    }
}

/*
 *  Imprime CPF de cada pessoas em ordem (esq para dir) recursivamente
 */
static void in_order(NODE *root) {
    if (root != NULL) {
        in_order(root->esq);
        pessoa_imprimir_cpf(root->pessoa);
        in_order(root->dir);
    }
}

/*
 *  Imprime CPF de cada pessoas em pos-ordem recursivamente
 */
static void post_order(NODE *root) {
    if (root != NULL) {
        post_order(root->esq);
        post_order(root->dir);
        pessoa_imprimir_cpf(root->pessoa);
    }
}

/*
 *  Libera toda a memoria da arvore
 */
void AB_destroy( ARVORE_BINARIA *tree ) {

    if( tree != NULL ) {

        NODE *root = tree->root;

        if (root != NULL) 
            node_destroy( root );

        free( tree );
        tree = NULL;
    }
}

/*
 *  Libera a memoria de cada NODE da arvore recursivamente
 */
static void node_destroy(NODE *node) {
    
    if (node != NULL) {

        node_destroy( node->esq );
        node_destroy( node->dir );

        pessoa_destroy( node->pessoa );        

        free( node );
        node = NULL;
    }
}