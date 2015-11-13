/*
 * TRABALHO 2 - ALGORITIMOS E ESTRUTURAS DE DADOS I
 * CAINÃ D'AJUDA        8531511
 * VICTOR BENEVIDES     8531491
*/

#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"


int main(){
    List *L;
    int tam, vert, x, y, i;
    i = 0;

    scanf("%d", &vert);
    scanf("%d", &tam);
    scanf("%d%d", &x, &y);

    //Inicialização da lista para que não haja um nó cabeça
    L = create_list_unit();
    L->info = x;
    L->edge = unit_edge();
    L->edge->info = y;

    L->vert = create_list_unit();
    L->vert->info = y;
    L->vert->edge = unit_edge();
    L->vert->edge->info = x;
    //

    while(i < tam-1){
        scanf("%d%d", &x, &y);
        connect(L, x, y);
        i++;
    }
    printf("%d\n", degree(L, vert));
    printf("%.2f\n", average_degree(L, vert));
    free (L);
    return 0;
}
