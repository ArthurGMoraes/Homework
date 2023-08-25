/*
 Exemplo0607 - v0.1. 
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
 Method01a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method01a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", x );
 // passar ao proximo
 method01a ( x - 1 ); // motor da recursividade
 } // fim se
} // fim method01a( )
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
// identificar
 IO_id ( "EXEMPLO0607 - Method01 - v0.1" );
// executar o metodo auxiliar
 method01a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )


/**
 Method02a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method02a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // passar ao proximo
 method02a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", x );
 } // fim se
} // fim method02a( )
/**
 Method02.
*/
void method02 ( )
{
// identificar
 IO_id ( "EXEMPLO0607 - Method02 - v0.1" );
// executar o metodo auxiliar
 method02a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )
/**
 Method03a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method03a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // passar ao proximo
 method03a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", x );
 }
 else
 { // base da recursividade
 // mostrar o ultimo
 IO_printf ( "%s\n", "Valor = 1" );
 } // fim se
} // fim method03a( )
/**
 Method03.
*/
void method03 ( )
{
// identificar
 IO_id ( "EXEMPLO0607 - Method03 - v0.1" );
// executar o metodo auxiliar
 method03a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
 Method04a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method04a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // passar ao proximo
 method04a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", 2*(x-1) );
 }
 else
 { // base da recursividade
 // mostrar o ultimo
 IO_printf ( "%s\n", "Valor = 1" );
 } // fim se
} // fim method04a( )
/**
 Method04.
*/
void method04 ( )
{
// identificar
 IO_id ( "EXEMPLO0607 - Method04 - v0.1" );
// executar o metodo auxiliar
 method04a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
 Method05a - Mostrar certa quantidade de valores recursivamente.
 @param x - quantidade de valores a serem mostrados
*/
void method05a ( int x )
{
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // passar ao proximo
 method05a ( x - 1 ); // motor da recursividade
 // mostrar valor
 IO_printf ( "%d: %d/%d\n", x, (2*(x-1)), (2*(x-1)+1) );
 }
 else
 { // base da recursividade
 // mostrar o ultimo
 IO_printf ( "%d: %d\n", x, 1 );
 } // fim se
} // fim method05a( )
/**
 Method05.
*/
void method05 ( )
{
// identificar
 IO_id ( "EXEMPLO0607 - Method05 - v0.1" );
// executar o metodo auxiliar
 method05a ( 5 ); // motor da recursividade
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )
/**
 somarFracoes - Somar certa quantidade de fracoes recursivamente.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracoes ( int x )
{
// definir dado local
 double soma = 0.0;
// repetir enquanto valor maior que zero
 if ( x > 1 )
 {
 // separar um valor e passar ao proximo (motor da recursividade)
 soma = (2.0*(x-1))/(2.0*(x-1)+1) + somarFracoes ( x - 1 );
 // mostrar valor
 IO_printf ( "%d: %lf/%lf\n", x, (2.0*(x-1)), (2.0*(x-1)+1) );
 }
 else
 {
 // base da recursividade
 soma = 1.0;
 // mostrar o ultimo
 IO_printf ( "%d; %lf\n", x, 1.0 );
 } // fim se
// retornar resultado
 return ( soma );
} // fim somarFracoes ( )
/**
 Method06.
*/
void method06 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "EXEMPLO0607 - Method06 - v0.1" );
// chamar a funcao e receber o resultado
 soma = somarFracoes ( 5 );
// mostrar resultado
 IO_printf ( "soma = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )
/**
 somarFracoes2b - Somar certa quantidade de fracoes recursivamente.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados (controle)
 @param soma - valor atual da soma (historia = memoria)
 @param numerador - numerador da parcela a ser somada
 @param denominador - denominador da parcela a ser somada
*/
double somarFracoes2b ( int x, double soma, double numerador, double denominador )
{
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // mostrar valores atuais
 IO_printf ( "%d: %lf/%lf\n", x, numerador, denominador );
 // somar o termo atual e passar ao proximo (motor da recursividade)
 soma = somarFracoes2b ( x - 1, // proximo
 soma + ((1.0*numerador) / denominador), // atualizar
 numerador +2.0 , // proximo
 denominador+2.0 ); // proximo
 }
// retornar resultado
 return ( soma );
} // fim somarFracoes2b ( )
/**
 somarFracoes2a - Somar certa quantidade de fracoes.
 Funcao de servico para preparar e 
 disparar o mecanismo recursivo.
 @return soma de valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracoes2a ( int x )
{
// definir dado local
 double soma = 0.0;
// repetir enquanto valor maior que zero
 if ( x > 0 )
 {
 // mostrar o ultimo
 IO_printf ( "%d: %lf\n", x, 1.0 );
 // preparar a soma do valor atual e o proximo
 soma = somarFracoes2b ( x-1, 1.0, 2.0, 3.0 );
 } // fim se
// retornar resultado
 return ( soma );
} // fim somarFracoes2a ( )
/**
 Method07.
*/
void method07 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "EXEMPLO0607 - Method07 - v0.1" );
// chamar a funcao e receber o resultado
 soma = somarFracoes2a ( 5 );
// mostrar resultado
 IO_printf ( "soma = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
 Method08.
*/
void method08 ( )
{
// identificar
 IO_id ( "EXEMPLO0607 - Method08 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{
// identificar
 IO_id ( "EXEMPLO0607 - Method09 - v0.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "EXEMPLO0607 - Method10 - v0.0" );
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
 IO_id ( "EXEMPLO0607 - Programa - v0.1" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - Parar" );
 IO_println ( " 1 - Mostrar certa quantidade de valores recursivamente." );
 IO_println ( " 2 - Mostrar certa quantidade de valores recursivamente. (alternativo)" );
 IO_println ( " 3 - Mostrar certa quantidade de valores recursivamente. (alternativo)" );
 IO_println ( " 4 - Mostrar certa quantidade de pares recursivamente" );
 IO_println ( " 5 - Mostrar valores de parcelas de um somatorio" );
 IO_println ( " 6 - Calcular o somatorio: 1 + 2/3 + 4/5 + 6/7 + ..." );
 IO_println ( " 7 - Calcular o somatorio: 1 + 2/3 + 4/5 + 6/7 + ... (alternativo)" );
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
