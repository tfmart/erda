#include "Item.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

void frequencia(t_item **item)
{
	int cont= 0;

    cont = (*item)->freq;
    cont++;
    (*item)->freq = cont;

}

int aloca_item(t_item **item)
{
	(*item) = (t_item*)malloc(sizeof(t_item));
	(*item)->freq = 1;
}
