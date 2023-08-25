// Arthur Goncalves de Moraes 816479

#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres: strcat( ), strcpy( ), strdup( ), strlen( )
#include <math.h> // para funcoes matematicas


 int main (  int argc, char* argv [ ] )
 {
 int x = 0;
 int z = 0;
 int y = 0;
 printf ("%s\n","Digite um valor para o lado:" );
 scanf ( "%d", &x );
 z = x * x ;
 while (y<7) {
 printf ( "%s%d\n", "A area do quadrado e': ", z );
 y = y + 1;
 }
 getchar();
 return(0);
 }

