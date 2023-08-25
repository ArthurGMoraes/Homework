/*
 Author: Arthur Goncalves de Moraes 816479
*/
// dependencias
#include "io.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )

/**
 Arthur Goncalves de Moraes 816479
 exercicio01 - mostrar soma dos divisores
 @param x - valor que tera seus divisores somados
 teste n = 5
       x = {4, 25, 36, 77, 123}
*/
int exercicio01(int x)
{
 int soma = 0;
 int i = 0;
 for (i = 1; i<=x; i = i + 1)
 {
    if(x%i==0)
    {
        soma = soma + i;
    }
 }
 return soma;
}
/**
 disparo do excercico01
*/
void method01 ( )
{
// identificar
 IO_id ( "EXERCICIO01 - Method01" );
 int n = 0;
 int x = 0;
 printf("quantos numeros serao testados? ");
 scanf("%d", &n);
 while (n>0)
 {
    scanf("%d",&x);
    printf("a soma e': %d\n",exercicio01(x));
    n = n - 1;
 }
 getchar();
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 Arthur Goncalves de Moraes 816479
 exercicio02 - dizer se e' primo
 @param x - valor para verificar se e' primo ou nao
       teste n = 5
       x = {4, 25, 11, 77, 113}
*/
int exercicio02 (int x)
{
  int divisores = 0;
  int i = 0;
 for (i = 1; i<=x; i = i + 1)
 {
    if(x%i==0)
    {
        divisores = divisores + 1;
    }
 }
return divisores;
  
}
/**
 disparo do excercico02
*/
void method02 ( )
{
IO_id ( "EXERCICIO02 - Method02" );
 int n = 0;
 int x = 0;
 int resultado = 0;
 printf("quantos numeros serao testados? ");
 scanf("%d", &n);
 while (n>0)
 {
    scanf("%d",&x);
    resultado = exercicio02(x);
    if (resultado > 2)
    {
    printf("nao e' primo\n");
    }
    else
    {
    printf("e' primo\n");
    }

    n = n - 1;
 }
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
 Arthur Goncalves de Moraes 816479
 exercicio03 - dizer a funcao de cada simbolo de uma palavra lida
 teste = b@nanana!+<-e,
         &/% =a@^.
*/

chars exercicio03 ()
{
   int x = 0;
   char teste [80] = {0};
   int tamanho = 0;
   char simbolo = '0';
   char resultado [80] = {0};
   char * retorno = malloc(1); 
   // char copiaTeste [80] = {0};
   printf("Qual e' a palavra? ");
   scanf("%s", &teste);
   tamanho = strlen(teste);
   //printf("%d\n",tamanho);
   for (x = 0; x<tamanho; x = x + 1)
   {
      simbolo = teste[x];
      printf("%c\n", simbolo);
      if ( simbolo == '&' || simbolo == '|'  || simbolo == '!' )
      {
         strcpy(resultado,"operador logico " );
      }
      else if (simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '/'  || simbolo == '%' )
      {
         strcpy(resultado,"operador aritmetico " );
      }
      else if (simbolo == '<' || simbolo == '>' || simbolo == '=' )
      {
         strcpy(resultado,"operador relacional " ) ;
      }
      else if (simbolo == ' '  ||simbolo == '.' || simbolo == ',' || simbolo == ';' || simbolo == ':' || simbolo == '_' )
      {
         strcpy(resultado, "separadores ") ;
      }
      else 
      {
         strcpy(resultado,"outro " );
      }
      //printf("%s\n", resultado);
      strcat(retorno,resultado);
   }
   //printf("%s", retorno);
   return retorno;
}

/**
 disparo do excercico03
*/
void method03 ( )
{
// identificar
 IO_id ( "EXERCICIO03 - Method03" );
 printf("%s\n", exercicio03());
 getchar();
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )
// nao tinha percebido que o enunciado pedia para fazer uma funcao para cada simbolo entao so fiz pro ex 4

/**
 Arthur Goncalves de Moraes 816479
 exercicio04 - dizer quantos simbolos de uma palvra sao letras maiusculas, minusculas, operadores, digitos e separadores
 teste = b@nan0a34na9!+<-e,
         &BAPO/% =a9@^.
*/
int maiuscula(char c) {
    return (c >= 'A' && c <= 'Z');
}

int minuscula(char c) {
    return (c >= 'a' && c <= 'z');
}

int digito(char c) {
    return (c >= '0' && c <= '9');
}

int separador(char c) {
    return (c == ' ' || c == '.' || c == ',' || c == ';' || c == ':' || c == '_');
}

int operador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'  || c == '%' ||
            c == '<' || c == '>' || c == '=' || c == '&' || c == '|'  || c == '!');
}

