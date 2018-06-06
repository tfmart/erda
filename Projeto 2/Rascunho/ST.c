#include "Item.h"
#include "ST.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore celula;
typedef struct tipo_item t_item;

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
        return (frequencia(&(*raiz)->item));
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
