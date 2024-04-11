#include <stdio.h>
#include <math.h>
double derive(double (*f)(double), double x0)
{
    const double delta = 1.0e-6; // or similar
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

double somatorio(int li, int ls, int n, int q){
    double deltaX = ((double)ls - (double)li)/(double)n;
    printf("%f\n", deltaX);
    double result = 0;
    double a = 0;
    switch (q){
        case 1:
            // y = (4 - x^2)^(-1/2)
            for (int i = 1; i < n; i++){
                a = li + (i * deltaX);
                printf("%f a\n", a);
                result += deltaX*(sqrt(4-pow(a,2))); 
                printf("%f\n", result);
            };
        case 2:
            // y = (1+f'(x)^2)^(1/2)
            //printf("aqui");
            for (int i = 1; i < n; i++){
                //printf("%f a\n", a);
                result += deltaX*(sqrt(4-(2*pow(1,2)))); 
                //printf("%f\n", result);
            }
            return(result);
        case 3:
            for (int i = 1; i < n; i++){
                a = li + (i * deltaX);
                printf("%f a\n", a);
                result += deltaX*(sqrt(4-pow(a,2))); 
                printf("%f\n", result);
            };
        case 4:
            for (int i = 1; i < n; i++){
                a = li + (i * deltaX);
                printf("%f a\n", a);
                result += deltaX*(sqrt(4-pow(a,2))); 
                printf("%f\n", result);
            };
    }
        
    return(result);
}

int main (void){
    int limiteSup, limiteInf, n, q;
    printf("Inserir limite inferior, limite superior, n e o numero da questao \n");
    scanf("%d %d %d %d", &limiteInf, &limiteSup, &n, &q);
    printf("%d %d %d %d\n", limiteInf, limiteSup, n, q);
    printf("%f\n", somatorio(limiteInf, limiteSup, n, q));
}

