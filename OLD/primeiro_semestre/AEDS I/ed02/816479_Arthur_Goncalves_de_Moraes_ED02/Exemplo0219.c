// Arthur Goncalves de Moraes 816479

#include "io.h"

int main (){
 double x=0;
 double y=0;
 double z=0;
 x = IO_readdouble ("Digitar um valor real: ");
 y = IO_readdouble ("Digitar outro valor real: ");
 z = IO_readdouble ("Digitar outro valor real: ");
 
    if (x>y){
        if ((z<x) && (z>y)){
            IO_printf ("O terceiro numero esta entre os dois primeiros");
        }
        else{
         IO_printf ("O terceiro numero nao esta entre os dois primeiros ou e' igual a pelo menos um deles.");   
        }
    }
        
        if(x<y){
            if ((z>x) && (z<y)){
                IO_printf ("O terceiro numero esta entre os dois primeiros");
            }
            else{
                IO_printf ("O terceiro numero nao esta entre os dois primeiros ou e' igual a pelo menos um deles.");
            }
            }
        
    
   
 
 IO_pause ("Apertar enter para finalizar");
 return(0);
}