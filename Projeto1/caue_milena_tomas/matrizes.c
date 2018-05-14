#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrizes.h"

struct No {
    char nomeMatriz[20];
    int linhas, colunas;
    float **matriz;
    struct No *prox;
};

celula **lista = NULL;

int criarMatriz(int linhas, int colunas, char nome[]) {
    celula *aux = (*lista);                                                     //auxilia na insercao da matriz da lista
    celula *validaNome = (*lista);                                              //ajuda a verificar se o nome lido ja foi usado
    celula *novo = (celula*)malloc(sizeof(celula));                             //no para armazenar a matriz a ser criada
    int contador;
    
    //valida a criação da matriz
    if((linhas < 1 || linhas > 50) || (colunas < 1 || colunas > 50)) return 0;  //verifica se as dimensoes sao validas
    if (validaNome != NULL) {                                                   //verifica se a matriz ja existe
        if (strcmp(validaNome->nomeMatriz, nome) == 0) return 0;
        while (aux->prox != NULL) {
            if (strcmp(validaNome->nomeMatriz, nome) == 0) return 0;
            validaNome = validaNome->prox;
        }
    }
    
    //armazena os dados novos
    strcpy(novo->nomeMatriz, nome);
    novo->linhas = linhas;
    novo->colunas = colunas;
    novo->matriz = (float**)malloc(linhas * sizeof(sizeof(float*)));        //atribui as linhas para a matriz
    for (contador = 0; contador < colunas; contador++) {                    //atribui as colunas para a matriz
        novo->matriz[contador] = (float*)malloc(colunas * sizeof(float));
    }
    novo->prox = NULL;
    
    if (aux == NULL) {
        *lista = novo;                              //cria uma nova lista caso a lista esteja vazia
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;                           //caso contrário, insere a nova matriz na lista de matrizes
    }
    return 1;
    //retorna 0 para ERRO, 1 para OK
}

int destruirMatriz(char nome[]) {
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
    //retorna 0 para ERRO, 1 para OK
}

