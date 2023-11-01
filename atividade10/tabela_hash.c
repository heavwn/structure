#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

#define HASH_TABLE_SIZE 100

typedef struct HashNode {
    char* chave;
    char* dado;
    struct HashNode* proximo;
} HashNode;

static HashNode* hash_table[HASH_TABLE_SIZE];

static int hash(char* chave) {
    int hash_value = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        hash_value += chave[i];
    }
    return hash_value % HASH_TABLE_SIZE;
}

void hash_table_init() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    int index = hash(chave);
    HashNode* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->chave, chave) == 0) {
            return current->dado;
        }
        current = current->proximo;
    }
    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int index = hash(chave);
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->chave = strdup(chave);
    new_node->dado = strdup(dado);
    new_node->proximo = hash_table[index];
    hash_table[index] = new_node;
}

int hash_table_contains(char* chave) {
    int index = hash(chave);
    HashNode* current = hash_table[index];
    while (current != NULL) {
        if (strcmp(current->chave, chave) == 0) {
            return 1;
        }
        current = current->proximo;
    }
    return 0;
}

void hash_table_remove(char* chave) {
    int index = hash(chave);
    HashNode* current = hash_table[index];
    HashNode* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->chave, chave) == 0) {
            if (previous == NULL) {
                hash_table[index] = current->proximo;
            } else {
                previous->proximo = current->proximo;
            }
            free(current->chave);
            free(current->dado);
            free(current);
            return;
        }
        previous = current;
        current = current->proximo;
    }
}

void hash_table_cleanup() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode* current = hash_table[i];
        while (current != NULL) {
            HashNode* next = current->proximo;
            free(current->chave);
            free(current->dado);
            free(current);
            current = next;
        }
        hash_table[i] = NULL;
    }
}