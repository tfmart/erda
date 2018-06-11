#include "Item.h"
#include"ST.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arvore celula;
typedef struct tipo_item t_item;


//void printa(celula *raiz, int *print){

//if(raiz){
//printa(raiz->esq,print);
//exi





//}

void cria_arvore(celula *raiz, celula **raiz_freq){

	
		if(raiz){
		

		cria_arvore(raiz->dir,raiz_freq);

		nova_arvore(raiz,raiz_freq);

		cria_arvore(raiz->esq,raiz_freq);
		}

}
	

int nova_arvore(celula **raiz_freq,celula *raiz ){


if((*raiz_freq)==NULL){

(*raiz_freq)=(celula*)malloc(sizeof(celula));

(*raiz)->esq==NULL;
(*raiz)->dir==NULL;

armazena(raiz->item->palavra,raiz->item->freq,raiz_freq);

}
else if((*raiz_freq)->item->freq)==(raiz->item->palavra)){

lista(raiz_freq,raiz);
return 0;


}
else if((*raiz_freq)->item->freq)==(raiz->item->palavra)){
return(nova_arvore(raiz,&(*raiz_freq)->esq));
return(nova_arvore(raiz,&(*raiz_freq)->dir));


}
}
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

