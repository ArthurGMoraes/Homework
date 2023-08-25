/*
 Exercicios
 Author: Arthur Goncalves de Moraes 816479
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos
/**
 Method00 - nao faz nada.
*/
void method00()
{
    // nao faz nada
} // fim method00 ( )
/**
 Method01 - Mostrar certa quantidade de valores.
*/
void method01()
{
    int tamanho = 0;
    int valor = 0;
    int x = 0;
    cout << endl
         << "EXERCICIOS - Method01 - v1.0" << endl;
    ofstream arquivo("INT_ARRAY.TXT");
    cin >> tamanho;
    arquivo << tamanho;
    Array<int> int_array(tamanho, 0);
    for (x = 0; x < tamanho; x = x + 1)
    {
        valor = rand() % 500;
        int_array.set(x, valor);
    }
    int_array.fprint("INT_ARRAY.TXT");
    int_array.free();
    pause("Apertar ENTER para continuar");
} // fim method01 ( )

int Exemplo1112(string fileName)
{
    int x = 0;
    int tamanho = 0;
    int resultado = 0;
    int valor = 0;
    ifstream arquivo(fileName);
    arquivo >> tamanho;
    for (x = 0; x < tamanho; x = x + 1)
    {
        arquivo >> valor;
        if (valor % 2 != 0 && valor > resultado)
        {
            resultado = valor;
        }
    }
    return resultado;
}

/**
 Method02.
*/
void method02()
{
    int tamanho = 0;
    int valor = 0;
    int resultado = 0;
    int x = 0;
    cout << endl
         << "EXERCICIOS - Method02 - v1.0" << endl;
    resultado = Exemplo1112("INT_ARRAY.TXT");
    cout << endl
         << resultado << endl;
    pause("Apertar ENTER para continuar");

} // fim method02 ( )

int Exemplo1113(string fileName)
{
    int x = 0;
    int tamanho = 0;
    int resultado = 501;
    int valor = 0;
    ifstream arquivo(fileName);
    arquivo >> tamanho;
    for (x = 0; x < tamanho; x = x + 1)
    {
        arquivo >> valor;
        if (valor % 2 == 0 && valor < resultado)
        {
            resultado = valor;
        }
    }
    return resultado;
}

/**
 Method03.
*/
void method03()
{
    int resultado = 0;
    cout << endl << "EXERCICIOS - Method03 - v1.0" << endl;
    resultado = Exemplo1113("INT_ARRAY.TXT");
    cout << endl << resultado << endl;
    pause("Apertar ENTER para continuar");
} // fim method03 ( )

int somarValores (string fileName, int inicio, int fim){
    int tamanho = 0;
    int valor = 0;
    int resultado = 0;
    int x = 0;
    ifstream arquivo(fileName);
    arquivo >> tamanho;
    for (x = 0; x < tamanho; x = x + 1)
    {
        if ( x >= inicio && x <= fim){
        arquivo >> valor;
        resultado = resultado + valor;
        }
        
    }
    return resultado;

}
/**
 Method04.
*/
void method04()
{
    int resultado = 0;
    cout << endl << "EXERCICIOS - Method04 - v1.0" << endl;
    resultado = somarValores("INT_ARRAY.TXT", 4, 7);
    cout << endl << resultado << endl;
    pause("Apertar ENTER para continuar");
} // fim method04 ( )

int media (string fileName, int inicio, int fim){
    int tamanho = 0;
    int valor = 0, valor2 = 0;
    int resultado = 0;
    int x = 0;
    int quantidade = (fim - inicio) + 1;
    ifstream arquivo(fileName);
    arquivo >> tamanho;
    for (x = 0; x < tamanho; x = x + 1)
    {
        if ( x >= inicio && x <= fim){
        arquivo >> valor;
        valor2 = valor2 + valor;
        resultado = valor2/quantidade;
        }
        
    }
    return resultado;
}

/**
 Method05.
*/
void method05()
{
    int resultado = 0;
    cout << endl << "EXERCICIOS - Method05 - v1.0" << endl;
    resultado = media("INT_ARRAY.TXT", 4, 7);
    cout << endl << resultado << endl;
    pause("Apertar ENTER para continuar");
} // fim method05 ( )

int positivo (string fileName){
    int tamanho = 0;
    int valor = 0;
    int resultado = 0;
    int x = 0;
    ifstream arquivo(fileName);
    arquivo >> tamanho;
    for (x = 0; x < tamanho; x = x + 1)
    {
        arquivo >> valor;
        if ( valor < 0){
        resultado = 1;
        x = tamanho;
        } 
    }
    return resultado;
}
/**
 Method06.
*/
void method06()
{
    int resultado = 0;
    cout << endl << "EXERCICIOS - Method06 - v1.0" << endl;
    resultado = positivo("INT_ARRAY.TXT");
    if (resultado == 1){
       cout << endl << "Nem todos sao positivos" << endl; 
    } else{
       cout << endl << "Todos sao positivos" << endl; 
    }
    pause("Apertar ENTER para continuar");
} // fim method06( )

