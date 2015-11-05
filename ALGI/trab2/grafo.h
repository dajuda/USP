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
No *unit_edge(int info);
void insert_vet(No *N, int x);
int inGraph(List *L, int info);
void connect(List *L, int x, int y);
