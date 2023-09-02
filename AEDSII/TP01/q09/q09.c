#include <stdio.h>



int main(void){
        int quantidade = 0; 
        double Y = 0.0;
        scanf("%d", &quantidade);
        FILE * Arq = fopen("resposta.txt", "w"); 

        for(int i = 0; i < quantidade; i++) 
        {
            double numero = 0.0; 

            scanf("%lf", &numero); //lendo um numero
            fwrite(&numero, sizeof(double), 1, Arq);
        }
        fclose(Arq); //salvando arquivo

        FILE * Arq2 = fopen("resposta.txt", "rb"); ; //abrindo o arquivo novamente para leitura

        do
        {
            long position = (quantidade - 1 )*8;  
           // printf("%ld\n", position);
            fseek(Arq2, position, SEEK_SET);  
        
            fread(&Y, sizeof(double), 1, Arq2);
            
            
            if (Y == (int) Y) 
            {
                printf("%d\n",(int) Y);  
            } else {
                printf("%g\n", Y);  
            }
        
            quantidade--; //passando pra próxima posição
        } while (quantidade > 0);
        
        fclose(Arq2);
}