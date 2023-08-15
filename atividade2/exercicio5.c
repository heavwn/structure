#include <stdio.h>
#include <stdlib.h>

int main(){

    int n=0,i=0,j=0;

    printf("Informe o tamanho maximo das strings: ");
        scanf("%d", &n);

    int string[n];
    int string2[n];
    int stringresultado[n];

    for(i=0;i<n;i++){
        printf("\nInforme o %d numero da Primeira string: ", i+1);
            scanf("%d", &string[i]);
    }

    system("clear");

    for(i=0;i<n;i++){
        printf("\nInforme o %d numero da segunda string: ", i+1);
            scanf("%d", &string2[i]);
    }

    system("clear");

    for(i=0;i<n;i++){
        stringresultado[i] = string[i] * string2[i];
    }

    printf("Primeira String: ");
    for(i=0;i<n;i++){
        printf("%d ", string[i]);
    }

    printf("\n");

    printf("Segunda String: ");
    for(i=0;i<n;i++){
        printf("%d ", string2[i]);
    }

    printf("\n");

    printf("\nResultado: ");
    for(i=0;i<n;i++){
        printf("%d ", stringresultado[i]);
    }

    printf("\n");
    
    return 0;
}
