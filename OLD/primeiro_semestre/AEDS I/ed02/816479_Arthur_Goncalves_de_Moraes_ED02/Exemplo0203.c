/*
 Exemplo0203 - v0.3.
 Author: Arthur Goncalves de Moraes 816479
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0203 exemplo0203.c
 Windows: gcc -o exemplo0203 exemplo0203.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0203
 Windows: exemplo0203
*/
// dependencias
#include "io.h" // para definicoes proprias
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// identificar
 IO_id ( "EXEMPLO0203 - Programa - v0.3" );
// ler do teclado
 x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
 if ( x == 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
 if ( x > 0 )
 {
 IO_printf ( "%s (%d)\n", "Valor maior que zero", x );
 }
 else
 {
 IO_printf ( "%s (%d)\n", "Valor menor que zero", x );
 } // fim se
} // fim se
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 5
c.) -5
---------------------------------------------- historico
Versao
 0.1 esboco
 0.2
 0.3
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
 0.2 02. ( OK )
 0.3 01. ( OK )
*/