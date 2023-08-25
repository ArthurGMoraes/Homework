/*
 Exercicios - v0.1. 
 Author: Arthur Goncalves de Moraes 816479
 
*/
// dependencias
#include "io.h" // para definicoes proprias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )
/**
 Method01 - Repeticao para ler certa quantidade de valores.
*/
void method01 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
// identificar
 IO_id ( "Exercicios - Method01 - v0.1" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat ( 
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // passar ao proximo valor
 controle = controle + 1;
 } // fim repetir
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )


/**
 Funcao para determinar se valor inteiro e' positivo.
 @return true, se positivo; false, caso contrario
 @param x - valor a ser testado
*/
bool positive ( int x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( x > 0 )
 {
 result = true;
 } // fim se
 return ( result );
} // fim positive ( )


/**
 Method02 - Ler valores e contar positivos.
*/
void method02 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Exercicios - Method02 - v0.1" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( positive ( valor ) )
 {
 contador = contador + 1;
 } // fim se
 // passar ao proximo valor
 controle = controle + 1;
 } // fim repetir
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
 Funcao para determinar se valor inteiro pertence a intervalo aberto.
 @return true, se pertencer; false, caso contrario
 @param x - valor a ser testado
*/
bool belongsTo ( int x, int inferior, int superior )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( inferior < x && x < superior )
 {
 result = true;
 } // fim se
 return ( result );
} // fim belongsTo ( )


/**
 Method03 - Ler valores e contar positivos menores que 100.
*/
void method03 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Exercicios - Method03 - v0.1" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo
 if ( belongsTo ( valor, 0, 100 ) )
 {
 contador = contador + 1;
 } // fim se
 // passar ao proximo valor
 controle = controle + 1;
 } // fim repetir
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
 Funcao para determinar se valor inteiro e' par.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool even ( int x )
{
// definir dado local
 bool result = false;
// testar a condicao ( resto inteiro (%) da divisao por 2 igual a zero )
 if ( x % 2 == 0 )
 {
 result = true;
 } // fim se
 return ( result );
} // fim even ( )


/**
 Method04 - Ler valores e contar positivos menores que 100 e pares.
*/
void method04 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
// identificar
 IO_id ( "Exercicios - Method04 - v0.1" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 if ( belongsTo ( valor, 0, 100 ) && even ( valor ) )
 {
 contador = contador + 1;
 } // fim se
 // passar ao proximo valor
 controle = controle + 1;
 } // fim repetir
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )


/**
 Method05 - Ler valores e contar positivos menores que 100 e pares (alternativo).
*/
void method05 ( )
{
// definir dado
 int quantidade = 0;
 int valor = 0;
 int controle = 0;
 int contador = 0;
 bool ok = false;
// identificar
 IO_id ( "Exercicios - Method05 - v0.1" );
// ler do teclado
 quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
 controle = 1;
 while ( controle <= quantidade )
 {
 // ler valor do teclado
 valor = IO_readint ( IO_concat (
 IO_concat ( "", IO_toString_d ( controle ) ),
 ": " ) );
 // testar e contar se valor for positivo menor que 100 e par
 ok = belongsTo ( valor, 0, 100 );
 ok = ok && even ( valor );
 if ( ok )
 {
 contador = contador + 1;
 } // fim se
 // passar ao proximo valor
 controle = controle + 1;
 } // fim repetir
// mostrar a quantidade de valores positivos
 IO_printf ( "%s%d\n", "Positivos menores que 100 e pares = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
 Funcao para determinar se caractere e' letra minuscula.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isLowerCase ( char x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( 'a' <= x && x <= 'z' )
 {
 result = true;
 } // fim se
 return ( result );
} // fim isLowerCase ( )
/**
 Method06 - Ler palavra e contar letras minusculas.
*/
void method06 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Exercicios - Method06 - v0.1" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 contador = contador + 1;
 } // fim se
 } // fim repetir
