// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 int x=0;
 x = IO_readint ("DIgitar um valor inteiro: ");
 if((x >= 15) && (x <= 50)) {
    IO_printf ("Pertence ao intervalo fechado (15;50)");
 }
 else{
    IO_printf ("Nao pertence ao intervalo fechado (15;50)");
 }
 IO_pause ("Apertar enter para finalizar");
 return(0);
}