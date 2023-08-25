// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 int x=0;
 x = IO_readint ("DIgitar um valor inteiro: ");
 if(x % 2 == 0) {
    IO_printf ("O numero e' par");
 }
 else{
    IO_printf ("O numero e' impar");
 }
 IO_pause ("Apertar enter para finalizar");
 return(0);
}