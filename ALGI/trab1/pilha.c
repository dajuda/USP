#include <stdlib.h>
#include <stdio.h>


// CRIA UMA UNIDADE DA PILHA DINAMICA
NO *unit(){
    NO *aux = (NO*) malloc (sizeof(NO));
    aux->item = (int*) malloc (sizeof(int));
    return aux;
}


// REALIZA O PUSH NA PILHA
void push(PILHA_DINAMICA *pilha, int x){
    NO *new;
    new = unit();
    new->item = x;
    new->anterior = pilha->topo;
    pilha->topo = new;
    pilha->tamanho++;
}


// REALIZA O POP NA PILHA
int pop(PILHA_DINAMICA *pilha){
    int aux;
    NO *empty;
    aux = pilha->topo->item;
    empty = pilha->topo;
    pilha->topo = pilha->topo->anterior;
    pilha->tamanho--;
    free(empty);
    return (aux);
}
