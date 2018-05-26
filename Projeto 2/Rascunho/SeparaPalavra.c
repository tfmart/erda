#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char frase[50], *palavra;
    
    //leitura de uma string
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    strtok(frase, "\n");
        
    //armazena cada palavra da frase em *palavra (separadas por espaco, virgula, ponto, hifen, exclamação e interrogacao)
    palavra = strtok(frase, " ,.-!?");
    while (palavra != NULL) {
        printf("%s\n", palavra);
        palavra = strtok(NULL, " ,.-!?");
    }
    
    return 0;
}
