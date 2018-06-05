
//TODAS AS FUNÇOES


#include "Item.h"


int insere(celula **raiz, char palavra[]) 
{	
    celula *aux = (*raiz);
    
    if ((*raiz) == NULL)
    {
        (*raiz) = (celula *)malloc(sizeof(celula));
        strcpy((*raiz)->palavra, palavra);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        return 1;
    }
    else if(strcmp((*raiz)->palavra, palavra) == 0)
    {
        return (freq( &(*raiz)));
    }
    else if (strcmp(palavra,(*raiz)->palavra) > 0)
    { 
        return(insere(&(*raiz)->dir, palavra));
    }
    else if (strcmp(palavra,(*raiz)->palavra) < 0)
    {
        return (insere(&(*raiz)->esq, palavra));
    }
}

int freq(celula **raiz)
{
    int freq;

    freq = (*raiz)->freq;
    freq++;
    (*raiz)->freq = freq;

	return ((*raiz)->freq + 1);
}
