#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int n = -1; int k = -1; int cont= 0;
    int c= -1; int s = -1;
    int Ci[500];
    int Si[500];
    

    while(n != 0 && k != 0){
        scanf("%d", &n);
        scanf("%d", &k);
        cont = 0;
        for(int i = 0; i < n; i++){
            
            if(n != 0 && k != 0){
                scanf("%d", &Ci[i]);
                scanf("%d", &Si[i]);
            }
        }
        if (n != 0 && k != 0){
            for(int i = n -1; i > 0; i--){
                if(Si[i] < Si[i-1] && Si[i] < Ci[i-1]){ // deveria verificar todos os Ci ---- mais um for?
                    printf("Nao\n");
                    i = 0;
                    cont++;
                }
            }
            if(cont < 1){
                printf("Sim\n");
            }
        }
    }
}