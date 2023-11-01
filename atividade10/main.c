#include <stdio.h>
#include "tabela_hash.h"

int main() {
    hash_table_init();

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");
    hash_table_put("chave4", "valor4");
    hash_table_put("chave5", "valor5");

    printf("Valor para chave1: %s\n", hash_table_get("chave1"));
    printf("Valor para chave2: %s\n", hash_table_get("chave2"));
    printf("Valor para chave3: %s\n", hash_table_get("chave3"));
    printf("Valor para chave4: %s\n", hash_table_get("chave4"));
    printf("Valor para chave5: %s\n", hash_table_get("chave5"));
    printf("\n");

    if (hash_table_contains("chave1")) {
        printf("A chave1 está na tabela.\n");
    } else {
        printf("A chave1 não está na tabela.\n");
    }

    if (hash_table_contains("chave2")) {
        printf("A chave2 está na tabela.\n");
    } else {
        printf("A chave2 não está na tabela.\n");
    }

    hash_table_remove("chave3");
    if (hash_table_contains("chave3")) {
        printf("A chave3 está na tabela.\n");
    } else {
        printf("A chave3 não está mais na tabela.\n");
    }

    hash_table_remove("chave4");
    if (hash_table_contains("chave4")) {
        printf("A chave4 está na tabela.\n");
    } else {
        printf("A chave4 não está mais na tabela.\n");
    }

    if (hash_table_contains("chave5")) {
        printf("A chave5 está na tabela.\n");
    } else {
        printf("A chave5 não está na tabela.\n");
    }

    if (hash_table_contains("chave100")) {
        printf("A chave100 está na tabela.\n");
    } else {
        printf("A chave100 não está na tabela.\n");
    }

    hash_table_cleanup();
    return 0;
}