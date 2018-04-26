#ifndef MATRIZES_H_
#define MATRIZES_H_

typedef struct No celula;

Matriz CM;
//Permite a criação de uma matriz
//ENTRADA: CM <nome sem espa os> <n mero de linhas> <n mero de colunas>
//SAIDA: OK ou ERRO (caso matriz ja exista ou uma das dimensoes seja menor do que 1 ou maior que 50)

Matriz DM;
//Remove uma matriz
//ENTDADA: DM <nome>
//SAIDA: OK ou ERRO

void IM;
//Imprime uma matriz
//ENTRADA: IM <nome>
//SAIDA: a(1,1) ... a(1, m) (SEPARADOS POR ESPAÇO)
//       a(n,1) ... a(n, m)
//       ou ERRO caso a matriz nao exista

void atribuirElemento;
//Atribui um numero em uma posicao de um vetor
//ENTRADA: AE <nome> <linha> <coluna> <valor>
//SAIDA: OK ou ERRO (caso o vetor nao exista ou a posicao seja invalida)

void atribuirLinha;
//Atribui uma linha de elementos a uma coluna de um vetor
//ENTRADA: AL <nome> <linha> <val1> ... <valn>
//SAIDA: OK ou ERRO (caso o vetor nao exista, a coluna seja invalida ou a qtde de elementos nao seja condizente com as dimensoes do vetor)

void transporMatriz;
//Transpoe uma matriz
//ENTRADA: TM <nome> <nome-resultado sem espacos>
//SAIDA: Imprime a matriz resultante ou ERRO (caso alguma das matrizes nao exista, suas dimensoes nao sejam as mesmas ou a matriz resultante ja existe)

void soma;
//Realiza a soma de duas matrizes
//ENTRADA: SM <nome1> <nome2> <nome-resultado sem espacos>
//SAIDA: mprime a matriz resultante ou ERRO (caso alguma das matrizes nao exista, suas dimensoes nao sejam as mesmas ou a matriz resultante ja existe)

void divisao;
//Divide uma matriz pela outra (elemento a elemento)
//ENTRADA: DV <nome1> <nome2> <nome-resultado sem espacos>
//SAIDA: OK ou ERRO (caso o vetor nao exista ou a posicao seja invalida)

void multMatriz1;
void multMatriz2;

#endif
