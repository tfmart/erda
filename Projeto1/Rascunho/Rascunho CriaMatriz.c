//OBS: O programa não verifica se o nome dado para matriz a ser criada já foi utilizado anteriormente.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct No {
    char nomeMatriz[20];
    int linhas, colunas;
    float **matriz;
    struct No *prox;
};

typedef struct No celula;

int buscaMatriz(celula **lista, char nome[]) {
    celula *aux = *lista;
    int c1, c2;
    
    if(aux == NULL) return 0;
    else {
        while (aux->prox != NULL) {
            if (strcmp(aux->nomeMatriz, nome) == 0) {
                for (c1 = 0; c1 < aux->linhas; c1++) {
                    for (c2 = 0; c2 < aux->colunas; c2++) {
                        printf("%6.2f ", aux->matriz[c1][c2]);
                    }
                    printf("\n");
                }
                return 1;
            }
            aux = aux->prox;
        }
        //condicao p/ ultimo elemento da lista
        if (strcmp(aux->nomeMatriz, nome) == 0) {
            for (c1 = 0; c1 < aux->linhas; c1++) {
                for (c2 = 0; c2 < aux->colunas; c2++) {
                    printf("%6.2f ", aux->matriz[c1][c2]);
                }
                printf("\n");
            }
            return 1;
        }
    }
    return 0;
}

int criarMatriz(celula **lista, int linhas, int colunas, char nome[]) {
    celula *aux = (*lista);
    celula *novo = (celula*)malloc(sizeof(celula));
    int contador;

    //valida a criação da matriz
    if((linhas < 1 || linhas > 50) || (colunas < 1 || colunas > 50)) return 0;

    strcpy(novo->nomeMatriz, nome);
    novo->linhas = linhas;
    novo->colunas = colunas;
    novo->matriz = (float**)malloc(linhas * sizeof(sizeof(float*)));
    for (contador = 0; contador < colunas; contador++) {
        novo->matriz[contador] = (float*)malloc(colunas * sizeof(float));
    }
    novo->prox = NULL;
    
    if (aux == NULL) {
        *lista = novo;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }


    return 1;
}

int destruirMatriz(celula **lista, char nome[]) {
    celula *aux = *lista;
    celula *temp = *lista;
    //condicao para primeiro elemento da lista
    if (aux == NULL) return 0;
    if (strcmp(aux->nomeMatriz, nome) == 0) {
        temp = temp->prox;
        free(aux);
        *lista = temp;
        return 1;
    } else {                                            //outros elementos da lista
        while (aux->prox != NULL) {
            if (strcmp(aux->nomeMatriz, nome) == 0) {
                temp->prox = aux->prox;
                free(aux);
                return 1;
            }
            temp = aux;
            aux = aux->prox;
        }
    }
    //condicao para ultimo elemento da lista
    if (strcmp(aux->nomeMatriz, nome) == 0) {
        temp->prox = aux->prox;
        free(aux);
        return 1;
    }
    return 0;
}

int main() {
    int linhas, colunas, menu = 0;
    char nome[20];
    celula *lista;
    
    do {
        printf("1- Cadastrar matriz\n");
        printf("2- Remover matriz\n");
        printf("3- Buscar uma matriz\n");
        printf("4- Finalizar programa\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                fpurge(stdin);
                printf("digite um nome para a sua matriz: ");
                fgets(nome, sizeof(nome), stdin);
                strtok(nome, "\n");
                printf("Digite a quantidade de linhas e colunas: ");
                fpurge(stdin);
                scanf("%i %i", &linhas, &colunas);
                if (criarMatriz(&lista, linhas, colunas, nome) != 1) printf("ERRO\n");
                else printf("OK\n");
                break;
            case 2:
                fpurge(stdin);
                printf("Digite o nome da matriz a ser removida: ");
                fgets(nome, sizeof(nome), stdin);
                strtok(nome, "\n");
                if(destruirMatriz(&lista, nome) == 1) printf("OK\n");
                else printf("ERRO\n");
                break;
            case 3:
                fpurge(stdin);
                printf("Digite o nome da matriz que deseja buscar: ");
                fgets(nome, sizeof(nome), stdin);
                strtok(nome, "\n");
                if (buscaMatriz(&lista, nome) == 0) printf("ERRO\n");
                break;
            case 4:
                printf("Finalizando...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
        
    } while (menu != 4);

    return 0;
}
