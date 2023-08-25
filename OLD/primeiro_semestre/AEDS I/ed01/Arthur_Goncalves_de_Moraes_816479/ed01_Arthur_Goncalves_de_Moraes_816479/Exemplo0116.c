// Arthur Goncalves de Moraes 816479

#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres: strcat( ), strcpy( ), strdup( ), strlen( )
#include <math.h>    // para funcoes matematicas

int main(int argc, char *argv[])
{
    double x = 0.0; // lado

    double k = 0.0;
    double y = 0.0;
    double z = sqrt(3);

    printf("%s\n", "Digite um valor para o lado:");
    scanf("%lf", &x);
    k = x/6;

    y = ((k*k)* z )/4;


    printf("%s%lf\n", "A area do triangulo e':", y);

    getchar();
    return (0);
}
