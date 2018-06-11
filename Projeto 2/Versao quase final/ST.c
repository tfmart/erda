#include"ST.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printa(celula *raiz,int *numero){

if(raiz && *numero !=0){

printa(raiz->dir, &(*numero));

if(*numero!=0){

printf("%i %s\n",raiz->item->freq,raiz->item->palavra);
*numero-=1;


if(raiz->item->prox!=NULL && *numero !=0){
raiz->item=raiz->item->prox;



while(raiz->item->prox!=NULL && *numero!=0){
printf("%i %s\n",raiz->item->prox->freq,raiz->item->palavra);
raiz->item=raiz->item->prox;
*numero-=1;
}}



}
printa(raiz->esq, &(*numero));
}
}







void cria_arvore(celula *raiz, celula **raiz_freq){

	
		if(raiz){
		

		cria_arvore(raiz->dir,&(*raiz_freq));

		if(!nova_arvore(raiz,&(*raiz_freq)))
			printf("Erro!\n");

		cria_arvore(raiz->esq,&(*raiz_freq));
		}

}
	

int nova_arvore(celula *raiz,celula **raiz_freq ){


if(*raiz_freq==NULL){

(*raiz_freq)=(celula*)malloc(sizeof(celula));

(*raiz_freq)->esq=NULL;
(*raiz_freq)->dir=NULL;

armazena(raiz_freq,raiz->item->freq,raiz->item->palavra);
return 1;
}
else if(((*raiz_freq)->item->freq)==(raiz->item->freq)){

lista((*raiz_freq)->item,raiz->item);
return 1;


}

if(((*raiz_freq)->item->freq)>(raiz->item->freq)){
return(nova_arvore(raiz,&(*raiz_freq)->esq));

}

return(nova_arvore(raiz,&(*raiz_freq)->dir));
}

int armazena(celula **raiz,int freq,char palavra[]){


(*raiz)->item=(t_item*)malloc(sizeof(t_item));

strcpy((*raiz)->item->palavra,palavra);
(*raiz)->item->freq=freq;
(*raiz)->item->prox=NULL;
return 0;}

void lista(t_item *item_raiz,t_item *pitem){


 t_item *auxiliador = item_raiz;



while(auxiliador->prox!=NULL){

auxiliador=auxiliador->prox;

}

auxiliador->prox = pitem;



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
