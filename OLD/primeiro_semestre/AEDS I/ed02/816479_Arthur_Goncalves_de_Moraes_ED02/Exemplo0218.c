// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 double x=0;
 double y=0;
 x = IO_readdouble ("Digitar um valor inteiro: ");
 y = IO_readouble ("Digitar outro valor inteiro: ");
 
    if (y<x){
    IO_printf ("O segundo numero e' menor que o primeiro");
    }
    else{
        if (y>x){
           IO_printf ("O segundo numero e' maior que o primeiro"); 
        }
        else {
            IO_printf ("Os numeros sao iguais"); 
        }
    }
 
 IO_pause ("Apertar enter para finalizar");
 return(0);
}