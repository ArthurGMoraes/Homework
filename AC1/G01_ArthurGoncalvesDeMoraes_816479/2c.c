/*
Guia_0102 2c)
Arthur Goncalves de Moraes 816479
*/

#include <stdio.h>
#include <math.h>

int bin2dec(int binario){
    int decimal = 0;
    int potencia = 0;
    while (binario > 0){
        if (binario % 10 == 1){
        decimal = decimal + pow(2,potencia);
        }
        potencia = potencia + 1;
        binario = binario / 10;
    }
    return decimal;
}  

int main (void){
    int binario = 0;
    printf("Insira um numero binario: ");
    scanf("%d", &binario);
    printf("decimal = %d\n", bin2dec(binario));
}