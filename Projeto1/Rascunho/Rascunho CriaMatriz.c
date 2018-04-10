//OBS:
//  - Este "protótipo" não verifica se o nome lido na main ja existe na lista
//  - Por enquanto, este programa cria uma matriz e armazena os seus dados na lista

#include <stdio.h>
#include <string.h>

struct No {
    char nomeMatriz[20];
    int linhas, colunas;
    float **matriz;
    struct No *prox;
};

typedef struct No celula;

int criarMatriz(celula **lista, int linhas, int colunas, char nome[]) {
    celula *aux = *lista;
    int contador;
    
    //FALTA VERIFICAR SE NOME LIDO JA EXISTE
    if((linhas < 1 || linhas > 50) || (colunas < 1 || colunas > 50)) return 0;
    
    //caso a lista esteja vazia (registra no comeco da lista)
    if (aux == NULL) {
        printf("Lista NULL\n");
        aux = (celula*)malloc(sizeof(celula));
        aux->linhas = linhas;
        aux->colunas = colunas;
        strcpy(aux->nomeMatriz, nome);
        
        //cria matriz
        aux->matriz = (float**)malloc(linhas * sizeof(sizeof(float*)));
        for (contador = 0; contador < colunas; contador++) {
            aux->matriz[contador] = (float*)malloc(colunas * sizeof(float));
        }
        
        //PREENCHENDO MATRIZ P/ TESTES
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                aux->matriz[i][j] = 2;
            }
        }
        aux->prox = *lista;
        *lista = aux;
    }
    
    //caso a lista ja tenha pelo menos um nó (registra no final da lista)
    else {
        printf("Not NULL\n");
        aux = *lista;
        celula *aux2 = (celula*)malloc(sizeof(celula));
        aux2 = (celula*)malloc(sizeof(celula));
        aux2->linhas = linhas;
        aux2->colunas = colunas;
        strcpy(aux2->nomeMatriz, nome);
        
        //cria matriz
        aux->matriz = (float**)malloc(linhas * sizeof(sizeof(float*)));
        for (contador = 0; contador < colunas; contador++) {
            aux->matriz[contador] = (float*)malloc(colunas * sizeof(float));
        }
        
        while (aux->prox) {
            aux = aux->prox;
        }
        aux->prox = aux2;
        
        //PREENCHENDO MATRIZ P/ TESTES
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                aux->matriz[i][j] = 2.0;
            }
        }
        
        
    }
    
    return 1;
}



int main() {
    int linhas, colunas;
    char nome[20];
    celula *lista;
    printf("digite um nome para a sua matriz: ");
    fgets(nome, sizeof(nome), stdin);
    strtok(nome, "\n");
    printf("Digite a quantidade de linhas e colunas: ");
    scanf("%i %i", &linhas, &colunas);
    if (criarMatriz(&lista, linhas, colunas, nome) == 1) printf("OK\n");
    else printf("ERRO\n");
    
    //IMPRIME CELULA PARA TESTE
    printf("Nome da celula: %s\n", lista->nomeMatriz);
    printf("Linhas %i, colunas %i\n", lista->linhas, lista->colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.1f ", lista->matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


