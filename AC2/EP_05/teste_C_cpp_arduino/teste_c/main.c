#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t inicio, fim, T;
    float Tempo, mediaC=0,mediaI=0,mediaF=0;
    register c;
    char *ic, *jc,xc=3,yc=1;
    ic=&xc;
    jc=&yc;

    int *ii, *ji,xi=3,yi=1;
    ii=&xi;
    ji=&yi;

    float *ifl, *jf,xf=3,yf=1;
    ifl=&xf;
    jf=&yf;

    int k, num1=1, num2=3;
    T=CLOCKS_PER_SEC;
    for (k=1;k<=10;k=k+1)
    {   inicio=clock();
        for (c=1;c<=10000000;c=c+1);
        fim = clock();
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC);
        printf("\nTempo : %g ms.", Tempo);
        mediaC=mediaC+Tempo;
    }

    for (k=1;k<=10;k=k+1)
    {   inicio=clock();
        for (c=1;c<=10000000;c=c+1);
        fim = clock();
        Tempo =( (fim - inicio)*1000/CLOCKS_PER_SEC);
        printf("\nTempo : %g ms.", Tempo);
        mediaC=mediaC+Tempo;
    }
    printf("\nTempo gasto media: %g ms.", mediaC/10);
}
