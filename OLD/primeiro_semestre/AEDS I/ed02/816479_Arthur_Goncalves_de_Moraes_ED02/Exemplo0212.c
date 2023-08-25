// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 int x=0;
 x = IO_readint ("DIgitar um valor inteiro: ");
 if((x % 2 == 0) && (x < -25)) {
    IO_printf ("O numero e' par e menor que -25");
 }
 else{
    if ((x % 2 != 0) && (x > 25)){
    IO_printf ("O numero e' impar e maior que 25");
    }
    else{
        IO_printf ("Valor entre -25 e 25 ou valor impar menor que -25 ou valor par maior que 25");
    }
 }
 IO_pause ("Aperte enter para finalizar");
 return(0);
}