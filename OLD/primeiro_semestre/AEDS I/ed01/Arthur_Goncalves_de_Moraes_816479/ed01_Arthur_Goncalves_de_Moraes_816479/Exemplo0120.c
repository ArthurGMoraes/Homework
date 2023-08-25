// Arthur Goncalves de Moraes 816479

#include <stdio.h>   // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h>  // para cadeias de caracteres: strcat( ), strcpy( ), strdup( ), strlen( )
#include <math.h>    // para funcoes matematicas
# define M_PI           3.14159265358979323846

int main(int argc, char *argv[])
{
    double x = 0.0; // raio

    double y = M_PI;
    double z = 0.0;

    printf("%s\n", "Digite um valor para o raio:");
    scanf("%lf", &x);

   z =  (pow((3*x)/5,3)*y*4)/3;

   printf("%s%lf\n", "o volume da esfera e':", z);
    
 


    getchar();
    return (0);
}
