struct tipo_item{
	int freq;
	char palavra[20];
};

typedef struct arvore celula;
typedef struct tipo_item t_item;

int frequencia(t_item **item);
int aloca_item(t_item **item);
