#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compNome(int id1, int id2){
    //printf("comp");
    char *nome1 = malloc (120);
    char *nome2 = malloc (120);
    FILE *arq1;
    FILE *arq2;

    arq1 = fopen("/tmp/players.csv", "r");
    for (int i = 0; i < id1 + 2; i++){
        fgets(nome1, 120, arq1);
    }
    fclose(arq1);
    if ((strlen(nome1) > 0) && (nome1[strlen (nome1) - 1] == '\n')){
        nome1[strlen (nome1) - 1] = '\0';
    }

    arq2 = fopen("/tmp/players.csv", "r");
    for (int i = 0; i < id2 + 2; i++){
        fgets(nome2, 120, arq2);
    }
    fclose(arq2);
    if ((strlen(nome2) > 0) && (nome2[strlen (nome2) - 1] == '\n')){
        nome2[strlen (nome2) - 1] = '\0';
    }

    //printf("%s\n", nome1);
    //printf("%s\n", nome2);
    
    int j = 0;
    char *info1 = strtok(nome1, ",");
    char *teste1 = malloc(40);
    char *teste2 = malloc(40);
    int result = -1;

    while (j < 2)
        {
            if(j == 1){
                teste1 = info1;
            }
            info1 = strtok(NULL, ",");
            j++;
        }
        j = 0;

        char *info2 = strtok(nome2, ",");
        while (j < 2)
        {
            if(j == 1){
                teste2 = info2;
            }
            info2 = strtok(NULL, ",");
            j++;
        }

        if(strcmp(teste1, teste2) > 0){
            result = 1;
        } else if (strcmp(teste1, teste2) == 0){
            result = 0;
        }

        //printf("%s %s\n", teste1, teste2);
    return result;
}

int compNome2(int id1, char* nome){
    //printf("comp");
    char *nome1 = malloc (120);
    FILE *arq1;
    

    arq1 = fopen("/tmp/players.csv", "r");
    for (int i = 0; i < id1 + 2; i++){
        fgets(nome1, 120, arq1);
    }
    //printf("leu");
    fclose(arq1);
    if ((strlen(nome1) > 0) && (nome1[strlen (nome1) - 1] == '\n')){
        nome1[strlen (nome1) - 1] = '\0';
    }

    //printf("leu2");

    
    int j = 0;
    char *info1 = strtok(nome1, ",");
    char *teste1 = malloc(40);
    int result = -1;

    while (j < 2)
        {
            if(j == 1){
                teste1 = info1;
            }
            info1 = strtok(NULL, ",");
            j++;
        }
        j = 0;


        if(strcmp(teste1, nome) > 0){
            result = 1;
        } else if (strcmp(teste1, nome) == 0){
            result = 0;
        }

        //printf("%s %s\n", teste1, nome);
        free(nome1);
    return result;
}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void ordenar(int *array, int n){
    for (int i = 0; i < (n - 1); i++) {
      int menor = i;
      for (int j = (i + 1); j < n; j++){
         if (compNome(array[menor], array[j]) > 0){
            menor = j;
         }
      }
      swap(&array[menor], &array[i]);
   }
}

int pesquisar(int *id, char *nome, int inicio, int fim){
    //printf("pesq");
    int i = (inicio + fim) / 2;

    if (inicio > fim) {  // Ponto de parada
        //printf("n achou");
        return -1;
    }

    if (compNome2(id[i],nome) == 0) {  // Item encontrado 
        //printf("achou");
        return 1;
    }

    if (compNome2(id[i], nome) < 0) {  // Item está à direita 
        //printf("maior");
        return pesquisar(id, nome, i+1 , fim );
    
    } else {  //Item está à esquerda 
        //printf("menor");
        return pesquisar(id, nome, inicio, i-1);
    }
}


int main (void){
    int ids[80];
    char nome[40];
    char lixo[10];
    char *resp = malloc(10);
    int id = 0;
    int lastId = -1;
    int i = 0;
    int j = 0;

   while (id != lastId){
        lastId = id;
        scanf("%d", &id);
        if (id != lastId){
            ids[i] = id;
            i++;
        }
    }

   ordenar(ids, i);

   /*for(j = 0; j < i; j++){
    printf("%d", ids[j]);
   }*/

    //printf("teste1");
    fgets(lixo, 10, stdin);
    //printf("%s", lixo);

    do{
        //printf("teste2");
        fgets(nome, 40, stdin);
        if ((strlen(nome) > 0) && (nome[strlen (nome) - 1] == '\n')){       // formatacao da entrada
            nome[strlen (nome) - 1] = '\0';
        }
        
               
        if(strcmp(nome, "FIM\0")!=0){
            
            //printf("%s", nome);
            
            resp = (pesquisar(ids, nome, 0, i-1) > 0) ? "SIM\n" : "NAO\n";
            printf("%s", resp);
        }
    } while (strcmp(nome, "FIM\0")!=0); 
}