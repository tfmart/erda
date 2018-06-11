#include"ST.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printa(celula *raiz,int *numero){

if(raiz){

printa(raiz->dir,numero);

if(*numero!=0){

printf("%i %s\n",raiz->item->freq,raiz->item->palavra);


if(raiz->item->prox!=NULL){

printf("%i %s\n",raiz->item->prox->freq,raiz->item->palavra);

}
(*numero)--;

}
printa(raiz->esq, numero);
}
}







void cria_arvore(celula *raiz, celula **raiz_freq){

	
		if(raiz){
		

		cria_arvore(raiz->dir,raiz_freq);

		nova_arvore(raiz,&(*raiz_freq));

		cria_arvore(raiz->esq,raiz_freq);
		}

}
	

int nova_arvore(celula *raiz,celula **raiz_freq ){


if(*raiz_freq==NULL){

(*raiz_freq)=(celula*)malloc(sizeof(celula));

(*raiz_freq)->esq==NULL;
(*raiz_freq)->dir==NULL;

armazena(raiz_freq,raiz->item->freq,raiz->item->palavra);

}
else if(((*raiz_freq)->item->freq)==(raiz->item->freq)){

lista((*raiz_freq),&raiz);
return 0;


}
else if(((*raiz_freq)->item->freq)==(raiz->item->freq)){
return(nova_arvore(raiz,&(*raiz_freq)->esq));
return(nova_arvore(raiz,&(*raiz_freq)->dir));


}
}

int armazena(celula **raiz,int freq,char palavra[]){


(*raiz)->item=(t_item*)malloc(sizeof(t_item));

strcpy((*raiz)->item->palavra,palavra);
(*raiz)->item->freq=freq;
(*raiz)->item->prox=NULL;
return 0;}

void lista(celula *raiz, celula **raiz_freq){

 t_item *aux=(t_item*)malloc(sizeof(t_item));

 t_item *auxiliador=(t_item*)malloc(sizeof(t_item));

auxiliador->prox=NULL;

aux=(*raiz_freq)->item;

strcpy(auxiliador->palavra,(raiz)->item->palavra);

if(aux == NULL){

(*raiz_freq)->item=auxiliador;

}

else{

while(aux->prox!=NULL){
aux=aux->prox;
aux->prox=auxiliador;}

}
}

void insere(celula **raiz, char palavra[]) 
{	
    celula *aux = (*raiz);
    
    if ((*raiz) == NULL)
    {
        (*raiz) = (celula *)malloc(sizeof(celula));
	
		aloca_item(&(*raiz)->item);

        strcpy((*raiz)->item->palavra, palavra);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        return ;

    }
    else if(strcmp((*raiz)->item->palavra, palavra) == 0)
    {
		 frequencia(&(*raiz)->item);
    }
    else if (strcmp(palavra,(*raiz)->item->palavra) > 0)
    { 
        insere(&(*raiz)->esq, palavra);
    }
    else if (strcmp(palavra,(*raiz)->item->palavra) < 0)
    {
        insere(&(*raiz)->dir, palavra);
    }
}