// mostrar a quantidade de minusculas
 IO_printf ( "%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
 Method07 - Ler palavra, contar e mostrar letras minusculas.
*/
void method07 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Exercicios - Method07 - v0.1" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar se caractere e' letra minuscula
 if ( isLowerCase ( simbolo ) )
 {
 // mostrar
 IO_printf ( "%c ", simbolo );
 // contar
 contador = contador + 1;
 } // fim se
 } // fim repetir
// mostrar a quantidade de minusculas
 IO_printf ( "\n%s%d\n", "Minusculas = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )


/**
 Method08 - Ler palavra, contar e mostrar letras minusculas (alternativo).
*/
void method08 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
 chars minusculas = IO_new_chars ( STR_SIZE );
 strcpy ( minusculas, STR_EMPTY ); // vazio
// identificar
 IO_id ( "Exercicios - Method08 - v0.1" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar as letras minusculas de uma palavra
 if ( isLowerCase ( simbolo ) )
 {
 // concatenar simbolo encontrado
 minusculas = IO_concat ( minusculas, IO_toString_c ( simbolo ) );
 // contar
 contador = contador + 1;
 } // fim se
 } // fim repetir
// mostrar a quantidade de minusculas
 IO_printf ( "\n%s%d [%s]\n", "Minusculas = ", contador, minusculas );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )


/**
 Funcao para determinar se caractere e' digito.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isDigit ( char x )
{
// definir dado local
 bool result = false;
// testar a condicao
 if ( '0' <= x && x <= '9' )
 {
 result = true;
 } // fim se
 return ( result );
} // fim isDigit ( )
/**
 Method09 - Ler palavra e contar os algarismos.
*/
void method09 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 int contador = 0;
// identificar
 IO_id ( "Exercicios - Method09 - v0.1" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com caracteres: " );
// determinar a quantidade de simbolos
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar os algarismos em uma cadeia de caracteres
 if ( isDigit ( simbolo ) )
 {
 // mostrar
 IO_printf ( "%c ", simbolo );
 // contar
 contador = contador + 1;
 } // fim se
 } // fim repetir
// mostrar a quantidade de digitos
 IO_printf ( "\n%s%d\n", "Algarismos = ", contador );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
 Funcao para determinar se caractere e' digito.
 @return true, se par; false, caso contrario
 @param x - valor a ser testado
*/
bool isADigit ( char x )
{
 return ( '0' <= x && x <= '9' );
} // fim isADigit ( )
/**
 Funcao para concatenar 'a cadeia de caracteres mais um digito.
 @return cadeia de caracteres acrescida de mais um digito
 @param digits - cadeia de caracteres
 @param digit - simbolo a ser acrescentado 'a cadeia de caracteres
*/
chars concatADigit ( chars string, char digit )
{
 return ( IO_concat ( string, IO_toString_c ( digit ) ) );
} // fim concatADigit ( )
/**
 Method10.
*/
void method10 ( )
{
// definir dado
 chars palavra = IO_new_chars ( STR_SIZE );
 int tamanho = 0;
 int posicao = 0;
 char simbolo = '_';
 chars digitos = IO_new_chars ( STR_SIZE );
 strcpy ( digitos, STR_EMPTY ); // vazio
// identificar
 IO_id ( "Exercicios - Method10 - v0.1" );
// ler do teclado
 palavra = IO_readstring ( "Entrar com uma palavra: " );
// determinar a quantidade de simbolos na palavra
 tamanho = strlen ( palavra );
// repetir para a quantidade de vezes informada
 for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
 {
 // isolar um simbolo por vez
 simbolo = palavra [ posicao ];
 // testar e contar os algarismos em uma cadeia de caracteres
 if ( isADigit ( simbolo ) )
 {
 // concatenar simbolo encontrado
 digitos = concatADigit ( digitos, simbolo );
 } // fim se
 } // fim repetir
// mostrar a quantidade de digitos
 IO_printf ( "\n%s%d [%s]\n", "Algarismos = ", strlen( digitos ), digitos );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )


