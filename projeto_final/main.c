#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int chave;
    struct TreeNode* esquerda;
    struct TreeNode* direita;
};

struct TreeNode* criarNo(int chave) {
    struct TreeNode* novoNo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void inserir(struct TreeNode** raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = criarNo(chave);
    } else if (chave < (*raiz)->chave) {
        inserir(&((*raiz)->esquerda), chave);
    } else if (chave > (*raiz)->chave) {
        inserir(&((*raiz)->direita), chave);
    }
}

struct TreeNode* buscar(struct TreeNode* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    }
    return buscar(raiz->direita, chave);
}

struct TreeNode* encontrarMinimo(struct TreeNode* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

struct TreeNode* remover(struct TreeNode* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }
    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        if (raiz->esquerda == NULL) {
            struct TreeNode* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct TreeNode* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        struct TreeNode* temp = encontrarMinimo(raiz->direita);
        raiz->chave = temp->chave;
        raiz->direita = remover(raiz->direita, temp->chave);
    }
    return raiz;
}

void percorrerEmOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        percorrerEmOrdem(raiz->direita);
    }
}

void percorrerPreOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        percorrerPreOrdem(raiz->esquerda);
        percorrerPreOrdem(raiz->direita);
    }
}

void percorrerPosOrdem(struct TreeNode* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->esquerda);
        percorrerPosOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

int encontrarMaximo(struct TreeNode* raiz) {
    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }
    return raiz->chave;
}

int main() {
    struct TreeNode* raiz = NULL;

    inserir(&raiz, 50);
    inserir(&raiz, 30);
    inserir(&raiz, 20);
    inserir(&raiz, 40);
    inserir(&raiz, 70);
    inserir(&raiz, 60);
    inserir(&raiz, 80);

    printf("percorrer em ordem: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    printf("percorrer em pre-ordem: ");
    percorrerPreOrdem(raiz);
    printf("\n");

    printf("percorrer pos-ordem: ");
    percorrerPosOrdem(raiz);
    printf("\n");

    int chaveBuscada = 40;
    if (buscar(raiz, chaveBuscada) != NULL) {
        printf("%d encontrado na arvore.\n", chaveBuscada);
    } else {
        printf("%d nao encontrado na arvore.\n", chaveBuscada);
    }

    int valorMinimo = encontrarMinimo(raiz)->chave;
    int valorMaximo = encontrarMaximo(raiz);

    printf("valor minimo: %d\n", valorMinimo);
    printf("valor maximo: %d\n", valorMaximo);

    raiz = remover(raiz, 30);

    printf("percorrer em ordem apos a remocao de 30: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    return 0;
}
