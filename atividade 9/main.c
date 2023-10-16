#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    float valor;
    struct No* prox;
} No;

void lista_inserir_no_ordenado(No* L, No* no) {
    No* atual = L;
    No* anterior = NULL;

    while (atual != NULL && atual->valor < no->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        no->prox = L->prox;
        L->prox = no;
    } else {
        no->prox = anterior->prox;
        anterior->prox = no;
    }
}

void lerArquivoEInserirNasListas(const char* nome_arquivo, No* lista_nao_ordenada, No* lista_ordenada) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("não foi possível abrir o arquivo.\n");
        exit(1);
    }

    clock_t inicio, fim;
    double tempo_nao_ordenada = 0.0, tempo_ordenada = 0.0;
    int quantidade_numeros = 0;
    char linha[50];

    while (fgets(linha, sizeof(linha), arquivo)) {
        float valor = atof(linha);

        No* novo_no = (No*)malloc(sizeof(No));
        if (novo_no == NULL) {
            printf("erro na alocação de memória.\n");
            exit(1);
        }
        novo_no->valor = valor;
        novo_no->prox = NULL;

        inicio = clock();
        novo_no->prox = lista_nao_ordenada->prox;
        lista_nao_ordenada->prox = novo_no;
        fim = clock();
        tempo_nao_ordenada += (double)(fim - inicio) / CLOCKS_PER_SEC;

        inicio = clock();
        No* novo_no_ordenado = (No*)malloc(sizeof(No));
        if (novo_no_ordenado == NULL) {
            printf("erro na alocação de memória.\n");
            exit(1);
        }
        novo_no_ordenado->valor = valor;
        novo_no_ordenado->prox = NULL;
        lista_inserir_no_ordenado(lista_ordenada, novo_no_ordenado);
        fim = clock();
        tempo_ordenada += (double)(fim - inicio) / CLOCKS_PER_SEC;

        quantidade_numeros++;

        if (quantidade_numeros % 10000 == 0) {
            printf("números processados: %d\n", quantidade_numeros);
        }
    }

    fclose(arquivo);

    printf("tempo médio de inserção na lista não ordenada: %f segundos\n", tempo_nao_ordenada / quantidade_numeros);
    printf("tempo médio de inserção na lista ordenada: %f segundos\n", tempo_ordenada / quantidade_numeros);
}

int main() {
    No lista_nao_ordenada, lista_ordenada;

    lista_nao_ordenada.prox = NULL;
    lista_ordenada.prox = NULL;

    char nome_arquivo[100];
    printf("informe o nome do arquivo a ser lido: ");
    scanf("%s", nome_arquivo);

    lerArquivoEInserirNasListas(nome_arquivo, &lista_nao_ordenada, &lista_ordenada);

    No* atual = lista_nao_ordenada.prox;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    atual = lista_ordenada.prox;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}