void Exemplo0411(){
    double valor1, valor2, teste = 0;
    int quantidade = 0;
    int dentro = 0;
    int fora = 0;
    valor1 = IO_readdouble("Primeiro limite: ");
    valor2 = IO_readdouble("Segundo limite: ");
    quantidade = IO_readint("Quantos numeros serao testados? ");
    while (quantidade>0){
    teste = IO_readdouble("Insira um numero: ");
    if(valor1<valor2 && (teste>valor1 && teste<valor2)){
        dentro = dentro + 1;
      //  printf("%d dentro\n", dentro);
      } else if(valor1<valor2 && !(teste>valor1 && teste<valor2)){
        fora = fora + 1;
      //  printf("%d fora\n", fora);
      }

      if(valor1>valor2 && (teste<valor1 && teste>valor2)){
        dentro = dentro + 1;
       // printf("%d dentro\n", dentro);
      } else if(valor1>valor2 && !(teste<valor1 && teste>valor2)){
        fora = fora + 1;
        // printf("%d fora\n", fora);
      }
      quantidade = quantidade - 1;
      }
    printf("\n%d fora\n", fora);
    printf("%d dentro\n", dentro);
    IO_pause ( "Apertar ENTER para continuar" );

    }
  
void Exemplo0412( ){
    char palavra[80] = "0";
     char simbolo = '0';
     int tamanho = 0;
     int x = 0;
     int maiuscula = 0;
     
     printf ("\nqual a palavra: ");
     scanf( "%s",palavra); getchar();
    
     tamanho = strlen (palavra);
     
     for (x=tamanho-1; x>=0; x=x-1)
     {
         simbolo = palavra [ x ];
         
         
         if ('A' <= simbolo && simbolo<'K')
         {
             printf ("\n %c \n", simbolo);
             maiuscula = maiuscula + 1;
             
         }
    }
       printf ("\nMaiusculas menores que K = %d\n", maiuscula);
        printf("\nApertar ENTER para encerrar");
   getchar();  

}

int contagemK(char* palavra) {
    int count = 0;
    while (*palavra) {
        if (isupper(*palavra) && *palavra < 'K') {
            count++;
        }
      
        palavra++;
    }
    return count;
}
void Exemplo0413( ){
     char palavra[80] = "0";
    
     int contagem = 0;
     printf ("\nqual a palavra: ");
     scanf( "%s", palavra); getchar();
     contagem = contagemK(palavra);
     printf("Numero de maiusculas = %d\n", contagem);
     printf("\nApertar ENTER para encerrar");
   getchar();  
}

char* maiusculasK(char* palavra) {
    char* palavramaius = malloc(80 * sizeof(char));
    palavramaius[0] = '\0';
    char letra = '0';
    int tamanho = strlen(palavra);
    int x = 0;
    for (x = 0; x < tamanho; x++) {
        letra = palavra[x];
        if (letra>='A' && letra < 'K') {
            strncat(palavramaius, &letra, 1);
        }
    }
    return palavramaius;
}

void Exemplo0414() {
    char palavra[80] = "";
    char* maiuscula;
    int tamanho = 0;
    printf("\nqual a palavra: ");
    scanf("%s", palavra);
    getchar();
    tamanho = strlen(palavra);
    maiuscula = maiusculasK(palavra);
    printf("Maiusculas = %s\n", maiuscula);
    
    printf("\nApertar ENTER para encerrar");
    getchar();
}


int numeroK(char* palavra) {
    char* menorK = malloc(80 * sizeof(char));
    menorK[0] = '\0';
    char letra = '0';
    int tamanho = strlen(palavra);
    int x = 0;
    int contagem = 0;
    for (x = 0; x < tamanho; x++) {
        letra = palavra[x];
        if ((letra>='A' && letra < 'K') || (letra>= 'a' && letra<'k')) {
            contagem = contagem + 1;
        }
    }
    return contagem;
}

