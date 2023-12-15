/*
Guia_0101 1c)
Arthur Goncalves de Moraes 816479
*/

#include <stdio.h>
#include <math.h>

int dec2bin (int decimal){
    int binario = 0;
    int potencia = 1;
    while (decimal > 0){
        binario = binario + potencia * (decimal % 2);
        decimal = decimal / 2;
        potencia = potencia * 10;
        //printf("%d\n", binario);
        //printf("%d\n", decimal);
        //printf("%d\n", potencia);
    }
    return binario;
}

int main (void){
    int decimal = 0;
    printf("Insira um numero decimal: ");
    scanf("%d", &decimal);
    printf("binario = %d\n", dec2bin(decimal));
}