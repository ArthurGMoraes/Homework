#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* combinar(char *text1, char *text2){
    int tam1 = strlen(text1);
    int tam2 = strlen(text2);
    char* resp= malloc (200);
    int j = 0;

    if (tam1>=tam2){
        for(int i = 0; i <= tam1+tam2+1; i++, j++){
            if(j<tam1){
                resp[i] = text1[j];
            }
            
            if(j < tam2){
                resp[i+1] = text2[j];
                i = i + 1;
            }
        }
    } else if(tam1<tam2){
        for(int i = 0; i < tam2+tam1; i++, j++){
            if(j < tam1){
                resp[i] = text1[j];     
                i = i + 1;   
            }
            if(j<=tam2){
                resp[i] = text2[j];
            }
        }
    }
    return resp;
    free(resp);
}

int main(void){
    //char linha[200];
    char text1[100];
    char text2[100];
    //scanf("%[^\n]", linha);
    //printf("%s", linha);

    while (scanf(" %s %s", text1, text2) != EOF){
        printf("%s\n", combinar(text1, text2));
    }

}