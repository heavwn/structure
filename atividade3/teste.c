#include <stdio.h>
#include <stdlib.h>


// INFORMAR O NUMERO DE PONTOS NA PRIMEIRA LINHA DO ARQUIVO .CSV, OU BAIXAR O .CSV QUE ESTÁ DENTRO DA PASTA, ANTES DA EXECUÇÃO

typedef struct {
    int x;
    float y;
} Ponto;

void calcular_regressao(Ponto pontos[], int n, float *inclinacao, float *intercepcao) {
    float soma_xy = 0.0, soma_x = 0.0, soma_y = 0.0, soma_x_ao_quadrado = 0.0;

    for (int i = 0; i < n; i++) {
        soma_xy += pontos[i].x * pontos[i].y;
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
        soma_x_ao_quadrado += pontos[i].x * pontos[i].x;
    }

    float numerador_inclinacao = n * soma_xy - soma_x * soma_y;
    float denominador_inclinacao = n * soma_x_ao_quadrado - soma_x * soma_x;

    if (denominador_inclinacao != 0) {
        *inclinacao = numerador_inclinacao / denominador_inclinacao;
        *intercepcao = (soma_y - *inclinacao * soma_x) / n;
    } else {
        printf("Denominador e zero. Nao e possivel calcular a inclinacao e a intercepcao.\n");
        *inclinacao = 0.0;
        *intercepcao = 0.0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);

    Ponto *pontos = (Ponto *)malloc(n * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro na alocacao de memoria\n");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%d,%f", &pontos[i].x, &pontos[i].y);
    }

    fclose(arquivo);

    float inclinacao, intercepcao;
    calcular_regressao(pontos, n, &inclinacao, &intercepcao);

    printf("A inclinacao da reta de regressao e: %.2f\n", inclinacao);
    printf("A intercepcao da reta de regressao e: %.2f\n", intercepcao);
    printf("Equacao da regressao linear: y = %.2fx + %.2f\n", inclinacao, intercepcao);

    free(pontos);

    return 0;
}