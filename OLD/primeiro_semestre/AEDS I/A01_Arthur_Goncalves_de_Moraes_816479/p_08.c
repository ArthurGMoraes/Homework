// Arthur Goncalves de Moraes 816479
#include <stdio.h>
#include <math.h>
#include <string.h>

double somar (int n)
{
    int i = 0;
    double resultado = 0.0;
    for(i = 1; i<=n; i = i + 1)
    {
    resultado = resultado + (double)i/((double)n-((double)i-1.0));
    //printf("%lf\n",resultado);
    }
    return resultado;
}

void main (void)
{
    int teste = 0;
    int i = 0;
    int valor [3] = {0,0,0};
    double resultado [3] = {0,0,0};
    for (i = 0; i < 3; i = i + 1)
    {
     printf("valor %d: ", i + 1);
     scanf("%d",&teste);
     valor[i] = teste;
     //printf("%d", valor[i]);
     resultado[i] = somar(valor[i]); 
     //printf("%lf\n", resultado[i]);
    }
    if ((resultado[0] == resultado [1]) && (resultado[0] == resultado[2]))
    {
        printf("resultados iguais\n");
    }
    else
    {
        if ((resultado[0] > resultado[1]) && (resultado[1]>resultado[2]))
        {
            printf("O valor 1: %d tem a maior soma\n", valor[0]);
           
        } 
        else if ((resultado[1] > resultado[0]) && (resultado[0]>resultado[2]))
        {
            printf("O valor 2: %d tem a maior soma\n", valor[1]);
        }
        else if ((resultado[2] > resultado[0]) && (resultado[0]>resultado[1]))
        {
            printf("O valor 3: %d tem a maior soma\n", valor[2]);
        }
    }    
}