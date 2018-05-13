#include "lista.h"
#include "matrizes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int linhas, colunas,valor, opNum;
    char nome[20], nome1[20], nomeR[20];
    char opcao[2];
    
    do
    {
        opNum = 0;
        scanf("%s", opcao);
        if(strcmp(opcao, "CM") == 0) opNum = 1;
        if(strcmp(opcao, "DM") == 0) opNum = 2;
        if(strcmp(opcao, "IM") == 0) opNum = 3;
        if(strcmp(opcao, "AE") == 0) opNum = 4;
        if(strcmp(opcao, "AL") == 0) opNum = 5;
        if(strcmp(opcao, "AC") == 0) opNum = 6;
        if(strcmp(opcao, "TM") == 0) opNum = 7;
        if(strcmp(opcao, "SM") == 0) opNum = 8;
        if(strcmp(opcao, "DV") == 0) opNum = 9;
        if(strcmp(opcao, "MM") == 0) opNum = 10;
        if(strcmp(opcao, "ME") == 0) opNum = 11;
        if(strcmp(opcao, "FE") == 0) opNum = 12;
        switch(opNum)
        {
            case 1://CM <nome sem espaços> <número de linhas> <número de colunas>
                scanf("%s",nome);
                scanf("%i %i", &linhas,&colunas);
                if (criarMatriz(linhas, colunas, nome) != 1) printf("ERRO\n");
                else printf("OK\n");
                break;
                
            case 2://DM <nome>
                scanf("%s",nome);
                if(destruirMatriz(nome) == 1) printf("OK\n");
                else printf("ERRO\n");
                break;
                
            case 3://IM <nome>
                scanf("%s",nome);
                if (imprimirMatriz(nome) == 0) printf("ERRO\n");
                break;
                
            case 4://AE <nome> <linha> <coluna> <valor>
                scanf("%s",nome);
                scanf("%i %i", &linhas, &colunas);
                scanf("%i",&valor);
                if(atribuirElemento(nome,linhas,colunas,valor)==1)printf("OK\n");
                else printf("ERRO\n");
                break;
                
            case 5://AL <nome> <linha> <val1>  ...  <valn> #
                scanf("%s", nome);
                scanf("%i", &linhas);
                if(atribuirLinha(nome,linhas)==1)printf("OK\n");
                else printf("ERRO\n");
                break;
                
            case 6://AC <nome> <coluna> <val1>  ...  <valm> #
                scanf("%s", nome);
                scanf("%i", &colunas);
                if (atribuirColuna(nome,colunas)==0) printf("ERRO\n");
                else printf("OK\n");
                break;
                
            case 7://TM <nome> <nome-resultado sem espaços>
                scanf("%s",nome);
                scanf("%s",nomeR);
                if(transporMatriz(nome,nomeR)==1) printf("ERRO\n");
                break;
                
            case 8://SM <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);
                scanf("%s",nome1);
                scanf("%s",nomeR);
                if(somarMatriz(nome,nome1,nomeR)==1) printf("ERRO\n");
                break;
                
            case 9://DV <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);
                scanf("%s",nome1);
                scanf("%s",nomeR);
                if(dividirMatriz(nome,nome1,nomeR)==0) printf("ERRO\n");
                break;
                
            case 10://MM <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);
                scanf("%s",nome1);
                scanf("%s",nomeR);
                if(multiplicarMatriz(nome,nome1,nomeR)==1) printf("ERRO\n");
                break;
                
            case 11://ME <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);
                scanf("%s",nome1);
                scanf("%s",nomeR);
                if(multiplicarElementos(nome,nome1,nomeR)==1) printf("ERRO\n");
                break;
            case 12:
                break;
            default:
                printf("OPCAO INVALIDA\n");
                fflush(stdin);
                break;
        }
    } while(opNum != 12);
    return 0;
}

