#include <iostream>

class Cell {
    public:
    int elemento;
    Cell* prox;

    Cell(int elemento, Cell* prox = nullptr) : elemento(elemento) , prox(prox){};
};

class Pilha {
    public:
    Cell* topo;
    int tam;

    Pilha() : topo(nullptr), tam(0){};

    void add(int e){
        if (topo == nullptr){
            topo = new Cell(e);
            tam++;
        } else {
            topo = new Cell(e, topo);
            tam++;
        }
    }
    
    int rm(){
        if(topo == nullptr){
            return 0;
        }
        int e = topo->elemento;
        topo = topo->prox;
        tam--;
        return e;
    }

    bool buscar(int e){
        for(Cell* i = topo; i != nullptr; i = i->prox){
            if (e == i->elemento){
                return true;
            }
        }
        return false;
    }

    void print(){
        Cell* tmp = topo;
        for (int i = 0; i < tam; i++){
            std::cout << tmp->elemento << std::endl;
            tmp = tmp->prox;
        }
    };

};

int main() {
    std::cout << "ARTHUR GONCALVES DE MORAES - 816479" << std::endl << "IMPLEMENTACAO 1: PILHA" << std::endl << std::endl;
    
    Pilha* p = new Pilha();

    p->add(9);
    p->add(6);
    p->add(7);
    p->add(8);
    p->add(1);
    p->add(5);
    p->print();

    std::cout << std::endl;

    std::cout << "ELEMENTO " << p->rm() << " REMOVIDO" << std::endl;
    std::cout << "ELEMENTO " << p->rm() << " REMOVIDO" << std::endl;
    std::cout << "ELEMENTO " << p->rm() << " REMOVIDO" << std::endl;
    std::cout << std::endl;
    p->print();

    std::cout << std::endl;

    std::string resp = (p->buscar(1))?"SIM":"NAO";
    std::cout << resp << std::endl;
    resp = (p->buscar(12))?"SIM":"NAO";
    std::cout << resp << std::endl;
}