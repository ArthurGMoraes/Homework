/*
 Exemplo0103 - v0.3. - __ / __ / _____
 Author:Arthur Goncalves de Moraes 816479
 
 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0103 exemplo0103.c
 Windows: gcc -o exemplo0103 exemplo0103.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0103
 Windows: exemplo0103
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dado
 char x = 'A'; // definir variavel com valor inicial
// identificar
 printf ( "%s\n", "Exemplo0103 - Programa = v0.3" );
 printf ( "%s\n", "Autor: Arthur Goncalves de Moraes" );
 printf ( "\n" ); // mudar de linha
// mostrar valor inicial
 printf ( "%s%c\n" , "x = ", x );
// OBS.: O formato para char -> %c
 printf ( "&%s%p\n", "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
 printf ( "Entrar com um caractere: " );
 scanf ( "%c", &x );
// OBS.: Necessario indicar o endereco -> &
 getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
 printf ( "%s%c\n", "x = ", x );
// encerrar
 printf ( "\n\nApertar ENTER para terminar." );
 getchar( ); // aguardar por ENTER
 return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
 0.2 mudanca de versao
 0.3
---------------------------------------------- testes
Versao Teste
0.1 01. ( ok ) identificacao de programa
leitura e exibicao de inteiro
0.2 01.(ok) identificacao de programa
leitura e exibicao de real
0.3 01.(ok)
*/
