/*
  Arthur Goncalves de Moraes
  Ex 00b 3
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void maiorMenor (int*array, int tamanho){
    int maior = 0;
    int menor = array[0];
    int i = 0;
    for(i = 0; i < tamanho; i++){
        if(array[i]>= maior){
            maior = array[i];
        }else if(array[i]<= menor){
            menor = array[i];
        }
    }
    printf("menor = %d ; maior = %d", menor, maior);
}

int main(void)
{
    int tamanho = 10;
    int array[10] = {6,2,3,4,5,6,7,8,9,10};
    maiorMenor(array, tamanho);
}