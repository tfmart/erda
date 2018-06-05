//CHAMADA DAS FUNÇOES
struct tipo_item{
int freq;
char palavra[20];

};
typedef struct arvore celula;
typedef struct tipo_item t_item;

void frequencia(t_item **item);
int aloca_item(t_item **item);
