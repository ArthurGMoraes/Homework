#include <stdio.h>

void ordenar(int array[], int tamanho){
    int mov = 0;
    int tmp = 0;

    for (int i = 0; i < tamanho-1; i++){
        if(array[i+1] < array[i]){
            //printf("if1\n");
            for (int j = i+1; j > 0; j--){
                if (array[j] < array[j-1]){
                    //printf("if2\n");
                    tmp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = tmp;
                    mov++;
                }
            }
        }
    }

    printf("%d\n", mov);
}

int main (void){
    int quantidade = 0;
    int tamanho = 0;
    scanf("%d", &quantidade);
    for (int i = 0; i < quantidade; i++){
        scanf("%d", &tamanho);
        int array[tamanho];
        for (int j = 0; j < tamanho; j++){
            scanf("%d", &array[j]);
        }
        ordenar(array,tamanho);
    }
}