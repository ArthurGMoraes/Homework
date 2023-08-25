// Arthur Goncalves de Moraes 816479

#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres: strcat( ), strcpy( ), strdup( ), strlen( )
#include <math.h>    // para funcoes matematicas

int main(int argc, char *argv[])
{
    double x = 0.0; // comprimnto
    double y = 0.0; // largura
    double z = 0.0; // altura

    double k = 0.0;

    printf("%s\n", "Digite um valor para o comprimento:");
    scanf("%lf", &x);
    printf("%s\n", "Digite um valor para a largura:");
    scanf("%lf", &y);
    printf("%s\n", "Digite um valor para a altura:");
    scanf("%lf", &z);
    k = (x / 5) * (y / 5) * (z / 5);

    printf("%s%lf\n", "O volume do cubo e':", k);

    getchar();
    return (0);
}
