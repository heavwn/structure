#include <stdio.h>

int main(void){
    int i=0,j=0;
    int tam=0,n=0;

    printf("Informe o tamanho da string: ");
        scanf("%d", &tam);
    
    int string[tam];

    for(i=0;i<tam;i++){
        printf("Informe o valor %d da string: ", i+1);
            scanf("%d", &string[i]);
    }

    printf("Informe o numero a ser comparado: ");
        scanf("%d", &n);

    for(i=0;i<tam;i++){
        if(string[i]==n){
            j++;
        }
    }

    printf("O numero %d se repetiu %d vezes.\n", n,j);

return 0;
}