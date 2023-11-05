#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Jogador lista[2000];

typedef struct Jogador {
    char id[100];
    char nome[100];
    char peso[100];
    char altura[100];
    char universidade[100];
    char anoNascimento[100];
    char cidadeNascimento[100];
    char estadoNascimento[100];
} Jogador;

int n = 0;

Jogador clone(Jogador *jogador) {
    Jogador novo;
    strcpy(novo.id, jogador->id);
    strcpy(novo.nome, jogador->nome);
    strcpy(novo.altura, jogador->altura);
    strcpy(novo.peso, jogador->peso);
    strcpy(novo.anoNascimento, jogador->anoNascimento);
    strcpy(novo.cidadeNascimento, jogador->cidadeNascimento);
    strcpy(novo.estadoNascimento, jogador->estadoNascimento);
    strcpy(novo.universidade, jogador->universidade);
    return novo;
}

void imprimir(Jogador *jogador, int pos) {
    printf("[%d] ## %s ## %s ## %s ## %s ## %s ## %s ## %s ##\n", pos, jogador->nome, jogador->altura, jogador->peso, jogador->anoNascimento, jogador->universidade, jogador->cidadeNascimento, jogador->estadoNascimento);
}

void ler(Jogador *jogador, char linha[1000]) {
    int pos[7];
    int virgulas = 0;
    for (int i = 0; i < strlen(linha); i++) {
        if (linha[i] == ',') {
            pos[virgulas] = i;
            virgulas++;
        }
    }

    int cont = 0;
    char id[100];
    char nome[100];
    char peso[100];
    char altura[100];
    char universidade[100];
    char anoNascimento[100];
    char cidadeNascimento[100];
    char estadoNascimento[100];

    if (pos[0] - 0 != 0) {
        for (int i = 0; i < pos[0]; i++) {
            id[cont++] = linha[i];
        }
        id[cont] = '\0';
        strcpy(jogador->id, id);
    } else {
        strcpy(jogador->id, "nao informado");
    }
    cont = 0;

    if (pos[1] - (pos[0]) != 1) {
        for (int j = pos[0] + 1; j < pos[1]; j++) {
            nome[cont++] = linha[j];
        }
        nome[cont] = '\0';
        strcpy(jogador->nome, nome);
    } else {
        strcpy(jogador->nome, "nao informado");
    }
    cont = 0;

    if (pos[2] - (pos[1]) != 1) {
        for (int k = pos[1] + 1; k < pos[2]; k++) {
            altura[cont++] = linha[k];
        }
        altura[cont] = '\0';
        strcpy(jogador->altura, altura);
    } else {
        strcpy(jogador->altura, "nao informado");
    }
    cont = 0;

    if (pos[3] - (pos[2]) != 1) {
        for (int l = pos[2] + 1; l < pos[3]; l++) {
            peso[cont++] = linha[l];
        }
        peso[cont] = '\0';
        strcpy(jogador->peso, peso);
    } else {
        strcpy(jogador->peso, "nao informado");
    }
    cont = 0;

    if (pos[4] - (pos[3]) != 1) {
        for (int m = pos[3] + 1; m < pos[4]; m++) {
            universidade[cont++] = linha[m];
        }
        universidade[cont] = '\0';
        strcpy(jogador->universidade, universidade);
    } else {
        strcpy(jogador->universidade, "nao informado");
    }
    cont = 0;

    if (pos[5] - (pos[4]) != 1) {
        for (int n = pos[4] + 1; n < pos[5]; n++) {
            anoNascimento[cont++] = linha[n];
        }
        anoNascimento[cont] = '\0';
        strcpy(jogador->anoNascimento, anoNascimento);
    } else {
        strcpy(jogador->anoNascimento, "nao informado");
    }
    cont = 0;

    if (pos[6] - (pos[5]) != 1) {
        for (int o = pos[5] + 1; o < pos[6]; o++) {
            cidadeNascimento[cont++] = linha[o];
        }
        cidadeNascimento[cont] = '\0';
        strcpy(jogador->cidadeNascimento, cidadeNascimento);
    } else {
        strcpy(jogador->cidadeNascimento, "nao informado");
    }
    cont = 0;

    if ((strlen(linha) - 1) - (pos[6]) != 1) {
        for (int p = pos[6] + 1; p < strlen(linha) - 1; p++) {
            estadoNascimento[cont++] = linha[p];
        }
        estadoNascimento[cont] = '\0';
        strcpy(jogador->estadoNascimento, estadoNascimento);
    } else {
        strcpy(jogador->estadoNascimento, "nao informado");
    }
    cont = 0;
}

void inserirInicio( Jogador x) {
    for (int i = n; i > 0; i--) {
        lista[i] = lista[i - 1];
    }
    lista[0] = x;
    n++;
}

void inserir(Jogador x, int pos) {
    for (int i = n; i > pos; i--) {
        lista[i] = lista[i - 1];
    }
    lista[pos] = x;
    n++;
}

void inserirFim(Jogador x) {
    lista[n] = x;
    n++;
}

void removerInicio() {
    Jogador *temp = lista[0];
    for (int i = 0; i < n - 1; i++) {
        lista[i] = lista[i + 1];
    }
    n--;
    printf("(R) %s\n", temp -> nome);
}

void remover(int pos) {
    Jogador temp = lista[pos];
    for (int i = pos; i < n - 1; i++) {
        lista[i] = lista[i + 1];
    }
    n--;
    printf("(R) %s\n", temp.nome);
}

void removerFim() {
    Jogador temp = lista[--n];
    printf("(R) %s\n", temp.nome);
}

void imprimeArray() {
    for (int i = 0; i < n; i++) {
        imprimir(lista[i], i);
    }
}



int main() {
    char entrada[1000];
    FILE *arq = fopen("players.csv", "r");
    Jogador jogador[3922];

    fgets(entrada, sizeof(entrada), arq); // Pula a primeira linha do arquivo
    int cont = 0;
    while (fgets(entrada, 1000, arq)) {
        ler(lista[cont], entrada);
        cont++;
    }

    
    scanf("%[^\n]", entrada);
    cont = 0;
    while (strcmp(entrada, "FIM") != 0) {
        int id = atoi(entrada);
        inserirFim(jogador[id]);
        cont++;
        scanf("%s", entrada);
    }

    int registros;
    scanf("%d", &registros);
    for (int i = 0; i < registros; i++) 
    {
        char entrada[10];
        scanf("%s", entrada);
        if (strcmp(entrada, "II") == 0) 
        {
            int id;
            scanf("%d", &id);
            inserirInicio(lista[id]);
        } 
        else if (strcmp(entrada, "IF") == 0) 
        {
            int id;
            scanf("%d", &id);
            inserirFim(lista[id]);
        } 
        else if (strcmp(entrada, "I*") == 0) 
        {
            int id;
            int pos;
            scanf("%d %d", &id, &pos);
            inserir(lista[id], pos);
    
        } 
        else if (strcmp(entrada, "RI") == 0) 
        {
            removerInicio();
        } 
        else if (strcmp(entrada, "RF") == 0) 
        {
            removerFim();
        } 
        else if (strcmp(entrada, "R*") == 0) 
        {
            int pos;
            scanf("%d", &pos);
            remover(pos);
        }
    }

    imprimeArray();
    fclose(arq);
    return 0;
}