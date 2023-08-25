/*
 Exemplo0104 - v0.4. - __ / __ / _____
 Author:Arthur Goncalves de Moraes 816479
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0104 exemplo0104.c
 Windows: gcc -o exemplo0104 exemplo0104.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0104
 Windows: exemplo0104
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
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
// definir dado
 bool x = false; // definir variavel com valor inicial
 int y = 0;
// identificar
 printf ( "%s\n", "Exemplo0104 - Programa = v0.4" );
 printf ( "%s\n", "Autor: Arthur Goncalves de Moraes" );
 printf ( "\n" ); // mudar de linha
// mostrar valor inicial
 printf ( "%s%d\n" , "x = ", x );
// OBS.: O formato para equivalente inteiro -> %d
 printf ( "&%s%p\n", "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
 printf ( "Entrar com um valor logico: " );
 scanf ( "%d", &y );
// OBS.: 0=false
 getchar ( ); // OBS.: Limpar a entrada de dados
 //garantir valor logico no intervalo [0:1]
 x = (y!=0);
// mostrar valor lido
 printf ( "%s%d\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 1
b.) 0
c.) true
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
 0.2 mudanca de versao
 0.3
 0.4
---------------------------------------------- testes
Versao Teste
0.1 01. ( ok ) identificacao de programa
leitura e exibicao de inteiro
0.2 01.(ok) identificacao de programa
leitura e exibicao de real
0.3 01.(ok)
0.4 01.(ok)
*/
