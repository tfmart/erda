#include "ST.h"
#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

typedef struct arvore celula;
typedef struct tipo_item t_item;

int frequencia(t_item **item)
{
	int frequencia = 0;

    frequencia = (*item)->freq;
    frequencia++;
    (*item)->freq = frequencia;

  return 0;
}

int aloca_item(t_item **item)
{
	(*item) = (t_item*)malloc(sizeof(t_item));
	(*item)->freq = 0;
}

int armazena(celula **raiz,int freq,char palavra[]){


(*raiz)->item=(celula*)malloc(sizeof(celula));

strcpy((*raiz)->item->palavra,palavra);
(*raiz)->item->freq=freq;
(*raiz)->item->prox=NULL;
return 0;}


void lista(celula *raiz, celula **raiz_freq){

lista *aux=(lista*)malloc(sizeof(lista));

lista *auxiliador=(lista*)malloc(sizeof(lista));

auxiliador->prox=NULL;

aux=(*raiz_freq)->item;

strcpy(auxiliador->palavra,(raiz)->item->palavra);

if(aux == NULL){

(*raiz_freq)->item=auxiliador;

}

else{

while(aux->prox!=NULL){
aux=aux->prox;
aux->prox=auxiliador;}}

}






}
