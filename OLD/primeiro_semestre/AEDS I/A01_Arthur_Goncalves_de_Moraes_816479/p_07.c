// Arthur Goncalves de Moraes 816479
#include <stdio.h>
#include <math.h>
#include <string.h>

int main ()
{
    int tamanho = 0;
    char teste [80]  = "0";
    char letra [2]   = "0";
    char letra2 [2]  = "0";
    int resultado = 0;     
    while (0 != strcmp(teste,"PARAR"))
    {
        resultado = 0;
        scanf("%s",teste);
        //printf("%s\n",teste);
        tamanho = strlen(teste) - 1 ;
        //printf("%d\n",tamanho);
        while (tamanho > 0)
        {
            letra2 [0] = teste [tamanho - 1];
            letra [0]  = teste [tamanho];
            //printf("%s\n",teste [tamanho]);
            //printf("%s\n",letra);
            //printf("%s\n",letra2);
            if(strcmp(teste,"PARAR") == 0)
            {
                return 0;
            }
            else if ((strcmp(letra, "b") == 0 || strcmp(letra, "p") == 0)&&(strcmp(letra2, "n") == 0))
            {
                resultado = resultado + 1;
            }
            tamanho = tamanho - 1;
        }
        //printf("%d", resultado);
        if (resultado != 0)
        {
            printf("resultado incorreto\n");
        }
        else
        {
            printf("palavra correta\n");
        }
    }    
 return 0;
}