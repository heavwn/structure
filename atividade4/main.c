#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void imprimir(int v1[], int n){
    for (int i =0; i < n; i++){
        printf("%d ", v1[i]);
    }
    printf("\n");
}


int main(int argc, char* argv[]){
int i;

int v[argc-1];

for (int i = 1; i < argc; ++i) {
    v[i - 1] = atoi(argv[i]);
}

int tam = sizeof(v)/sizeof(int);


imprimir(v, tam);
bubble_sort(v, tam);
imprimir(v, tam);


    exit (0);
}