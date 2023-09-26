#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "pilha.h"
#include "fila.h"

typedef struct {
    int codigo;
    char nome[100];
    float preco;
} ItemCardapio;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pilha pilhaPedidos;
    Fila filaCozinha;

    inicializarPilha(&pilhaPedidos);
    inicializarFila(&filaCozinha);

    int opcao;
    Pedido pedido;
    int numeroPedido = 0;

    ItemCardapio cardapio[] = {
        {1, "Balde com 10 Asinhas + Refrigerante (1.5L)", 20.90},
        {2, "Balde com 10 Coxinhas + Refrigerante (1.5L)", 23.99},
        {3, "COMBO - Balde 10 Asinhas de Frango + Porção de Batata Frita + Refrigerante (2L)", 39.99},
        {4, "ESPECIAL - Porção de Batata Frita com queijo e bacon + Refrigerante (lata)", 15.99} 
    };
    int tamanhoCardapio = sizeof(cardapio) / sizeof(cardapio[0]);

    printf("Bem-vindo ao Heavn's Wings!\n");

    while (1) {
        printf("\nOpções:\n");
        printf("1. Fazer um pedido\n");
        printf("2. Preparar pedido na cozinha\n");
        printf("3. Entregar pedido\n");
        printf("4. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao) {
            case 1:
                printf("\n============================================= Cardápio =============================================\n\n");
                for (int i = 0; i < tamanhoCardapio; i++) {
                    printf("%d. %s - R$ %.2f\n", cardapio[i].codigo, cardapio[i].nome, cardapio[i].preco);
                }
                printf("\n====================================================================================================\n\n");
                printf("Escolha um item: ");
                scanf("%d", &opcao);
                if (opcao >= 1 && opcao <= tamanhoCardapio) {
                    numeroPedido++;
                    pedido.numeroPedido = numeroPedido;
                    strcpy(pedido.descricao, cardapio[opcao - 1].nome);
                    if (empilhar(&pilhaPedidos, pedido)) {
                        printf("Pedido #%d empilhado com sucesso!\n", numeroPedido);
                    } else {
                        printf("Erro: Pilha de pedidos está cheia!\n");
                    }
                } else {
                    printf("Opção inválida. Tente novamente.\n");
                }
                break;
            case 2:
                if (desempilhar(&pilhaPedidos, &pedido)) {
                    enfileirar(&filaCozinha, pedido);
                    printf("Preparando Pedido #%d: %s\n", pedido.numeroPedido, pedido.descricao);
                } else {
                    printf("Erro: Não há pedidos para preparar na pilha!\n");
                }
                break;
            case 3:
                if (desenfileirar(&filaCozinha, &pedido)) {
                    printf("Pedido #%d entregue ao cliente: %s\n", pedido.numeroPedido, pedido.descricao);
                } else {
                    printf("Erro: Não há pedidos na fila da cozinha!\n");
                }
                break;
            case 4:
                printf("Obrigado pela preferência e volte sempre!\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}