// 1465552_AED1
#include <stdio.h>
#include "string.h"
#include "io.h"

void method00(){

}

 void Exemplo0311(){
     char palavra[80] = "0";
     char simbolo = '0';
     int tamanho = 0;
     int x = 0;
     int maiuscula = 0;
     
     printf ("qual a palavra: ");
     scanf( "%s",palavra); getchar();
     printf ("\npalavra = [%s] \n", palavra);
     tamanho = strlen (palavra);
     printf ("\ntamanho = [%d]\n\n", tamanho);
     for (x=0; x<tamanho ; x=x+1)
     {
         simbolo = palavra [ x ];
         
         
         if ('A' <= simbolo && simbolo<='Z')
         {
             printf (" %c\n", simbolo);
             maiuscula = maiuscula + 1;
             

         }
       
   
    }
    printf("\nApertar ENTER para encerrar");
   getchar();   
 }



 void Exemplo0312(){
     char palavra[80] = "0";
     char simbolo = '0';
     int tamanho = 0;
     int x = 0;
     int maiuscula = 0;
     
     printf ("qual a palavra: ");
     scanf( "%s",palavra); getchar();
     printf ("\npalavra = [%s] \n", palavra);
     tamanho = strlen (palavra);
     printf ("\ntamanho = [%d]\n", tamanho);
     for (x=0; x<tamanho ; x=x+1)
     {
         simbolo = palavra [ x ];
         
         
         if ('A' <= simbolo && simbolo<='Z')
         {
             printf ("\n %c", simbolo);
             maiuscula = maiuscula + 1;
             

         }
       
   
    }
       printf ("\n\nmaiusculas = %d\n", maiuscula);
        printf("\nApertar ENTER para encerrar");
   getchar();  
 }


 void Exemplo0313(){
     char palavra[80] = "0";
     char simbolo = '0';
     int tamanho = 0;
     int x = 0;
     int maiuscula = 0;
     
     printf ("qual a palavra: ");
     scanf( "%s",palavra); getchar();
     printf ("\npalavra = [%s] \n", palavra);
     tamanho = strlen (palavra);
     printf ("\ntamanho = [%d]\n", tamanho);
     for (x=tamanho-1; x>=0; x=x-1)
     {
         simbolo = palavra [ x ];
         
         
         if ('A' <= simbolo && simbolo<='Z')
         {
             printf ("\n %c", simbolo);
             maiuscula = maiuscula + 1;
             

         }
       
   
    }
       printf ("\n\nmaiusculas = %d\n", maiuscula);
        printf("\nApertar ENTER para encerrar");
   getchar();  
 }


 void Exemplo0314(){
     char palavra[80] = "0";
     char simbolo = '0';
     int tamanho = 0;
     int x = 0;
     int maiuscula = 0;
     int letras = 0;
     
     printf ("qual a palavra: ");
     scanf( "%s",palavra); getchar();
     printf ("\npalavra = [%s] \n", palavra);
     tamanho = strlen (palavra);
     printf ("\ntamanho = [%d]\n", tamanho);
     for (x=0; x<tamanho ; x=x+1)
     {
         simbolo = palavra [ x ];
         
         
         if (('A' <= simbolo && simbolo<='Z') || ('a' <= simbolo && simbolo<='z'))
         {
             printf ("\n %c", simbolo);
             letras = letras  + 1;
             

         }
       
   
    }
       printf ("\n\n letras = %d\n", letras);
        printf("\nApertar ENTER para encerrar");
   getchar();  
 }


    void Exemplo0315(){
     char palavra[80] = "0";
     char simbolo = '0';
     int tamanho = 0;
     int x = 0;
     int maiuscula = 0;
     int digitos = 0;
     
     printf ("qual a palavra: ");
     scanf( "%s",palavra); getchar();
     printf ("\npalavra = [%s] \n", palavra);
     tamanho = strlen (palavra);
     printf ("\ntamanho = [%d]\n", tamanho);
     for (x=tamanho-1; x>=0; x=x-1)
     {
         simbolo = palavra [ x ];
         
         
         if ('0' <= simbolo && simbolo<='9')
         {
             printf ("\n %c", simbolo);
             digitos =  digitos + 1;
             

         }
       
   
    }
       printf ("\n\ndigitos = %d\n", digitos );
        printf("\nApertar ENTER para encerrar");
   getchar();  
 }

  void Exemplo0316(){
     char palavra[80] = "0";
     char simbolo = '0';
     int tamanho = 0;
     int x = 0;
     int maiuscula = 0;
     int letras = 0;
     int outros = 0;
     
     printf ("qual a palavra: ");
     scanf( "%s",palavra); getchar();
     printf ("\npalavra = [%s] \n", palavra);
     tamanho = strlen (palavra);
     printf ("\ntamanho = [%d]\n", tamanho);
     for (x=0; x<tamanho ; x=x+1)
     {
         simbolo = palavra [ x ];
         
         
         if (!('A' <= simbolo && simbolo<='Z'|| 'a' <= simbolo && simbolo<='z' || '0' <= simbolo && simbolo<='9'))
         {
             printf ("\n %c", simbolo);
             outros = outros  + 1;
             

         }
       
   
    }
       printf ("\n\n outros = %d\n", outros);
        printf("\nApertar ENTER para encerrar");
   getchar();  
 }

 void Exemplo0317() {
    int a, b, n, x, count = 0;
    
    printf("Informe o limite inferior do intervalo: ");
    scanf("%d", &a);
    
    printf("\nInforme o limite superior do intervalo: ");
    scanf("%d", &b);
    
    printf("\nInforme a quantidade de valores a serem testados: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("\nInforme o %d valor a ser testado: ", i);
        scanf("%d", &x);
        
        if (x >= a && x <= b && x % 3 == 0) {
            count++;
        }
    }
    
    printf("\nQuantidade de valores que sao multiplos de 3 e pertencem ao intervalo [%d:%d]: %d\n", a, b, count);
    printf("\nApertar ENTER para finalizar");
    getchar(); // getchar nao funcionou
    
}

 void Exemplo0318() {
    int a, b, n, x, count = 0;
    
    printf("Informe o limite inferior do intervalo: ");
    scanf("%d", &a);
    
    printf("\nInforme o limite superior do intervalo: ");
    scanf("%d", &b);
    
    printf("\nInforme a quantidade de valores a serem testados: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("\nInforme o %d valor a ser testado: ", i);
        scanf("%d", &x);
        
        if (x >= a && x <= b && x % 2 == 0 && x % 5 != 0 ) {
            count++;
        }
    }
    
    printf("\nQuantidade de valores que sao multiplos de 2 e nao de 5 e pertencem ao intervalo [%d:%d]: %d\n", a, b, count);
    printf("\nApertar ENTER para finalizar"); getchar();  // getchar nao funcionou
    
}

