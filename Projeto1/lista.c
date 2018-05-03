#include <stdio.h>
#include "lista.h"

struct No {
    char nomeMatriz[20];
    int linhas, colunas;
    float **matriz;
    struct No *prox;
};
