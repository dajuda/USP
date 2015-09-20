typedef struct pilha_dinamica PILHA_DINAMICA;

typedef struct NO{
    int *item;
    struct NO *anterior;
}NO;


struct pilha_dinamica{
    NO *topo;
    int tamanho;
};

enum OP{
    soma= 1,
    subtracao,
    divisao,
    multiplicacao
};

PILHA_DINAMICA *create_stack();
NO *unit();
void push(PILHA_DINAMICA *pilha, int x);
int pop(PILHA_DINAMICA *pilha);
void new_item(PILHA_DINAMICA *pilha, int x);
void operation(PILHA_DINAMICA *pilha, int op);
void empty_stack(PILHA_DINAMICA *pilha);
