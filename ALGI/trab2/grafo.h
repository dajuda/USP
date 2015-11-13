/*
 * TRABALHO 2 - ALGORITIMOS E ESTRUTURAS DE DADOS I
 * CAINÃ D'AJUDA        8531511
 * VICTOR BENEVIDES     8531491
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int info;
    struct no *next;
}No;


typedef struct list{
    int info;
    No *edge;
    struct list *vert;
}List;

List *create_list_unit();
List *inser_growing(List *L, int x);
List *searchListElement(List *L, int info);
No *unit_edge();
void insert_vet(List *L, int x);
void connect(List *L, int x, int y);
int inGraph(List *L, int info);
int degree(List *L, int info);
float average_degree(List *L, int info);
