/*
 Exemplo0806 - v1.0. 
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
 IO_id ( "EXEMPLO0806 - Method01 - v1.0" );
// executar o metodo auxiliar
 printIntArray ( 5, array );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 readIntArray - Ler arranjo com valores inteiros.
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
void readIntArray ( int n, int array [ ] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 chars text = IO_new_chars ( STR_SIZE );
// ler e guardar valores em arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // ler valor
 strcpy ( text, STR_EMPTY );
 y = IO_readint ( IO_concat (
 IO_concat ( text, IO_toString_d ( x ) ), " : " ) );
 // guardar valor
 array [ x ] = y;
 } // fim repetir
} // readIntArray ( )
/**
 Method02.
*/
void method02 ( )
{
// definir dados
 int n = 5; // quantidade de valores
 int array [ n ];
// identificar
 IO_id ( "EXEMPLO0806 - Method02 - v1.0" );
// ler dados
 readIntArray ( n, array );
// mostrar dados
 IO_printf ( "\n" );
 printIntArray ( n, array );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
 fprintIntArray - Gravar arranjo com valores inteiros.
 @param fileName - nome do arquivo
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
void fprintIntArray ( chars fileName, int n, int array [ ] )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
 int x = 0;
// gravar quantidade de dados
 IO_fprintf ( arquivo, "%d\n", n );
// gravar valores no arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // gravar valor
 IO_fprintf ( arquivo, "%d\n", array [ x ] );
 } // fim repetir
 
// fechar arquivo
 fclose ( arquivo );
} // fprintIntArray ( )
/**
 Method03.
*/
void method03 ( )
{
// definir dados
 int n = 5; // quantidade de valores
 int array [ n ];
// identificar
 IO_id ( "EXEMPLO0806 - Method03 - v1.0" );
// ler dados
 readIntArray ( n, array );
// mostrar dados
 IO_printf ( "\n" );
 fprintIntArray ( "ARRAY1.TXT", n, array );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )
/**
 freadArraySize - Ler tamanho do arranjo com valores inteiros.
 @return quantidade de valores lidos
 @param fileName - nome do arquivo
*/
int freadArraySize ( chars fileName )
{
// definir dados locais
 int n = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
 IO_fscanf ( arquivo, "%d", &n );
 if ( n <= 0 )
 {
 IO_println ( "ERRO: Valor invalido." );
 n = 0;
 } // fim se
// retornar dado lido
 return ( n );
} // freadArraySize ( )
/**
 freadIntArray - Ler arranjo com valores inteiros.
 @param fileName - nome do arquivo
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
void freadIntArray ( chars fileName, int n, int array [ ] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
 IO_fscanf ( arquivo, "%d", &x );
 if ( n <= 0 || n > x )
 {
 IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
 // ler e guardar valores em arranjo
 x = 0;
 while ( ! feof ( arquivo ) && x < n )
 {
 // ler valor
 IO_fscanf ( arquivo, "%d", &y );
 // guardar valor
 array [ x ] = y;
 // passar ao proximo
 x = x+1;
 } // fim repetir
 } // fim se
} // freadIntArray ( )
/**
 Method04.
*/
void method04 ( )
{
// definir dados
 int n = 0; // quantidade de valores
// identificar
 IO_id ( "EXEMPLO0806 - Method04 - v1.0" );
// ler dados
 n = freadArraySize ( "ARRAY1.TXT" );
 if ( n <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // definir armazenador
 int array [ n ];
 // ler dados
 freadIntArray ( "ARRAY1.TXT", n, array );
 // mostrar dados
 IO_printf ( "\n" );
 printIntArray ( n, array );
 } // fim se
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )
/**
 copyIntArray - Copiar arranjo com valores inteiros.
 @param n - quantidade de valores
 @param copy - copia do grupo de valores inteiros
 @param array - grupo de valores inteiros
*/
void copyIntArray ( int n, int copy [ ], int array [ ] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 if ( n <= 0 )
 {
 IO_println ( "ERRO: Valor invalido." );
 n = 0;
 }
 else
 {
 // copiar valores em arranjo
 for ( x = 0; x < n; x = x + 1 )
 {
 // copiar valor
 copy [ x ] = array [ x ];
 } // fim repetir
 } // fim se
} // copyIntArray ( )
/**
 Method05.
*/
void method05 ( )
{
// definir dados
 int n = 0; // quantidade de valores
// identificar
 IO_id ( "EXEMPLO0806 - Method05 - v1.0" );
// ler a quantidade de dados
 n = freadArraySize ( "ARRAY1.TXT" );
 if ( n <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // definir armazenador
 int array [ n ];
 int other [ n ];
 // ler dados
 freadIntArray ( "ARRAY1.TXT", n, array );
 // copiar dados
 copyIntArray ( n, other, array );
 // mostrar dados
 IO_printf ( "\nOriginal\n" );
 printIntArray ( n, array );
 // mostrar dados
 IO_printf ( "\nCopia\n" );
 printIntArray ( n, other );
 } // fim se
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
 sumIntArray - Somar valores em arranjo com inteiros.
 @return - soma dos valores
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
int sumIntArray ( int n, int array [ ] )
{
// definir dados locais
 int soma = 0;
 int x = 0;
// mostrar valores no arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // somar valor
 soma = soma + array [ x ];
 } // fim repetir
// retornar resposta
 return ( soma );
} // sumIntArray ( )
/**
 Method06.
*/
void method06 ( )
{
// definir dados
 int n = 0; // quantidade de valores
// identificar
 IO_id ( "EXEMPLO0806 - Method06 - v1.0" );
// ler a quantidade de dados
 n = freadArraySize ( "ARRAY1.TXT" );
 if ( n <= 0 )
 {
 IO_printf ( "\nERRO: Valor invalido.\n" );
 }
 else
 {
 // definir armazenador
 int array [ n ];
 // ler dados
 freadIntArray ( "ARRAY1.TXT", n, array );
 // mostrar a soma dos valores no arranjo
 IO_printf ( "\nSoma = %d\n", sumIntArray ( n, array ) );
 } // fim se
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
 IO_id ( "EXEMPLO0806 - Programa - v1.0" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - Mostrar arranjo com valores inteiros" );
 IO_println ( " 2 - Ler arranjo com valores inteiros" );
 IO_println ( " 3 - Gravar arranjo com valores inteiros" );
 IO_println ( " 4 - Ler arranjo com valores inteiros" );
 IO_println ( " 5 - Copiar arranjo com valores inteiros" );
 IO_println ( " 6 - Somar valores em arranjo com inteiros" );
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