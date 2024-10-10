#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

typedef pair<int, int> pii;

void printPath(int start, int end, const vector<int>& parent) {
    if (end == start) {
        cout << start << " ";
        return;
    }
    printPath(start, parent[end], parent);
    cout << end << " ";
}

void dijkstra(int start, const vector<vector<int>>& matrix, vector<int>& dist, int V, vector<int>& parent) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();

        if (!(uDist > dist[u])){
            for (int v = 0; v < V; v++) {
                int weight = matrix[u][v];
                if (weight != INT_MAX && dist[u] + weight < dist[v]) { 
                    dist[v] = dist[u] + weight;
                    parent[v] = u; 
                    pq.push({dist[v], v});
                }
            }
        }

        
    }
}

bool readGraph(int *V, int *E, int *start, int *end, vector<vector<int>> &matrix) {
    ifstream inputFile("graph_input.txt");

    if (!inputFile) {
        cerr << "Erro ao abir arquivo" << endl;
        return 0;
    }

    inputFile >> *V >> *E;
    if(inputFile.fail()){
        cerr << "Erro ao ler quantidade de vertices e arestas" << endl;
        return 0;
    }

    matrix.resize(*V, vector<int>(*V, INT_MAX));
    for (int i = 0; i < *V; i++) {
        matrix[i][i] = 0;
    }

    for (int i = 0; i < *E; i++) {
        int u, v, w;
        inputFile >> u >> v >> w;
        if(inputFile.fail()){
            cerr << "Erro ao ler arestas" << endl;
            return 0;
        }
        matrix[u][v] = w; 
    }

    inputFile >> *start >> *end;
    if(inputFile.fail()){
        cerr << "Erro ao ler vertices de inicio e fim" << endl;
        return 0;
    }

    if((*start < 0 || *start > *V - 1) || (*end < 0 || *end > *V - 1)){
        cerr << "Vertice de inico ou fim invalido" << endl;
        return 0;
    }

    inputFile.close();
    return 1;
}

int main() {
    int  V, E, start, end;
    vector<vector<int>> matrix;

    cout << "IMPLEMENTACAO DIJKSTRA - ARTHUR GONCALVES DE MORAES\n" << endl;

    if (!readGraph(&V, &E, &start, &end, matrix)) {
        cerr << "Programa encerrado" << endl;
        return 1;
    }

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);  
    parent[start] = start;
    dijkstra(start, matrix, dist, V, parent);

    if (dist[end] == INT_MAX) {
        cout << "Vertice " << end << " nao e' alcancado por " << start << ".\n";
    } else {
        cout << "O menor caminho de " << start << " a " << end << " vale: " << dist[end] << "\n";
        cout << "Caminho: ";
        printPath(start, end, parent);  
        cout << endl;
    }

    return 0;
}

