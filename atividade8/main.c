#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv[]){

    No* n0 = no('C', NULL);
    No* n1 = no('E', NULL);
    No* n2 = no('A', no('D', no('B', no('X', no('Z', NULL)))));
    No* n3 = no('U', NULL);
    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    
    printf("---------- Lista original ----------\n");
    lista_imprimir(n0);
    printf("\n\nQuantidade de nós: %d\n", lista_quantidade_nos(n0));

    char valor_busca = 'B';
    if (lista_verificar_existencia(n0, valor_busca)) {
        printf("O valor %c existe na lista.\n", valor_busca);
    } else {
        printf("O valor %c NÃO existe na lista.\n", valor_busca);
    }

    valor_busca = 'E';
    int ocorrencias = lista_verificar_ocorrencias(n0, valor_busca);
    printf("O valor %c ocorre %d vezes na lista.\n", valor_busca, ocorrencias);

    printf("Lista original inversa: ");
    lista_imprimir_inversa(n0);
    printf("\n");

    int i = 2;
    char novo_valor = 'Q';
    lista_inserir_no_i(n0, i, novo_valor);
    printf("Lista após inserção na posição %d: ", i);
    lista_imprimir(n0);
    printf("\n");

    i = 3;
    lista_remover_no_i(n0, i);
    printf("Lista após remoção da posição %d: ", i);
    lista_imprimir(n0);
    printf("\n");

    valor_busca = 'A';
    lista_remover_no(n0, valor_busca);
    printf("Lista após remoção dos nós com valor %c: ", valor_busca);
    lista_imprimir(n0);
    printf("\n");

    lista_liberar(n0);
    n0 = NULL;
    lista_imprimir(n0);

    exit(0);
}