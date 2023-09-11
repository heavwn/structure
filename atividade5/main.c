#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo_entrada\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    char **palavras = NULL;
    int num_palavras = 0;
    char palavra[100];

    while (fscanf(input_file, "%s", palavra) != EOF) {
        num_palavras++;
        palavras = (char **)realloc(palavras, num_palavras * sizeof(char *));
        palavras[num_palavras - 1] = strdup(palavra);
    }

    fclose(input_file);

    bubbleSort(palavras, num_palavras);

    FILE *output_file = fopen("arq_palavras_ordenado.txt", "w");

    if (output_file == NULL) {
        perror("Erro ao criar o arquivo de saída");
        return 1;
    }

    for (int i = 0; i < num_palavras; i++) {
        fprintf(output_file, "%s\n", palavras[i]);
        free(palavras[i]);
    }

    fclose(output_file);
    free(palavras);

    printf("palavras ordenadas e salvas em arq_palavras_ordenado.txt\n");

    return 0;
}