int imprimirMatriz(char nome[]) {
    celula *aux = *lista;
    int c1, c2;
    
    if(aux == NULL) return 0;                                   //caso a lista esteja vazia
    else {
        while (aux->prox != NULL) {
            if (strcmp(aux->nomeMatriz, nome) == 0) {
                for (c1 = 0; c1 < aux->linhas; c1++) {          //imprime a matriz
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
    return 0;                                                   //caso a matriz lida nao exista
    //retorna 0 para caso matriz lida não exista, 1 para OK
}

int atribuirElemento(char nome[], int linha, int coluna, float n) {
    int val = 0;    //validacao
    
    //Procura pelo vetor
    celula *aux = *lista;
    while (aux->prox != NULL) {
        if (strcmp(nome, aux->nomeMatriz) == 0) {
            val = 1;
            break;
        }
    }
    if(val == 0 || linha >= aux->linhas || linha < 0 || coluna >= aux->colunas || coluna < 0) {
        return 0;
    }
    aux->matriz[linha-1][coluna-1] = n;
    return 1;
    
}

int atribuirLinha(char Nome[], int linha) {
    
    float info;
    int cont = 0, i;
    celula *aux = (*lista);
    celula *novo = (celula*)malloc(sizeof(celula));
    
    while (aux != NULL) {
        
        if (strcmp(Nome, aux->nomeMatriz) == 0) {
            cont++;
            break;
        }
        aux = aux->prox;
    }
    
    if (cont == 1) {
        if (aux->linhas < linha) {
            return 1;
        }
        
        else {
            printf("Quais Elementos?\n");
            for (i = 0; i < aux->colunas; i++) {
                if ((scanf("%f", &info) == 1)) {
                    aux->matriz[linha-1][i] = info;
                }
                else {
                    break;
                }
            }
            
            return 0;
        }
    }
    
    else {
        return 1;
    }
}

int atribuirColuna(char Nome[], int coluna) {
    float info;
    int cont = 0, i;
    celula *aux = (*lista);
    celula *novo = (celula*)malloc(sizeof(celula));
    
    while (aux != NULL) {
        
        if (strcmp(Nome, aux->nomeMatriz) == 0) {
            cont++;
            break;
            
        }
        aux = aux->prox;
    }
    
    if (cont == 1) {
        if (aux->colunas < coluna) {
            return 1;
        }
        
        else {
            
            printf("Quais Elementos?\n");
            
            for (i = 0; i < aux->colunas; i++) {
                
                if ((scanf("%f", &info) == 1)) {
                    aux->matriz[i][coluna-1] = info;
                }
                else {
                    break;
                }
            }
            
            return 0;
        }
    }
    
    else {
        
        return 1;
    }
}

int transporMatriz(char nome[], char nomeResultado[])
{
    celula *aux = *lista;
    int i,j;
    float **matrizResultante = NULL;
    
    //buscar matriz conforme o nome
    if(aux == NULL)
    {
        return 1;
    }
    else
    {
        while(aux->prox != NULL)
        {
            if(strcmp(aux->nomeMatriz,nome) == 0)
            { //montando a matriz-resultante sendo o inverso de LxC de matriz
                *matrizResultante = malloc(aux->colunas * sizeof(float *));
                
                for(i=0;i< aux->linhas;i++)
                {
                    matrizResultante[i] = malloc(aux->linhas * sizeof(float));
                }
                //transpondo as matrizes
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0;j<aux->colunas;j++)
                    {
                        matrizResultante[j][i] = aux->matriz[i][j];
                    }
                }
                
                //printando a matriz resultante
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0;j<aux->colunas;j++)
                    {
                        printf("%6.2f ",matrizResultante[i][j]);
                    }
                    printf("/n");
                }
                return 0;
            }
            aux = aux->prox;
        }
    }
    
    //para ultimo elemento da lista de matrizes existentes
    if(strcmp(aux->nomeMatriz,nome)==0)
    {
        *matrizResultante = malloc(aux->colunas * sizeof(float *));
        
        for(i=0;i< aux->linhas;i++)
        {
            matrizResultante[i] = malloc(aux->linhas * sizeof(float));
        }
        //transpondo as matrizes
        for(i=0; i< aux->linhas;i++)
        {
            for(j=0;j<aux->colunas;j++)
            {
                matrizResultante[j][i] = aux->matriz[i][j];
            }
        }
        for(i=0; i< aux->linhas;i++)
        {
            for(j=0;j<aux->colunas;j++)
            {
                printf("%6.2f ",matrizResultante[i][j]);
            }
            printf("/n");
        }
        return 0;
    }
    else
    {  return 1;}
}


int somarMatriz(char nome[],char nome1[],char nomeResultado[])
{
    celula *aux = *lista;
    int i,j;
    float **matrizResultante = NULL;
    int achou1=0,achou2=0;
    
    if(aux == NULL)
    {
        return 1;
    }
    else
    {//procura a primeira matriz
        while(aux->prox !=NULL)
        {
            if(strcmp(aux->nomeMatriz, nome)==0)
            {
                achou1 = 1;
                break;
            }
            
            aux = aux->prox;
        }
        //se nao achar a matriz antes da ultima posicao
        if(achou1 == 0)
        {
            if(strcmp(aux->nomeMatriz, nome)==0)
            {//procura a segunda matriz
                while(aux->prox != NULL)
                {
                    if(strcmp(aux->nomeMatriz,nome1)==0)
                    {
                        achou2 = 1;
                        break;
                    }
                    aux = aux->prox;
                }
            }
            else
            {
                return 1;
            }
        }
        
        //verifica ultima posicao da segunda matriz
        if(achou2 == 0)
        {
            if(strcmp(aux->nomeMatriz,nome1)==0)
            {
                achou2 = 1;
            }
            else
            {
                return 1;
            }
        }
        
        //se encontrar as duas matrizes
        if(achou1 == 1 && achou2 == 1)
        { //verifica se as matrizes tem o mesmo tamanho
            if(aux->linhas == aux->linhas && aux->colunas == aux->colunas)
            {
                *matrizResultante = malloc(aux->linhas * sizeof(float *));
                
                for(j=0;j< aux->linhas;i++)
                {
                    matrizResultante[j] = malloc(aux->colunas * sizeof(float));
                }
                //somando as matrizes
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0; j< aux->colunas;j++)
                    {
                        matrizResultante[i][j] = aux->matriz[i][j] + aux->matriz[i][j];
                    }
                }
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0;j<aux->colunas;j++)
                    {
                        printf("%6.2f ",matrizResultante[i][j]);
                    }
                    printf("/n");
                }
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}


