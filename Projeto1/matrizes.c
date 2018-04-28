#define <stdio.h>
#define <string.h>
#define "matrizes.h"

struct No {
    char nomeMatriz[20];
    int linhas, colunas;
    float **matriz;
    struct No *prox;
};

int CM(celula **lista, int linhas, int colunas, char nome[]) {
    celula *aux = (*lista);
    celula *aux2 = (*lista);
    celula *novo = (celula*)malloc(sizeof(celula));
    int contador;
    
    //valida a criação da matriz
    if((linhas < 1 || linhas > 50) || (colunas < 1 || colunas > 50)) return 0;
    if (aux2 != NULL) {
        if (strcmp(aux2->nomeMatriz, nome) == 0) return 0;
        while (aux->prox != NULL) {
            if (strcmp(aux2->nomeMatriz, nome) == 0) return 0;
            aux2 = aux2->prox;
        }
    }
    
    strcpy(novo->nomeMatriz, nome);
    novo->linhas = linhas;
    novo->colunas = colunas;
    novo->matriz = (float**)malloc(linhas * sizeof(sizeof(float*)));
    for (contador = 0; contador < colunas; contador++) {
        novo->matriz[contador] = (float*)malloc(colunas * sizeof(float));
    }
    novo->prox = NULL;
    
    if (aux == NULL) {
        *lista = novo;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return 1;
}

int DM(celula **lista, char nome[]) {
    celula *aux = *lista;
    celula *temp = *lista;
    //condicao para primeiro elemento da lista
    if (aux == NULL) return 0;
    if (strcmp(aux->nomeMatriz, nome) == 0) {
        temp = temp->prox;
        free(aux);
        *lista = temp;
        return 1;
    } else {                                            //outros elementos da lista
        while (aux->prox != NULL) {
            if (strcmp(aux->nomeMatriz, nome) == 0) {
                temp->prox = aux->prox;
                free(aux);
                return 1;
            }
            temp = aux;
            aux = aux->prox;
        }
    }
    //condicao para ultimo elemento da lista
    if (strcmp(aux->nomeMatriz, nome) == 0) {
        temp->prox = aux->prox;
        free(aux);
        return 1;
    }
    return 0;
}

int buscaMatriz(celula **lista, char nome[]) {
    celula *aux = *lista;
    int c1, c2;
    
    if(aux == NULL) return 0;
    else {
        while (aux->prox != NULL) {
            if (strcmp(aux->nomeMatriz, nome) == 0) {
                for (c1 = 0; c1 < aux->linhas; c1++) {
                    for (c2 = 0; c2 < aux->colunas; c2++) {
                        printf("%6.2f ", aux->matriz[c1][c2]);
                    }
                    printf("\n");
                }
                return 1;
            }
            aux = aux->prox;
        }
        //condicao p/ ultimo elemento da lista
        if (strcmp(aux->nomeMatriz, nome) == 0) {
            for (c1 = 0; c1 < aux->linhas; c1++) {
                for (c2 = 0; c2 < aux->colunas; c2++) {
                    printf("%6.2f ", aux->matriz[c1][c2]);
                }
                printf("\n");
            }
            return 1;
        }
    }
    return 0;
}

void atribuirElemento {
    
}

void atribuirLinha{
    
}

int TM(**lista,char nome, char nome-resultado)
{
  celula *aux = *lista;
  int i,j;
  float **matriz-resultante = NULL;

//buscar matriz conforme o nome
  if(aux == NULL)
  {
     return "ERRO";
  }
  else
  {
    while(aux->prox != NULL)
    {
      if(strcmp(aux->nomeMatriz,nome) == 0)
      { //montando a matriz-resultante sendo o inverso de LxC de matriz
        *matriz-resultante = malloc(aux->colunas * sizeof(float *));

        for(i=0;i< aux->linhas;i++)
        {
          matriz-resultante[i] = malloc(aux->linhas * sizeof(float));
        }
        //transpondo as matrizes
        for(i=0; i< aux->linhas;i++)
        {
          for(j=0;j<aux->colunas;j++)
          {
            matriz-resultante[j][i] = aux->matriz[i][j]
          }
        }

        //printando a matriz resultante
        for(i=0; i< aux->linhas;i++)
        {
          for(j=0;j<aux->colunas;j++)
          {
            printf("%i ",matriz-resultante[i][j]);
          }
            printf("/n");
        }
        return;
      }
      aux = aux->prox;
    }
  }

  //para ultimo elemento da lista de matrizes existentes
  if(strcmp(aux->nomeMatriz,nome)==0)
  {
    *matriz-resultante = malloc(aux->colunas * sizeof(float *));

    for(i=0;i< aux->linhas;i++)
    {
      matriz-resultante[i] = malloc(aux->linhas * sizeof(float));
    }
    //transpondo as matrizes
    for(i=0; i< aux->linhas;i++)
    {
      for(j=0;j<aux->colunas;j++)
      {
        matriz-resultante[j][i] = aux->matriz[i][j]
      }
    }
    for(i=0; i< aux->linhas;i++)
    {
      for(j=0;j<aux->colunas;j++)
      {
        printf("%i ",matriz-resultante[i][j]);
      }
        printf("/n");
    }
    return;
  }
  else
  {  return "ERRO";}
}


int SM(**lista,char nome[],char nome1[],char nome-resultado)
{
  celula **aux = *lista;
  int i,j;
  float **matriz-resultante = NULL;
  int achou1=0,achou2=0;

  if(aux == NULL)
  {
    return "ERRO";
  }
  else
  {//procura a primeira matriz
    while(aux->prox !=NULL)
    {
      if(strcmp(aux->nomeMatriz, nome)==0)
      {
        achou1 = 1;
         break;
      }

      aux = aux->prox;
    }
    //se nao achar a matriz antes da ultima posicao
    if(achou1 == 0)
    {
      if(strcmp(aux->nomeMatriz, nome)==0)
      {//procura a segunda matriz
        while(*aux->prox != NULL)
        {
          if(strcmp(*aux->nomeMatriz,nome1)==0)
          {
            achou2==1
            break;
          }
          *aux=*aux->prox;
        }
      }
      else
      {
        return "ERRO";
      }
    }

    //verifica ultima posicao da segunda matriz
    if(achou2 == 0)
    {
      if(strcmp(*aux->nomeMatriz,nome1)==0)
      {
        achou2 = 1;
      }
      else
      {
        return "ERRO";
      }
    }

    //se encontrar as duas matrizes
    if(achou1 == 1 && achou2 == 1)
    { //verifica se as matrizes tem o mesmo tamanho
      if(aux->linhaMatriz == *aux->linhaMatriz && aux->colunaMatriz == *aux->colunaMatriz)
      {
          *matriz-resultante = malloc(aux->linas * sizeof(float *));

          for(j=0;j< aux->linhas;i++)
          {
            matriz-resultante[j] = malloc(aux->colunas * sizeof(float));
          }
          //somando as matrizes
          for(i=0; i< aux->linhaMatriz;i++)
          {
            for(j=0; j< aux->colunaMatriz;j++)
            {
              matriz-resultante[i][j] = aux->matriz[i][j] + *aux->matriz[i][j];
            }
          }
          for(i=0; i< aux->linhas;i++)
          {
            for(j=0;j<aux->colunas;j++)
            {
              printf("%i ",matriz-resultante[i][j]);
            }
              printf("/n");
          }
          return;
        }
        else
        {
          return "ERRO";
        }
      }
    }
  }


int DV(**lista,char nome[],char nome1[],char nome-resultado)
{
  celula **aux = *lista;
  int i,j;
  float **matriz-resultante = NULL;
  int achou1=0,achou2=0;

  if(aux == NULL)
  {
    return "ERRO";
  }
  else
  {//procura a primeira matriz
    while(aux->prox !=NULL)
    {
      if(strcmp(aux->nomeMatriz, nome)==0)
      {
        achou1 = 1;
         break;
      }

      aux = aux->prox;
    }
    //se nao achar a matriz antes da ultima posicao
    if(achou1 == 0)
    {
      if(strcmp(aux->nomeMatriz, nome)==0)
      {
        while(*aux->prox != NULL)
        {
          if(strcmp(*aux->nomeMatriz,nome1)==0)
          {
            achou2==1
            break;
          }
          *aux=*aux->prox;
        }
      }
      else
      {
        return "ERRO";
      }
    }

    //verifica ultima posicao
    if(achou2 == 0)
    {
      if(strcmp(*aux->nomeMatriz,nome1)==0)
      {
        achou2 = 1;
      }
      else
      {
        return "ERRO";
      }
    }

    //se encontrar as duas matrizes
    if(achou1 == 1 && achou2 == 1)
    { //verifica se as matrizes tem o mesmo tamanho
      if(aux->linhaMatriz == *aux->linhaMatriz && aux->colunaMatriz == *aux->colunaMatriz)
      {
          *matriz-resultante = malloc(aux->linas * sizeof(float *));

          for(j=0;j< aux->linhas;i++)
          {
            matriz-resultante[j] = malloc(aux->colunas * sizeof(float));
          }
          //dividindo as matrizes
          for(i=0; i< aux->linhaMatriz;i++)
          {
            for(j=0; j< aux->colunaMatriz;j++)
            {
              matriz-resultante[i][j] = aux->matriz[i][j] / *aux->matriz[i][j];
            }
          }
          for(i=0; i< aux->linhas;i++)
          {
            for(j=0;j<aux->colunas;j++)
            {
              printf("%i ",matriz-resultante[i][j]);
            }
              printf("/n");
          }
          return;
        }
        else
        {
          return "ERRO";
        }

      }
    }
  }

void multMatriz1{
    
}

int ME(**lista,char nome[],char nome1[],char nome-resultado)
{
  celula **aux = *lista;
  int i,j;
  float **matriz-resultante = NULL;
  int achou1=0,achou2=0;

  if(aux == NULL)
  {
    return "ERRO";
  }
  else
  {//procura a primeira matriz
    while(aux->prox !=NULL)
    {
      if(strcmp(aux->nomeMatriz, nome)==0)
      {
        achou1 = 1;
         break;
      }

      aux = aux->prox;
    }
    //se nao achar a matriz antes da ultima posicao
    if(achou1 == 0)
    {
      if(strcmp(aux->nomeMatriz, nome)==0)
      {
        while(*aux->prox != NULL)
        {
          if(strcmp(*aux->nomeMatriz,nome1)==0)
          {
            achou2==1
            break;
          }
          *aux=*aux->prox;
        }
      }
      else
      {
        return "ERRO";
      }
    }

    //verifica ultima posicao
    if(achou2 == 0)
    {
      if(strcmp(*aux->nomeMatriz,nome1)==0)
      {
        achou2 = 1;
      }
      else
      {
        return "ERRO";
      }
    }

    //se encontrar as duas matrizes
    if(achou1 == 1 && achou2 == 1)
    { //verifica se as matrizes tem o mesmo tamanho
      if(aux->linhaMatriz == *aux->linhaMatriz && aux->colunaMatriz == *aux->colunaMatriz)
      {
          *matriz-resultante = malloc(aux->linas * sizeof(float *));

          for(j=0;j< aux->linhas;i++)
          {
            matriz-resultante[j] = malloc(aux->colunas * sizeof(float));
          }
          //multiplicando as matrizes
          for(i=0; i< aux->linhaMatriz;i++)
          {
            for(j=0; j< aux->colunaMatriz;j++)
            {
              matriz-resultante[i][j] = aux->matriz[i][j] * *aux->matriz[i][j];
            }
          }
          for(i=0; i< aux->linhas;i++)
          {
            for(j=0;j<aux->colunas;j++)
            {
              printf("%i ",matriz-resultante[i][j]);
            }
              printf("/n");
          }
          return;
        }
        else
        {
          return "ERRO";
        }

      }
    }
  }

