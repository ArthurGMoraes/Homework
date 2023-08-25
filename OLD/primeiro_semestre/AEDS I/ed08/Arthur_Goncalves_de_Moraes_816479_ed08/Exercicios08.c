/*
 Exercicios - v1.0. 
 Author: Arthur Goncalves de Moraes 816479
*/
// dependencias
#include "io.h" // para definicoes proprias
#include "array.h"
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )

void method01 ( )
{
 int x = 0;
 int y = 0;
 int teste = 0;
// identificar
 IO_id ( "Exemplo0811 - Method01 - v1.0" );
// encerrar
 x = IO_readint("Tamanho array: ");
 int array[x];
 if (x>0){
 while (y<x){
    teste = IO_readint("Valor: ");
    if (teste >= 0 && teste % 2 == 0){
        array[y] = teste;
        y++;   
    }
  }
}
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

void ex0812(int array[], chars fileName, int x){
FILE* arquivo = fopen ( fileName, "wt" );
int teste = 0;
int tamanho= 0;
int tamanhoFim = 0;
if (x<=0){
    printf("valor invalido");
}
while(teste<x){
 if(array[teste]>0 && array[teste]%2==0){
    array[tamanho+1] = array[teste];
    tamanho++;
    teste++;
 }
 teste++;
}
int arrayNova[tamanho];
arrayNova[0]=tamanho;
for (teste=1; teste<=tamanho ;teste++)
{
    arrayNova[teste]=array[teste];
}
for (teste=0; teste<=tamanho ;teste++){
    IO_fprintf ( arquivo, "%d\n", arrayNova [ teste ] );
}
fclose ( arquivo );
}
/**
 Method02.
*/
void method02 ( )
{
int array[6] = {2,7,-1,9,-2,4};
int tamanho =  (int)( sizeof(array) / sizeof(array[0]));
ex0812(array, "ARRAY0812.TXT", tamanho);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

void ex0813(int quantidade,int inferior,int superior){
FILE* arquivo = fopen ( "ex0813.TXT", "wt" );
int x = 0;
int valor = 0;
    while (x<quantidade){
        valor = rand() % superior;
        if (valor>inferior){
       IO_fprintf ( arquivo, "%d\n", valor );
       x++;
        }
        
    }
    fclose (arquivo);
}
/**
 Method03.
*/
void method03 ( )
{   
    int x = 0;
// identificar
 IO_id ( "Exemplo0813 - Method03 - v1.0" );
 x = IO_readint("Escolha o tamanho: ");
 ex0813(x,10,100);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )


void ex0814(chars fileName){
 int x = 0;
 int y = 0;
 int teste = 0;
 int copiaTeste= 0;
 int resultado=0;
 int k = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 int n = freadArraySize(fileName);
 //int array[10] = {0,0,0,0,0,0,0,0,0,0};
 IO_fscanf ( arquivo, "%d", &x );
 //array [ 0 ] = x;
 if ( n <= 0 || n > x )
 {
 IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
 x = 0;
 while ( ! feof ( arquivo ) && x < n )
 {
 IO_fscanf ( arquivo, "%d", &y );
 if(y%2==0){
 teste = teste +1 ;
 } 
 x = x+1;
 }
 //printf("%d\n",teste);
 copiaTeste = teste;
 int array[copiaTeste];
 //printIntArray(copiaTeste,array);
 //teste = 0;
 x = 0;
   while ( ! feof ( arquivo ) && x < n )
 {
 IO_fscanf ( arquivo, "%d", &y );
 int array2[copiaTeste];
 if( y % 2 == 0){
 array2[k] = y ;
 array[k] = array2[k];
 k = k + 1;
 x = x + 1;
 
 } 
 x = x+1;
 
  }
 printIntArray(copiaTeste,array);
 x=0;
 while (x<(copiaTeste-2)){
    if(array[x]<array[x+1]){
    resultado = array[x];
    x = x + 1;
 } else {
   resultado = array[x+1];
   x++;}
 }
 
 } 
 


 printf("%d\n", resultado);

fclose(arquivo);
}

/**
 Method04.
*/
void method04 ( )
{
// identificar
 IO_id ( "Exemplo0814 - Method04 - v1.0" );
 ex0814 ("ex0814.TXT");
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )
/*Nos exercicios 0814 e 0815 nao consegui mudar os 
valores da array que armazenaria os pares ou impares,
ela sempre continha os "lixos". Os codigos desses exercicios
estao bem baguncados e os resulatdos errados pois estava testando 
v0arias formas e mesmo assim nao deu certo*/

void ex0815 (chars fileName){
 int x = 0;
 int y = 0;
 int teste = 0;
 int resultado;
 int array[1] = {0};
 FILE* arquivo = fopen ( fileName, "rt" );
 int n = freadArraySize(fileName);
 IO_fscanf ( arquivo, "%d", &x );
 array [ 0 ] = x;
 if ( n <= 0 || n > x )
 {
 IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
 x = 0;
 while ( ! feof ( arquivo ) && x < n )
 {
 IO_fscanf ( arquivo, "%d", &y );
 teste = y;
 if(y%2!=0){
 array[x]=y;  
   x = x+1; 
 } 
 } 
 printIntArray(n,array);
 /*x=0;
 while (x<((int)sizeof(array)-1)){
    if(array[x]>array[x+1]){
    resultado = array[x];
    x = x + 1;
 } else {
   resultado = array[x+1];
   x++;}
 } 
 printf("%d\n", resultado);*/
} 
fclose (arquivo);
}

/**
 Method05.
*/
void method05 ( )
{
// identificar
 IO_id ( "Exemplo0815 - Method05 - v1.0" );
 ex0815 ("ex0815.TXT");
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/*Nos exercicios 0814 e 0815 nao consegui mudar os 
valores da array que armazenaria os pares ou impares,
ela sempre continha os "lixos". Os codigos desses exercicios
estao bem baguncados e os resulatdos errados pois estava testando 
v0arias formas e mesmo assim nao deu certo*/

void ex0816 (chars fileName){
 FILE* arquivo = fopen ( fileName, "rt" );
 FILE* menor = fopen("MENOR.TXT", "wt");
 FILE* maiorIgual = fopen("MAIORIGUAL.TXT","wt");
 int x = 0;
 int y = 0;
 int n = freadArraySize(fileName);
 //printf("%d",n);
 int media = 0;
 int array[n];
 //int menores[n]={0};
 //int maiores[n]={0};
 IO_fscanf ( arquivo, "%d", &x );
 if ( n <= 0 || n > x )
 {
 IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
 x = 0;
 while ( ! feof ( arquivo ) && x < n )
 {
 IO_fscanf ( arquivo, "%d", &y );
 //printf("%d",y);
 array[x]=y;
 x = x + 1;
 }
 x = 0;
 //printIntArray(n,array);
 media = sumIntArray(n,array)/n;
while ( x < n  )
 {
 y = array[x];
 if (y<media){
   IO_fprintf ( menor, "%d\n", y );
   x++;
 } else {
   IO_fprintf ( maiorIgual, "%d\n", y );
   x++;
 }

 }
 //printf("%d",media);
}
 fclose(arquivo);
 fclose(menor);
 fclose(maiorIgual);
}
/**
 Method06.
*/
void method06 ( )
{
// identificar
 IO_id ( "Exemplo0816 - Method06 - v1.0" );
// encerrar
ex0816("ex0816.TXT");
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

void ex0817(int array[],int tamanho){
int x = 0;
for(x=0;x<tamanho-1;x=x+1){
    if(array[x]<array[x+1]){
        printf("Nao e' decrescente");
    } else {
        x++;
    }
}
printf ("decrescente");
}
/**
 Method07.
*/
void method07 ( )
{
    int array[6] = {9,8,7,4,1,10};
    int tamanho =  (int)( sizeof(array) / sizeof(array[0]));
// identificar
 IO_id ( "Exemplo0817 - Method07 - v1.0" );
 ex0817(array,tamanho);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

bool ex0818 ( int value, int n, chars fileName )
{
FILE* arquivo = fopen ( fileName, "rt" );
 int array[n];
 bool result = false;
 int x = 0;
 int y = 0;
 x = 0;
 while ( ! feof ( arquivo ) && x < n )
 {
 IO_fscanf ( arquivo, "%d", &y );
 array[x]=y;
 x = x + 1;
 }
 x = 0;
 while ( x<n && ! result )
 {
 result = ( value == array [ x ] );
 x = x + 1;
 } 
 return ( result );
}
/**
 Method08.
*/
void method08 ( )
{
    int x = IO_readint("Qual o valor?");
    int n = freadArraySize("ex0818.TXT");
    
// identificar
 IO_id ( "Exemplo0818 - Method08 - v1.0" );
 bool resultado = ex0818(x,n,"ex0818.TXT");
 if (resultado == 1){
    printf("existe\n");
 } else{
    printf("nao existe\n");
 }
  
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

int ex0819 ( int value, int n, chars fileName )
{
FILE* arquivo = fopen ( fileName, "rt" );
 int array[n];
 bool result = false;
 int x = 0;
 int y = 0;
 x = 0;
 while ( ! feof ( arquivo ) && x < n )
 {
 IO_fscanf ( arquivo, "%d", &y );
 array[x]=y;
 x = x + 1;
 }
 x = 0;
 while ( x<n && ! result )
 {
 result = ( value == array [ x ] );
 x = x + 1;
 } 
 return ( x );
}
/**
 Method09.
*/
void method09 ( )
{
 int x = IO_readint("Qual o valor?");
    int n = freadArraySize("ex0818.TXT");
    
// identificar
 IO_id ( "Exemplo0819 - Method09 - v1.0" );
 int resultado = ex0819(x,n,"ex0819.TXT");
 printf("%d\n",resultado);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

int ex0820 ( int value, int n, chars fileName )
{
FILE* arquivo = fopen ( fileName, "rt" );
 int array[n];
 bool result = false;
 int x = 0;
 int y = 0;
 int final = 0;
 while ( ! feof ( arquivo ) && x < n )
 {
 IO_fscanf ( arquivo, "%d", &y );
 array[x]=y;
 x = x + 1;
 }
 //printIntArray(n,array);
 x = 0;
 while ( x<n )
 {
 result = ( value == array [ x ] );
 if (result == 1){
   final = final + 1;
 }
 x = x + 1;
 } 
 return ( final );
}
/**
 Method10.
*/
void method10 ( )
{
    int x = IO_readint("Qual o valor?");
    int n = freadArraySize("ex0820.TXT");
// identificar
 IO_id ( "Exemplo0820 - Method10 - v1.0" );
 int resultado = ex0820(x,n,"ex0820.TXT");
 printf("%d\n",resultado);
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )
/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "Exercicios - Programa - v1.0" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - Exemplo0811" );
 IO_println ( " 2 - Exemplo0812" );
 IO_println ( " 3 - Exemplo0813" );
 IO_println ( " 4 - Exemplo0814" );
 IO_println ( " 5 - Exemplo0815" );
 IO_println ( " 6 - Exemplo0816" );
 IO_println ( " 7 - Exemplo0817" );
 IO_println ( " 8 - Exemplo0818" );
 IO_println ( " 9 - Exemplo0819" );
 IO_println ( "10 - Exemplo0820" );
 IO_println ( "" );
 x = IO_readint ( "Entrar com uma opcao: " );
 
 // testar valor
 switch ( x )
 {
 case 0:
 method00 ( );
 break;
 case 1:
 method01 ( );
 break;
 case 2:
 method02 ( );
 break;
 case 3:
 method03 ( );
 break;
 case 4:
 method04 ( );
 break;
 case 5:
 method05 ( );
 break;
 case 6:
 method06 ( );
 break;
 case 7:
 method07 ( );
 break;
 case 8:
 method08 ( );
 break;
 case 9:
 method09 ( );
 break;
 case 10:
 method10 ( );
 break;
 default:
 IO_println ( "ERRO: Valor invalido." );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )