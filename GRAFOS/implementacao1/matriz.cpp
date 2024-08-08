#include <iostream>

class Cell {
    public:
    int elemento;
    Cell* nxtRow;
    Cell* nxtCol;

    Cell(int elemento = -1, Cell* nxtRow = nullptr, Cell* nxtCol = nullptr) : elemento(elemento) , nxtRow(nxtRow), nxtCol(nxtCol){};
};

class Matriz{
    public:
    int row;
    int col;
    Cell* inicio;

    Matriz(int row, int col) : row(row), col(col), inicio(nullptr){
        if (row > 0 && col > 0){
            inicio = new Cell();

            Cell* tmpR = inicio;
            Cell* tmpC;

            for (int r = 0; r < row; r++) {
            tmpC = tmpR;
                for (int c = 0; c < col - 1; c++) {
                    tmpC->nxtCol = new Cell();
                    tmpC = tmpC->nxtCol;
                }
                if (r < row - 1) {
                    tmpR->nxtRow = new Cell();
                    tmpR = tmpR->nxtRow;
                }
            }
        }
    };

    Cell* getCell(int r, int c){
        Cell* tmp = inicio;
        for (int i = 0; i < r - 1; i++){
            tmp = tmp->nxtRow;
        }

        for (int j = 0; j < c - 1; j++){
            tmp = tmp->nxtCol;
        }

        return tmp;
    }

    void setValue(int r, int c, int e){
        if (r <= row && c <= col && r > 0 && c > 0){
            Cell* pos = getCell(r, c);
            pos->elemento = e;
        } else {
            std::cout<< std::endl << "POSICAO (" << r << "," << c << ") INVALIDA";
        }
    }

    int deleteValue(int r, int c){
        if (r <= row && c <= col && r > 0 && c > 0){
            Cell* pos = getCell(r, c);
            int e = pos->elemento;
            pos->elemento = -1;
            return e;
        } else {
            std::cout<< std::endl << "POSICAO (" << r << "," << c << ") INVALIDA";
        }
        return -1;
    }

    bool buscar(int e){
        Cell* r = inicio;
        Cell* c;
        while (r != nullptr) {
            c = r;
            while (c != nullptr) {
                if (e == c->elemento){
                    return 1;
                }
                c = c->nxtCol;
            }
            r = r->nxtRow;
        }
        return 0;
    }

    void print(){
        Cell* r = inicio;
        Cell* c;
        while (r != nullptr) {
            c = r;
            while (c != nullptr) {
                std::cout << c->elemento << " ";
                c = c->nxtCol;
            }
            std::cout << std::endl;
            r = r->nxtRow;
        }
    }


};

int main(){
    std::cout << "ARTHUR GONCALVES DE MORAES - 816479" << std::endl << "IMPLEMENTACAO 1: MATRIZ" << std::endl;

    Matriz* m = new Matriz(3,3);

    m->setValue(3,2,1);
    m->setValue(3,3,7);
    m->setValue(3,4,3);
    m->setValue(1,1,4);
    m->setValue(2,2,9);
    m->setValue(3,1,2);
    m->setValue(1,2,8);
    m->setValue(1,3,6);
    m->setValue(2,1,5);
    m->setValue(2,3,3);
    m->setValue(-1,3,3);

    std::cout << std::endl;

    m->print();

    m->deleteValue(1,1);
    m->deleteValue(3,2);
    m->deleteValue(4,2);
    m->deleteValue(2,2);

    std::cout << std::endl;

    m->print();

    std::cout << std::endl;

    std::string resp = (m->buscar(1))?"SIM":"NAO";
    std::cout << resp << std::endl;
    resp = (m->buscar(12))?"SIM":"NAO";
    std::cout << resp << std::endl;
    resp = (m->buscar(5))?"SIM":"NAO";
    std::cout << resp << std::endl;
}