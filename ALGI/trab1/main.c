// CAINA DAJUDA         8531511
// VICTOR BENEVIDES     8531491
// PRISCILLA PARODI     8626207


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"


int main(){
    PILHA_DINAMICA *pilha;
    char str[512], *trim;

    pilha = create_stack();
    printf("- \n");
    fgets(str, sizeof(str), stdin);
    trim = strtok(str," ");
    while (trim != NULL){

        // OPRECAO INSERE ZERO
        if (!strcmp("E", trim)){
            insert_zero(pilha);
            print_stack(pilha);
        }

        // OPERACAO LIMPA PILHA
        if (!strcmp("C", trim)){
            empty_stack(pilha);
            printf("- \n");
        }

        // OPERACAO COM OS ULTIMOS ELEMENTOS DA PILHA
        if (!strcmp("+",trim) || !strcmp("-",trim) || !strcmp("/",trim) ||
            !strcmp("*",trim) || !strcmp("^",trim) || !strcmp("!",trim)){
            operation(pilha, trim);
            print_stack(pilha);
        }

        // INSERCAO DE NUMEROS NA PILHA
        if (!strcmp("0",trim) || !strcmp("1",trim) || !strcmp("2",trim) ||
            !strcmp("3",trim) || !strcmp("4",trim) || !strcmp("5",trim) ||
            !strcmp("6",trim) || !strcmp("7",trim) || !strcmp("8",trim) ||
            !strcmp("9",trim)){
            new_item(pilha, atoi(trim));
            print_stack(pilha);
        }
        trim = strtok(NULL," ");
    }
    empty_stack(pilha);
    free(pilha);
return 0;
}
