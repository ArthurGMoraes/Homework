// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 int x=0;
 x = IO_readint ("DIgitar um valor inteiro: ");
 if((x >= 15) && (x <= 25)) {
    IO_printf ("Pertence aos intervalos fechados (10;25) e (15;60)");
 }
 else{
   if ((x >= 10) && (x < 15)){
    IO_printf("Pertence somente ao intervalo fechado (10;25)");
   }
   else{
    if((x>25) && (x <= 60)){
    IO_printf("Pertence somente ao intervalo fechado (15;60)");
   }
   else {
    IO_printf ("Nao pertence aos intervalos");
   }
   
   }
 }

 IO_pause ("Apertar enter para finalizar");
 return(0);
}