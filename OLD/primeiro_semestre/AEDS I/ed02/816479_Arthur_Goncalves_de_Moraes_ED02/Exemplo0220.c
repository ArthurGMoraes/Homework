// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 double x=0;
 double y=0;
 double z=0;
 x = IO_readdouble ("Digitar um valor real: ");
 y = IO_readdouble ("Digitar outro valor real: ");
 z = IO_readdouble ("Digitar outro valor real: ");
 
    if (z>y){
        if ((x<z) && (x>y)){
            IO_printf ("O primeiro numero esta entre os outros dois");
        }
        else{
         IO_printf ("O primeiro numero nao esta entre os outros dois ou e' igual a pelo menos um deles.");   
        }
    }
        
        if(z<y){
            if ((x>z) && (x<y)){
                IO_printf ("O primeiro numero esta entre os outros dois");
            }
            else{
                IO_printf ("O primeiro numero nao esta entre os outros dois ou e' igual a pelo menos um deles.");
            }
            }
        
    
   
 
 IO_pause ("Apertar enter para finalizar");
 return(0);
}