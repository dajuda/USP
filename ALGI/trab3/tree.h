// CAINA DAJUDA         8531511
// VICTOR BENEVIDES     8531491
// PRISCILLA PARODI     8626207

#include <stdlib.h>
#include <stdio.h>

typedef struct pilha_dinamica PILHA_DINAMICA;

// UNIDADE LISTA
typedef struct NO{
    int *item;
    struct NO *anterior;
}NO;

// UNIDADE PILHA DINAMICA
struct pilha_dinamica{
    NO *topo;
    int tamanho;
};

// UNIDADE DA ARVORE
typedef struct node{
    PILHA_DINAMICA *pg;
    char word[30];
    int first;
    struct node *right, *left;
}Node;

// UNIDADE DA LISTA ENCADEADA
typedef struct q_node{
    Node *item;
    int end;
    struct q_node *next;
}QNode;

// RETORNA UMA UNIDADE DA ARVORE
Node *unit();

// RETORNA UMA UNIDADE DA PILHA DINAMICA
NO *unit_stack();

// CRIA O "THE FIRST STEP" DA PILHA DINAMICA
PILHA_DINAMICA *create_stack();

// REALIZA O PUSH NA PILHA
void push(PILHA_DINAMICA *pilha, int x);

// REALIZA O POP NA PILHA
int pop(PILHA_DINAMICA *pilha);

// FAZ A PRIMEI INSERCAO NA ARVORE
void first_insert(Node *x, int pg, char *word);

// INSERRE NO NO A DIREITA
void right_insert(Node *x, int pg, char *word);

// INSERE NO NO A ESQUERDA
void left_insert(Node *x, int pg, char *word);

// INSERE NA ARVORE
void insert(Node *r, int pg, char *word);

// IMPRIME TODAS AS PAGINAS DA FOLHA(ARVORE) EM ORDEM CRESCENTE
void print_pages(PILHA_DINAMICA *P);

// PROCURA FOLHA NA ARVORE
void search(Node *r, char *word);

// REALIZA A BUSCA REMISSIVA
void remissivo(Node *node);

// INSERE UM ELEMENTO NA LISTA
void enqueue(QNode **queue, Node *node);

// REMOVE UM ELEMENTO NA LISTA
Node *dequeue(QNode **queue);
