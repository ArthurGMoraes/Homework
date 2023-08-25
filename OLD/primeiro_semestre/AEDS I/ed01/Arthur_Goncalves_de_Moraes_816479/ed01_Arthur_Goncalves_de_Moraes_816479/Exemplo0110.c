/*
 Exemplo0110 - v1.0. - __ / __ / _____
 Author:Arthur Goncalves de Moraes 816479
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0110 exemplo0110.c
 Windows: gcc -o exemplo0110 exemplo0110.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0110
 Windows: exemplo0110
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres: strcat( ), strcpy( ), strdup( ), strlen( )
#include <math.h> // para funcoes matematicas
#include "io.h" // para definicoes proprias ( na mesma pasta )

// Nota: Em alguns compiladores pode haver problemas
// com relacao a essa biblioteca, caso acontecer
// considerar o uso de definicoes alternativas.
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados
 int x = 5 ; // definir variavel com valor inicial
 double y = 3.5; // definir variavel com valor inicial
 char z = 'A'; // definir variavel com valor inicial
 bool w = TRUE; // definir variavel com valor inicial
 chars a = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
 chars b = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
 chars c = IO_new_chars(STR_SIZE); // definir variavel com tamanho inicial
// identificar
 IO_id ( "EXEMPLO0110 - Programa - v1.0" );
// concatenar (juntar) cadeias de caracteres
 strcpy ( a, "abc" ); // atribuir a variavel (a) o valor constante ("abc")
 strcpy ( b, "def" ); // OBS.: a atribuicao de cadeia de caracteres NAO usa (=)
 IO_printf ( "\na = %s b = %s\n", a, b );
 c = IO_concat ( a, b ); // alternativa melhor para a funcao nativa strcat (a,b)
 IO_printf ( "\nc = [%s]+[%s] = [%s]\n", a, b, c );
 strcpy ( a, "c = " );
 strcpy ( c, STR_EMPTY ); // limpar a cadeia de caracteres
 IO_printf ( "%s\n", IO_concat ( a, IO_toString_c ( z ) ) );
 IO_println ( IO_concat ( "x = ", IO_toString_d ( x ) ) );
 IO_println ( IO_concat ( "w = ", IO_toString_b ( w ) ) );
 strcpy ( b, STR_EMPTY );
 IO_print ( "y = " );
 IO_print ( IO_concat ( b, IO_toString_f ( y ) ) );
 IO_print ( "\n" );
 z = IO_readchar ( "char = " );
 IO_println ( IO_concat ( a, IO_toString_c ( z ) ) );
 y = IO_readdouble ( "double = " );
 IO_println ( IO_concat ( a, IO_toString_f ( y ) ) );
 x = IO_readint ( "int = " );
 IO_println ( IO_concat ( a, IO_toString_d ( x ) ) );
 w = IO_readbool ( "bool = " );
 IO_println ( IO_concat ( a, IO_toString_b ( w ) ) );
 b = IO_readstring ( "chars = " );
 IO_println ( IO_concat ( a, b ) );
 b = IO_readln ( "line = " );
 IO_println ( IO_concat ( a, b ) );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
// chamar metodo para pausar
 return ( 0 ); // voltar ao SO (sem erros)

} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes

---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
 0.2 mudanca de versao
 0.3
 0.4
 0.5
 0.6
 0.7
 0.8
 0.9
 1.0
---------------------------------------------- testes
Versao Teste
0.1 01. ( ok ) identificacao de programa
leitura e exibicao de inteiro
0.2 01.(ok) identificacao de programa
leitura e exibicao de real
0.3 01.(ok)
0.4 01.(ok)
0.5 01.(ok)
0.6 01.(ok)
0.7 01.(ok)
0.8 01.(ok)
0.9 01.(ok)
1.0 01.(ok)
*/
