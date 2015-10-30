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

List *create_list_unit(int info);
List *inser_growing(Lista *L, int x);
No *unit_edge(int info);
void insert_vet(No *N, int x);
int inGraph(List *L, int info);
void connect(List *L, int x, int y);
