/*
 Exercicios07 - v1.0. 
 Author: Arthur Goncalves de Moraes 816479
*/
// dependencias
#include "io.h" // para definicoes proprias
#include <math.h>
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )

void multiplos3 (chars fileName, int x)
{
FILE* arquivo = fopen ( fileName, "wt" );
 int multiplo = 0;

 while ( x>0 )
 {
 multiplo = multiplo + 3;
 if (multiplo % 2 == 0)
  {
 fprintf ( arquivo, "%d\n", multiplo );
 x = x - 1;
  }
 } 
 fclose ( arquivo );
} 

/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
int x = 0;
// identificar
 IO_id ( "EXEMPLO0711 - Method01 - v1.0" );
 x = IO_readint("Escreva um numero: ");
 multiplos3("DADOS0711.txt",x);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

void multiplos5 (chars fileName, int x)
{
FILE* arquivo = fopen ( fileName, "wt" );
 int multiplo = 15;
 int resultado = 0;
 for (x = (x-1) * 10; x >= 0; x = x - 10)
 {
    resultado = multiplo + x;
    fprintf ( arquivo, "%d\n", resultado );
 }

 fclose ( arquivo );
} 
/**
 Method02.
*/
void method02 ( )
{
int x = 0;
// identificar
 IO_id ( "EXEMPLO0712 - Method02 - v1.0" );
 x = IO_readint("Escreva um numero: ");
 multiplos5("DADOS0712.txt",x);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

void exp6 (chars fileName, int x)
{
FILE* arquivo = fopen ( fileName, "wt" );
 int expoente = 0;
 int y = 0;
 while (y<x)
 {
    expoente = pow(6,y);
    fprintf ( arquivo, "%d\n", expoente);
    y = y + 1;
 }

 fclose ( arquivo );
} 

/**
 Method03.
*/
void method03 ( )
{
 int x = 0;
// identificar
 IO_id ( "EXEMPLO0713 - Method03 - v1.0" );
 x = IO_readint("Escreva um numero: ");
 exp6("DADOS0713.txt",x);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

void frac6 (chars fileName, int x)
{
FILE* arquivo = fopen ( fileName, "wt" );
 int resultado = 0;
 int y = x - 1;
 while ( y >= 0)
 {
   resultado = pow(6,y);
   fprintf ( arquivo, "1/%d\n", resultado);
   y = y - 1;
 }

 fclose ( arquivo );
} 
/**
 Method04.
*/
void method04 ( )
{
 int x = 0;
// identificar
 IO_id ( "EXEMPLO0714 - Method04 - v1.0" );
 x = IO_readint("Escreva um numero: ");
 frac6("DADOS0714.txt",x);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

void fracao (chars fileName, int x, int z)
{
FILE* arquivo = fopen ( fileName, "wt" );
 int resultado = 0;
 int y = 0;
 int exp = 0;
 while ( y < x)
 {
   resultado = pow(z,exp);
   fprintf ( arquivo, "1/%d\n", resultado);
   exp = exp + 2;
   y = y + 1;
 }

 fclose ( arquivo );
} 

/**
 Method05.
*/
void method05 ( )
{
int x = 0;
int z = 0;
// identificar
 IO_id ( "EXEMPLO0715 - Method05 - v1.0" );
 x = IO_readint("Escreva um numero: ");
 z = IO_readint("Escreva outro numero: ");
 fracao("DADOS0715.txt",x,z);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
 copyText - Copiar arquivo texto.
 @param fileOut - nome do arquivo de saida (destino)
 @param fileIn - nome do arquivo de entrada (origem )
*/
void copyText ( chars fileName, int x )
{
 int resultado = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
 FILE* arquivoNovo = fopen ( "RESULTADO06.txt" , "wt" );
 chars linha = IO_new_chars ( STR_SIZE );
 int linhaint = (int) linha;
 strcpy ( linha, IO_freadln ( arquivo ) );
 while ( ! feof (arquivo) &&
 strcmp ( "PARAR", linha ) != 0 )
 {
 resultado = resultado + linhaint;
 strcpy ( linha, IO_freadln ( arquivo ) );
 }
 fprintf ( arquivoNovo, "%d\n", resultado);
}

/**
 Method06.
*/
void method06 ( )
{
int x = 0;
// identificar
 IO_id ( "EXEMPLO0716 - Method06 - v1.0" );
 x = IO_readint("Escreva um numero: ");
 copyText("DADOS0715.txt",x);
 // encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
 Method07.
*/
void method07 ( )
{
// identificar
 IO_id ( "EXEMPLO0717 - Method07 - v1.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )
/**
 Method08.
*/
void method08 ( )
{
// identificar
 IO_id ( "EXEMPLO0718 - Method08 - v1.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{
// identificar
 IO_id ( "EXEMPLO0719 - Method09 - v1.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "EXEMPLO0720 - Method10 - v1.0" );
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
 IO_id ( "EXEMPLO0701 - Programa - v1.0" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - 0711" );
 IO_println ( " 2 - 0712" );
 IO_println ( " 3 - 0713" );
 IO_println ( " 4 - 0714" );
 IO_println ( " 5 - 0715" );
 IO_println ( " 6 - 0716" );
 IO_println ( " 7 - 0717" );
 IO_println ( " 8 - 0718" );
 IO_println ( " 9 - 0719" );
 IO_println ( "10 - 0720" );
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