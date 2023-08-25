/*
 Exemplo0107 - v0.7. - __ / __ / _____
 Author:Arthur Goncalves de Moraes 816479
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0107 exemplo0107.c
 Windows: gcc -o exemplo0107 exemplo0107.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0107
 Windows: exemplo0107
  Para alguns compiladores poderá ser necessário indicar a inclusão da biblioteca no comando para compilar:
 gcc -o exemplo0107 exemplo0107.c -lm
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> // para valores logicos
#include <string.h> // para cadeias de caracteres
#include <math.h> // para funcoes matemáticas: pow( ), sqrt( ), sin( ), cos( ) ...
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dados
 double x = 0.0; // definir variavel com valor inicial
 double y = 0.0; // definir variavel com valor inicial
 double z = 0.0; // definir variavel com valor inicial
// identificar
 printf ( "%s\n", "EXEMPLO0107 - Programa - v0.0" );
 printf ( "%s\n", "Autor: ______________________" );
 printf ( "\n" ); // mudar de linha
// mostrar valores iniciais
 printf ( "%s%lf\n", "x = ", x );
 printf ( "%s%lf\n", "y = ", y );
// OBS.: O formato para int -> %d (ou %i)
// ler do teclado
 printf ( "Entrar com um valor real: " );
 scanf ( "%lf", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
 printf ( "Entrar com outro valor real: " );
 scanf ( "%lf", &y );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// operar valores
 z = pow( x, y ); // elevar a base (x) 'a potencia (y)
// mostrar valor resultante
 printf ( "%s(%lf) elevado a (%lf) = (%lf)\n", "z = ", x, y, z );
// operar valores
 x = pow( z, 1.0/y ); // elevar a base (x) 'a potencia inversa de (y) (raiz)
// mostrar valor resultante
 printf ( "%s(%lf) elevado a (1/%lf) = (%lf)\n", "z = ", z, y, x );
// operar valores
 z = sqrt( x ); // raiz quadrada do argumento
// mostrar valor resultante
 printf ( "%sraiz(%lf) = (%lf)\n", "z = ", x, z );
// encerrar
 printf ( "\n\nApertar ENTER para terminar.\n" );
 fflush ( stdin ); // limpar a entrada de dados
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 2.0 e 3.0
b.) 3.0 e 2.0
c.) -3.0 e 2.0
d.) -2.0 e -3.0
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
 0.2 mudanca de versao
 0.3
 0.4
 0.5
 0.6
 0.7
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
*/
