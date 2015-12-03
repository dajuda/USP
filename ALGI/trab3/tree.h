#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int pag;
    char word[30];
    struct node *right, *left;
}Node;
