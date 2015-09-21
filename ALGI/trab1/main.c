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
        if (!strcmp("E", trim)){
            insert_zero(pilha);
            print_stack(pilha);
        }
        if (!strcmp("C", trim)){
            empty_stack(pilha);
            printf("- \n");
        }
        if (!strcmp("+",trim) || !strcmp("-",trim) || !strcmp("/",trim) ||
            !strcmp("*",trim) || !strcmp("^",trim) || !strcmp("!",trim)){
            operation(pilha, trim);
            print_stack(pilha);
        }
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
