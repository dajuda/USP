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
No *unit_edge(int info);
