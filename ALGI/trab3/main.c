#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"


int main(){
    Node *N;
    char op[1], word[30];
    int pg;

    while(strcmp(op, "s") != 0){
        scanf("%c", &op);
        switch(op[0]){
            case 'i':
                scanf("%s%d", &word, &pg);
                //CHAMHA FUNCAO
                break;

            case 'b':
                scanf("%s", &word);
                //CHAMHA FUNCAO
                break;

            case 'r':
                //CHAMHA FUNCAO
                break;

        }
    }

    return 0;
}
