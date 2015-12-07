#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"


int main(){
    Node *N;
    char op[1], word[30], mychar;
    int pg, i, signal=1;

    N = unit();
    N->pg = create_stack();
    N->first = 1;

    while(signal){
        scanf("%c", &op);
        switch(op[0]){
            case 'i':
                scanf("%s%d", &word, &pg);

                while(i < strlen(word)){
                    word[i] = tolower(word[i]);
                    i++;
                }
                insert(N, pg, word);
                break;

            case 'b':
                scanf("%s", &word);
                search(N, word);
                break;

            case 'r':
                //FUNCAO REMISSIVO AQUI.
                break;

            case 's':
                signal = 0;
                break;
        }
    }

    return 0;
}
