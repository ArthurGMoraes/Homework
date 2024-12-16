#ifndef SEGMENT
#define SEGMENT

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

#include "Matrix.hpp"
#include "Graph.hpp"

using namespace std;

// Max-Flow using Edmonds-Karp (BFS-based Ford-Fulkerson)

// O(VxE^2) muito lentooooo (aprox O(n^3)) 
float maxFlow(Graph& graph, int source, int sink) {
    float max_flow = 0;
    vector<int> parent(graph.size());

    while (true) {
        // BFS to find an augmenting path
        fill(parent.begin(), parent.end(), -1);
        queue<pair<int, float>> q;
        q.emplace(source, numeric_limits<float>::infinity());

        while (!q.empty() && parent[sink] == -1) {
            int curr = q.front().first;
            float flow = q.front().second;
            q.pop();

            for (int idx : graph.getAdj(curr)) {
                Edge& edge = graph.getEdge(idx);
                if (parent[edge.to] == -1 && edge.capacity > edge.flow && edge.to != source) {
                    parent[edge.to] = idx;
                    float new_flow = min(flow, edge.capacity - edge.flow);
                    if (edge.to == sink) {
                        max_flow += new_flow;

                        // Augment flow along the path
                        int node = sink;
                        while (node != source) {
                            int edge_idx = parent[node];
                            graph.getEdge(edge_idx).flow += new_flow;
                            graph.getEdge(edge_idx ^ 1).flow -= new_flow;
                            node = graph.getEdge(edge_idx).from;
                        }
                        goto augment_found;
                    }
                    q.emplace(edge.to, new_flow);
                }
            }
        }
        break;
    augment_found:;
    }
    return max_flow;
}

Matrix segmentImage(const Matrix& image, float lambda, float sigma) {
    int height = image.height;
    int width = image.width;
    int num_nodes = height * width;
    int source = num_nodes;
    int sink = num_nodes + 1;
    Graph graph(num_nodes + 2);

    

    auto getNode = [&](int i, int j) { return i * width + j; };
    

    cout << "links ";
    // Add edges
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int curr = getNode(i, j);
            float intensity = image.getValue(i, j) / 255.0f;

            // T-links
            graph.addEdge(source, curr, lambda * (1.0f - intensity));
            graph.addEdge(curr, sink, lambda * intensity);

            // N-links
            if (i > 0) {
                int up = getNode(i - 1, j);
                float weight = exp(-pow(image.getValue(i, j) - image.getValue(i - 1, j), 2) / (2 * sigma * sigma));
                graph.addEdge(curr, up, weight);
                graph.addEdge(up, curr, weight);
            }
            if (j > 0) {
                int left = getNode(i, j - 1);
                float weight = exp(-pow(image.getValue(i, j) - image.getValue(i, j - 1), 2) / (2 * sigma * sigma));
                graph.addEdge(curr, left, weight);
                graph.addEdge(left, curr, weight);
            }
        }
    }
    

    // Compute max flow
    cout << "maxFLow ";
    maxFlow(graph, source, sink);
    

    // Generate segmentation
    cout << "seg ";
    Matrix segmentation(height, width);
    vector<bool> visited(num_nodes + 2, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int idx : graph.getAdj(node)) {
            Edge& edge = graph.getEdge(idx);
            if (!visited[edge.to] && edge.capacity > edge.flow) {
                visited[edge.to] = true;
                q.push(edge.to);
            }
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            segmentation[i][j] = visited[getNode(i, j)] ? 255 : 0;
        }
    }
   
    return segmentation;
}

void printSegmentationPPM(const Matrix& segmentation, const string& filename) {
    cout << "print";
    ofstream outFile("output/" + filename);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    int height = segmentation.height;
    int width = segmentation.width;

    // PPM header: P3 for ASCII color, width and height, and max intensity (255)
    outFile << "P3\n";  // PPM header for ASCII color
    outFile << width << " " << height << "\n";  // Image dimensions
    outFile << "255\n";  // Maximum pixel value (color)

    // Assign colors for segmented areas (binary segmentation)
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (segmentation[i][j] == 255) {
                outFile << "255 0 0 ";  // Red for object
            } else {
                outFile << "0 0 255 ";  // Blue for background
            }
        }
        outFile << "\n";  // End of row
    }

    outFile.close();
    cout << "Segmentation saved as " << filename << endl;
}

#endif