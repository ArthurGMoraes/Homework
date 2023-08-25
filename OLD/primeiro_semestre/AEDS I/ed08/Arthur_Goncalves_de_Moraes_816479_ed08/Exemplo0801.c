/*
 Exemplo0801 - v1.0. 
 Author: Arthur Goncalves de Moraes 816479
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )

/**
 printIntArray - Mostrar arranjo com valores inteiros.
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
void printIntArray ( int n, int array [ ] )
{
// definir dado local
 int x = 0;
 
// mostrar valores no arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // mostrar valor
 IO_printf ( "%2d: %d\n", x, array [ x ] );
 } // fim repetir
} // printIntArray ( )
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
// definir dado
 int array [ ] = { 1, 2, 3, 4, 5 };
// identificar
 IO_id ( "EXEMPLO0801 - Method01 - v1.0" );
// executar o metodo auxiliar
 printIntArray ( 5, array );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 Method02.
*/
void method02 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method02 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )
/**
 Method03.
*/
void method03 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method03 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )
/**
 Method04.
*/
void method04 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method04 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )
/**
 Method05.
*/
void method05 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method05 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )
/**
 Method06.
*/
void method06 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method06 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )
/**
 Method07.
*/
void method07 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method07 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )
/**
 Method08.
*/
void method08 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method08 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method09 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "EXEMPLO0000 - Method10 - v0.0" );
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
 IO_id ( "EXEMPLO0801 - Programa - v1.0" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - Mostrar arranjo com valores inteiros" );
 IO_println ( " 2 - " );
 IO_println ( " 3 - " );
 IO_println ( " 4 - " );
 IO_println ( " 5 - " );
 IO_println ( " 6 - " );
 IO_println ( " 7 - " );
 IO_println ( " 8 - " );
 IO_println ( " 9 - " );
 IO_println ( "10 - " );
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