int dividirMatriz(char nome[],char nome1[],char nomeResultado[])
{
    celula *aux = *lista;
    int i,j;
    float **matrizResultante = NULL;
    int achou1=0,achou2=0;
    
    if(aux == NULL)
    {
        return 1;
    }
    else
    {//procura a primeira matriz
        while(aux->prox !=NULL)
        {
            if(strcmp(aux->nomeMatriz, nome)==0)
            {
                achou1 = 1;
                break;
            }
            
            aux = aux->prox;
        }
        //se nao achar a matriz antes da ultima posicao
        if(achou1 == 0)
        {
            if(strcmp(aux->nomeMatriz, nome)==0)
            {
                while(aux->prox != NULL)
                {
                    if(strcmp(aux->nomeMatriz,nome1)==0)
                    {
                        for(i=0; i< aux->linhas;i++)
                        {
                            for(j=0; j< aux->colunas;j++)
                            {
                                if(aux->matriz[i][j]==0)
                                {
                                    return 1;
                                }
                            }
                        }
                        achou2=1;
                        break;
                    }
                    *aux=*aux->prox;
                }
            }
            else
            {
                return 1;
            }
        }
        
        //verifica ultima posicao
        if(achou2 == 0)
        {
            if(strcmp(aux->nomeMatriz,nome1)==0)
            {
                //verifica se tem zero em algum elemento da matriz2
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0; j< aux->colunas;j++)
                    {
                        if(aux->matriz[i][j]==0)
                        {
                            return 1;
                        }
                    }
                }
                achou2 = 1;
            }
            else
            {
                return 1;
            }
        }
        
        //se encontrar as duas matrizes
        if(achou1 == 1 && achou2 == 1)
        { //verifica se as matrizes tem o mesmo tamanho
            if(aux->linhas == aux->linhas && aux->colunas == aux->colunas)
            {
                *matrizResultante = malloc(aux->linhas * sizeof(float *));
                
                for(j=0;j< aux->linhas;i++)
                {
                    matrizResultante[j] = malloc(aux->colunas * sizeof(float));
                }
                //dividindo as matrizes
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0; j< aux->colunas;j++)
                    {
                        matrizResultante[i][j] = aux->matriz[i][j] / aux->matriz[i][j];
                    }
                }
                for(i=0; i < aux->linhas;i++)
                {
                    for(j=0; j<  aux->colunas; j++)
                    {
                        printf("%6.2f ",matrizResultante[i][j]);
                    }
                    printf("/n");
                }
                return 0;
            }
            else
            {
                return 1;
            }
            
        }
    }
    return 1;
}

