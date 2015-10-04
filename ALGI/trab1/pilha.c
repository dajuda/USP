// CAINA DAJUDA         8531511
// VICTOR BENEVIDES     8531491
// PRISCILLA PARODI     8626207


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pilha.h"


// CRIA PILHA
PILHA_DINAMICA *create_stack(){
    PILHA_DINAMICA *aux;
    aux = (PILHA_DINAMICA*) malloc (sizeof(PILHA_DINAMICA));
    aux->tamanho = 0;
    return (aux);
}


// CRIA UMA UNIDADE DA PILHA
NO *unit(){
    NO *aux = (NO*) malloc (sizeof(NO));
    aux->item = (long*) malloc (sizeof(long));
    return aux;
}


// REALIZA O PUSH NA PILHA
void push(PILHA_DINAMICA *pilha, long x){
    NO *new;
    new = unit();
    *new->item = x;
    new->anterior = pilha->topo;
    pilha->topo = new;
    pilha->tamanho++;
}


// REALIZA O POP NA PILHA
long pop(PILHA_DINAMICA *pilha){
    long aux;
    NO *empty;
    aux = *pilha->topo->item;
    empty = pilha->topo;
    pilha->topo = pilha->topo->anterior;
    pilha->tamanho--;
    free(empty);
    return (aux);
}


// INSERE OUTRO ELEMENTO NA PILHA, MAS REALIZANDO UMA OPERACAO COM
// O ANTERIOR
void new_item(PILHA_DINAMICA *pilha, int x){
    long aux;
    aux = pop(pilha);
    aux = (aux*10)+x;
    push(pilha, aux);
}


// REALIZA A OPERACAO SOLICITADA COM OS DOIS ULTIMOS
// ITENS DA PILHA
void operation(PILHA_DINAMICA *pilha, char *op){
    long x, y, i;

    // SOMA
    if (!strcmp("+", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x+y);
    }

    // SUBTRACAO
    if (!strcmp("-", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x-y);
    }

    // DIVISAO
    if (!strcmp("/", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x/y);
    }

    // MULTIPLICACAO
    if (!strcmp("*", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x*y);
    }

    // POTENCIACAO
    if (!strcmp("^", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, (pow(x,y)));
    }

    // FATORIAL
    if (!strcmp("!", op)){
        y = pop(pilha);
        for(i=1; y > 1; y--){
            i = i*y;
        }
        push(pilha, i);
    }
}


// INSERE ZERO NO TOPO DA PILA
void insert_zero(PILHA_DINAMICA *pilha){
    push(pilha, 0);
}


// LIMPA A PILHA
void empty_stack(PILHA_DINAMICA *pilha){
    long aux;
    while(pilha->tamanho != 0){
        aux = pop(pilha);
    }
}


// IMPRIME A PILHA
void print_stack(PILHA_DINAMICA *pilha){
    long *vet;
    int aux;
    NO *p_aux;

    vet = (long*) malloc (sizeof(long)*pilha->tamanho);
    aux = pilha->tamanho;
    p_aux = pilha->topo;
    while(aux != 0){
        vet[aux-1] = *p_aux->item;
        p_aux = p_aux->anterior;
        aux--;
    }
    for(aux=0; aux < pilha->tamanho; aux++){
        printf("%li ",vet[aux]);
    }
    printf("\n");
    free(vet);
    free(p_aux);
}
