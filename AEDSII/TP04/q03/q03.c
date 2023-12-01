#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define bool   short
#define true   1
#define false  0

int comp = 0;

typedef struct No {
    char* nome;
    int nivel;
	struct No *esq, *dir;
} No;

No* newNo(char* elemento) {
   No* new = (No*) malloc(sizeof(No));
   new->nome = elemento;
   new->esq = NULL;
   new->dir = NULL;
   new->nivel = 1;
   return new;
}

int getNivel(No* no) {
	return (no == NULL) ? 0 : no->nivel;
}

 void setNivel(No* no) {
    int resp = 0;
    if(getNivel(no->esq)>=getNivel(no->dir)){
        resp = getNivel(no->esq);
    } else {
        resp = getNivel(no->dir);
    }
	no->nivel = 1 + resp;
}

No* raiz;

void start() {
   raiz = NULL;
}

No* rotacionarDir(No* no) {
	No* noEsq = no->esq;
	No* noEsqDir = noEsq->dir;

	noEsq->dir = no;
	no->esq = noEsqDir;
	setNivel(no); // Atualizar o nivel do no
	setNivel(noEsq); // Atualizar o nivel do noEsq

	return noEsq;
}

No* rotacionarEsq(No* no) {
		No* noDir = no->dir;
		No* noDirEsq = noDir->esq;

		noDir->esq = no;
		no->dir = noDirEsq;

		setNivel(no); // Atualizar o nivel do no
		setNivel(noDir); // Atualizar o nivel do noDir
		return noDir;
	}

No* balancear(No* no) {
		if (no != NULL) {
            comp++;
			int fator = getNivel(no->dir) - getNivel(no->esq);
            int fator2 = fator;
			if (fator2 < 0) {
                fator2 = fator2 *(-1);
            }
            // Se balanceada
            if(fator2 <= 1){
                comp++;
				setNivel(no);
			// Se desbalanceada para a direita
			} else if (fator == 2) {
                comp++;
				int fatorFilhoDir = getNivel(no->dir->dir) - getNivel(no->dir->esq);
				// Se o filho a direita tambem estiver desbalanceado
				if (fatorFilhoDir == -1) {
                    comp++;
					no->dir = rotacionarDir(no->dir);
				}
				no = rotacionarEsq(no);
			// Se desbalanceada para a esquerda
			} else if (fator == -2) {
                comp++;
				int fatorFilhoEsq = getNivel(no->esq->dir) - getNivel(no->esq->esq);
				// Se o filho a esquerda tambem estiver desbalanceado
				if (fatorFilhoEsq == 1) {
                    comp++;
					no->esq = rotacionarEsq(no->esq);
				}
				no = rotacionarDir(no);
			} 
		}
		return no;
	}

No* inserirRec(char* x, No** i) {
    if (*i == NULL) {
        comp++;
        *i = newNo(x);
    } else if (strcmp(x, (*i)->nome) < 0) {   
        comp++; 
        inserirRec(x, &((*i)->esq));
    } else if (strcmp(x, (*i)->nome) > 0) {
        comp++;
        inserirRec(x, &((*i)->dir));
    }
    *i = balancear(*i);
    return *i;
}

void inserir(char* x) {
   raiz = inserirRec(x, &raiz);
}

bool pesquisarRec(char* x, No* i) {
    bool resp;
   
    if (i == NULL) {
        comp++;
        resp = false;
    } else if (strcmp(x, (i)->nome) == 0) { 
        comp++;
        resp = true;
    } else if (strcmp(x, (i)->nome) < 0) {
        comp++;
        printf("esq ");
        resp = pesquisarRec(x, i->esq);
    } else {
        printf("dir ");
        resp = pesquisarRec(x, i->dir);
    }
   return resp;
}

bool pesquisar(char* x) {
   printf("raiz ");
   return pesquisarRec(x, raiz);
}

char* getNome(int x){
    FILE *arq = fopen("/tmp/players.csv", "r");
    char *str = malloc(120);
    int j = 0;
    char *output;

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

    fclose(arq);
    
    return info;
}



int main (void){
    int ins = 0;
    int ant = -1;
    char nome[25];
    clock_t inicio, fim;
    double total;

    inicio = clock();
    while (ant != ins){
        ant = ins;
        scanf("%d", &ins);
        if (ant != ins){
            inserir(getNome(ins));
        }
    }
    getchar();
    getchar();
    getchar();
    getchar(); 
   
    do {
        fgets(nome, 25, stdin);
        nome[strcspn(nome, "\n")] = '\0'; // Remove trailing newline
        if(strcmp(nome, "FIM") != 0){
            printf("%s ", nome );
            printf("%s\n",(pesquisar(nome) > 0)?"SIM":"NAO");
        }  
    } while (strcmp(nome, "FIM") != 0);
    fim = clock();
    FILE* arq = fopen("816479_avl.txt", "w");
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC);    
    fprintf(arq, "816479\t%lf\t%d", total, comp);
    fclose(arq);
    //caminharCentral();
}