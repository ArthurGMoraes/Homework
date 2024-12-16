#ifndef GRAPH
#define GRAPH

#include <vector>

using namespace std;

// Graph edge structure
struct Edge {
    int from, to;
    float capacity;
    float flow;
    Edge(int from, int to, float capacity) : from(from), to(to), capacity(capacity), flow(0) {}
};

class Graph {
    vector<vector<int>> adj;
    vector<Edge> edges;

public:
    explicit Graph(int n) : adj(n) {}

    void addEdge(int from, int to, float capacity) {
        edges.emplace_back(from, to, capacity);
        edges.emplace_back(to, from, 0); // Reverse edge with zero initial capacity
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }

    const vector<int>& getAdj(int node) const {
        return adj[node];
    }

    Edge& getEdge(int index) {
        return edges[index];
    }

    int size() const {
        return adj.size();
    }
};

#endif