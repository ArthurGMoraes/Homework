// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 int x=0;
 int y=0;
 x = IO_readint ("Digitar um valor inteiro: ");
 y = IO_readint ("Digitar outro valor inteiro: ");
 if((x % 2 != 0) && (y %2 == 0)) {
    IO_printf ("O primeiro numero e' impar e o segundo e' par");
 }
 else{
    if ((x %2 == 0) && (y%2 !=0)){
    IO_printf ("O primeiro numero e' par e o segundo e' impar");
    }
    else{
        if ((x %2 == 0) && (y%2 ==0)){
           IO_printf ("Os dois numeros sao pares"); 
        }
        else {
            IO_printf ("Os dois numeros sao impares"); 
        }
    }
 }
 IO_pause ("Apertar enter para finalizar");
 return(0);
}