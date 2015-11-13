/*
 * TRABALHO 2 - ALGORITIMOS E ESTRUTURAS DE DADOS I
 * CAINÃ D'AJUDA        8531511
 * VICTOR BENEVIDES     8531491
*/


#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

//Aloca a Lista dinamicamente
List *create_list_unit(){
    List *new;
    new = (List*) malloc (sizeof(List));
    new->edge = NULL;
    new->vert = NULL;

    return(new);
}

//Aloca o No dinamicamente
No *unit_edge(){
    No *new;
    new = (No*) malloc (sizeof(No));
    new->next = NULL;

    return(new);
}

//Realiza a insercao de um novo vertice
List *insert_growing(List *L, int x){
    List *aux, *aux2, *new;

    aux = L;
    while(aux->vert != NULL){
        //aux2 = aux;
        if(aux->info == x){
            return aux;
        }
        aux = aux->vert;
    }
    if(aux->info == x){
        return aux;
    }
    new = create_list_unit();
    new->info = x;
    aux->vert = new;
    return new;
}


//Retorna a média do grau dos vizinhos
float average_degree(List *L, int info){
    float i;
    int j;
    List *aux;
    No *aux2;

    i = 0;
    j = 0;

    aux = searchListElement(L, info);
    aux2 = aux->edge;
    while(aux2 != NULL){
        i = i + degree(L, aux2->info);
        aux2 = aux2->next;
        j++;
    }
    return(i/j);

}

//Insere insere a conexão na lista do vértice
void insert_vet(List *L, int x){
    No *aux;
    List *aux2;
    aux2 = L;
    if(aux2->edge == NULL){
        aux2->edge = unit_edge();
        aux2->edge->info = x;
    }else{
        aux = aux2->edge;
        while(aux->next != NULL){
            //printf("LLL: %d\n", aux->info);
            aux = aux->next;
        }
        aux->next = unit_edge();
        aux->next->info = x;
    }
}

//Verifica se o vertice está no grafo
int inGraph(List *L, int info){
    List *aux;
    aux = L;
    if(aux == NULL){
        //printf("CCC");
        return 0;
    }
    while(aux->vert != NULL){
        if(aux->info == info){
            return 1;
        }
        aux = aux->vert;
    }
    if(aux->info == info){
        return 1;
    }

    //printf("GGG");
    return 0;
}

//Retorna a lista do vértice
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

//Calcula o grau da vértice
int degree(List *L, int info){
    List *aux;
    No *aux2;
    int i=0;

    aux = searchListElement(L, info);
    aux2 = aux->edge;
    //printf("AAA:\n");
    while(aux2 != NULL){
        aux2 = aux2->next;
        i++;
    }
    return i;
}

//Realiza a conexão entre dois vértices
void connect(List *L, int x, int y){
    List *aux;
    No *aux2;

    if(!(inGraph(L, x))){
        aux = insert_growing(L, x);
        insert_vet(aux, y);
    }else{
        aux = searchListElement(L, x);
        insert_vet(aux, y);
    }

    if(!(inGraph(L, y))){
        aux = insert_growing(L, y);
        insert_vet(aux, x);
    }else{
        aux = searchListElement(L, y);
        insert_vet(aux, x);
    }
}

