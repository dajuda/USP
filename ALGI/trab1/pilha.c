#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pilha.h"


//INICIA PILHA
PILHA_DINAMICA *create_stack(){
    PILHA_DINAMICA *aux;
    aux = (PILHA_DINAMICA*) malloc (sizeof(PILHA_DINAMICA));
    aux->tamanho = 0;
    return (aux);
}

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


// INSERE OUTRO ELEMENTO NA PILHA, MAS REALIZANDO UMA OPERACAO COM
// O ANTERIOR
void new_item(PILHA_DINAMICA *pilha, int x){
    int aux, result;
    aux = pop(pilha);
    aux = (aux*10)+x;
    push(pilha, aux);
}

// REALIZA A OPERACAO SOLICITADA COM OS DOIS ULTIMOS
// ITENS DA PILHA
void operation(PILHA_DINAMICA *pilha, char *op){
    int x, y;
    if (!strcmp("+", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x+y);
    }
    if (!strcmp("-", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x-y);
    }
    if (!strcmp("/", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x/y);
    }
    if (!strcmp("*", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, x*y);
    }
    if (!strcmp("^", op)){
        y = pop(pilha);
        x = pop(pilha);
        push(pilha, (pow(x,y)));
    }
}


// INSERE ZERO NO TOPO DA PILA
void insert_zero(PILHA_DINAMICA *pilha){
    push(pilha, 0);
}

// LIMPA A PILHA
void empty_stack(PILHA_DINAMICA *pilha){
    int aux;
    while(pilha->tamanho != 0){
        aux = pop(pilha);
    }
}


// IMPRIME A PILHA
void print_stack(PILHA_DINAMICA *pilha){
    int *vet, aux;
    NO *p_aux;

    vet = (int*) malloc (sizeof(int)*pilha->tamanho);
    aux = pilha->tamanho;
    p_aux = pilha->topo;
    while(aux != 0){
        vet[aux-1] = *p_aux->item;
        p_aux = p_aux->anterior;
        aux--;
    }
    for(aux=0; aux < pilha->tamanho; aux++){
        printf("%d ",vet[aux]);
    }
    printf("\n");
    //p_aux = NULL;
    free(vet);
    free(p_aux);
}
