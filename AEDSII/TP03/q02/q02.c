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

typedef struct Lista {
  struct Jogador *inicio;
  struct Jogador *fim;
  int n;
} Lista;

Lista *newLista() {
  Lista *l = (Lista *)malloc(sizeof(Lista));
  l->inicio = NULL;
  l->fim = NULL;
  return l;
}

void inserirInicio(Jogador *c, Lista *l) {
  if (l->inicio == NULL) {
    l->inicio = l->fim = c;
    l->n = l->n + 1;
  } else {
    c->prox = l->inicio;
    l->inicio = c;
    l->n = l->n + 1;
  }
}

void inserir(Jogador *c, Lista *l, int pos) {
  Jogador *j = l->inicio;
  if (l->inicio == NULL) {
    l->inicio = l->fim = c;
    l->n = l->n + 1;
  } else if (pos <= l->n) {
    for (int i = 0; i < pos - 1; i++) {
      j = j->prox;
    }
    Jogador *tmp = j->prox;
    c->prox = tmp;
    j->prox = c;
    l->n = l->n + 1;
  }
}

void inserirFim(Jogador *c, Lista *l) {
  if (l->inicio == NULL) {
    l->inicio = l->fim = c;
    l->n = l->n + 1;
  } else {
    l->fim->prox = c;
    l->fim = c;
    l->n = l->n + 1;
  }
}

Jogador *removerInicio(Lista *l) {
  Jogador *remov = NULL;
  if (l->inicio != NULL) {
    if (l->inicio != l->fim) {
      remov = l->inicio;
      l->inicio = l->inicio->prox;
      l->n = l->n - 1;
    } else {
      remov = l->inicio;
      l->inicio = l->fim = NULL;
      l->n = l->n - 1;
    }
  }
  return remov;
}

Jogador *removerFim(Lista *l) {
  Jogador *remov = NULL;
  Jogador *i = NULL;
  if (l->inicio != NULL) {
    if (l->inicio != l->fim) {
      for (i = l->inicio; i->prox->prox != NULL; i = i->prox)
        ;
      remov = i->prox;
      l->fim = i;
      i->prox = NULL;
      l->n = l->n - 1;
    } else {
      remov = l->fim;
      l->inicio = l->fim = NULL;
      l->n = l->n - 1;
    }
  }
  return remov;
}

Jogador *remover(Lista *l, int num) {
  Jogador *remov = NULL;
  Jogador *i = NULL;
  int j = 0;
  if (l->inicio != NULL && num <= l->n) {
    if (l->inicio != l->fim) {
      for (i = l->inicio, j = 0; j < num-1; i = i->prox, j++);
      remov = i->prox;
      i->prox = i->prox->prox;
      l->n = l->n - 1;
    } else {
      remov = l->fim;
      l->inicio = l->fim = NULL;
      l->n = l->n - 1;
    }
  }
  return remov;
}

int main(void) {
  int id = 0;
  int lastId = -1;
  int i = 0;
  Lista *l = newLista();
  int quant = 0;
  int k = 0;

  while (id != lastId) {
    lastId = id;
    scanf("%d", &id);
    if (id != lastId) {
      // printf("%d\n", id);
      Jogador *jogador = newJogador(id);
      ler(jogador);
      inserirFim(jogador, l);
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
      if (strcmp("II", action) == 0) {
        scanf("%d", &id);
        Jogador *j = newJogador(id);
        ler(j);
        inserirInicio(j, l);
      } else if (strcmp("I*", action) == 0) {
        scanf("%d", &pos);
        scanf("%d", &id);
        Jogador *j = newJogador(id);
        ler(j);
        inserir(j, l, pos);
      } else if (strcmp("IF", action) == 0) {
        scanf("%d", &id);
        Jogador *j = newJogador(id);
        ler(j);
        inserirFim(j, l);
      } else if (strcmp("RI", action) == 0) {
        printf("(R) %s\n", removerInicio(l)->nome);
      } else if (strcmp("RF", action) == 0) {
        printf("(R) %s\n", removerFim(l)->nome);
      }else if (strcmp("R*", action) == 0) {
        scanf("%d", &pos);
        printf("(R) %s\n", remover(l, pos)->nome);
      }
    }
  }

  for (Jogador *i = l->inicio; i != NULL; i = i->prox) {
    imprimir(i, k);
    k++;
  }
}
