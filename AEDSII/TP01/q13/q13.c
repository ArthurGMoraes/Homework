#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar(char *palavra, char base, char troca, char* resposta, int i)
{
    // Inicializacao de variaveis
    int tamanho = strlen(palavra);

    // Loop percorre toda a string alterando o caracter da base pelo da troca
    if (i < tamanho){
        if (palavra[i] == base)
        {
            resposta[i] = troca; // troca de caracter
            trocar(palavra, base, troca, resposta, i + 1);
        }
        else
        {
            resposta[i] = palavra[i]; // formar string com as letras ao alteradas
            trocar(palavra, base, troca, resposta, i + 1);
        }
    } else {
        printf ("%s\n", resposta);
    }
}

int main(void)
{
    // Inicializacao de variaveis, MyIO e Random
    char *palavra = malloc(1000);
    char *resposta = malloc(1000);
    char a = ' ';
    char b = ' ';
    srand(4); // set seed

    do
    {
        fgets(palavra, 1000, stdin); // leitura da entrada substituindo o scanf para leitura de espacos
        if ((strlen(palavra) > 0) && (palavra[strlen(palavra) - 1] == '\n'))
            palavra[strlen(palavra) - 1] = '\0'; // formatacao da entrada
        if (strcmp(palavra, "FIM\0") != 0){
            strcpy(resposta, palavra);
            char a = (char)('a' + (rand() % 26));
            char b = (char)('a' + (rand() % 26));
            //printf("%c\n",a);
            //printf("%c\n",b);
        
            trocar(palavra, a, b, resposta, 0); // a entrada e dois caracteres gerados aleatoriamente sao passados para a funcao
        }
    } while (strcmp(palavra, "FIM\0") != 0); // Loop para executar a funcao rand enquanto palavra != FIM
    free(palavra);
    free(resposta);
}
