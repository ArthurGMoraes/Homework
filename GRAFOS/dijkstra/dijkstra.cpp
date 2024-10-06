#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

typedef pair<int, int> pii;

// Function to implement Dijkstra's algorithm
void dijkstra(int start, const vector<vector<int>>& matrix, vector<int>& dist, int V) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap priority queue
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();

        if (uDist > dist[u])
            continue;

        for (int v = 0; v < V; v++) {
            int weight = matrix[u][v];
            if (weight != INT_MAX && dist[u] + weight < dist[v]) { // Check if there's an edge
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int V, E, start, end;

    // Open the file for reading
    ifstream inputFile("graph_input.txt");

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Reading number of vertices and edges from the file
    inputFile >> V >> E;

    // Initialize adjacency matrix with INT_MAX
    vector<vector<int>> matrix(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < V; i++) {
        matrix[i][i] = 0; // Distance to itself is zero
    }

    // Reading the edges from the file
    for (int i = 0; i < E; i++) {
        int u, v, w;
        inputFile >> u >> v >> w;
        matrix[u][v] = w; // For directed graphs
        matrix[v][u] = w; // For undirected graphs
    }

    // Reading the starting and ending vertices from the file
    inputFile >> start >> end;

    // Close the input file
    inputFile.close();

    vector<int> dist(V, INT_MAX);
    dijkstra(start, matrix, dist, V);

    // Output the shortest distance to the end vertex
    if (dist[end] == INT_MAX) {
        cout << "Vertex " << end << " is unreachable from vertex " << start << ".\n";
    } else {
        cout << "Shortest distance from vertex " << start << " to vertex " << end << ": " << dist[end] << "\n";
    }

    return 0;
}

