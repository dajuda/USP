#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"


int main(){
    List *L;
    L = NULL;
    //L = create_list_unit();
    int tam, vert, x, y, i;
    scanf("%d", &vert);
    scanf("%d", &tam);
    i = 0;
    while(i < tam){
        scanf("%d%d", &x, &y);
        connect(L, x, y);
        i++;
    }
    free (L);
    return 0;
}
