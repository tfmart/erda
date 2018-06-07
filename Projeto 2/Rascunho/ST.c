#include "Item.h"
#include"ST.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arvore celula;
typedef struct tipo_item t_item;

//void cria_arvore(celula *raiz){

	
//		if(raiz){
		

//		cria_arvore(raiz->dir);

//		nova_arvore(raiz,raiz->item);

//		cria_arvore(raiz->esq);
//		}

//	}
	

//int nova_arvore(celula **raiz,char n){


//if((*raiz)==NULL){

//(*raiz)=(celula*)malloc(sizeof(celula));

//(*raiz)->esq==NULL;
//(*raiz)->dir==NULL;

//}





//}


int insere(celula **raiz, char palavra[]) 
{	
    celula *aux = (*raiz);
    
    if ((*raiz) == NULL)
    {
        (*raiz) = (celula *)malloc(sizeof(celula));
	
		aloca_item(&(*raiz)->item);

        strcpy((*raiz)->item->palavra, palavra);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        return 1;
    }
    else if(strcmp((*raiz)->item->palavra, palavra) == 0)
    {
		 (frequencia( &(*raiz)->item));
    }
    else if (strcmp(palavra,(*raiz)->item->palavra) > 0)
    { 
        return(insere(&(*raiz)->esq, palavra));
    }
    else if (strcmp(palavra,(*raiz)->item->palavra) < 0)
    {
        return (insere(&(*raiz)->dir, palavra));
    }
}
