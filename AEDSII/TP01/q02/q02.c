#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindromo (char* palavra){
    int tamanho = strlen(palavra);
    //printf ("%d\n", tamanho);
    int i = 0;
    int f = tamanho - 1;
    int resposta = 0;
    for(i = 0; i < tamanho/2; i++ , f--){
        if (palavra[i] == palavra[f]){
            resposta = 1;
        } else {
            resposta = 0;
            i = tamanho;
        }
    }
    return resposta;
}

int main(void)
{
    int resposta = 0;
    char *palavra = malloc(1024);
    do
    {
        fgets(palavra, 1024, stdin);
        if ((strlen(palavra) > 0) && (palavra[strlen (palavra) - 1] == '\n'))
        palavra[strlen (palavra) - 1] = '\0';
        if (strcmp(palavra, "FIM\0") != 0)
        {
            resposta = palindromo(palavra);

            if (resposta == 0){
                printf ("NAO\n");
            } else {
                printf ("SIM\n");
            }
        }
    } while (strcmp(palavra, "FIM\0") != 0);
    free(palavra);
}


