#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipoAluno {
    char nome[50];
    int ra;
    float nota;
    struct tipoAluno *proximo;  //endereço pra próxima célula da lista
};

//declaracao da celula
typedef struct tipoAluno celula;

//declaracão das funções
celula *buscaRa(int ra, celula *lista);
celula *buscaNome(char nome[], celula *lista);
void todosAlunos (celula *lista);
void ordernarLista(celula *lista);

int main() {
    int leituraRA, menu, boolCadastro = 0;
    char leituraNome[50];
    celula *dados = NULL, *retorno, *nova;
    //cria o primeiro elemento da lista
    dados = malloc(sizeof(dados));
    
    do {
        printf("1- CADASTRAR ALUNO\n2- BUSCAR ALUNO POR RA\n3- BUSCAR ALUNO POR NOME\n4- EXIBIR TODOS OS ALUNOS CADASTRADOS\n5- SAIR DO PROGRAMA\n\n");
        scanf("%d", &menu);
        getchar();
        switch (menu) {
            case 1:
                //CADASTRO DE ALUNOS
                nova = malloc(sizeof(nova));
                printf("Digite o nome do aluno: ");
                fgets(nova->nome, sizeof(nova->nome), stdin);
                strtok(nova->nome, "\n");
                printf("Digite o RA de %s: ", nova->nome);
                scanf("%d", &nova->ra);
                printf("Digite a nota de %s: ", nova->nome);
                scanf("%f", &nova->nota);
                printf("%s foi cadastrado com sucesso!\n\n", nova->nome);
                //cria uma nova célula na lista
                nova->proximo = dados->proximo;
                dados->proximo = nova;
                boolCadastro = 1;
                //ordernarLista(dados);
                break;
            case 2:
                //BUSCA POR RA
                printf("Digite o RA de um aluno: ");
                scanf("%d", &leituraRA);
                retorno = buscaRa(leituraRA, dados);
                if (retorno != NULL) {
                    printf("Aluno encontrado:\n%s\nRA: %i\nNota: %.1f\n\n", retorno->nome, retorno->ra, retorno->nota);
                }
                else {
                    printf("Aluno nao encontrado\n\n");
                }
                break;
            case 3:
                //BUSCA POR NOME
                printf("Digite o nome de um aluno: ");
                fgets(leituraNome, sizeof(leituraNome), stdin);
                strtok(leituraNome, "\n");
                retorno = buscaNome(leituraNome, dados);
                if (retorno != NULL) {
                    printf("Aluno encontrado:\n%s\nRA: %i\nNota: %.1f\n\n", retorno->nome, retorno->ra, retorno->nota);
                }
                else {
                    printf("Aluno nao encontrado\n\n");
                }
                break;
            case 4:
                if (boolCadastro == 0) {
                    printf("Nenhum aluno foi cadastrado até o momento\n\n");
                }
                else {
                    ordernarLista(dados);
                    todosAlunos(dados);
                }
                break;
            case 5:
                //finaliza o programa
                printf("Finalizando...\n\n");
                break;
            default:
                //opcao invalida
                printf("Opcao invalida\n\n");
                break;
        }
    } while (menu != 5);
    
    return 0;
}


//funcao para buscar aluno na lista pelo RA lido
celula *buscaRa(int ra, celula *lista) {
    celula *busca;
    busca = lista;
    while (busca != NULL && busca->ra != ra) {
        busca = busca->proximo;
    }
    //o programa retorna o endereco da celula com o RA lido, caso exista. Senão, retorna NULL
    return busca;
}

//funcao para buscar aluno pelo na nome lido
celula *buscaNome(char nome[], celula *lista) {
    celula *busca;
    busca = lista;
    while (busca != NULL && strcmp(busca->nome, nome) != 0) {
        busca = busca->proximo;
    }
    //o programa retorna o endereco da celula com o nome lido, caso exista. Senão, retorna NULL
    return busca;
}

//imprime todos os alunos cadastrados
void todosAlunos (celula *lista) {
    celula *print;
    printf("Alunos cadastrados: \n\n");
    for (print = lista->proximo; print != NULL; print = print->proximo) {
        printf("%s\nRA: %d\nNota: %.1f\n\n", print->nome, print->ra, print->nota);
    }
}

//funcao para ordernar a lista de alunos por RA (ordem crescente)
void ordernarLista(celula *lista) {
    //todosAlunos(lista);
    celula *i, *j;
    i = j = lista;
    int auxRA;
    float auxNota;
    char auxNome[50];
    while (i != NULL) {
        while (j->proximo != NULL) {
            if (j->ra > j->proximo->ra) {
                auxRA = j->ra;
                auxNota = j->nota;
                strcpy(auxNome, j->nome);
                j->ra = j->proximo->ra;
                j->nota = j->proximo->nota;
                strcpy(j->nome, j->proximo->nome);
                j->proximo->ra = auxRA;
                j->proximo->nota = auxNota;
                strcpy(j->proximo->nome, auxNome);
            }
            j = j->proximo;
        }
        j = lista;
        i = i->proximo;
    }
}