int outro(char c) {
    return !maiuscula(c) && !minuscula(c) && !digito(c) && !separador(c) && !operador(c);
}
/**
 disparo do excercico04
*/
void method04 ( )
{
 char teste[100] = {0};
 int tamanho = 0;
 int x = 0;
 int maiusculas = 0, minusculas = 0, operadores = 0, outros = 0, separadores = 0, digitos = 0;
// identificar
 IO_id ( "EXERCICIO04 - Method04" );
 printf("Digite uma cadeia de caracteres: ");
 scanf("%s",teste);
 tamanho = strlen(teste);
 for (x = 0; x < tamanho; x = x + 1) 
 {
        if (maiuscula(teste[x])) 
        {
            maiusculas = maiusculas + 1;
        } 
        else if (minuscula(teste[x])) 
        {
            minusculas = minusculas + 1;
        } 
        else if (digito(teste[x])) 
        {
            digitos = digitos + 1;
        } 
        else if (separador(teste[x])) 
        {
            separadores = separadores + 1;
        } 
        else if (operador(teste[x])) 
        {
            operadores = operadores + 1;
        }
        else if (outro(teste[x])) 
        {
           outros = outros + 1;
        }
 }
 printf ("%d maiusculas, %d minusculas, %d operadores,  %d digitos, %d separadores, %d outros\n", maiusculas, minusculas, operadores, digitos, separadores, outros );
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
 Arthur Goncalves de Moraes 816479
 exercicio05 - calcular media
 teste = b@nan0a34na9!+<-e,
         &BAPO/% =a9@^.
*/
int maiorMedia (int media1, int media2, int media3)
{
   if (media1>media2)
   {
      if (media1>media3)
      {
       return media1;
      }
      else 
      {
         return media3;
      }
   }
   else if (media2>media3)
   {
      return media2;
   }
   else
   {
      return media3;
   }
}

int exercicio05 (int n)
{
   int media1 = 0, media2 = 0, media3 = 0;
   int valores [20];
   int x = 0;
   int teste = 0;
   int contador1 = 0, contador2 = 0, contador3 = 0;
   while (x < n)
   {
      printf("valor %d: ", x+1);
      scanf("%d", &valores[x]);
      //printf("%d",valores[x]);
      x = x + 1;
   }
  
   x = 0;
   while (x<n)
   {
    teste = valores[x];
    if (teste < (-32.25))
    {
      contador1 = contador1 + 1;
      media1 = media1 + teste;
    }
    else if (teste >= (-32.25) && teste <= 63.75)
    {
      contador2 = contador2 + 1;
      media2 = media2 + teste;
    }
    else if (teste > 63.75)
    {
      contador3 = contador3 + 1;
      media3 = media3 + teste;
    }
    //printf("%d %d - %d %d - %d %d\n", contador1, media1, contador2, media2, contador3, media3);
    x = x + 1;
   }
   if (contador1 == 0)
   {
      media1 = 0;
   } else { media1 = media1/contador1;}
   if (contador2 == 0)
   {
      media2 = 0;
   } else {media2 = media2/contador2;}
   if (contador3 == 0)
   {
      media3 = 0;
   } else {media3 = media3/contador3;}
   return maiorMedia(media1,media2,media3);
}


/**
 Method05.
*/
void method05 ( )
{
 int n = 0;
// identificar
 IO_id ( "EXERCICIO05 - Method05" );
 printf("Quantos numeros? ");
 scanf("%d",&n);
 printf("A maior media e' %d\n", exercicio05(n));
// encerrar
 getchar();
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )
// ultimo ex feito

/**
 Method06.
*/
void method06 ( )
{
// identificar
 IO_id ( "EXERCICIO06 - Method06" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )
/**
 Method07.
*/
void method07 ( )
{
// identificar
 IO_id ( "EXERCICIO07 - Method07" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )
/**
 Method08.
*/
void method08 ( )
{
// identificar
 IO_id ( "EXERCICIO08 - Method08" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{
// identificar
 IO_id ( "EXERCICIO09 - Method09" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "EXERCICIO10 - Method10" );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )
/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 // identificar
 IO_id ( "Recuperacao - Programa" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - exercicio01" );
 IO_println ( " 2 - exercicio02" );
 IO_println ( " 3 - exercicio03" );
 IO_println ( " 4 - exercicio04" );
 IO_println ( " 5 - exercicio05" );
 IO_println ( " 6 - exercicio06" );
 IO_println ( " 7 - exercicio07" );
 IO_println ( " 8 - exercicio08" );
 IO_println ( " 9 - exercicio09" );
 IO_println ( "10 - exercicio10" );
 IO_println ( "" );
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
 default:
 IO_println ( "ERRO: Valor invalido." );
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 IO_pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )

/*
resultados dos testes:
exercicio01: 7, 31 , 91. 96, 128
exercicio02: nao e' primo, nao e' primo, e' primo , nao e' primo, e' primo
exercicio03: outro outro outro outro outro outro outro outro operador logico operador aritmetico operador relacional operador aritmetico outro separadores
             operador logico operador aritmetico operador aritmetico -> ERRO: apos o espaco nada foi considerado
exercicio04: 0 maiusculas, 8 minusculas, 4 operadores,  4 digitos, 1 separadores, 1 outros
             4 maiusculas, 0 minusculas, 3 operadores,  0 digitos, 0 separadores, 0 outros -> ERRO: apos o espaco nada foi considerado

*/