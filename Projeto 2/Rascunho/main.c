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
    int numero,op, i,j, resposta;
    char palavra[20];
 
	for(i=0;i<argc;i++)
	{
		if(argv[i][0] == '-')
		{
			if(argv[i][1] == 'n')
			{ 
				numero = converte(argv[i]);
			}
		}
	}

	printf("%d",numero);

    while((scanf ("%s", palavra)) != EOF)
    {
		for(j = 0; j < numero; j++)
		{
        	resposta = insere(&lista, palavra);
        	printf("%6d - %s\n",resposta, palavra);
        }
    }

    return 0;
}

int converte(char caracter[])
{
	int tamanho = 0,i, X = 1,numero = 0;

	tamanho = strlen(caracter);

	for(i = tamanho - 1; i > 1; i--)
	{
		numero+=(caracter[i] - '0')*X;
		X*=10;
	}
	return numero;
}
