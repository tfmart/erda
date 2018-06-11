typedef struct tipo_item t_item;

struct arvore{
    struct arvore *dir, *esq;
    t_item *item;
};

typedef struct arvore celula;

int insere(celula **raiz, char palavra[]);
void cria_arvore(celula *raiz, celula **raiz_freq);
int nova_arvore(celula *raiz,celula **raiz_freq );
void printa(celula *raiz);
