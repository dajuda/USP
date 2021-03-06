// CAINA DAJUDA         8531511
// VICTOR BENEVIDES     8531491
// PRISCILLA PARODI     8626207


typedef struct pilha_dinamica PILHA_DINAMICA;

// UNIDADE LISTA
typedef struct NO{
    long *item;
    struct NO *anterior;
}NO;


// UNIDADE PILHA DINAMICA
struct pilha_dinamica{
    NO *topo;
    int tamanho;
};


PILHA_DINAMICA *create_stack();
NO *unit();
void push(PILHA_DINAMICA *pilha, long x);
long pop(PILHA_DINAMICA *pilha);
void new_item(PILHA_DINAMICA *pilha, int x);
void operation(PILHA_DINAMICA *pilha, char *op);
void empty_stack(PILHA_DINAMICA *pilha);
void print_stack(PILHA_DINAMICA *pilha);