int crescente (string fileName){
    int tamanho = 0;
    int valor = 0;
    int resultado = 0;
    int x = 0;
    int inicio = 0;
    ifstream arquivo(fileName);
    arquivo >> tamanho;
    arquivo >> inicio;
    for (x = 0; x < tamanho - 1; x = x + 1)
    {
        arquivo >> valor;
        if ( valor < inicio){
        resultado = 1;
        x = tamanho;
        } 
    }
    return resultado;
}

/**
 Method07.
*/
void method07()
{
    int resultado = 0;
    cout << endl << "EXERCICIOS - Method07 - v1.0" << endl;
    resultado = crescente("INT_ARRAY.TXT");
    if (resultado == 1){
       cout << endl << "Nao esta em ordem crescente" << endl; 
    } else{
       cout << endl << "Esta em ordem crescente" << endl; 
    }
    pause("Apertar ENTER para continuar");
} // fim method07 ( )

int valorPresente (string fileName, int inicio, int fim, int busca){
    int tamanho = 0;
    int valor = 0;
    int resultado = 0;
    int x = 0;
    ifstream arquivo(fileName);
    arquivo >> tamanho;
    for (x = 1; x <= tamanho; x = x + 1)
    {
        arquivo >> valor;
        if ( x >= inicio && x <= fim && valor == busca){
        resultado = 1;
        x = tamanho;
        }
        
    }
    return resultado;
}
/**
 Method08.
*/
void method08()
{
    int busca = 0;
    int resultado = 0;
    cout << endl << "EXERCICIOS - Method08 - v1.0" << endl;
    cin >> busca;
    resultado = valorPresente("INT_ARRAY.TXT", 3, 6, busca);
    if (resultado == 1){
       cout << endl << "Existe" << endl; 
    } else{
       cout << endl << "Nao existe" << endl; 
    }
    pause("Apertar ENTER para continuar");
} // fim method08 ( )

/**
 Method09.
*/
void method09()
{
   int tamanho = 0;
   int constante = 0;
   int x = 0, y = 0;
   int valor = 0;
   int inicio = 3;
   int fim = 6;
   cout << endl << "EXERCICIOS - Method08 - v1.0" << endl;
   cin >> constante;
   ifstream arquivo("INT_ARRAY.TXT");
   arquivo >> tamanho;
   Array<int> int_array((fim - inicio)+1, 0 );
   for (x = 1; x <= tamanho; x = x + 1){
    arquivo >> valor;
    if (x>=inicio && x<=fim){
        valor = valor * constante;
        int_array.set(y, valor);
        y = y + 1;
    }
   }
   int_array.print();
   int_array.free();
   pause("Apertar ENTER para continuar");
} // fim method09 ( )

/*
void ordenarCrescente (int length){
   // length = 0;
    int valor = 0, x = 0;
 for (x = 0; x < length-1; x = x + 1){
    if (data [x]<data[x+1]){
     valor = data [x];
     int_array.set(x, data[x+1]);//data [x] = data [x+1];
     int_array.set(x+1, valor);//data [x+1] = valor;
    }
 }
 }
/**
 Method10.

void method10()
{
    int tamanho = 0;
    // identificar
    cout << endl
         << "EXEMPLO1101 - Method10 - v1.0" << endl;
    ifstream arquivo("INT_ARRAY.TXT");
     arquivo >> tamanho;
    Array <int> int_array ( tamanho, 0 );
    int_array.fread("INT_ARRAY.TXT");
    ordenarCrescente(tamanho);
    int_array.print();
    pause("Apertar ENTER para continuar");
} // fim method10 ( )
*/ 

// nao consegui fazer o ex10, tentei fazer na classe e por aqui

// ----------------------------------------------- acao principal
/*
 Funcao principal.
 @return codigo de encerramento
*/
void method10()
{
}
int main(int argc, char **argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
               // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - ex1 " << endl;
        cout << " 2 - ex2" << endl;
        cout << " 3 - ex3" << endl;
        cout << " 4 - ex4" << endl;
        cout << " 5 - ex5" << endl;
        cout << " 6 - ex6" << endl;
        cout << " 7 - ex7" << endl;
        cout << " 8 - ex8" << endl;
        cout << " 9 - ex9" << endl;
        cout << "10 - ex10" << endl;
        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
            break;
        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        } // fim escolher
    } while (x != 0);
    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )