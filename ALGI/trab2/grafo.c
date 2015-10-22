#include <stdlib.h>
#include <stdio.h>


List *create_list_unit(int info){
    List *new;
    new = (List*) malloc (sizeof(List));
    new->info = info;
    new->edge = NULL;
    new->vert = NULL;

    return(new);
}


No *unit_edge(int info){
    No *new;
    new = (No*) malloc (sizeof(No));
    new->next = NULL;
    new->info = info;

    return(new);
}


void connect(List *L, int x, int y){
    List *aux;
    No *aux2;

    if(L == NULL){

    }
    aux = L;

    while(aux->info != x){
        aux = aux->vert;
    }
    aux2 = aux->edge;
    while(aux2->info != NULL){
        aux2 = aux2->next;
    }
}

