/*
Guia_0103 3c)
Arthur Goncalves de Moraes 816479
*/

#include <stdio.h>
#include <math.h>

int dec2base (int decimal, int base){
    int resultado = 0;
    char resultCHAR[80] = "";
    int potencia = 1;
    int decimalCopia = 0;
    if (base>0 && base<10){
    while (decimal > 0){
        resultado = resultado + potencia * (decimal % base);
        decimal = decimal / base;
        potencia = potencia * 10;
        //printf("%d\n", resultado);
        //printf("%d\n", decimal);
        //printf("%d\n", potencia);
    }
  } 
  
  /* else if (base>9){
    potencia = 0;
    while (decimal>0){
        decimalCopia = decimal / base;
        potencia = potencia + 1;
    }
    while (decimal>0)
    {
        resultCHAR[potencia] = 
    }
    

  } */
  /* nao consegui pensar em uma solucao para 
  as bases maiores que 9 por causa das letras*/
    return resultado;
}

int main (void){
    int decimal = 0;
    int base = 0;
    printf("Insira um numero decimal: ");
    scanf("%d", &decimal);
    printf("Insira uma base: ");
    scanf("%d", &base);
    printf("base %d = %d\n", base, dec2base(decimal, base));
}