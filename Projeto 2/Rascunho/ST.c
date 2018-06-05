#include"ST.h"

struct tipo_item{
int freq;
char palavra[20];

};


int insere(celula **raiz, char palavra[]) 
{	
    celula *aux = (*raiz);
    
    if ((*raiz) == NULL)
    {
        (*raiz) = (celula *)malloc(sizeof(celula));
        strcpy((*raiz)->item->palavra, palavra);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        return 1;
    }
    else if(strcmp((*raiz)->item->palavra, palavra) == 0)
    {
        return (freq( &(*raiz)));
    }
    else if (strcmp(palavra,(*raiz)->item->palavra) > 0)
    { 
        return(insere(&(*raiz)->dir, palavra));
    }
    else if (strcmp(palavra,(*raiz)->item->palavra) < 0)
    {
        return (insere(&(*raiz)->esq, palavra));
    }
}
