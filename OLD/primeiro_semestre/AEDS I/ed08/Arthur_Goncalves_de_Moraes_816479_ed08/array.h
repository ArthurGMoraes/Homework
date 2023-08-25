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
 isAllZeros - Testar valores inteiros em arranjo.
 @return - true, se todos os dados forem iguais a zero;
 false, caso contrario
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
bool isAllZeros ( int n, int array [ ] )
{
// definir dados locais
 bool result = true;
 int x = 0;
// mostrar valores no arranjo
 x=0; 
 while ( x<n && result )
 {
 // testar valor
 result = result && ( array [ x ] == 0 );
 // passar ao proximo
 x = x + 1;
 } // fim repetir
// retornar resposta
 return ( result );
} // isAllZeros ( )

/**
 addIntArray - Somar arranjos com inteiros.
 @return - arranjo ocm a soma resultante
 @param n - quantidade de valores
 @param array3 - soma de grupo de valores inteiros
 @param array1 - grupo de valores inteiros (1)
 @param k - constante para multiplicar o segundo arranjo
 @param array2 - grupo de valores inteiros (2)
*/
void addIntArray ( int n, int array3 [ ], 
 int array1 [ ], int k, int array2 [ ] )
{
// definir dados locais
 int x = 0;
// mostrar valores no arranjo
 for ( x=0; x<n; x=x+1 )
 {
 // somar valor
 array3 [ x ]= array1 [ x ] + k * array2 [ x ];
 } // fim repetir
} // addIntArray ( )


/**
 isEqual - Testar arranjos com inteiros sao iguais.
 @return - true, se todos os dados forem iguais;
 false, caso contrario
 @param n - quantidade de valores
 @param array1 - grupo de valores inteiros (1)
 @param array2 - grupo de valores inteiros (2)
*/
bool isEqual ( int n, int array1 [ ], int array2 [ ] )
{
// definir dados locais
 bool result = true;
 int x = 0;
// mostrar valores no arranjo
 x = 0;
 while ( x<n && result )
 {
 // testar valor
 result = result && ( array1 [ x ] == array2 [ x ] );
 // passar ao proximo
 x = x + 1;
 } // fim repetir
// retornar resposta
 return ( result );
} // isEqual ( )

/**
 searchArray - Procurar valor em arranjo com inteiros.
 @return - true, se encontrar;
 false, caso contrario
 @param value - valor a ser procurado
 @param n - quantidade de valores
 @param array - grupo de valores inteiros
*/
bool searchArray ( int value, int n, int array [ ] )
{
// definir dados locais
 bool result = false;
 int x = 0;
// mostrar valores no arranjo
 x = 0;
 while ( x<n && ! result )
 {
 // testar valor
 result = ( value == array [ x ] );
 // passar ao proximo
 x = x + 1;
 } // fim repetir
// retornar resposta
 return ( result );
} // searchArray ( )
