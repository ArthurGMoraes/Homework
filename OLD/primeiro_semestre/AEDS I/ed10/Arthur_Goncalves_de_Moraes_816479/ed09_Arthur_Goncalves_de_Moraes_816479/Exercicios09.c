/*
 Exercicios - v1.0. 
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

void printDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
// definir dado local
 int x = 0;
 int y = 0;
// mostrar valores na matriz
 for ( x=0; x<rows; x=x+1 )
 {
 for ( y=0; y<columns; y=y+1 )
 {
 // mostrar valor
 IO_printf ( "%3lf\t", matrix [ x ][ y ] );
 } // fim repetir
 IO_printf ( "\n" );
 } // fim repetir
} // printDoubleMatrix ( )

void readNegativeDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 double z = -1;
 chars text = IO_new_chars ( STR_SIZE );
// ler e guardar valores em arranjo
 for ( x=0; x<rows; x=x+1 )
 {
 for ( y=0; y<columns; y=y+1 )
 {
 // ler valor
    strcpy ( text, STR_EMPTY );
    z = IO_readdouble ( IO_concat (
    IO_concat ( IO_concat ( text, IO_toString_f ( x ) ), ", " ),
    IO_concat ( IO_concat ( text, IO_toString_f ( y ) ), " : " ) ) );
 // guardar valor
 if (z<=0)
 {
    matrix [ x ][ y ] = z;
 } else {
    printf("Somente valores negativos\n");
    strcpy ( text, STR_EMPTY );
    z = IO_readdouble ( IO_concat (
    IO_concat ( IO_concat ( text, IO_toString_f ( x ) ), ", " ),
    IO_concat ( IO_concat ( text, IO_toString_f ( y ) ), " : " ) ) );
    matrix [ x ][ y ] = z;
 }
 } // fim repetir
 } // fim repetir
} // readNegativeDoubleMatrix ( )

bool allZerosLTriangleDoubleMatrix (int rows, int columns, double matrix[][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
        //printf ("%lf\t",matrix[x][y]);
        if ( (x > y) ) 
        {
        if (matrix[x][y] != 0.0)
        {
            return 0;
        }
       }
    }
    }

   return 1;
}

void method01 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 bool result = false;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0919 - Method01 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 result = allZerosLTriangleDoubleMatrix( i, j, negativeMatrix );
 if (result == 1)
 {
    printf("Tudo zero");
 }
 else
 {
    printf("Nem todos sao zero");
 }
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

bool allZerosUTriangleDoubleMatrix (int rows, int columns, double matrix[][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
        //printf ("%lf\t",matrix[x][y]);
        if ( (x < y) ) 
        {
        if (matrix[x][y] != 0.0)
        {
            return 0;
        }
       }
    }
    }

   return 1;
}

/**
 Method02.
*/
void method02 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 bool result = false;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0920 - Method02 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 result = allZerosUTriangleDoubleMatrix( i, j, negativeMatrix );
 if (result == 1)
 {
    printf("Tudo zero");
 }
 else
 {
    printf("Nem todos sao zero");
 }
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

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
 IO_id ( "EXERCICIOS - Programa - v1.0" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - Inforamar se todos os valores abaixo da diagonal principal sao 0" );
 IO_println ( " 2 - Inforamar se todos os valores acima da diagonal principal sao 0" );
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
 default:
 IO_println ( "ERRO: Valor invalido." );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )