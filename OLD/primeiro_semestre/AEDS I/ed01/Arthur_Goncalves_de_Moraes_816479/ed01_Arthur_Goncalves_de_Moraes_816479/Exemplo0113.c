// Arthur Goncalves de Moraes 816479

#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres: strcat( ), strcpy( ), strdup( ), strlen( )
#include <math.h> // para funcoes matematicas


 int main (  int argc, char* argv [ ] )
 {
 int x = 0;
 int y = 0;
 int k = 0;
 int l = 0;
 printf ("%s\n","Digite um valor para o lado:" );
 scanf ( "%d", &x );
 printf ("%s\n","Digite um valor para o outro lado:" );
 scanf ( "%d", &y );
 k = (x * y)/2;
 while (l<3){
    printf("%s%d\n","A area para um triangulo retangulo e':", k);
    l = l+1;
 }
    getchar();
    return(0);
 }

