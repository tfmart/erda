#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ST.h"

int converte(char caracter[]);


int main(int argc,char *argv[]) 
{
    celula *lista2= NULL,*lista = NULL;
    int numero,op, i,j;
    char palavra[20];
                  

 
for(i=0;i<argc;i++){

if(argv[i][0] == '-'){
if(argv[i][1]== 'n'){ 

numero = converte(argv[i]);}}

}


    while((scanf ("%s", palavra)) != EOF)

    {

        
        insere(&lista,palavra);
    }


cria_arvore(lista,&lista2);


printa(lista,&numero);


    return 0;
}

int converte(char caracter[]){

int tamanho=0,i, X=1,numero=0;

tamanho=strlen(caracter);



for(i=tamanho-1;i>1;i--){


numero+=(caracter[i]-'0')*X;

X*=10;
}
return numero;


}
