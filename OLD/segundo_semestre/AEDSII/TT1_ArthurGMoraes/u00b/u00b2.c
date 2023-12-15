/*
  Arthur Goncalves de Moraes
  Ex 00b 2
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool existe (int*array, int busca, int tamanho, int inicio){
    bool result = false;
    while(inicio < tamanho){
        if(array[inicio]==busca){
            inicio = tamanho;
            result = true;
        } else  if(busca<array[inicio]){
            inicio--;
        } else if(busca>array[inicio]){
           inicio++;
        }
    }
    return result;
}

int main(void)
{
    int tamanho = 10;
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int busca = 0;
    printf("Qual numero sera procurado? ");
    scanf("%d", &busca);
    printf("%d\n",existe(array , busca, tamanho, tamanho/2)); // 1 = true | 0 = false
}