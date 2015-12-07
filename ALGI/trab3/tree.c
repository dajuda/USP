#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"

// CRIA PILHA
PILHA_DINAMICA *create_stack(){
    PILHA_DINAMICA *aux;
    aux = (PILHA_DINAMICA*) malloc (sizeof(PILHA_DINAMICA));
    aux->tamanho = 0;
    return (aux);
}


// CRIA UMA UNIDADE DA PILHA
NO *unit_stack(){
    NO *aux = (NO*) malloc (sizeof(NO));
    aux->item = (int*) malloc (sizeof(int));
    //printf("\nAloca unidade pilha");
    return aux;
}


// REALIZA O PUSH NA PILHA
void push(PILHA_DINAMICA *pilha, int x){
    NO *new;
    new = unit_stack();
    *new->item = x;
    new->anterior = pilha->topo;
    pilha->topo = new;
    pilha->tamanho++;
}


// REALIZA O POP NA PILHA
int pop(PILHA_DINAMICA *pilha){
    int aux;
    NO *empty;
    aux = *pilha->topo->item;
    empty = pilha->topo;
    pilha->topo = pilha->topo->anterior;
    pilha->tamanho--;
    free(empty);
    return (aux);
}


// RETORNA UMA UNIDADE DA ARVORE
Node *unit(){
    Node *aux;
    aux = (Node*) malloc (sizeof(Node));
    //printf("\nAloca unidade arvore");
    return (aux);
}


// FAZ A PRIMEI INSERCAO NA ARVORE
void first_insert(Node *x, int pg, char *word){
    push(x->pg, pg);
    strcpy(x->word, word);
}


// INSERRE NO NO A DIREITA
void right_insert(Node *x, int pg, char *word){
    x->right = unit();
    x->right->pg = create_stack();
    push(x->right->pg, pg);
    strcpy(x->right->word, word);
}


// INSERE NO NO A ESQUERDA
void left_insert(Node *x, int pg, char *word){
    x->left = unit();
    x->left->pg = create_stack();
    push(x->left->pg, pg);
    strcpy(x->left->word, word);
}


// INSERE NA ARVORE
void insert(Node *r, int pg, char *word){
    Node *son, *father;
    if (r->first){
        first_insert(r, pg, word);
        r->first = 0;
        return;
    }
    son = r;
    while (son != NULL){
        father = son;
        if (strcmp(son->word, word) > 0){
            son = son->left;
        }else{
            son = son->right;
        }
    }
    if (!(strcmp(father->word, word))){
        push(father->pg, pg);
    }
    else{
        if (strcmp(father->word, word) > 0){
            left_insert(father, pg, word);
        }
        else{
            right_insert(father, pg, word);
        }
    }
}


// IMPRIME TODAS AS PAGINAS DA FOLHA(ARVORE) EM ORDEM CRESCENTE
void print_pages(PILHA_DINAMICA *P){
    int *vet, i, j, aux;

    vet = (int*) malloc (P->tamanho * sizeof(int));
    i = P->tamanho;
    j = P->tamanho;
    while(P->tamanho != 0){
        vet[i-1] = pop(P);
        i--;
    }
    while(i < j){
        push(P, vet[i]);
        i++;
    }
    for(i=0; i<P->tamanho; i++){
        for(j=i+1; j<P->tamanho; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    printf("%d", vet[0]);
    for(i=1;i< P->tamanho;i++)
    {
        printf(",%d", vet[i]);
    }
    printf("\n");
    free(vet);
}


// PROCURA FOLHA NA ARVORE
void search(Node *r, char *word) {

    while (r != NULL && strcmp(r->word, word)) {
        if (strcmp(r->word, word) > 0)
            r = r->left;
        else
            r = r->right;
    }
    if(r != NULL){
        print_pages(r->pg);
        return;
    }
    printf("0\n");
}
