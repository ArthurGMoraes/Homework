/*
 Exercicios  
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
 if (z<0)
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

void method01 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0911 - Method01 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 printDoubleMatrix ( i, j, negativeMatrix );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

void fprintDoubleMatrix ( chars fileName, int rows, int columns, double matrix[ ][columns] )
{
// definir dados locais
 FILE* arquivo = fopen ( fileName, "wt" );
 int x = 0;
 int y = 0;
// gravar quantidade de dados
 IO_fprintf ( arquivo, "%d\n", rows );
 IO_fprintf ( arquivo, "%d\n", columns );
// gravar valores no arquivo
 for ( x=0; x<rows; x=x+1 )
 {
 for ( y=0; y<columns; y=y+1 )
 {
 // gravar valor
 IO_fprintf ( arquivo, "%lf\n", matrix [ x ][ y ] );
 } // fim repetir
 } // fim repetir
// fechar arquivo
 fclose ( arquivo );
} // fprintDoubleMatrix ( )

void freadDoubleMatrix ( chars fileName, int rows, int columns, double matrix[ ][columns] )
{
// definir dados locais
 int x = 0;
 int y = 0;
 double z = 0;
 FILE* arquivo = fopen ( fileName, "rt" );
// ler a quantidade de dados
 IO_fscanf ( arquivo, "%d", &x );
 IO_fscanf ( arquivo, "%d", &y );
 if ( rows <= 0 || rows > x ||
 columns <= 0 || columns > y )
 {
 IO_println ( "ERRO: Valor invalido." );
 }
 else
 {
 // ler e guardar valores em arranjo
 x = 0;
 while ( ! feof ( arquivo ) && x < rows )
 {
 y = 0;
 while ( ! feof ( arquivo ) && y < columns )
 {
 // ler valor
 IO_fscanf ( arquivo, "%lf", &z );
 // guardar valor
 matrix [ x ][ y ] = z;
 // passar ao proximo
 y = y+1;
 } // fim repetir
 // passar ao proximo
 x = x+1;
 } // fim repetir
 } // fim se
// fechar arquivo
 fclose ( arquivo );
} // freadDoubleMatrix ( )

/**
 Method02.
*/
void method02 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0912 - Method02 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 fprintDoubleMatrix ("MATRIX_01.TXT", i, j, negativeMatrix );
 freadDoubleMatrix ("MATRIX_01.TXT", i, j, negativeMatrix );
 printDoubleMatrix ( i, j, negativeMatrix );
 }
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

void printDiagonalDoubleMatrix (int rows, int columns, double matrix [][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
      if (x == y) 
      {
        printf("%lf\t ", matrix[x][y]);
      }
    }
   }
}

/**
 Method03.
*/
void method03 (void)
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0) && (i == j))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0913 - Method03 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 printDiagonalDoubleMatrix ( i, j, negativeMatrix );
 }
 else
 {
   printf ("A matriz nao e' quadrada\n");
 }
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

void printSDiagonalDoubleMatrix (int rows, int columns, double matrix [][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
      if (x + y == rows - 1) 
      {
        printf("%lf\t ", matrix[x][y]);
      }
    }
   }
}
/**
 Method04.
*/
void method04 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0) && (i == j))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0914 - Method04 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 printSDiagonalDoubleMatrix ( i, j, negativeMatrix );
 }
 else
 {
   printf ("A matriz nao e' quadrada\n");
 }
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

void printLDTriangleDoubleMatrix (int rows, int columns, double matrix [][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
      if ((x == y) || (x > y) ) 
      {
        printf("%lf\t ", matrix[x][y]);
      }
    }
   }
}
/**
 Method05.
*/
void method05 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0) && (i == j))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0915 - Method05 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 printLDTriangleDoubleMatrix ( i, j, negativeMatrix );
 }
 else
 {
   printf ("A matriz nao e' quadrada\n");
 }
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

void printLUTriangleDoubleMatrix (int rows, int columns, double matrix [][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
      if ((x == y) || (x < y) ) 
      {
        printf("%lf\t ", matrix[x][y]);
      }
    }
   }
}
/**
 Method06.
*/
void method06 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0) && (i == j))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0916 - Method06 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 printLUTriangleDoubleMatrix ( i, j, negativeMatrix );
 }
 else
 {
   printf ("A matriz nao e' quadrada\n");
 }
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

void printSLDTriangleDoubleMatrix (int rows, int columns, double matrix [][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
      if ((x + y >= rows - 1)) 
      {
        printf("%lf\t ", matrix[x][y]);
      }
    }
   }
}
/**
 Method07.
*/
void method07 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0) && (i == j))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0917 - Method07 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 printSLDTriangleDoubleMatrix ( i, j, negativeMatrix );
 }
 else
 {
   printf ("A matriz nao e' quadrada\n");
 }
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

void printSLUTriangleDoubleMatrix (int rows, int columns, double matrix [][columns])
{
   int x = 0;
   int y = 0;
   for (x = 0; x < rows; x = x + 1) 
   {
    for (y = 0; y < columns; y = y + 1) 
    {
      if ((x + y <= rows - 1)) 
      {
        printf("%lf\t ", matrix[x][y]);
      }
    }
   }
}
/**
 Method08.
*/
void method08 ( )
{
// definir dados
 int i = 0; // quantidade de valores
 int j = 0;
 printf("Quantas linhas: ");
 scanf("%d", &i);
 printf("Quantas colunas: ");
 scanf("%d", &j);
 if((i <= 10 && i > 0) && (j <= 10 && j > 0) && (i == j))
 {
 double negativeMatrix [ i ][ j ];
// identificar
 IO_id ( "EXEMPLO0918 - Method08 - v1.0" );
// ler dados
 readNegativeDoubleMatrix ( i, j, negativeMatrix );
// mostrar dados
 IO_printf ( "\n" );
 printSLUTriangleDoubleMatrix ( i, j, negativeMatrix );
 }
 else
 {
   printf ("A matriz nao e' quadrada\n");
 }
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{
// identificar
 IO_id ( "EXERCICIO09 - Method09 - v1.0" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "EXERCICIO10 - Method10 - v1.0" );
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
 IO_id ( "EXERCICIOS - Programa - v1.0" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - Ler e mostrar matriz real com valores negativos" );
 IO_println ( " 2 - Gravar uma matriz real em arquivo." );
 IO_println ( " 3 - Mostrar a diagonal principal de uma matriz quadrada" );
 IO_println ( " 4 - Mostrar a diagonal secundaria de uma matriz quadrada" );
 IO_println ( " 5 - Mostrar o triangulo inferior de uma matriz quadrada" );
 IO_println ( " 6 - Mostrar o triangulo superior de uma matriz quadrada" );
 IO_println ( " 7 - Mostrar o triangulo inferior secundario de uma matriz quadrada" );
 IO_println ( " 8 - Mostrar o triangulo superior secundario de uma matriz quadrada" );
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