#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compNome(int id1, int id2)
{
    // printf("comp");
    char *nome1 = malloc(120);
    char *nome2 = malloc(120);
    FILE *arq1;
    FILE *arq2;

    arq1 = fopen("/tmp/players.csv", "r");
    for (int i = 0; i < id1 + 2; i++)
    {
        fgets(nome1, 120, arq1);
    }
    fclose(arq1);
    if ((strlen(nome1) > 0) && (nome1[strlen(nome1) - 1] == '\n'))
    {
        nome1[strlen(nome1) - 1] = '\0';
    }

    arq2 = fopen("/tmp/players.csv", "r");
    for (int i = 0; i < id2 + 2; i++)
    {
        fgets(nome2, 120, arq2);
    }
    fclose(arq2);
    if ((strlen(nome2) > 0) && (nome2[strlen(nome2) - 1] == '\n'))
    {
        nome2[strlen(nome2) - 1] = '\0';
    }

    // printf("%s\n", nome1);
    // printf("%s\n", nome2);

    int j = 0;
    char *info1 = strtok(nome1, ",");
    
    char *teste1 = malloc(40);
    char *teste2 = malloc(40);
    int result = -1;

    while (j < 2)
    {
        if (j == 1)
        {
            teste1 = info1;
        }
        info1 = strtok(NULL, ",");
        j++;
    }
    j = 0;

    

    char *info2 = strtok(nome2, ",");
    while (j < 2)
    {
        if (j == 1)
        {
            teste2 = info2;
        }
        info2 = strtok(NULL, ",");
        j++;
    }
    

    if (strcmp(teste1, teste2) > 0)
    {
        result = 1;
    }
    else if (strcmp(teste1, teste2) == 0)
    {
        result = 0;
    }
    

    // printf("%s %s\n", teste1, teste2);
    return result;
} 

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void ordenar(int *array, int n, int i)
{
    if (i < (n - 1))
    {
        int menor = i;
        for (int j = (i + 1); j < n; j++)
        {
            if (compNome(array[menor], array[j]) > 0)
            {
                menor = j;
            }
        }
        swap(&array[menor], &array[i]);
        i++;
        ordenar(array, n, i);
    }
    
}

void imprimir(int *ids, int k)
{
    char *str = malloc(120);
    for (int i = 0; i < k; i++)
    {
        
        char *output;
        int j = 0;
        FILE *arq = fopen("/tmp/players.csv", "r");
        for (int n = 0; n < ids[i] + 1; n++)
        {
            fgets(str, 120, arq);
        }

        fgets(str, 120, arq); // leitura da entrada substituindo o scanf para leitura de espacos
        if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n'))
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
            //printf("%s\n", info);

            if (j == 0){
                printf("[%s ## ", info);
            }

            if (j == 1)
            {
                printf("%s ## ", info);
            }
            else if (j == 2)
            {
                printf("%s ## ", info);
            }
            else if (j == 3)
            {
                printf("%s ## ", info);
            }
            else if (j == 4)
            {
                printf("%s ## ", info);
            }
            else if (j == 5)
            {
                printf("%s ## ", info);
            }
            else if (j == 6)
            {
                printf("%s ## ", info);
            }
            else if (j == 7)
            {
                printf("%s]\n", info);
            }

            info = strtok(NULL, ",");
            j++;
        }
        
        fclose(arq);
        
    }
    
    // printf("%s", str);
}

int main(void)
{
    int ids[1000];
    int lastId = -1;
    int id = 0;
    int i = 0;

    while (id != lastId)
    {
        lastId = id;
        scanf("%d", &id);
        if (id != lastId)
        {
            ids[i] = id;
            i++;
        }
    }

    // printf("antes");

    ordenar(ids, i, 0);

    //printf("teste");

    /*for (int j = 0; j < i; j++){
        printf("%d\n",ids[j]);
    }*/

    imprimir(ids, i);
}