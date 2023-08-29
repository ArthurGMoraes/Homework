#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindromo (char* palavra){
    // Inicializacao de variaveis
    int tamanho = strlen(palavra);
    //printf ("%d\n", tamanho);
    int i = 0;
    int f = tamanho - 1;
    int resposta = 0;

    // loop para conferir se a palavra é um palindromo
    for(i = 0; i < tamanho/2; i++ , f--){            // percorre dos extremos ate o centro comparando as letras    
        if (palavra[i] == palavra[f]){
            resposta = 1;
        } else {
            resposta = 0;
            i = tamanho;                             // caso uma letra nao seja compativel a funcao e' encerrada
        } 
    }
    return resposta;
}

int main(void)
{
    // Inicializando variaveis
    int resposta = 0;
    char *palavra = malloc(1024);                   // Alocacao de memoria 
    do
    {
        fgets(palavra, 1024, stdin);                // leitura da entrada substituindo o scanf para leitura de espacos
        if ((strlen(palavra) > 0) && (palavra[strlen (palavra) - 1] == '\n'))
        palavra[strlen (palavra) - 1] = '\0';       // formatacao da entrada

        if (strcmp(palavra, "FIM\0") != 0)
        {
            resposta = palindromo(palavra);

            if (resposta == 0){
                printf ("NAO\n");
            } else {
                printf ("SIM\n");
            }
        }
    } while (strcmp(palavra, "FIM\0") != 0);       // Loop para executar a funcao palindromo enquanto palavra != FIM 
    free(palavra);
}


