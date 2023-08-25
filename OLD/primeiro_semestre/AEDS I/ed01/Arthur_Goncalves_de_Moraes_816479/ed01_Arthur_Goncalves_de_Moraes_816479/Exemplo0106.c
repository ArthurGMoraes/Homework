/*
 Exemplo0106- v0.6. - __ / __ / _____
 Author:Arthur Goncalves de Moraes 816479
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0106 exemplo0106.c
 Windows: gcc -o exemplo0106 exemplo0106.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0106
 Windows: exemplo0106
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres
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
  int x = 0; // definir variavel com valor inicial
 int y = 0; // definir variavel com valor inicial
 int z = 0; // definir variavel com valor inicial
 int *py = &y; // definir acesso a y via endereco
// identificar
 printf ( "%s\n", "Exemplo0106 - Programa = v0.6" );
 printf ( "%s\n", "Autor: Arthur Goncalves de Moraes" );
 printf ( "\n" ); // mudar de linha
// mostrar valor inicial
printf ( "%s%d\n", "x = ", x );
// OBS.: O formato para caracteres -> %s
 printf ( "&%s%p\n", "x = ", &x );
printf ( "%s%i\n" , "y = ", y );
// OBS.: O formato para int -> %d (ou %i)
// ler do teclado
 printf ( "Entrar com um valor inteiro: " );
 scanf ( "%d", &x);
// OBS.: indicar endereco &
// O tamanho do valor NAO devera' ultrapassar 80 símbolos.
 getchar ( ); // OBS.: Limpar a entrada de dados
 printf ( "Entrar com outro valor inteiro: " );
 scanf ( "%i", py );
// OBS.: Não e' necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados

 // operar valores
 z = x * y; // guardar em z o produto de x por y

// mostrar valor resultante
 printf ( "%s(%i)*(%i) = (%d)\n", "z = ", x, y, z );

// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 3 e 5
b.) -3 e 5
c.) -3 e -5
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
 0.2 mudanca de versao
 0.3
 0.4
 0.5
 0.6
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
*/
