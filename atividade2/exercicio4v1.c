#include <stdio.h>



int main() {

    int i=0, j=0, n=0, tam=0;

    printf("Informe o tamanho da string desejada: ");
        scanf("%d", &tam);

    int vet[tam];
    
    for (i = 0; i < tam; i++) {
        printf("Informe o valor do %d valor: ", i+1);
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < tam; i++) {
        for (j = i+1; j < tam; j++) {
            if (vet[i] == vet[j]) {
                n++;
            }
        }
    }

    printf("Existem %d valores repetidos.\n", n);

    return 0;
}