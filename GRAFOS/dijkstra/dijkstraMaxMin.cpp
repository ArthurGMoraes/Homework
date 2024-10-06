#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>

using namespace std;

typedef pair<int, int> pii; // pair for (edge_weight, vertex)

// Function to implement modified Dijkstra's algorithm
void DijkstraMaxMin(int start, const vector<vector<int>>& matrix, vector<int>& maxMinEdgeWeight, int V) {
    priority_queue<pii, vector<pii>, less<pii>> pq; // Max-heap priority queue
    pq.push({INT_MAX, start}); // Start with maximum possible weight
    maxMinEdgeWeight[start] = INT_MAX; // Initialize start vertex

    while (!pq.empty()) {
        int u = pq.top().second;
        int minWeight = pq.top().first;
        pq.pop();

        // Explore neighbors
        for (int v = 0; v < V; v++) {
            int weight = matrix[u][v];
            if (weight != INT_MAX) { // Check if there's an edge
                // Calculate the maximum of the minimum edge weight for the path to v
                int newMinWeight = min(minWeight, weight);
                if (newMinWeight > maxMinEdgeWeight[v]) {
                    maxMinEdgeWeight[v] = newMinWeight;
                    pq.push({newMinWeight, v});
                }
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
    }

    // Reading the starting and ending vertices from the file
    inputFile >> start >> end;

    // Close the input file
    inputFile.close();

    vector<int> maxMinEdgeWeight(V, INT_MIN); // Store the max of min edge weights
    DijkstraMaxMin(start, matrix, maxMinEdgeWeight, V);

    // Output the maximum of the minimum edge weights to the end vertex
    if (maxMinEdgeWeight[end] == INT_MIN) {
        cout << "Vertex " << end << " is unreachable from vertex " << start << ".\n";
    } else {
        cout << "Maximum of the minimum edge weights from vertex " << start << " to vertex " << end << ": " 
             << maxMinEdgeWeight[end] << "\n";
    }

    return 0;
}
