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

typedef struct No celula;
struct No *lista = NULL;

int criarMatriz(int linhas, int colunas, char nome[]) {
    celula *aux;                                                                //auxilia na insercao da matriz da lista
    
    aux = (lista);
    celula *validaNome = (lista);                                              //ajuda a verificar se o nome lido ja foi usado
    celula *novo = (celula*)malloc(sizeof(celula));                             //no para armazenar a matriz a ser criada
    int contador;
    
    //valida a criação da matriz
    if((linhas < 1 || linhas > 50) || (colunas < 1 || colunas > 50)) return 0;  //verifica se as dimensoes sao validas
    if (validaNome != NULL) {                                                   //verifica se a matriz ja existe
        if (strcmp(validaNome->nomeMatriz, nome) == 0) return 0;
        while (aux->prox != NULL) {
            if (strcmp(validaNome->nomeMatriz, nome) == 0) return 0;
            validaNome = validaNome->prox;
            aux=aux->prox;
        }
       
    }
    
    //armazena os dados novos
    strcpy(novo->nomeMatriz, nome);
    novo->linhas = linhas;
    novo->colunas = colunas;
    novo->matriz = (float**)malloc(linhas * sizeof(float*));        //atribui as linhas para a matriz
    for (contador = 0; contador < linhas; contador++) {                    //atribui as colunas para a matriz
        novo->matriz[contador] = (float*)calloc(colunas , sizeof(float));
    }
    novo->prox = NULL;
    
    if (aux == NULL) {
        lista = novo;                              //cria uma nova lista caso a lista esteja vazia
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
    celula *aux = lista;
    celula *temp = lista;
    //condicao para primeiro elemento da lista
    if (aux == NULL) return 0;
    if (strcmp(aux->nomeMatriz, nome) == 0) {
        temp = temp->prox;
        free(aux);
        lista = temp;
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
    celula *aux = lista;
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
    celula *aux = lista;
    while (aux!= NULL) {
        if (strcmp(nome, aux->nomeMatriz) == 0) {
            val = 1;
            break;
        }
        aux= aux->prox;
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
    celula *aux = (lista);
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
    celula *aux = (lista);
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
    celula *aux = lista;
    celula *matrizResultante = lista;
    int cont = 0,i,j;
    int linhas,colunas;
    
    //verifica se matriz que deseja transpor existe e faz ponteiro apontar para a matriz
     while (aux != NULL)
     {
        
        if (strcmp(nome, aux->nomeMatriz) == 0) 
        {
            cont++;
            break;
            
        }
        aux = aux->prox;
    }

    

    if(cont == 1)
    {   //passa tamanho de linhas e colunas que a matriz resultante deve ter
        linhas = aux->linhas;
        colunas = aux->colunas;

        //chama funcao cria matriz aonde vai ser criada a matriz resultante e la mesmo eh feito a verificacao se matriz resultante, que sera a nova matriz ja existe
    	criarMatriz(linhas,colunas,nomeResultado); 

        //faz ponteiro achar a matriz resultante criada e faz ponteiro apontar para a matriz
    	while(matrizResultante != NULL)
    	{
        
       		 if (strcmp(nomeResultado,matrizResultante->nomeMatriz) == 0) 
       		{
           	    cont++;
            	break;
            
       		}

        	matrizResultante = matrizResultante->prox;
   		}
   	}

    if(cont==2)
    {	//transposicao das matrizes
        for(i=0;i < aux->linhas; i++)
    	{
    		for(j=0; j < aux->colunas;j++)
    		{
    			matrizResultante->matriz[i][j] = aux->matriz[i][j];
    		}
    	}

        //printa matriz resultante
    	for(i=0;i < aux->linhas; i++)
    	{
    		for(j=0; j < aux->colunas;j++)
    		{
    			printf("%6.2f ",matrizResultante->matriz[i][j]);
    		}
            printf("\n");
    	}

    }
    else
    {
    	return 1;    //retornando 1 printa palavra erro
    }

 }

int somarMatriz(char nome[],char nome2[],char nomeResultado[])
{
	celula *aux = lista;
	celula *aux1 = lista;
	celula *matrizResultante = lista;
	int cont = 0,i,j;
	int linhas,colunas;
	
    //verifica se a 1matriz que deseja somar existe e faz ponteiro apontar para a matriz
	while(aux != NULL)
	{
		if(strcmp (nome,aux->nomeMatriz)==0)
		{
			cont++;
			break;
		}
		aux = aux->prox;
	}

     //verifica se a 2matriz que deseja somar existe e faz ponteiro apontar para a matriz
       while(aux1 != NULL)
	   {
		  if(strcmp (nome2,aux1->nomeMatriz)==0)
		  {
		     cont++;
			 break;
		  }
		   aux1 = aux1->prox;
	   }
   


	if(cont == 2)
	{      //verificacao de as matrizes desejadas tem as mesmas dimensoes
		if((aux->linhas == aux1->linhas) && (aux->colunas == aux1->colunas))
		{	//passa tamanho de linhas e colunas que a matriz resultante deve ter			
            linhas = aux->linhas;
			colunas = aux->colunas;
			criarMatriz(linhas,colunas,nomeResultado);
			
            //verifica se matrizresultante existe e faz ponteiro apontar para a matriz
            while(matrizResultante != NULL)
            {
                if(strcmp(nomeResultado,matrizResultante->nomeMatriz)==0)
                {
                    cont++;
                    break;
                }
                matrizResultante = matrizResultante->prox;
            }
        }
        else
         { 
            return 1;
        } 
    }  
    
    else
    {
        return 1;
    }

    if(cont == 3)
	{ 	//soma das matrizes
        for(i=0;i<aux->linhas;i++)
		{
			for(j=0;j<aux->colunas;j++)
			{
				matrizResultante->matriz[i][j] = aux->matriz[i][j] + aux1->matriz[i][j];
			}
		}
        //printa matriz resultante
		for(i=0;i<aux->linhas;i++)
		{
			for(j=0;j<aux->colunas;j++)
			{
				 printf("%6.2f ",matrizResultante->matriz[i][j]);
			 }
			    printf("\n");
		}    
	}
	else
	{
		return 1;
	}
	
}

int dividirMatriz(char nome[],char nome1[],char nomeResultado[])
{
    celula *aux = lista;
    celula *aux1 = lista;
    celula *matrizResultante = lista;
    int cont =0 ,i,j;
    int linhas,colunas;

    //verifica se a 1matriz que deseja somar existe e faz ponteiro apontar para a matriz
    while(aux != NULL)
    {
        if(strcmp (nome,aux->nomeMatriz)==0)
        {
            cont++;
            break;
        }
        aux = aux->prox;
    }
    
    //verifica se a 2matriz que deseja somar existe e faz ponteiro apontar para a matriz
   
    while(aux1 != NULL)
    {
        if(strcmp (nome1,aux1->nomeMatriz)==0)
        {
            cont++;
            break;
        }
        aux1 = aux1->prox;
    }
   

    if(cont == 2)
    {   //verifica se a 1matriz e a 2matriz tem as mesmas dimensoes
        if((aux->linhas == aux1->linhas) && (aux->colunas == aux1->colunas))
        {  //anda por todos os elementos da 2matriz p verificar se nao existe elemento igual a zero, pois 2matriiz eh o denominador da divisao
            for(i=0;i<aux1->linhas;i++)
            {
                for(j=0;j<aux1->colunas;j++)
                {
                    if(aux1->matriz[i][j]== 0)
                    {
                        return 1;
                    }
                }
            }

            //passa tamanho de linhas e colunas que a matriz resultante deve ter    
            linhas = aux->linhas;
            colunas = aux->colunas;
            criarMatriz(linhas,colunas,nomeResultado);
            
            //verifica se a matriz resultante existe e faz ponteiro apontar para a matriz
            while(matrizResultante != NULL)
            {
                if(strcmp(nomeResultado,matrizResultante->nomeMatriz)==0)
                {
                    cont++;
                    break;
                }
                matrizResultante = matrizResultante->prox;
            }
        }
        else
        {
            return 1;
        }

    } 
    else
    {
        return 1;
    }
        
        if(cont==3)
        {   //divisao das matrizes  
            for(i=0; i< aux->linhas;i++)
            {
                for(j=0; j< aux->colunas;j++)
                {
                    matrizResultante->matriz[i][j] = aux->matriz[i][j] / aux1->matriz[i][j];
                }
            }

            //printa a matriz resultante
            for(i=0; i < aux->linhas;i++)
            {
                for(j=0; j<  aux->colunas; j++)
                {
                    printf("%6.2f ",matrizResultante->matriz[i][j]);
                }
                   printf("\n");
            }

        }    
    else
    {
    return 1;
    }
}


int multiplicarMatriz(char nome[],char nome1[],char nomeResultado[])
{   celula *aux = lista;
    celula *aux1 = lista;
    celula *matrizResultante = lista;
    int cont = 0 ,i,j;
    int soma = 0,k;
    int linhas,colunas;

    //verifica se 1matriz existe e faz ponteiro apontar para a matriz
    while(aux != NULL)
    {
        if(strcmp (nome,aux->nomeMatriz)==0)
        {
            cont++;
            break;
        }
        aux = aux->prox;
    }
    
    //verifica se 2matriz existe e faz ponteiro apontar para a matriz
    if(cont==1)
    { 
       while(aux1 != NULL)
       {
          if(strcmp (nome1,aux1->nomeMatriz)==0)
          {
             cont++;
             break;
          }
           aux1 = aux1->prox;
       }
    }
    else
    {
        return 1;
    }

    if(cont==2)
    {   //verifica se a coluna de 1matriz eh igual a linha da 2matriz
        if(aux->colunas == aux1->linhas)
        {
             //passa tamanho de linhas e colunas que a matriz resultante deve ter  
            linhas = aux->linhas;
            colunas = aux1->colunas;
            criarMatriz(linhas,colunas,nomeResultado);
            
            //verifica se matriz resultante existe e faz ponteiro apontar para a matriz
            while(matrizResultante != NULL)
            {
                if(strcmp(nomeResultado,matrizResultante->nomeMatriz)==0)
                {
                    cont++;
                    break;
                }
                matrizResultante = matrizResultante->prox;
            }

            if(cont == 3)
            {   //multiplicacao das matrizes
                for(i=0;i<aux->linhas;i++)
                 {
                    // j < colunas matriz2
                    for(j=0;j<aux->colunas;j++) 
                    {
                        // k < linhas matriz2
                        for(k=0;k<aux->linhas; k++) 
                        { //matriz1 x matriz2
                            soma = soma + (aux->matriz[i][k] * aux1->matriz[k][j]);
                        }
                        //armazena soma na matriz matrizResultante
                        matrizResultante->matriz[i][j] = soma;
                        
                        //zera soma novamente para cacular o proximo elemento
                        soma = 0;
                    }
                 }

                 //printa matriz resultante
                 for(i=0;i<aux->linhas;i++)
                {
                    for(j=0;j<aux1->colunas;j++)
                    {
                        printf("%6.2f",matrizResultante->matriz[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                return 1;
            }   
        }
        else
        {
            return 1;
        }   
    }
    else
    {
        return 1;
    }
}

int multiplicarElementos(char nome[],char nome1[],char nomeResultado[])
{   celula *aux = lista;
    celula *aux1 = lista;
    celula *matrizResultante= lista;
    int cont= 0,i,j;
    int linhas,colunas;


    //verifica se 1matriz existe e faz ponteiro apontar para a matriz
    while(aux != NULL)
    {
        if(strcmp (nome,aux->nomeMatriz)==0)
        {
            cont++;
            break;
        }
        aux = aux->prox;
    }
    
    if(cont==1)
    {   //verifica se 2matriz existe e faz ponteio apontar para a matriz
       while(aux1 != NULL)
       {
          if(strcmp (nome1,aux1->nomeMatriz)==0)
          {
             cont++;
             break;
          }
           aux1 = aux1->prox;
       }
    }
    else
    {
        return 1;
    }

    if(cont == 2)
    {   //verifica se a 1matriz e a 2matriz tem as mesmas dimensoes 
        if(aux->linhas == aux1->linhas && aux->colunas == aux1->colunas)
        {   
            //passa tamanho de linhas e colunas que a matriz resultante deve ter  
            linhas = aux->linhas;
            colunas = aux->colunas;
            criarMatriz(linhas,colunas,nomeResultado);


            //verifica se matriz resultante existe e faz ponteiro apontar para matriz
             while(matrizResultante != NULL)
            {
                if(strcmp(nomeResultado,matrizResultante->nomeMatriz)==0)
                {
                    cont++;
                    break;
                }
                matrizResultante = matrizResultante->prox;
            }

            if(cont == 3)
            {   //multiplicacao dos elementos das matrizes
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0; j< aux->colunas;j++)
                    {
                        matrizResultante->matriz[i][j] = aux->matriz[i][j] * aux1->matriz[i][j];
                    }
                }

                //printa matriz resultante
                for(i=0; i< aux->linhas;i++)
                {
                    for(j=0;j<aux->colunas;j++)
                    {
                        printf("%6.2f ",matrizResultante->matriz[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
 }


