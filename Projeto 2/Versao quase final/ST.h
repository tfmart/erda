#include "Item.h"

struct arvore{
    struct arvore *dir, *esq;
    t_item *item;
};
typedef struct arvore celula;

void insere(celula **raiz, char palavra[]);
void cria_arvore(celula *raiz, celula **raiz_freq);
int nova_arvore(celula *raiz,celula **raiz_freq );
void printa(celula *raiz,int *numero);
int armazena(celula **raiz,int freq,char palavra[]);
void lista(celula *raiz, celula **raiz_freq);
