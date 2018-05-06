#include "lista.h"
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    char nomeMatriz[20];
    int linhas, colunas;
    float **matriz;
    struct No *prox;
};

typedef struct No celula;

int main()
{
  int linhas, colunas,valor;
  char nome[20], nome1[20], nomeR[20];
  char opcao;
  celula *lista;

  do
  { system("clear");
    scanf("%s",opcao);
    switch(opcao)
    {
      case CM://CM <nome sem espaços> <número de linhas> <número de colunas>
              scanf("%s",nome);
              scanf("%i %i", &linhas,&colunas);
              if (criarMatriz(&lista, linhas, colunas, nome) != 1) printf("ERRO\n");
              else printf("OK\n");
              break;

      case DM://DM <nome>
              scanf("%s",nome);
              if(destruirMatriz(&lista, nome) == 1) printf("OK\n");
              else printf("ERRO\n");
              break;

      case IM://IM <nome>
              scanf("%s",nome);
              if (imprimirMatriz(&lista, nome) == 0)
              else printf("ERRO\n");
              break;

      case AE://AE <nome> <linha> <coluna> <valor>
              scanf("%s",nome);
              scanf("%i %i", &linhas, &colunas);
              scanf("%i",&valor);
              if(atribuirElemento(&lista, nome,linhas,colunas,valor)==1)printf("OK\n");
              else printf("ERRO\n");
              break;

      case AL://AL <nome> <linha> <val1>  ...  <valn> #
              scanf("%s", nome);
              scanf("%i", &linhas);
              if(atribuirLinha(&lista, nome,linhas)==0)printf("OK\n");
              else printf("ERRO\n");
              break;

      case AC://AC <nome> <coluna> <val1>  ...  <valm> #
              scanf("%s", nome);
              scanf("%i", &colunas);
              if (atribuirColuna(&lista, nome,colunas)==0)printf("OK\n");
              else printf("ERRO\n");
              break;

      case TM://TM <nome> <nome-resultado sem espaços>
              scanf("%s",nome);
              scanf("%s",nomeR);
              if(transporMatriz(&lista, nome,nomeR)==0)
              else printf("ERRO\n");
              break;

      case SM://SM <nome1> <nome2> <nome-resultado sem espaços >
              scanf("%s",nome);
              scanf("%s",nome1);
              scanf("%s",nomeR);
              if(somarMatriz(nome,nome1,nomeR)==0)
              else printf("ERRO\n");
              break;

      case DV://DV <nome1> <nome2> <nome-resultado sem espaços >
              scanf("%s",nome);
              scanf("%s",nome1);
              scanf("%s",nomeR);
              if(dividirMatriz(nome,nome1,nomeR)==0)
              else printf("ERRO\n");
              break;

      case MM://MM <nome1> <nome2> <nome-resultado sem espaços >
              scanf("%s",nome);
              scanf("%s",nome1);
              scanf("%s",nomeR);
              if(multiplicarMatriz(nome,nome1,nomeR)==0)
              else printf("ERRO\n");
              break;

      case ME://ME <nome1> <nome2> <nome-resultado sem espaços >
              scanf("%s",nome);
              scanf("%s",nome1);
              scanf("%s",nomeR);
              if(multiplicarElementos(nome,nome1,nomeR)==0)
              else printf("ERRO\n");
              break;
    }
  } while(opcao != FE);
  return 0;
}
