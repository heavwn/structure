#ifndef FILA_H
#define FILA_H
#include "pilha.h"

typedef struct Node {
    Pedido pedido;
    struct Node* proximo;
} Node;

typedef struct {
    Node* frente;
    Node* traseira;
} Fila;

void inicializarFila(Fila* fila);
int enfileirar(Fila* fila, Pedido pedido);
int desenfileirar(Fila* fila, Pedido* pedido);

#endif