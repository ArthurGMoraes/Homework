/*
 Exemplos - v0.1. 
 Author: Arthur Goncalves de Moraes
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
 int_array.set ( 0, 1 );
 int_array.set ( 1, 2 );
 int_array.set ( 2, 3 );
 int_array.set ( 3, 4 );
 int_array.set ( 4, 5 );
// identificar
 cout << "\nEXEMPLO1101 - Method01 - v1.0\n" << endl;
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
 Method02.
*/
void method02 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "EXEMPLO1102 - Method02 - v1.0" << endl;
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )
/**
 Method03.
*/
void method03 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "EXEMPLO1103 - Method03 - v1.0" << endl;
// ler dados
 int_array.read ( );
// mostrar dados
 int_array.fprint ( "INT_ARRAY1.TXT" );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method03 ()

/**
 Method04.
*/
void method04 ( )
{
// definir dados
 Array <int> int_array ( 5, 0 );
// identificar
 cout << endl << "EXEMPLO1104 - Method04 - v1.0" << endl;
// ler dados
 int_array.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 int_array.print ( );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
 Method05.
*/
void method05 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
// identificar
 cout << endl << "EXEMPLO1105 - Method05 - v1.0" << endl;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array.print ( );
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
 Method06.
*/
void method06 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
// identificar
 cout << endl << "EXEMPLO1106 - Method06 - v1.0" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// criar copia
 Array <int> int_array2 ( int_array1 );
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( );
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
 Method07.
*/
void method07 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
// identificar
 cout << endl << "EXEMPLO1107 - Method07 - v1.0" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// mostrar dados
 cout << "\nOriginal\n" << endl;
 int_array1.print ( );
// copiar dados
 int_array2 = int_array1;
// mostrar dados
 cout << "\nCopia\n" << endl;
 int_array2.print ( );
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
 Method08.
*/
void method08 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3 };
 Array <int> int_array1 ( 3, other );
 Array <int> int_array2 ( 3, other );
 int x;
// identificar
 cout << endl << "EXEMPLO1108 - Method08 - v1.0" << endl;
// mostrar dados
 cout << endl;
 cout << "Array_1";
 int_array1.print ( );
// mostrar dados
 cout << "Array_2";
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// alterar dado
 int_array2.set ( 0, (-1) );
// mostrar dados
 cout << endl;
 cout << "Array_1" << endl;
 int_array1.print ( );
// mostrar dados
 cout << "Array_2" << endl;
 int_array2.print ( );
// mostrar comparacao
 cout << "Igualdade = " << (int_array1==int_array2) << endl;
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{
// definir dados
 Array <int> int_array1 ( 1, 0 );
 Array <int> int_array2 ( 1, 0 );
 Array <int> int_array3 ( 1, 0 );
// identificar
 cout << endl << "EXEMPLO1109 - Method09 - v1.0" << endl;
// ler dados
 int_array1.fread ( "INT_ARRAY1.TXT" );
// copiar dados
 int_array2 = int_array1;
// somar dados
 int_array3 = int_array2 + int_array1;
// mostrar dados
 cout << endl;
 cout << "Original" << endl;
 int_array1.print ( );
// mostrar dados
 cout << "Copia" << endl;
 int_array2.print ( );
// mostrar dados
 cout << "Soma" << endl;
 int_array3.print ( );
// reciclar espaco
 int_array1.free ( ); 
 int_array2.free ( ); 
 int_array3.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
// definir dados
 int other [ ] = { 1, 2, 3, 4, 5 };
 Array <int> int_array ( 5, other );
 int x;
// identificar
 cout << endl << "EXEMPLO1110 - Method10 - v1.0" << endl;
// mostrar dados
 cout << "\nAcesso externo" << endl;
 for ( x=0; x<int_array.getLength( ); x=x+1 )
 {
 cout << endl << setw( 3 ) << x << " : " << int_array [ x ];
 } // fim repetir
 cout << endl << "\nFora dos limites:";
 cout << endl << "[-1]: " << int_array.get(-1) << endl;
 cout << endl << "[" << int_array.getLength( ) << "]: " 
 << int_array [ int_array.getLength( ) ] << endl;
// reciclar espaco
 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

// ----------------------------------------------- acao principal
/*
 Funcao principal.
 @return codigo de encerramento
*/
int main ( int argc, char** argv )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 // identificar
 cout << "EXEMPLOS - Programa - v1.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - mostrar dados inteiros em arranjo " << endl;
 cout << " 2 - gravar dados inteiros em arranjo" << endl;
 cout << " 3 - gravar dados interios em arquivo" << endl;
 cout << " 4 - ler dados inteiros de um arquivo" << endl;
 cout << " 5 - copiar dados de um arranjo" << endl;
 cout << " 6 - criar objeto a partir de outro" << endl;
 cout << " 7 - copiar dados de um arquivo para um arranjo" << endl;
 cout << " 8 - testar a igualdade de 2 arranjos" << endl;
 cout << " 9 - somar arranjos" << endl;
 cout << "10 - acessar valores externos ao arranjo" << endl;
 // ler do teclado
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
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
 cout << endl << "ERRO: Valor invalido." << endl;
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/