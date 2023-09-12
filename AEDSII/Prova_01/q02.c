// Arthur Goncalves de Moraes

#include <stdio.h>

int arredondar(double valor, double corte){
    int resposta = 0;

    if((valor - (int) valor) > corte){
        resposta = (int) valor + 1;
    } else {
        resposta = (int) valor;
    }
    
    return resposta;
}

int main(void){
    double valor = 0.0;
    double corte = 0.0;

    while (scanf("%lf", &valor) != EOF){
        scanf("%lf", &corte);
        printf("%d\n", arredondar(valor, corte));
    }
}