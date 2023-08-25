// Arthur Goncalves de Moraes 816479
#include <stdio.h>
#include <math.h>
#include <string.h>

int potencia (int base, int exp)
{
    int teste = 0;
    int result = 1;
    for (teste = 0; teste<exp; teste = teste + 1)
    {
        result = result * base;
    }
    return result;
}

void main (void)
{
    int m = 0;
    int n = 0;
    for (m = 0; m < 10; m = m + 1)
    {
        for(n = m + 1; n <= 10; n = n + 1)
        {
            if (potencia(m,n) == potencia(n,m))
            {
                printf("m = %d, n = %d",m,n);
            }
        }
    }

}
