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
        //"converte" a opcao lida para um inteiro, para que se possa utilizar o switch case (compativel somente com inteiros ou char de 1 caracter)
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
            case 1://CM (Criar Matriz) <nome sem espaços> <número de linhas> <número de colunas>
                scanf("%s",nome);                                               //leitura do nome da matriz a ser criada
                scanf("%i %i", &linhas,&colunas);                               //leitra do numero de linhas e colunas da matriz a ser criada
                if (criarMatriz(linhas, colunas, nome) != 1) printf("ERRO\n");
                else printf("OK\n");
                break;
                
            case 2://DM (Destruir Matriz) <nome>
                scanf("%s",nome);                                               //le o nome da matriz a ser destruida
                if(destruirMatriz(nome) == 1) printf("OK\n");
                else printf("ERRO\n");
                break;
                
            case 3://IM (Imprimir Matriz) <nome>
                scanf("%s",nome);                                              //le o nome da matriz a ser impressa
                if (imprimirMatriz(nome) == 0) printf("ERRO\n");               //a matriz, caso exista, é impressa dentro da funcao imprimeMatriz
                break;
                
            case 4://AE (Atribuir Elemento) <nome> <linha> <coluna> <valor>
                scanf("%s",nome);                                               //le o nome da matriz a ser atribuida o elemento
                scanf("%i %i", &linhas, &colunas);                              //le as coordenadas em que o elemneto sera atribuido na matriz
                scanf("%i",&valor);
                if(atribuirElemento(nome,linhas,colunas,valor)==0)printf("OK\n");
                else printf("ERRO\n");
                break;
                
            case 5://AL (Atribuir Linha) <nome> <linha> <val1>  ...  <valn> #
                scanf("%s", nome);                                              //le o nome da matriz a ser atribuida a linha
                scanf("%i", &linhas);                                           //a linha em que os elementos serão atribuidos
                if(atribuirLinha(nome,linhas)==0)printf("OK\n");                //a leitura dos elementos ocorre dentro da funcao
                else printf("ERRO\n");
                break;
                
            case 6://AC (Atribuir Coluna) <nome> <coluna> <val1>  ...  <valm> #
                scanf("%s", nome);                                              //le o nome da matriz a ser atribuida a coluna
                scanf("%i", &colunas);                                          //le a coluna em que os elementos serao atribuidos na matriz
                if (atribuirColuna(nome,colunas)==1) printf("ERRO\n");          //a leitura dos elementos ocorre dentro da funcao
                else printf("OK\n");
                break;
                
            case 7://TM (Transpor Matriz) <nome> <nome-resultado sem espaços>
                scanf("%s",nome);                                               //le o nome da matriz a ser transposta
                scanf("%s",nomeR);                                              //le o nome que sera dado a matriz resultado
                if(transporMatriz(nome,nomeR)==1) printf("ERRO\n");
                break;
                
            case 8://SM (Somar Duas Matrizes) <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);                                               //le o nome da primeira matriz a ser somada
                scanf("%s",nome1);                                              //le o nome da segunda matriz a ser somada
                scanf("%s",nomeR);                                              //le o nome que sera dado a matriz resultado da soma
                if(somarMatriz(nome,nome1,nomeR)==1) printf("ERRO\n");
                break;
                
            case 9://DV (Divisao Elemento por Elemento) <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);                                               //le o nome da primeira matriz
                scanf("%s",nome1);                                              //le o nome da segunda matriz
                scanf("%s",nomeR);                                              //nome que sera dadao a matriz que ira armazenar o resultado da divisao
                if(dividirMatriz(nome,nome1,nomeR)==1) printf("ERRO\n");
                break;
                
            case 10://MM (Multiplicacao de matriz) <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);                                               //le o nome da primeira matriz a ser multiplicada
                scanf("%s",nome1);                                              //le o nome da segunda matriz a ser multiplicada
                scanf("%s",nomeR);                                              //le o nome a ser dado que ira armazenar o resultado da multiplicacao
                if(multiplicarMatriz(nome,nome1,nomeR)==1) printf("ERRO\n");
                break;
                
            case 11://ME (Multiplicacao Elemento por Elemento) <nome1> <nome2> <nome-resultado sem espaços >
                scanf("%s",nome);                                               //le o nome da primeira matriz
                scanf("%s",nome1);                                              //le o nome da segunda matriz
                scanf("%s",nomeR);                                              //nome a ser dado pela matriz resultante da operacao
                if(multiplicarElementos(nome,nome1,nomeR)==1) printf("ERRO\n");
                break;
            case 12:
                //finaliza o programa
                break;
            default:
                printf("OPCAO INVALIDA\n");
                fflush(stdin);
                break;
        }
        fflush(stdin);
    } while(opNum != 12);
    return 0;
}

