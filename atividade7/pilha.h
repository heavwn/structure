#ifndef PILHA_H
#define PILHA_H
#define MAX_ORDERS 10

struct Pedido;

typedef struct {
    int numeroPedido;
    char descricao[100];
} Pedido;

typedef struct {
    Pedido pedidos[MAX_ORDERS];
    int topo;
} Pilha;

void inicializarPilha(Pilha* pilha);
int empilhar(Pilha* pilha, Pedido pedido);
int desempilhar(Pilha* pilha, Pedido* pedido);

#endif