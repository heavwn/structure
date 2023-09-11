#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bubble_sort.h"

void swap(char *str1, char *str2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void bubbleSort(char **arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}