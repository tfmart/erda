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

    return((*item)->freq + 1);
}

int aloca_item(t_item **item)
{
	(*item) = (t_item*)malloc(sizeof(t_item));
	(*item)->freq = 0;
}
