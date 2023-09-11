#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"


void swap(int* n1, int* n2){
    int aux;

    aux = *n1;
    *n1 = *n2;
    *n2= aux;
}


void bubble_sort(int v1[], int n){

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1; j++){
            int aux;

            if(v1[j] > v1[j+1]){
                swap(&v1[j], &v1[j+1]);
            }
        }
    }
}