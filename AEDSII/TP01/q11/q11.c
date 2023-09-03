#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void palindromo(char *palavra, int i, int f, int resposta)
{
    // Inicializacao de variaveis
    int tamanho = strlen(palavra);
    // printf ("%d\n", tamanho);

    // loop para conferir se a palavra é um palindromo
    if (i < tamanho / 2)
    {
        if (palavra[i] == palavra[f])
        {
            resposta = 1;
            palindromo(palavra, i + 1, f - 1, resposta);
        }
        else
        {
            printf("NAO\n");
            i = tamanho; // caso uma letra nao seja compativel a funcao e' encerrada
        }
    }
    else
    {
            printf("SIM\n");
    }
}

int main(void)
{
    // Inicializando variaveis
    int resposta = 0;
    char *palavra = malloc(1000); // Alocacao de memoria
    do
    {
        fgets(palavra, 1000, stdin); // leitura da entrada substituindo o scanf para leitura de espacos
        if ((strlen(palavra) > 0) && (palavra[strlen(palavra) - 1] == '\n'))
            palavra[strlen(palavra) - 1] = '\0'; // formatacao da entrada

        if (strcmp(palavra, "FIM\0") != 0)
        {
            palindromo(palavra, 0, strlen(palavra) - 1, 0);
        }
    } while (strcmp(palavra, "FIM\0") != 0); // Loop para executar a funcao palindromo enquanto palavra != FIM
    free(palavra);
}
