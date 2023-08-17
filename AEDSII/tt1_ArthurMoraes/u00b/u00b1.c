/*
  Arthur Goncalves de Moraes
  Ex 00b 1
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool existe (int*array, int busca, int tamanho){
    int i = 0;
    bool result = false;
    for(i = 0; i < tamanho; i++){
        if(array[i]==busca){
            i = tamanho;
            result = true;
        }
    }
    return result;
}

int main(void)
{
    int tamanho = 0;
    int array[tamanho];
    int i = 0;
    int busca = 0;
    printf("\nQual o tamanho do array? ");
    scanf("%d", &tamanho);
    printf("Digite os numeros do array:\n");
    for(i = 0; i < tamanho; i++){
        scanf("%d", &array[i]);
    }
    printf("Qual numero sera procurado? ");
    scanf("%d", &busca);
    printf("%d\n",existe(array , busca, tamanho)); // 1 = true | 0 = false
}