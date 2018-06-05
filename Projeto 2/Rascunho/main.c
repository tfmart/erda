#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Item.h"
#include"ST.h"

typedef struct arvore celula;
typedef struct tipo_item t_item;

int main(int argc,char *argv[]) 
{
    celula *lista = NULL;
    int op, resposta;
    char palavra[20];
                   
    while((scanf ("%s", palavra)) != EOF)
    {
        resposta = insere(&lista, palavra);
        printf("%6d - %s\n",resposta, palavra);
    }

    return 0;
}
