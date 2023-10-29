#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int id;
    char *nome;
    int altura;
    int peso;
    char *universidade;
    int anoNascimento;
    char *cidadeNascimento;
    char *estadoNascimento;
    struct Jogador* prox;
} Jogador;


Jogador* newJogador(int ids){
    Jogador *c = (Jogador*) malloc(sizeof(Jogador));
    c -> id = ids;
    c -> prox = NULL;
    return c;
}

typedef struct Lista{
    struct Jogador* inicio;
    struct Jogador* fim;
} Lista;

Lista* newLista(){
    Lista *c = (Lista*) malloc(sizeof(Lista));
    c -> inicio = NULL;
    return c;
}

void ler(Jogador *c){
    FILE *arq = fopen("players.csv", "r");
    char *str = malloc(120);
    int j = 0;
    char *output;
    
    for(int i = 0; i < c -> id + 1; i++){
        fgets(str, 120, arq);  
    }
    
    fgets(str, 120, arq);                // leitura da entrada substituindo o scanf para leitura de espacos
    if ((strlen(str) > 0) && (str[strlen (str) - 1] == '\n')){     // formatacao da entrada
        str[strlen (str) - 1] = '\0';
    }

     char *info = strtok(str, ",");
     char *teste = malloc(40);
   
    while (j < 8)
    {
        printf("%s\n", info);
        if (info == NULL || info == ""){
            info = "nao informado";
        }
        printf("%s\n", info);

        if(j == 1){
            c -> nome = info;
        } else if(j == 2){
            c -> altura = (int)strtol(info, &output, 10);
        } else if(j == 3){
            c -> peso = (int)strtol(info, &output, 10);
        } else if(j == 4){
            c -> universidade = info;
        } else if(j == 5){
            c -> anoNascimento = (int)strtol(info, &output, 10);
        } else if(j == 6){
            c -> cidadeNascimento = info;
        } else if(j == 7){
            c -> estadoNascimento = info;
        }

    
        info = strtok(NULL, ",");
        j++;
    }
               
    //printf("%s", str);



    fclose(arq);
}

void imprimir(Jogador *c){
    printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n", c -> id, c -> nome, c -> altura, c -> peso, c -> anoNascimento, c -> universidade, c -> cidadeNascimento, c -> estadoNascimento);
}



int main (void){
    int id = 0;
    int lastId = -1;
    int i = 0;

   while (id != lastId){
        lastId = id;
        scanf("%d", &id);
        if (id != lastId){
            //printf("%d\n", id);
            Jogador *jogador = newJogador(id);
            ler(jogador);
            imprimir(jogador);
        }
    }
}
