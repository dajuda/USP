typedef struct pilha_dinamica PILHA_DINAMICA;

typedef struct NO{
    int *item;
    struct NO *anterior;
}NO;


struct pilha_dinamica{
    NO *topo;
    int tamanho;
};

NO *unit();
void push(PILHA_DINAMICA *pilha, int x);
int pop(PILHA_DINAMICA *pilha);
