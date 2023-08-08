#include <stdio.h>
#include <stdlib.h>

/*
INFO:

gcc --version

Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: x86_64-apple-darwin21.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin


COMANDOS:

compilar: gcc verifica_numero_primo.c
executar: ./a.out (INFORME O NUMERO QUE DESEJA VERIFICAR) 

OBS: argv[0] = ./a.out
     argv[1] = NUMERO INFORMADO

*/

int primo(int n){
int i=0, j=0;

for(i=1;i<=n;i++){
    if(n%i==0){
        j++;
    }
}
if(j==2){
    n = 1;
}
else{
    n = 0;
}
return n;
}

int main(int argc, char **argv){
    int n = atoi(argv[1]);
    int j;

        printf("\n");
        printf("0 - Nao primo\n1 -  Primo\nResposta: %d\n", primo(n));
    return 0;
}