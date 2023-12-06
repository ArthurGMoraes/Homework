#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define bool   short
#define true   1
#define false  0

int comp = 0;

typedef struct Celula{
    char* nome;
    struct Celula* prox;
} Celula;

Celula* newCelula(char* elemento) {
   Celula* new = (Celula*) malloc(sizeof(Celula));
   new->nome = elemento;
   new->prox = NULL;
   return new;
}

Celula* tabelaHash[25];

void iniciar(){
    for (int i = 0; i < 25; i++){
        tabelaHash[i] = NULL;
    }
}

int hash(int altura){
    return(altura%25);
}

void inserirLista(Celula* inicio, char* nome){
    if(inicio->prox == NULL){
        inicio->prox = newCelula(nome);
    } else {
        inserirLista(inicio->prox, nome);
    }
}

void inserir(char* nome, int altura){
    int pos = hash(altura);
    if(tabelaHash[pos] == NULL){
        tabelaHash[pos] = newCelula(nome);
    } else {
        inserirLista(tabelaHash[pos],nome);
    }
}

bool pesquisarLista(Celula* inicio, char* nomeP){
    if(strcmp(inicio->nome, nomeP) == 0){
        return true;
    } else if (inicio->prox != NULL){
        return pesquisarLista(inicio->prox, nomeP);
    } else {
        return false;
    }
}

bool pesquisar(char* nome, int altura){
    int pos = hash(altura);
    if(tabelaHash[pos] == NULL){
        return false;
    } else{
        return pesquisarLista(tabelaHash[pos], nome);
    }
}



char** ler(int x){
    FILE *arq = fopen("/tmp/players.csv", "r");
    char *str = malloc(120);
    int j = 0;
    char *output;
    char** resp = malloc(2 * sizeof(char *));

    for (int i = 0; i < x + 1; i++)
    {
        fgets(str, 120, arq);
    }

    fgets(str, 120,
          arq); // leitura da entrada substituindo o scanf para leitura de espacos
    if ((strlen(str) > 0) &&
        (str[strlen(str) - 1] == '\n'))
    { // formatacao da entrada
        str[strlen(str) - 1] = '\0';
    }


    char *info = strtok(str, ",");
    info = strtok(NULL, ",");
    resp[0] = malloc(strlen(info) + 1); // +1 para o terminador nulo
    strcpy(resp[0], info);
    info = strtok(NULL, ",");
    resp[1] = malloc(strlen(info) + 1); // +1 para o terminador nulo
    strcpy(resp[1], info);

    fclose(arq);
    
    return resp;
}

int getAltura(char* nome){
    FILE *arq = fopen("/tmp/players.csv", "r");
    char *str = malloc(120);
    int j = 0;
    char *output;
    char *info = "";

    while(strcmp(info,nome)!=0 && j < 3921)
    {
        fgets(str, 120,arq); // leitura da entrada substituindo o scanf para leitura de espacos
        if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n'))
        { // formatacao da entrada
        str[strlen(str) - 1] = '\0';
        }
        info = strtok(str, ",");
        info = strtok(NULL, ",");
        j++;
    }
    if(j >= 3921){
        return 1;
    }
    fclose(arq);
    info = strtok(NULL, ",");
    //printf("%d", atoi(info));
    return atoi(info);
}

int main (void){
    int ins = 0;
    int ant = -1;
    char nome[25];
    char nome2[25];
    clock_t inicio, fim;
    double total;

    iniciar();

    //inicio = clock();
    while (ant != ins){
        ant = ins;
        scanf("%d", &ins);
        if (ant != ins){
            inserir(ler(ins)[0], atoi(ler(ins)[1]));
        }
    }

    fgets(nome, 25, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove trailing newline
    strcpy(nome, " ");

    while (strcmp(nome, "FIM") != 0) {
        fgets(nome, 25, stdin);
            nome[strcspn(nome, "\n")] = '\0'; // Remove trailing newline
            if(strcmp(nome, "FIM") != 0){
                printf("%s ", nome );
                printf("%s\n",(pesquisar(nome, getAltura(nome)) > 0)?"SIM":"NAO");
            }
    } 


    //fim = clock();
    //FILE* arq = fopen("816479_hashIndireta.txt", "w");
    //total = ((fim - inicio) / (double)CLOCKS_PER_SEC);    
    //fprintf(arq, "816479\t%lf\t%d", total, comp);
    //fclose(arq);
    //caminharCentral();
}