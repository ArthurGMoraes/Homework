// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 int x=0;
 int y=0;
 x = IO_readint ("Digitar um valor inteiro: ");
 y = IO_readint ("Digitar outro valor inteiro: ");
 if((x % 2 == 0) && (x<0) && (y %2 != 0) && (y>=0)) {
    IO_printf ("O primeiro numero e' par e negativo e o segundo e' impar e positivo");
 }
 else{
   IO_printf("Outra combinacao");
 }
 IO_pause ("Apertar enter para finalizar");
 return(0);
}