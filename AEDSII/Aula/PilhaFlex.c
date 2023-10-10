#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *prox;
    int valor;
}Celula;

typedef struct{
    Celula * topo;
}Pilha;

Celula* criarCelula(){
    Celula *celula = (Celula*) malloc(sizeof(Celula));
    celula -> prox = NULL;
    celula -> valor = 0;
    return celula;
}

Pilha* criarPilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p -> topo = criarCelula();
    return p;
}

Celula* inserirValor(int num, Pilha * p){
    Celula *c = criarCelula(); 
    c -> prox = p -> topo -> prox;
    p -> topo -> prox = c;
    c -> valor = num;
    return c;
} 

void imprimir (Pilha * p){
    for (Celula* i = p -> topo -> prox; i != NULL; i = i -> prox){
        printf("%d\n", i -> valor);
    }
}

int remover(Pilha * p){
    Celula *temp = p -> topo -> prox;
    if (temp == NULL){
        printf("ERRO\n");
        exit(-1);
    }
    printf("teste\n");
    p -> topo -> prox = temp -> prox;
    temp -> prox = NULL;
    int elemento = temp -> valor;
    free(temp);
    return elemento;

}


int main(void){
    Pilha *p = criarPilha();
    inserirValor(5, p);
    inserirValor(6, p);
    inserirValor(7, p);
    imprimir(p);
    //printf("teste\n");
    printf("remover = %d\n", remover(p));
    imprimir(p);

}