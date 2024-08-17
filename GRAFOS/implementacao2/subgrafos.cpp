#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Função para calcular o fatorial de um número
int fatorial(int n) {
    int fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

// Função para calcular o somatório (número total de subgrafos)
int somatorio(int n) {
    int somatorio = 0;
    for (int j = 1; j <= n; j++) {
        int tmp1 = fatorial(n) / (fatorial(j) * fatorial(n - j));
        int tmp2 = (j * (j - 1)) / 2;
        tmp2 = pow(2, tmp2);
        somatorio += (tmp1 * tmp2);
    }
    return somatorio;
}

// Função para imprimir todos os subgrafos possíveis
void listarSubgrafos(int n) {
    int total_subgrafos = somatorio(n);
    cout << "Total de subgrafos possiveis: " << total_subgrafos << endl;

    // Percorre todas as combinações possíveis de vértices
    for (int i = 1; i < pow(2,n); i++) {
        vector<int> vertices;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                vertices.push_back(j + 1);
            }
        }

        // Número de vértices no subgrafo atual
        int v_size = vertices.size();
        int num_arestas = (v_size * (v_size - 1)) / 2;

        // Percorre todas as combinações possíveis de arestas
        for (int k = 0; k < (1 << num_arestas); k++) {
            cout << "Subgrafo: { ";
            for (int v : vertices) {
                cout << v << " ";
            }
            cout << "} - Arestas: { ";

            int edge_count = 0;
            for (int x = 0; x < v_size; x++) {
                for (int y = x + 1; y < v_size; y++) {
                    if (k & (1 << edge_count)) {
                        cout << "(" << vertices[x] << ", " << vertices[y] << ") ";
                    }
                    edge_count++;
                }
            }
            cout << "}" << endl;
        }
    }
}

int main() {
    int n;
    cout << "Numero de vertices: ";
    cin >> n;

    listarSubgrafos(n);
}
