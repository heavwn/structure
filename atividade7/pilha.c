#include "pilha.h"

void inicializarPilha(Pilha* pilha) {
    pilha->topo = -1;
}

int empilhar(Pilha* pilha, Pedido pedido) {
    if (pilha->topo < MAX_ORDERS - 1) {
        pilha->pedidos[++(pilha->topo)] = pedido;
        return 1;
    }
    return 0;
}

int desempilhar(Pilha* pilha, Pedido* pedido) {
    if (pilha->topo >= 0) {
        *pedido = pilha->pedidos[(pilha->topo)--];
        return 1;
    }
    return 0;
}