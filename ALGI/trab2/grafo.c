#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"


List *create_list_unit(){
    List *new;
    new = (List*) malloc (sizeof(List));
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


List *insert_growing(List *L, int x){
    List *aux, *aux2, *new;

    if(L == NULL){
        L = create_list_unit();
        L->info = x;
        printf("CCC");
        return(L);
    }
    else{
        //while(aux->info <= x && aux != NULL){
            aux = L;
            aux2 = aux;
            aux = aux->vert;
            printf("XXX");
        //}

        new = create_list_unit();
        new->info = x;
        aux2->vert = new;
        new->vert = aux;
        return (new);
    }
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
    if(aux == NULL){
        printf("MMM");
        return 0;
    }

    while(aux->vert != NULL){
        if(aux->info == info){
            return 1;
        }
        aux = aux->vert;
    }

    return 0;
}


List *searchListElement(List *L, int info){
    List *aux;

    aux = L;
    while(aux != NULL){
        if(aux->info == info){
            return (aux);
        }
        aux = aux->vert;
    }
}


void connect(List *L, int x, int y){
    List *aux;
    No *aux2;

    if(!(inGraph(L, x))){
        printf("DDD");
        aux = insert_growing(L, x);
        //insert_vet(aux->edge, y);
    }else{
        //aux = searchListElement(L, x);
        //insert_vet(aux->edge, y);
    }

    if(!(inGraph(L, y))){
        //aux = insert_growing(L, y);
        //insert_vet(aux->edge, x);
    }else{
        //aux = searchListElement(L, y);
        //insert_vet(aux->edge, x);
    }
}

