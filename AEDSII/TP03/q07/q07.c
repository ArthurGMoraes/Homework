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
  struct Jogador *prox;
} Jogador;

Jogador *newJogador(int ids) {
  Jogador *c = (Jogador *)malloc(sizeof(Jogador));
  c->id = ids;
  c->prox = NULL;
  return c;
}

void ler(Jogador *c) {
  FILE *arq = fopen("/tmp/players.csv", "r");
  char *str = malloc(120);
  int j = 0;
  char *output;

  for (int i = 0; i < c->id + 1; i++) {
    fgets(str, 120, arq);
  }

  fgets(str, 120,
        arq); // leitura da entrada substituindo o scanf para leitura de espacos
  if ((strlen(str) > 0) &&
      (str[strlen(str) - 1] == '\n')) { // formatacao da entrada
    str[strlen(str) - 1] = '\0';
  }

  char *info = strtok(str, ",");
  char *teste = malloc(40);

  while (j < 8) {
    // printf("%s\n", info);
    if (info == NULL || info == "") {
      info = "nao informado";
    }
    // printf("%s\n", info);

    if (j == 1) {
      c->nome = info;
    } else if (j == 2) {
      c->altura = (int)strtol(info, &output, 10);
    } else if (j == 3) {
      c->peso = (int)strtol(info, &output, 10);
    } else if (j == 4) {
      c->universidade = info;
    } else if (j == 5) {
      c->anoNascimento = (int)strtol(info, &output, 10);
    } else if (j == 6) {
      c->cidadeNascimento = info;
    } else if (j == 7) {
      c->estadoNascimento = info;
    }

    info = strtok(NULL, ",");
    j++;
  }

  fclose(arq);
}

void imprimir(Jogador *c, int i) {
  printf("[%d] ## %s ## %d ## %d ## %d ## %s ## %s ## %s ##\n", i, c->nome,
         c->altura, c->peso, c->anoNascimento, c->universidade,
         c->cidadeNascimento, c->estadoNascimento);
}

typedef struct Fila {
  struct Jogador *inicio;
  int n;
} Fila;

Fila *l;

Fila *newFila() {
  l = (Fila *)malloc(sizeof(Fila));
  l->inicio = NULL;
  return l;
}



void printMedia(){
    double media = 0;
    if (l->n > 0){
        //printf("entrou\n");
        for(Jogador* i = l-> inicio; i != NULL; i = i->prox){
            //printf("%d\n", l[i]->altura);
            media = media + i->altura;
        } 
        media = media/l->n; 
        if ((media - (int) media) >= 0.5){
            media = (double)((int) media + 1);
        }   
    }
    printf("%d\n", (int)media);
}

Jogador *removerInicio() {
  Jogador *remov = NULL;
  if (l->inicio != NULL) {
    remov = l->inicio;
    l->inicio = l->inicio->prox;
    l->n--;
  }
  return remov;
}


void inserirFim(Jogador *c) {
  Jogador* i;
  if (l->inicio == NULL) {
    l->inicio = c;
    l->n = l->n + 1;
  } else {
    for (i = l->inicio; i->prox != NULL; i = i->prox);
    i->prox = c;
    l->n = l->n + 1;
    if(l->n > 5){
        removerInicio();
    }
    
  }
  printMedia();
}



int main(void) {
  int id = 0;
  int lastId = -1;
  int i = 0;
  newFila();
  int quant = 0;
  int k = 0;

  while (id != lastId) {
    lastId = id;
    scanf("%d", &id);
    if (id != lastId) {
      // printf("%d\n", id);
      Jogador *jogador = newJogador(id);
      ler(jogador);
      inserirFim(jogador);
    }
  }
  char teste[10];
  scanf("%s", teste);
  for (int j = 0; j < 1; j++) {
    scanf("%d", &quant);
    char action[10];
    int pos = 0;
    for (i = 0; i < quant; i++) {
      scanf("%s", action);
      //printf("%s\n", action);
        if (strcmp("I", action) == 0) {
        scanf("%d", &id);
        Jogador *j = newJogador(id);
        ler(j);
        inserirFim(j);
      } else if (strcmp("R", action) == 0) {
        printf("(R) %s\n", removerInicio()->nome);
      } 
    }
  }

  for (Jogador *i = l->inicio; i != NULL; i = i->prox) {
    imprimir(i, k);
    k++;
  }
}
