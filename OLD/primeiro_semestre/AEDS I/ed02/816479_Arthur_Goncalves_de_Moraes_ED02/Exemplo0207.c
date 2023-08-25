/*
 Exemplo0207 - v0.7.
 Author: Arthur Goncalves de Moraes 816479

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0207 exemplo0207.c
 Windows: gcc -o exemplo0207 exemplo0207.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0207
 Windows: exemplo0207
*/
// dependencias
#include "io.h" // para definicoes proprias
/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main()
{
    // definir dado
    char x = '_'; // definir variavel com valor inicia
                  // identificar
    IO_id("EXEMPLO0207 - Programa - v0.7");
    // ler do teclado
    x = IO_readchar("Entrar com um caractere: ");
   // testar valor
 if ( ! ( ( 'a' <= x && x <= 'z' ) || // NAO (minuscula OU
 ( 'A' <= x && x <= 'Z' ) ) ) // maiuscula)
 {
 IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
 }
 else
 {
 IO_printf ( "%s (%c)\n", "Letra", x );
 } // fim se
             
              // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 10
d.) -1
e.) 100
  
  ---------------------------------------------- historico
  Versao
   0.1 esboco
   0.2
   0.3
   0.4
   0.5
   0.6
   0.7
  ---------------------------------------------- testes
  Versao Teste
   0.1 01. ( OK ) identificacao de programa
   0.2 02. ( OK )
   0.3 01. ( OK )
   0.4 01, ( OK )
   0.5 01. ( OK )
   0.6 01. ( OK )
   0.7 01. ( OK )
  */