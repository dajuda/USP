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


List *insert_growing(Lista *L, int x){
    List *aux, *aux2, *new;
    aux = L;
    while(aux->info <= x && aux->vert != NULL){
        aux2 = aux;
        aux = aux->vert;
    }

    new = create_list_unit(x);
    aux2->vert = new;
    new->vert = aux;
    return (new);
}


void insert_vet(No *N, int x){
    No *aux;
    aux = N;

    while(aux != NULL){
        aux = aux->next;
    }
    aux = unit_edge(x);
}


int inGraph(List *L, int info){
    List *aux;
    aux = L;

    while(aux != NULL){
        if(aux->info == info){
            return 1;
        }
        aux = aux->vert;
    }

    return 0;
}


void connect(List *L, int x, int y){
    List *aux;
    No *aux2;

    if(!(inGraph(L, x))){
        aux = insert_growing(L, x);
        insert_vet(aux->edge, y);
    }else{

    }

    if(!(inGraph(L, y))){
        aux = insert_growing(L, y);
        insert_vet(aux->edge, x);
    }else{
// IMPLEMENTA SE ESTIVER NO GRAFO
    }
}

