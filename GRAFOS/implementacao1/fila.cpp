#include <iostream>

class Cell {
    public:
    int elemento;
    Cell* prox;

    Cell(int elemento, Cell* prox = nullptr) : elemento(elemento) , prox(prox){};
};

class Fila {
    public:
    Cell* inicio;
    Cell* fim;
    int tam;

    Fila() : inicio(nullptr), fim(nullptr), tam(0){};

    void add(int e){
        if (inicio == nullptr){
            inicio = new Cell(e);
            
            fim = inicio;
            tam++;
        } else {
            fim->prox = new Cell(e);
            fim = fim->prox;
            tam++;
        }
    }
    
    int rm(){
        if(inicio == nullptr){
            return 0;
        }
        int e = inicio->elemento;
        inicio = inicio->prox;
        tam--;
        return e;
    }

    bool buscar(int e){
        for(Cell* i = inicio; i != nullptr; i = i->prox){
            if (e == i->elemento){
                return true;
            }
        }
        return false;
    }

    void print(){
        Cell* tmp = inicio;
        for (int i = 0; i < tam; i++){
            std::cout << tmp->elemento << std::endl;
            tmp = tmp->prox;
        }
    };

};

int main() {
    std::cout << "ARTHUR GONCALVES DE MORAES - 816479" << std::endl << "IMPLEMENTACAO 1: FILA" << std::endl << std::endl;
    
    Fila* f = new Fila();

    f->add(9);
    f->add(6);
    f->add(7);
    f->add(8);
    f->add(1);
    f->add(5);
    f->print();

    std::cout << std::endl;

    std::cout << "ELEMENTO " << f->rm() << " REMOVIDO" << std::endl;
    std::cout << "ELEMENTO " << f->rm() << " REMOVIDO" << std::endl;
    std::cout << "ELEMENTO " << f->rm() << " REMOVIDO" << std::endl;
    std::cout << std::endl;
    f->print();

    std::cout << std::endl;

    std::string resp = (f->buscar(1))?"SIM":"NAO";
    std::cout << resp << std::endl;
    resp = (f->buscar(12))?"SIM":"NAO";
    std::cout << resp << std::endl;
}