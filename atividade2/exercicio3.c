#include <stdio.h>
#include <string.h>

int main(void){
    int i=0,j=0,n=0;
  
    char string[50];
    char stringbusca[50];
  
    printf("\nInforme a string: ");
        scanf("%s", string);
            printf("%s\n", string);

    printf("Informe a string de busca: ");
        scanf("%s", stringbusca);
            printf("%s\n", stringbusca);

    for (i=0; i<strlen(string); i++){
        for(j=0; j<strlen(stringbusca); j++){
            if(stringbusca[j]==string[i]){
            n=1;
            }
        }
    }
  
    printf("\n%d\n", n);

return 0;
}