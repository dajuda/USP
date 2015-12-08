#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"


int main(){
    Node *N;
    char op, word[50];
    int pg, i, signal=1;

    N = unit();
    N->pg = create_stack();
    N->first = 1;

    while(signal){
        op = getchar();
        switch(op){
            case 'i':
                scanf("%s%d", &(*word), &pg);

                while(i < strlen(word)){
                    word[i] = tolower(word[i]);
                    i++;
                }
                insert(N, pg, word);
                break;

            case 'b':
                scanf("%s", &(*word));
                search(N, word);
                break;

            case 'r':
                remissivo(N);
                break;

            case 's':
                signal = 0;
                break;
        }
    }
    return 0;
}
