#include <stdio.h>

int main(){
    int n=0,i=0;
    int maior=0,menor=0;
    
        printf("Informe o tamanho do array desejado: ");
            scanf("%d",&n);
    
    int array[n];

    for(i=0;i<n;i++){
        printf("\nInforme o %d elemento do array: ", i+1);
            scanf("%d", &array[i]);

        if(i==0){
            maior = array[i], menor = array[i];
        }
        if(array[i] > maior){
            maior = array[i];
        }
        else{
            if(array[i] < menor){
            menor = array[i];
            }
        }
    }

    printf("\nMaior elemento: %d", maior);
    printf("\nMenor elemento: %d\n", menor);

    return 0;
}