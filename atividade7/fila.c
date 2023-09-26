#include "fila.h"
#include <stdlib.h>

void inicializarFila(Fila* fila) {
    fila->frente = fila->traseira = NULL;
}

int enfileirar(Fila* fila, Pedido pedido) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->pedido = pedido;
    novoNode->proximo = NULL;

    if (fila->traseira == NULL) {
        fila->frente = fila->traseira = novoNode;
    } else {
        fila->traseira->proximo = novoNode;
        fila->traseira = novoNode;
    }
    return 1;
}

int desenfileirar(Fila* fila, Pedido* pedido) {
    if (fila->frente != NULL) {
        Node* temp = fila->frente;
        *pedido = temp->pedido;
        fila->frente = temp->proximo;
        free(temp);

        if (fila->frente == NULL) {
            fila->traseira = NULL;
        }
        return 1;
    }
    return 0; 
}