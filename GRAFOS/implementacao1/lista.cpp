#include <iostream>

class Cell {
    public:
    int elemento;
    Cell* prox;

    Cell(int elemento, Cell* prox = nullptr) : elemento(elemento) , prox(prox){};
};

class List {
    public:
    Cell* inicio;
    Cell* fim;
    int tam;

    List() : inicio(nullptr), fim(nullptr), tam(0){};

    void addFim(int e){
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

    void addInicio(int e){
        if (inicio == nullptr){
            inicio = new Cell(e);
            fim = inicio;
            tam++;
        } else {
            inicio = new Cell(e, inicio);
            tam++;
        }
    }

    void addPos(int e, int p){
        Cell* tmp = inicio;
        if (p > tam){
            std::cout << "POSICAO " << p << " INVALIDA, ELEMENTO " << e << " NAO ADICIONADO"  << std::endl << std::endl;
        } else {
            if (p == 0){
                addInicio(e);
            } else if (p == tam) {
                addFim(e);
            } else {
                for(int i = 0; i < p; i++){
                    tmp = tmp->prox;
                }
                tmp->prox = new Cell(e, tmp->prox);
                tam++;
            }
        }
    }

    int rmFim(){
        Cell* tmp = inicio;
        int e;
        if (tam == 0){
            return 0;
        }
        if (tam == 1){
            e = rmInicio();
            return e;
        }
        for (int i = 0; i < tam - 2; i++){
            tmp = tmp->prox;
        }
        e = tmp->prox->elemento;
        tmp->prox = nullptr;
        tam--;
        return e;
    }
    
    int rmInicio(){
        if(inicio == nullptr){
            return 0;
        }
        int e = inicio->elemento;
        inicio = inicio->prox;
        tam--;
        return e;
    }

    int rmPos(int p){
        Cell* tmp = inicio;
        int e;
        if (p > tam){
            std::cout << "POSICAO INVALIDA" << std::endl;
        } else {
            if (p == 0){
                e = rmInicio();
            } else if (p == tam) {
                e = rmFim();
            } else {
                for(int i = 0; i < p - 1; i++){
                    tmp = tmp->prox;
                }
                e = tmp->prox->elemento;
                tmp->prox = tmp->prox->prox;
                tam--;
            }
        }
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
    std::cout << "ARTHUR GONCALVES DE MORAES - 816479" << std::endl << "IMPLEMENTACAO 1: LISTA ENCADEADA" << std::endl << std::endl;
    
    List* l = new List();

    l->addFim(9);
    l->addFim(6);
    l->addFim(7);
    l->addFim(8);
    l->addPos(3, 2);
    l->addPos(5, 7);
    l->addInicio(1);
    l->addInicio(2);
    l->addPos(5, 0);
    l->addPos(5, 7);
    l->print();

    std::cout << std::endl;

    std::cout << "ELEMENTO " << l->rmFim() << " REMOVIDO" << std::endl;
    std::cout << "ELEMENTO " << l->rmInicio() << " REMOVIDO" << std::endl;
    std::cout << "ELEMENTO " << l->rmInicio() << " REMOVIDO" << std::endl;
    std::cout << "ELEMENTO " << l->rmPos(3) << " REMOVIDO" << std::endl;
    std::cout << std::endl;
    l->print();

    std::cout << std::endl;

    std::string resp = (l->buscar(1))?"SIM":"NAO";
    std::cout << resp << std::endl;
    resp = (l->buscar(12))?"SIM":"NAO";
    std::cout << resp << std::endl;
}