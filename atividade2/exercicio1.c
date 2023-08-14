#include <stdio.h>

int main(){
    int n=0,i=0,j=0;
    
    printf("Informe o tamanho do array desejado: ");
        scanf("%d",&n);
    
    int array[n];

    for(i=0;i<n;i++){
        printf("\nInforme o %d do array: ", i+1);
            scanf("%d", &array[i]);
        j = j + array[i];
    }

    printf("\nO resultado da soma do array eh: %d\n", j);

    return 0;
}