void Exemplo0415() {
     char palavra[80] = "";
    int menorK = 0;
    int tamanho = 0;
    printf("\nqual a palavra: ");
    scanf("%s", palavra);
    getchar();
    tamanho = strlen(palavra);
    menorK = numeroK(palavra);
    printf("Numero de letras antes de K = %d\n", menorK);
    
    printf("\nApertar ENTER para encerrar");
    getchar();

}


char* menorKk(char* palavra) {
    char* menorK = malloc(80 * sizeof(char));
    menorK[0] = '\0';
    char letra = '0';
    int tamanho = strlen(palavra);
    int x = 0;
    for (x = 0; x < tamanho; x++) {
        letra = palavra[x];
        if ((letra>='A' && letra < 'K') || (letra>= 'a' && letra<'k')) {
            strncat(menorK, &letra, 1);
        }
    }
    return menorK;
}

void Exemplo0416() {
    char palavra[80] = "";
    char* menorK;
    int tamanho = 0;
    printf("\nqual a palavra: ");
    scanf("%s", palavra);
    getchar();
    tamanho = strlen(palavra);
    menorK = menorKk(palavra);
    printf("Letras antes de K = %s\n", menorK);
    
    printf("\nApertar ENTER para encerrar");
    getchar();
}


int impar(char* palavra){
    int numeroImpar = 0;
    char letra = '0';
    int tamanho = strlen(palavra);
    int x = 0;
    for (x = 0; x < tamanho; x++) {
        letra = palavra[x];
        if ((letra >='0' &&  letra <='9')) {
            letra = (int) palavra[x];
            if (letra % 2 != 0) {
                numeroImpar++;
            }
        }
    }
  return numeroImpar;
}



void Exemplo0417() {
    char palavra[80] = "";
    int numImpar = 0;
    
    printf("\nqual a palavra: ");
    scanf("%s", palavra);
    getchar();
    numImpar = impar(palavra);
    printf("Quantidade de numeros impar = %d\n",numImpar );
    
    printf("\nApertar ENTER para encerrar");
    getchar();
}

char* difLetra(char* palavra) {
    char* diferente = malloc(80 * sizeof(char));
    diferente[0] = '\0';
    char letra = '0';
    int tamanho = strlen(palavra);
    int x = 0;
    for (x = 0; x < tamanho; x++) {
        letra = palavra[x];
        if (!((letra>='A' && letra < 'Z') || (letra>= 'a' && letra<'z') || (letra>='0' && letra<='9'))) {
            strncat(diferente, &letra, 1);
        }
    }
    return diferente;
}

void Exemplo0418() {
    char palavra[80] = "";
    char* resultado;
    int tamanho = 0;
    printf("\nqual a palavra: ");
    scanf("%s", palavra);
    getchar();
    tamanho = strlen(palavra);
    resultado = difLetra(palavra);
    printf("Diferente de alfanumerico = %s\n", resultado);
    
    printf("\nApertar ENTER para encerrar");
    getchar();
}


char* alfa(char* palavra) {
    char* igual = malloc(80 * sizeof(char));
    igual[0] = '\0';
    char letra = '0';
    int tamanho = strlen(palavra);
    int x = 0;
    for (x = 0; x < tamanho; x++) {
        letra = palavra[x];
        if ((letra>='A' && letra < 'Z') || (letra>= 'a' && letra<'z') || (letra>='0' && letra<='9')) {
            strncat(igual, &letra, 1);
        }
    }
    return igual;
}

void Exemplo0419() {
    char palavra[80] = "";
    char* resultado;
    int tamanho = 0;
    printf("\nqual a palavra: ");
    scanf("%s", palavra);
    getchar();
    resultado = alfa(palavra);
    printf("Caracteres alfanumericos = %s\n", resultado);
    
    printf("\nApertar ENTER para encerrar");
    getchar();
}

