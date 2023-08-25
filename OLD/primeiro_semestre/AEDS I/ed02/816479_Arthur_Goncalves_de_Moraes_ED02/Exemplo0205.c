/*
 Exemplo0205 - v0.5.
 Author: Arthur Goncalves de Moraes 816479

 Para compilar em terminal (janela de comandos):
 Linux : gcc -o exemplo0205 exemplo0205.c
 Windows: gcc -o exemplo0205 exemplo0205.c
 Para executar em terminal (janela de comandos):
 Linux : ./exemplo0205
 Windows: exemplo0205
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
    IO_id("EXEMPLO0205 - Programa - v0.5");
    // ler do teclado
    x = IO_readchar("Entrar com um caractere: ");
    // testar valor
    if (('a' <= x) && (x <= 'z'))
    {
        IO_printf("%s (%c)\n", "Letra minuscula", x); 
    }
    else
    {
        IO_printf("%s (%c)\n", "Valor diferente de minuscula", x);
        if (('A' <= x) && (x <= 'Z'))
        {
            IO_printf("%s (%c)\n", "Letra maiuscula", x);
        }
        else
        {
            if (('0' <= x) && (x <= '9'))
            {
                IO_printf("%s (%c)\n", "Algarismo", x);
            }
            else
            {
                IO_printf("%s (%c)\n", "Valor diferente de algarismo", x);
            } // fim se
        }     // fim se
    }         // fim se
             
              // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) a
  b.) A
  c.) 0
  d.) #
  
  ---------------------------------------------- historico
  Versao
   0.1 esboco
   0.2
   0.3
   0.4
   0.5
  ---------------------------------------------- testes
  Versao Teste
   0.1 01. ( OK ) identificacao de programa
   0.2 02. ( OK )
   0.3 01. ( OK )
   0.4 01, ( OK )
   0.5 01. ( OK )
  */