#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador
{
    int id;
    char *nome;
    int altura;
    int peso;
    char *universidade;
    int anoNascimento;
    char *cidadeNascimento;
    char *estadoNascimento;
    struct Jogador *prox;
    struct Jogador *ant;
} Jogador;

Jogador *newJogador(int ids)
{
    Jogador *c = (Jogador *)malloc(sizeof(Jogador));
    c->id = ids;
    c->prox = NULL;
    return c;
}

void ler(Jogador *c)
{
    FILE *arq = fopen("/tmp/players.csv", "r");
    char *str = malloc(120);
    int j = 0;
    char *output;

    for (int i = 0; i < c->id + 1; i++)
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
    char *teste = malloc(40);

    while (j < 8)
    {
        //printf("%s\n", info);
        if (info == NULL || info == "")
        {
            info = "nao informado";
        }
        // printf("%s\n", info);

        if (j == 1)
        {
            c->nome = info;
        }
        else if (j == 2)
        {
            c->altura = (int)strtol(info, &output, 10);
        }
        else if (j == 3)
        {
            c->peso = (int)strtol(info, &output, 10);
        }
        else if (j == 4)
        {
            if((int)strtol(info, &output, 10) > 1850 && (int)strtol(info, &output, 10) < 2020 ){
                c->anoNascimento = (int)strtol(info, &output, 10);
                c->universidade = "nao informado";
                j++;
            } else {
                c->universidade = info;
            }
        }
        else if (j == 5)
        {
            c->anoNascimento = (int)strtol(info, &output, 10);
        }
        else if (j == 6)
        {
            c->cidadeNascimento = info;
        }
        else if (j == 7)
        {
            c->estadoNascimento = info;
        }

        info = strtok(NULL, ",");
        j++;
    }

    fclose(arq);
}

void imprimir(Jogador *c)
{
    printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n", c->id, c->nome,
           c->altura, c->peso, c->anoNascimento, c->universidade,
           c->cidadeNascimento, c->estadoNascimento);
}

typedef struct Lista
{
    struct Jogador *inicio;
    struct Jogador *fim;
    int n;
} Fila;

Fila *l;

Fila *newFila()
{
    l = (Fila *)malloc(sizeof(Fila));
    l->inicio = NULL;
    return l;
}

void inserirFim(Jogador *c)
{
    Jogador *i;
    if (l->inicio == NULL)
    {
        l->inicio = c;
        l-> fim = c;
        c->ant = NULL;
        c->prox = NULL;
        l->n = l->n + 1;
    }
    else
    {
        l->fim->prox = c;
        c->ant = l->fim;
        l->fim = c;
        c->prox = NULL;
    }
}




int comparar(Jogador* a, Jogador* b){
    int result = strcmp(a->estadoNascimento, b->estadoNascimento );
    if (result == 0){
        result = strcmp(a->nome, b->nome );
    }
    return result;
}

Jogador* partition(Jogador* left, Jogador* right){
    Jogador* pivot = right;
    Jogador* i = left->ant;
    for(Jogador* ptr=left; ptr!=right; ptr=ptr->prox){
        if(comparar(ptr,pivot) < 0){
            i = (i==NULL?left:i->prox);
            int tmpId = i->id;
            char *tmpNome = i->nome;
            int tmpAltura = i->altura;
            int tmpPeso = i->peso;
            char *tmpUniversidade = i->universidade;
            int tmpAnoNascimento = i->anoNascimento;
            char *tmpCidadeNascimento = i->cidadeNascimento;
            char *tmpEstadoNascimento = i->estadoNascimento;
            i->id = ptr->id;
            i->nome = ptr->nome;
            i->altura = ptr->altura;
            i->peso = ptr->peso;
            i->universidade = ptr->universidade;
            i->anoNascimento = ptr->anoNascimento;
            i->cidadeNascimento = ptr->cidadeNascimento;
            i->estadoNascimento = ptr->estadoNascimento;
            ptr->id = tmpId;
            ptr->nome = tmpNome;
            ptr->altura = tmpAltura;
            ptr->peso = tmpPeso;
            ptr->universidade = tmpUniversidade;
            ptr->anoNascimento = tmpAnoNascimento;
            ptr->cidadeNascimento = tmpCidadeNascimento;
            ptr->estadoNascimento = tmpEstadoNascimento;
        }
    }
    i = (i==NULL?left:i->prox);
    int tempId = i->id;
    char *tempNome = i->nome;
    int tempAltura = i->altura;
    int tempPeso = i->peso;
    char *tempUniversidade = i->universidade;
    int tempAnoNascimento = i->anoNascimento;
    char *tempCidadeNascimento = i->cidadeNascimento;
    char *tempEstadoNascimento = i->estadoNascimento;
    i->id = pivot->id;
    i->nome = pivot->nome;
    i->altura = pivot->altura;
    i->peso = pivot->peso;
    i->universidade = pivot->universidade;
    i->anoNascimento = pivot->anoNascimento;
    i->cidadeNascimento = pivot->cidadeNascimento;
    i->estadoNascimento = pivot->estadoNascimento;
    pivot->id = tempId;
    pivot->nome = tempNome;
    pivot->altura = tempAltura;
    pivot->peso = tempPeso;
    pivot->universidade = tempUniversidade;
    pivot->anoNascimento = tempAnoNascimento;
    pivot->cidadeNascimento = tempCidadeNascimento;
    pivot->estadoNascimento = tempEstadoNascimento;
    return i;
}

void quicksort(Jogador* left, Jogador* right){
    if(right!=NULL && left!=right && left!=right->prox){
        Jogador* p = partition(left,right);
        quicksort(left,p->ant);
        quicksort(p->prox,right);
    }
}

void sort(){
    quicksort(l->inicio, l->fim);
}



int main(void)
{
    int id = 0;
    int lastId = -1;
    int i = 0;
    newFila();
    int quant = 0;
    int k = 0;

    while (id != lastId)
    {
        lastId = id;
        scanf("%d", &id);
        if (id != lastId)
        {
            // printf("%d\n", id);
            Jogador *jogador = newJogador(id);
            ler(jogador);
            inserirFim(jogador);
        }
    }

    sort();

    for (Jogador *i = l->inicio; i != NULL; i = i->prox)
    {
        imprimir(i);
    }
}
