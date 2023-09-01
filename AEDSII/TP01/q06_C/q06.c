#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Funcao que confere se todos os caracteres sao vogais
bool vogal(char palavra[])
{
    int tamanho = strlen(palavra);
    bool result = true;
    for (int i = 0; i < tamanho; i++)
    {
        if (palavra[i] != 'a' && palavra[i] != 'A' && palavra[i] != 'e' && palavra[i] != 'E' &&
            palavra[i] != 'i' && palavra[i] != 'I' && palavra[i] != 'o' && palavra[i] != 'O' &&
            palavra[i] != 'u' && palavra[i] != 'U')
        { // confere se o caracter nao e' vogal
            result = false;
            i = tamanho; // caso algum caractere nao seja voga a funcao pode ser encerrada e seu resultado sera false
        }
    }
    return result;
}

// Funcao que confere se todos os caracteres sao consoantes
bool consoante(char palavra[])
{
    int tamanho = strlen(palavra);
    bool result = true;
    for (int i = 0; i < tamanho; i++)
    {
        if (palavra[i] == 'a' || palavra[i] == 'A' || palavra[i] == 'e' || palavra[i] == 'E' ||
            palavra[i] == 'i' || palavra[i] == 'I' || palavra[i] == 'o' || palavra[i] == 'O' ||
            palavra[i] == 'u' || palavra[i] == 'U')
        { // como as vogais sao letras verifica-se se ha a presenca de alguma antes de verificarmos se o caracter e' diferentede letra
            result = false;
            i = tamanho;
        }
        else if (!(palavra[i] >= 'a' && palavra[i] <= 'z'))
        { // verifica se o caracter e' diferente de letra
            if (!(palavra[i] >= 'A' && palavra[i] <= 'Z'))
            {
                result = false;
                i = tamanho; // caso algum seja diferente de letra a funcao e' encerrada e retorna false
            }
        }
    }
    return result;
}

// Verifica se todos os caracteres sao numeros
bool numero(char palavra[])
{
    int tamanho = strlen(palavra);
    bool result = true;
    for (int i = 0; i < tamanho; i++)
    {
        if (!(palavra[i] >= '0' && palavra[i] <= '9'))
        {
            result = false;
            i = tamanho;
        }
    }
    return result;
}

// Verifica se a entrada e' um numero real
bool real(char palavra[])
{
    int tamanho = strlen(palavra);
    int contador = 0;
    bool result = true;

    for (int i = 0; i < tamanho; i++)
    {
        if (!(palavra[i] >= '0' && palavra[i] <= '9'))
        { // confere se o caractere e' != de numero

            if (palavra[i] == ',' || palavra[i] == '.')
            {               // numeros reais possuem caracteres nao numeros, portanto aqui conferimos se o caracter faz parte dos numero real
                contador++; // um numero real so possui um ponto ou virgula
            }
            else
            {
                result = false; // a entrada possui algum caractere que nao faz parte de um numero real e portanto seu resultado e' falso
                i = tamanho;    // encerra o loop
            }
        }
    }
    if ((result == true) && contador > 1)
    { // confere se o numero de virgulas e/ou pontos e' maior que 1
        result = false;
    }
    return result;
}

int main(void)
{
    // Inicializando variaveis
    char *palavra = malloc(1000); // Alocacao de memoria
    char x1[10] = "";
    char x2[10] = "";
    char x3[10] = "";
    char x4[10] = "";

    do
    {
        fgets(palavra, 1000, stdin); // leitura da entrada substituindo o scanf para leitura de espacos
        if ((strlen(palavra) > 0) && (palavra[strlen(palavra) - 1] == '\n'))
            palavra[strlen(palavra) - 1] = '\0'; // formatacao da entrada
        if (strcmp(palavra, "FIM\0") != 0)
        {
            strcpy(x1, vogal(palavra) ? "SIM" : "NAO" ); // resultados x1,x2,x3 e x4 formatados
            strcpy(x2, consoante(palavra) ? "SIM" : "NAO");
            strcpy(x3, numero(palavra) ? "SIM" : "NAO");
            strcpy(x4, real(palavra) ? "SIM" : "NAO");
            printf("%s %s %s %s\n", x1, x2, x3, x4); // saida dos resultados formatados
        }
    } while (strcmp(palavra, "FIM\0") != 0); // Loop para executar as funcoes enquanto palavra != FIM
    free(palavra);
}