int multiplicarMatriz(char nome[],char nome1[],char nomeResultado[])
{
    celula *aux = *lista;
    int i,j,k, soma = 0;
    float **matrizResultante = NULL;
    int achou1 = 0, achou2 = 0;
    
    if(aux==NULL) {
        return 1;
    }
    else {
        //procura primeira matrizes
        while(aux->prox != NULL) {
            if(strcmp(aux->nomeMatriz,nome)==0) {
                achou1 = 1;
                break;
            }
            aux = aux->prox;
        }
        
        if(achou1 == 0) {//confere ultima posicao da lista se contem matriz1
            if(strcmp(aux->nomeMatriz, nome)==0) {//procura matriz 2
                while(aux->prox != NULL)
                {
                    if(strcmp(aux->nomeMatriz,nome1)==0) {
                        achou2 = 1;
                        break;
                    }
                    aux = aux->prox;
                }
            }
        }
        else {
            return 1;
        }
        
        //verifica ultima posicao caso de matriz 2 na ultima posicao da lista
        if(achou2 == 0) {
            if(strcmp(aux->nomeMatriz,nome1)==0) {
                achou2 = 1;
            }
            else {
                return 1;
            }
        }
        
        //caso as duas matrizes existirem
        if(achou1 == 1 && achou2 == 1) { //verifica se Coluna de matriz 1 == Linha de matriz 2
            if(aux->colunas == aux->linhas) {
                // i < linhas matriz1
                for(i=0;i<aux->linhas;i++) {
                    // j < colunas matriz2
                    for(j=0;j<aux->colunas;j++) {
                        // k < linhas matriz2
                        for(k=0;k<aux->linhas; k++) { //matriz1 x matriz2
                            soma = soma + (aux->matriz[i][k] * aux->matriz[k][j]);
                        }
                        //armazena soma na matriz matrizResultante
                        matrizResultante[i][j] = soma;
                        
                        //zera soma novamente para cacular o proximo elemento
                        soma = 0;
                    }
                }
                
                //exibe matrizResultante
                // i < linha matriz1
                for(i=0;i<aux->linhas;i++)
                {
                    for(j=0;j<aux->colunas;j++)
                    {
                        printf("%6.2f",matrizResultante[i][j]);
                    }
                    printf("\n");
                }
                
            }
            else
            {
                return 1;
            }
        }
    }
    return 1;
}

int multiplicarElementos(char nome1[],char nome2[],char nomeResultado[])
{
    celula *aux = *lista;
    int i,j;
    float **matrizResultante = NULL;
    int achou1=0,achou2=0;
    
    if(aux == NULL)
    {
        return 1;
    }
    else
    {//procura a primeira matriz
        while(aux->prox !=NULL)
        {
            if(strcmp(aux->nomeMatriz, nome1)==0)
            {
                achou1 = 1;
                break;
            }
            
            aux = aux->prox;
        }
        //se nao achar a matriz antes da ultima posicao
        if(achou1 == 0)
        {
            if(strcmp(aux->nomeMatriz, nome1)==0)
            {
                while(aux->prox != NULL)
                {
                    if(strcmp(aux->nomeMatriz,nome2)==0)
                    {
                        achou2 = 1;
                        break;
                    }
                    aux=aux->prox;
                }
            }
            else
            {
                return 1;
            }
        }
        
        //verifica ultima posicao
        if(achou2 == 0)
        {
            if(strcmp(aux->nomeMatriz,nome2)==0)
            {
                achou2 = 1;
            }
            else
            {
                return 1;
            }
        }
        
        //se encontrar as duas matrizes
        if(achou1 == 1 && achou2 == 1)
        { //verifica se as matrizes tem o mesmo tamanho
            if(aux->linhas == aux->linhas && aux->colunas == aux->colunas)
            {
                *matrizResultante = malloc(aux->linhas * sizeof(float *));
                
                for(j=0;j< aux->linhas;i++)
                {
                    matrizResultante[j] = malloc(aux->colunas * sizeof(float));
                }
                //multiplicando as matrizes
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0; j< aux->colunas;j++)
                    {
                        matrizResultante[i][j] = aux->matriz[i][j] * aux->matriz[i][j];
                    }
                }
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0;j<aux->colunas;j++)
                    {
                        printf("%6.2f ",matrizResultante[i][j]);
                    }
                    printf("/n");
                }
                return 0;
            }
            else
            {
                return 1;
            }
            
        }
    }
    return 1;
}