int contarAlfa(char* palavra) {
    int igual = 0;
    char letra = '0';
    int tamanho = strlen(palavra);
    int x = 0;
    for (x = 0; x < tamanho; x++) {
        letra = palavra[x];
        if ((letra>='A' && letra < 'Z') || (letra>= 'a' && letra<'z') || (letra>='0' && letra<='9')) {
            igual++;
        }
    }
    return igual;
}

void Exemplo0420() {
    int total_simbolos = 0;
    int num_palavras;

    printf("\nDigite o numero de palavras a serem lidas: ");
    scanf("%d", &num_palavras);

    for (int i = 0; i < num_palavras; i++) {
        char palavra[100];
        printf("\nDigite a palavra %d: ", i+1);
        scanf("%s", palavra);

        int numero = contarAlfa(palavra);
        printf("\nA palavra %s tem %d simbolos alfanumericos.\n", palavra, numero);

        total_simbolos += numero;

        char* simbolo = alfa(palavra);
        printf("A palavra %s tem %s simbolos alfanumericos.\n", palavra, simbolo);
    }

    printf("\nO total acumulado de simbolos alfanumericos e' %d.\n", total_simbolos);
    getchar();
    IO_pause("Apertar ENTER para continuar\n");

}






/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
// definir dado
 int x = 0;
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "Exercicios" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - ler certa quantidade de valores" );
 IO_println ( " 2 - Ler valores e contar positivos" );
 IO_println ( " 3 - Ler valores e contar positivos menores que 100" );
 IO_println ( " 4 - Ler valores e contar positivos menores que 100 e pares" );
 IO_println ( " 5 - Ler valores e contar positivos menores que 100 e pares (alternativo)" );
 IO_println ( " 6 - Ler palavra e contar letras minusculas" );
 IO_println ( " 7 - Ler palavra, contar e mostrar letras minusculas" );
 IO_println ( " 8 - Ler palavra, contar e mostrar letras minusculas (alternativo)" );
 IO_println ( " 9 - Ler palavra e contar os algarismos" );
 IO_println ( "10 - Ler palavra, contar os algarismos e mostrar numero formado pelos algarismos" );
 IO_println ( "11 - Testar quantos numeros pertencem ou nao ao intervalo" );
 IO_println ( "12 - Ler palavra e contar letras maiusculas menores que K");
 IO_println ( "13 - Ler palavra e contar letras maiusculas menores que K (alternativo) ");
 IO_println ( "14 - Ler palavra e mostrar letras maiusculas menores que K ");
 IO_println ( "15 - Ler palavra e mostrar quantidade de letras menores que K ");
 IO_println ( "16 - Ler palavra e mostrar letras menores que K");
 IO_println ( "17 - Ler palavra e mostrar quantidade de numeros impar");
 IO_println ( "18 - Ler palavra e mostrar caracteres que nao sao alfanumericos");
 IO_println ( "19 - Ler palavra e mostrar caracteres que sao alfanumericos");
 IO_println ( "20 - Ler certa quantidade de cadeias de caracteres do teclado e mostrar e contar a quantidade de simbolos alfanumericos ");
 IO_println ( " ");
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
 case 11:
 Exemplo0411( );
 break;
 case 12:
 Exemplo0412( );
 break;
 case 13:
 Exemplo0413( );
 break;
 case 14:
 Exemplo0414( );
 break;
 case 15:
 Exemplo0415( );
 break;
 case 16:
 Exemplo0416( );
 break;
 case 17:
 Exemplo0417( );
 break;
 case 18:
 Exemplo0418( );
 break;
 case 19:
 Exemplo0419( );
 break;
 case 20:
 Exemplo0420( );
 break;
 default:
 IO_pause ( "ERRO: Valor invalido." );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
