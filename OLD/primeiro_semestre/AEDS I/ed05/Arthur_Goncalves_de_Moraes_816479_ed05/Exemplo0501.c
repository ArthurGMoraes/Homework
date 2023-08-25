/*
 Exemplo0501 - v0.1. 
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
 Method01a - Mostrar certa quantidade de valores.
 @param x - quantidade de valores a serem mostrados
*/
void method01a ( int x )
{
// definir dado local
 int y = 1; // controle
// repetir enquanto controle menor que a quantidade desejada
 while ( y <= x )
 {
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", y );
 // passar ao proximo
 y = y + 1;
 } // fim se
} // fim method01a( )
/**
 Method01 - Mostrar certa quantidade de valores.
 OBS.: Preparacao e disparo de outro metodo.
*/
void method01 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method01 - v0.1" );
// executar o metodo auxiliar
 method01a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )
/**
 Method02.
*/
void method02 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method02 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )
/**
 Method03.
*/
void method03 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method03 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )
/**
 Method04.
*/
void method04 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method04 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )
/**
 Method05.
*/
void method05 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method05 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )
/**
 Method06.
*/
void method06 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method06 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )
/**
 Method07.
*/
void method07 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method07 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )
/**
 Method08.
*/
void method08 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method08 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method09 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "EXEMPLO0501 - Method10 - v0.0" );
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
 IO_id ( "EXEMPLO0501 - Programa - v0.1" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - mostrar certa quantidade de valores" );
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
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5 -> { 1, 2, 3, 4, 5 }
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/