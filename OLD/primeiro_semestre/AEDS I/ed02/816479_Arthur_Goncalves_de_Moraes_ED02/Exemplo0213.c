// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 int x=0;
 x = IO_readint ("DIgitar um valor inteiro: ");
 if((x > 20) && (x < 45)) {
    IO_printf ("Pertence ao intervalo aberto (20;45)");
 }
 else{
    IO_printf ("Nao pertence ao intervalo aberto (20;45)");
 }
 IO_pause ("Apertar enter para finalizar");
 return(0);
}