void Exemplo0319() {
    double x = 0.0;
    int a, b, n , count = 0;
    
    printf("Informe o limite inferior do intervalo: ");
    scanf("%d", &a);
    
    printf("\nInforme o limite superior do intervalo: ");
    scanf("%d", &b);
     if (a<b){
    printf("\nInforme a quantidade de valores a serem testados: ");
    scanf("%d", &n);
   
    for (int i = 1; i <= n; i++) {
        printf("\nInforme o %d valor a ser testado: ", i);
        scanf("%lf", &x);
        
        if (x >= a && x <= b && (int)x % 2 == 0 ) {
            count++;
        }
    }
    
    printf("\nQuantidade de valores pares que pertencem ao intervalo [%d:%d]: %d\n", a, b, count);
    printf("\nApertar ENTER para finalizar"); 
    getchar();  // getchar nao funcionou
    }
}

void Exemplo0320() {
    double a, b, x = 0.0;
    int  n , count = 0;
    
    printf("Informe o limite inferior do intervalo: ");
    scanf("%lf", &a);
    
    printf("\nInforme o limite superior do intervalo: ");
    scanf("%lf", &b);
     if (a<b){
    printf("\nInforme a quantidade de valores a serem testados: ");
    scanf("%d", &n);
   
    for (int i = 1; i <= n; i++) {
        printf("\nInforme o %d valor a ser testado: ", i);
        scanf("%lf", &x);
        x = x - (int)x;
       // printf("\n%lf",x);   

        
        if (x < a || x > b ) {
            count++; //valores iguais ao limite do intervalo sao considerados fora mesmo sem utilizar <= ou >=
        }
    }
    
    printf("\nQuantidade de valores com a parte fracionaria fora do intervalo [%lf:%lf]: %d\n", a, b, count);
    printf("\nApertar ENTER para finalizar"); 
    getchar();  // getchar nao funcionou
    }
}























 /*
 Funcao principal.
*/
int main ( )
{
// definir dado
 int z = 0;
// repetir até desejar parar
 do
 {

 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( "0 - parar" );
 IO_println ( "1 - mostrar maiusculas" );
 IO_println ( "2 - mostrar e contar maiusculas" );
 IO_println ( "3 - mostrar e contar maiusculas ( decrescente )" );
 IO_println ( "4 - mostrar e contar letras" );
 IO_println ( "5 - contar e mostrar digitos (decrescente)" );
 IO_println ( "6 - contar e mostrar simbolos especiais" );
 IO_println ( "7 - multiplos de 3 em um intervalo" );
 IO_println ( "8 - multiplos de 2 que nao sao de 5" );
 IO_println ( "9 - valores com parte inteira par" );
 IO_println ( "10 - parte fracionaria fora do intervalo" );
  IO_println ( " " );
 z = IO_readint ( "Entrar com uma opcao: " );
 
 // testar valor
 switch ( z )
 {
 case 0:
 method00 ( );
 break;
 case 1:
 Exemplo0311 ( );
 break;
 case 2:
 Exemplo0312 ( );
 break;
 case 3:
 Exemplo0313 ( );
 break;
 case 4:
 Exemplo0314 ( );
 break;
 case 5:
 Exemplo0315 ( );
 break;
 case 6:
 Exemplo0316 ( );
 break;
 case 7:
 Exemplo0317 ( );
 break;
 case 8:
 Exemplo0318 ( );
 break;
 case 9:
 Exemplo0319 ( );
 break;
 case 10:
 Exemplo0320 ( );
 break; 
 default:
 IO_pause ( "ERRO: Valor invalido." );
 } // fim escolher
 }
 while ( z != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )