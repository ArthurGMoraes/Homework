/*
 Exercicios05k - v0.1. 
 Author: Arthur Goncalves de Moraes 816479
*/
// dependencias
#include "io.h" // para definicoes proprias
#include <math.h>
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )
/**
 Method01a - Mostrar certa quantidade de valores.
 @param x - quantidade de valores a serem mostrados
*/
void method01a ( int x )
{
// definir dado local
 int y = 1; // controle
// repetir enquanto controle menor que a quantidade desejada
 while ( y <= x )
 {
 // mostrar valor
 IO_printf ( "%s%d\n", "Valor = ", y );
 // passar ao proximo
 y = y + 1;
 } // fim se
} // fim method01a( )
/**
 Method01 - Mostrar certa quantidade de valores.
 OBS.: Preparacao e disparo de outro metodo.
*/
void method01 ( )
{
// identificar
 IO_id ( "Exercicios05k - Method01 - v0.1" );
// executar o metodo auxiliar
 method01a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )
/**
 Method02.
*/
/**
 Method02a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method02a ( int x )
{
// definir dado local
 int y = 1; // controle
 int z = 2;
// repetir enquanto controle menor que a quantidade desejada
 while ( y <= x )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, z );
 // passar ao proximo par
 z = z + 2;
 // passar ao proximo valor controlado
 y = y + 1;
 } // fim se
} // fim method02a( )
/**
 Method02.
*/
void method02 ( )
{
// identificar
 IO_id ( "Exercicios05k - Method02 - v0.1" );
// executar o metodo auxiliar
 method02a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
 Method03a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method03a ( int x )
{
// definir dado local
 int y = 1; // controle
 int z = 0;
// repetir enquanto controle menor que a quantidade desejada
 while ( y <= x )
 {
 // vincular o valor a ser mostrado ao controle
 z = 2 * y;
 // mostrar valor
 IO_printf ( "%d: %d\n", y, z );
 // passar ao proximo valor controlado
 y = y + 1;
 } // fim se
} // fim method03a( )
/**
 Method03.
*/
void method03 ( )
{
// identificar
 IO_id ( "Exercicios05k - Method03 - v0.1" );
// executar o metodo auxiliar
 method03a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
 Method04a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method04a ( int x )
{
// definir dado local
 int y = x; // controle
 int z = 0;
// repetir enquanto controle menor que a quantidade desejada
 while ( y > 0 )
 {
 // vincular o valor a ser mostrado ao controle
 z = 2 * y;
 // mostrar valor
 IO_printf ( "%d: %d\n", y, z );
 // passar ao proximo valor controlado
 y = y - 1;
 } // fim se
} // fim method04a( )
/**
 Method04.
*/
void method04 ( )
{
// identificar
 IO_id ( "Exercicios05k - Method04 - v0.1" );
// executar o metodo auxiliar
 method04a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
 Method05a - Mostrar certa quantidade de valores pares.
 @param x - quantidade de valores a serem mostrados
*/
void method05a ( int x )
{
// definir dado local
 int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = x; y > 0; y = y-1 )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, (2*y) );
 } // fim se
} // fim method05a( )
/**
 Method05.
*/
void method05 ( )
{
// identificar
 IO_id ( "Exercicios05k - Method05 - v0.1" );
// executar o metodo auxiliar
 method05a ( 5 );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )
/**

/**
 somarValores - funcao para somar certa quantidade de pares.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
int somarValores ( int x )
{
// definir dados locais
 int soma = 1;
 int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = x-1; y > 0; y = y-1 )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, (2*y) );
 // somar valor
 soma = soma + (2*y);
 } // fim se
// retornar resultado
 return ( soma );
} // fim somarValores ( )
/**
 Method06.
*/
void method06 ( )
{
// definir dado
 int soma = 0;
// identificar
 IO_id ( "Exercicios05k - Method06 - v0.1" );
// chamar e receber resultado da funcao
 soma = somarValores ( 5 );
// mostrar resultado
 IO_printf ( "soma de pares = %d\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )
/**
 somarFracao1 - funcao para somar certa quantidade de fracoes.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracao1 ( int x )
{
// definir dados locais
 double soma = 1.0;
 double numerador = 0.0;
 double denominador = 0.0;
 int y = 0 ; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = x-1; y > 0; y = y-1 )
 {
 // calcular numerador
 numerador = 1.0;
 // calcular denominador
 denominador = 2.0*y;
 // mostrar valor
 IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n",
 y, numerador, denominador, (numerador/denominador) );
 // somar valor
 soma = soma + (1.0)/(2.0*y);
 } // fim se
// retornar resultado
 return ( soma );
} // fim somarFracao1 ( )
/**
 Method07.
*/
void method07 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "Exercicios05k - Method07 - v0.1" );
// chamar e receber resultado da funcao
 soma = somarFracao1 ( 5 );
// mostrar resultado
 IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )
/**
 somarFracao2 - funcao para somar certa quantidade de fracoes.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracao2 ( int x )
{
// definir dados locais
 double soma = 1.0;
 double numerador = 0.0;
 double denominador = 0.0;
 int y = 0 ; // controle
// mostrar primeiro valor
 IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma );
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y <= (x-1); y = y+1 )
 {
 // calcular numerador
 numerador = 2.0*y-1;
 // calcular denominador
 denominador = 2.0*y;
 // mostrar valor
 IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n",
 y+1, numerador, denominador, (numerador/denominador) );
 // somar valor
 soma = soma + (2.0*y-1)/(2.0*y);
 } // fim se
// retornar resultado
 return ( soma );
} // fim somarFracao2 ( )
/**
 Method08.
*/
void method08 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "EXEMPLO0508 - Method08 - v0.1" );
// chamar e receber resultado da funcao
 soma = somarFracao2 ( 5 );
// mostrar resultado
 IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
 somarFracao3 - funcao para somar certa quantidade de fracoes.
 @return soma dos valores
 @param x - quantidade de valores a serem mostrados
*/
double somarFracao3 ( int x )
{
// definir dados locais
 double soma = 1.0;
 int y = 0 ; // controle
// mostrar primeiro valor
 IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma );
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y <= (x-1); y = y+1 )
 {
 // mostrar valor
 IO_printf ( "%d: %7.4lf/%7.4lf = %7.4lf\n",
 y+1, (2.0*y), (2.0*y+1), ((2.0*y)/(2.0*y+1)) );
 // somar valor
 soma = soma + (2.0*y)/(2.0*y+1);
 } // fim se
// retornar resultado
 return ( soma );
} // fim somarFracao3 ( )
/**
 Method09.
*/
void method09 ( )
{
// definir dado
 double soma = 0.0;
// identificar
 IO_id ( "Exercicios05k - Method09 - v0.1" );
// chamar e receber resultado da funcao
 soma = somarFracao3 ( 5 );
// mostrar resultado
 IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
 multiplicarValores - funcao para multiplicar certa quantidade de valores impares.
 @return produto de valores
 @param x - quantidade de valores
*/
int multiplicarValores ( int x )
{
// definir dados locais
 int produto = 1;
 int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
 for ( y = 1; y <= x; y = y+1 )
 {
 // mostrar valor
 IO_printf ( "%d: %d\n", y, (2*y-1) );
 // somar valor
 produto = produto * (2*y-1);
 } // fim se
// retornar resultado
 return ( produto );
} // fim multiplicarValores ( )
/**
 Method10.
*/
void method10 ( )
{
// identificar
 IO_id ( "Exercicios05k - Method10 - v0.1" );
// mostrar produto de valores
 IO_printf ( "%s%d\n", "produto = ", multiplicarValores ( 5 ) );
// encerrar
 IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )


int multiSeis(int k){
    int z,y = 0;

    for (y=0 ; y<k ; y=y+1){
        z = 6*y;
    printf("%d\n", z);
    }
}

void Exemplo0511(){ 
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    multiSeis(x);
    getchar();
    IO_pause("Apertar ENTER");

}

int multiSeisQuatro(int x){
 int teste = 0;
 int multiplos = 0;
 while (multiplos < x){
    teste = teste + 4;
    if ((teste % 4 == 0) && (teste % 6 == 0)){
        printf ("%d\n", teste);
        multiplos = multiplos + 1;
    }
 }
}

void Exemplo0512(){
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    multiSeisQuatro(x);
    getchar();
    IO_pause("Apertar ENTER");
}


int multiNoveImpar(int x){
int teste = 0;
 int multiplos = x;
 while (multiplos > 0){
    teste = teste + 9;
    if ((teste % 9 == 0) && (teste % 2 != 0)){
        printf ("%d\n", teste);
        multiplos = multiplos - 1;
    }
 }
}



void Exemplo0513(){
int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    multiNoveImpar(x);
    getchar();
    IO_pause("Apertar ENTER");

}

int denominadorMultiSeis(int x){
    int teste = 0;
 int multiplos = 0;
 while (multiplos < x){
    teste = teste + 6;
    printf ("1/%d\n", teste);
    multiplos = multiplos + 1;
    }
 }



void Exemplo0514(){
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    denominadorMultiSeis(x);
    getchar();
    IO_pause("Apertar ENTER");
}

double fracaoPotencia(double x){
double potencia = 0;
 double multiplos = 1;
 while (multiplos < x){
    potencia = pow(2,multiplos);
    printf ("1/%.0lf\n", potencia);
    multiplos = multiplos + 1;
    }
}

void Exemplo0515(){
    double x = 0;
    printf("Digite um valor: ");
    scanf("%lf", &x);
    fracaoPotencia(x);
    getchar();
    IO_pause("Apertar ENTER");
}

int naoMulti5(int x){
    int teste = 0;
 int valores = 0;
 int resultado = 0;
 while (valores < x){
    teste = teste + 6;
    if(teste%5!=0 && teste%2==0){
    resultado = resultado + teste;
    valores = valores + 1;
    }
}
//printf("%d", resultado);
return resultado;
}

void Exemplo0516(){
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    //naoMulti5(x);
    printf("%d", naoMulti5(x));
    getchar();
    IO_pause("Apertar ENTER");
}

double naoMulti5b(int x){
    int teste = 0;
 int valores = 0;
 double resultado = 0.0;
 double teste2 = 0.0;
 while (valores < x){
    teste = teste + 6;
    
    if(teste%5!=0 && teste%2==0){
    teste2 = 1/(double)teste;
    valores = valores + 1;
    //printf("%lf\n",teste2);
    resultado = resultado + teste2;
    }
    
}
//printf("\n%lf", resultado);
return resultado;
}


void Exemplo0517(){
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    //naoMulti5b(x);
    printf("\n%lf", naoMulti5b(x));
    getchar();
    IO_pause("Apertar ENTER");
}

int adicaoNaturais(int x){
   int teste = 0;
   int valorInicial = 5;
   int adicao = 0;
    while(teste<x){
        valorInicial = valorInicial + 1;
        adicao = adicao + valorInicial;
        teste = teste + 1;
    }
    return adicao;
}

void Exemplo0518(){
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    printf("%d", adicaoNaturais(x));
    getchar();
    IO_pause("Apertar ENTER");
}

double adicaoQuadNaturais(int x){
   int teste = 0;
   double valorInicial = 5;
   double potencia = 0.0;
   double adicao = 0;
    while(teste<x){
        valorInicial = valorInicial + 1;
        potencia = pow(valorInicial, 2);
        //printf("%lf\n",potencia);
        adicao = adicao + potencia;
        teste = teste + 1;
    }
    return adicao;
}

void Exemplo0519(){
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    printf("%.0lf", adicaoQuadNaturais(x));
    getchar();
    IO_pause("Apertar ENTER");
}

double adicaoInvNaturais(int x){
   int teste = 0;
   double valorInicial = 5;
   double fracao = 0.0;
   double adicao = 0;
    while(teste<x){
        valorInicial = valorInicial + 1;
        fracao = 1/valorInicial;
        //printf("%lf\n",fracao);
        adicao = adicao + fracao;
        teste = teste + 1;
    }
    return adicao;
}

void Exemplo0520(){
    int x = 0;
    printf("Digite um valor: ");
    scanf("%d", &x);
    printf("%lf", adicaoInvNaturais(x));
    getchar();
    IO_pause("Apertar ENTER");
}






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
 IO_id ( "Exercicios05k - Programa - v0.1" );
 
 // ler do teclado
 IO_println ( "Opcoes" );
 IO_println ( " 0 - parar" );
 IO_println ( " 1 - mostrar certa quantidade de valores" );
 IO_println ( " 2 - mostrar certa quantidade de valores pares" );
 IO_println ( " 3 - mostrar certa quantidade de valores pares (alternativo)" );
 IO_println ( " 4 - mostrar certa quantidade de valores pares (decrescente)" );
 IO_println ( " 5 - mostrar certa quantidade de valores pares (decrescente/alternativo)" );
 IO_println ( " 6 - mostrar e somar valores pares" );
 IO_println ( " 7 - mostrar e somar fracoes" );
 IO_println ( " 8 - mostrar e somar fracoes (alternativo)" );
 IO_println ( " 9 - mostrar e somar fracoes par/impar" );
 IO_println ( "10 - mostrar e multiplicar valores impares" );
 IO_println ( "11 - mostrar multiplos de 6" );
 IO_println ( "12 - mostrar multiplos de 6 e 4" );
 IO_println ( "13 - mostrar multiplos de 9 impares" );
 IO_println ( "14 - mostrar fracao com denominador multiplo de 6" );
 IO_println ( "15 - mostrar fracao com potencia no denominador" );
 IO_println ( "16 - somar multiplos de 6 nao multiplos de 5 a partir do 6" );
 IO_println ( "17 - somar inverso de multiplos de 6 nao multiplos de 5 a partir do 6" );
 IO_println ( "18 - somar os naturais a partir de 6" );
 IO_println ( "19 - somar os quadrados dos naturais a partir de 6" );
 IO_println ( "20 - somar os inversos dos naturais a partir de 6" );
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
 case 11:
 Exemplo0511 ( );
 break;
 case 12:
 Exemplo0512 ( );
 break;
 case 13:
 Exemplo0513 ( );
 break;
 case 14:
 Exemplo0514 ( );
 break;
 case 15:
 Exemplo0515 ( );
 break;
 case 16:
 Exemplo0516 ( );
 break;
 case 17:
 Exemplo0517 ( );
 break;
 case 18:
 Exemplo0518 ( );
 break;
 case 19:
 Exemplo0519 ( );
 break;
 case 20:
 Exemplo0520 ( );
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
