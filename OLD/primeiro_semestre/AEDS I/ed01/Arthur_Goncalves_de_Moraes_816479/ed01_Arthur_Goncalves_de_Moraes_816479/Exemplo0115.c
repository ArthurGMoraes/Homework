// Arthur Goncalves de Moraes 816479

#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres: strcat( ), strcpy( ), strdup( ), strlen( )
#include <math.h>    // para funcoes matematicas

int main(int argc, char *argv[])
{
    double x = 0.0; // lado
    double y = 0.0; // altura
    double k = 0.0;

    printf("%s\n", "Digite um valor para o lado:");
    scanf("%lf", &x);
    printf("%s\n", "Digite um valor para o outro lado:");
    scanf("%lf", &y);
    k = (x * (y * 2.0)) / 2.0;

    printf("%s%lf\n", "A area do triangulo e':", k);

    getchar();
    return (0);
}
