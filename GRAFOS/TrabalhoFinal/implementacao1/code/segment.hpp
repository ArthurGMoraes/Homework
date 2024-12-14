#ifndef SEGMENT
#define SEGMENT

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <random>
#include <stdexcept>

#include "Matrix.hpp"

using namespace std;

int dX[4] = {-1, 1, 0, 0};
int dY[4] = {0, 0, -1, 1};

// Calcula a dissimilaridade
float dissimilarity(int a, int b) {
	return abs(a-b);
}

// Arestas
struct Edge {
    int u, v;       // vértices
    double w;       // peso
};

// Componente
struct Component {
    int parent;         // predecessor
    int size;           // tamanho
    double maxWeight;   // maior peso no componente
};

// Find the root of a component with path compression
int findRoot(vector<Component>& components, int node) {
    if (components[node].parent != node)
        components[node].parent = findRoot(components, components[node].parent);
    return components[node].parent;
}

// Union of two components
void unionComponents(vector<Component>& components, int root1, int root2, double weight) {
    if (components[root1].size < components[root2].size)
        swap(root1, root2);

    components[root2].parent = root1;
    components[root1].size += components[root2].size;
    components[root1].maxWeight = max(components[root1].maxWeight, weight);
}

// Main segmentation function
vector<int> segmentImagePGM(Matrix image, double k) {
    //cout << "AAAAAAAAAA"
    int height = image.height;
    int width = image.width;
    vector<Edge> edges;
    
    // Create edges based on 4-connected neighbors
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int node = y * width + x;

            if (x < width - 1) { // Right neighbor
                int neighbor = node + 1;
                edges.push_back({node, neighbor,dissimilarity(image[y][x], image[y][x + 1])});
            }

            if (y < height - 1) { // Bottom neighbor
                int neighbor = node + width;
                edges.push_back({node, neighbor, dissimilarity(image[y][x], image[y+1][x])});
            }
        }
    }

    //cout << "AAAAAAAAAA";

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    // Initialize components
    vector<Component> components(width * height);
    for (int i = 0; i < width * height; ++i) {
        components[i] = {i, 1, 0.0};
    }

    // Merge components based on edge weights
    for (const auto& edge : edges) {
        int root1 = findRoot(components, edge.u);
        int root2 = findRoot(components, edge.v);

        if (root1 != root2) {
            double threshold1 = components[root1].maxWeight + k / components[root1].size;
            double threshold2 = components[root2].maxWeight + k / components[root2].size;

            if (edge.w <= min(threshold1, threshold2)) {
                unionComponents(components, root1, root2, edge.w);
            }
        }
    }

    // Assign component labels
    vector<int> labels(width * height);
    for (int i = 0; i < width * height; ++i) {
        labels[i] = findRoot(components, i);
    }

    return labels;
}

void printSegmentationPPM(const vector<int>& labels, int width, int height, const string& filename) {
    ofstream outFile("output/" + filename);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    // PPM header: P3 for ASCII color, width and height, and max intensity (255)
    outFile << "P3\n";  // PPM header for ASCII color
    outFile << width << " " << height << "\n";  // Image dimensions
    outFile << "255\n";  // Maximum pixel value (color)

    // Find the unique labels
    vector<int> uniqueLabels = labels;
    sort(uniqueLabels.begin(), uniqueLabels.end());
    uniqueLabels.erase(unique(uniqueLabels.begin(), uniqueLabels.end()), uniqueLabels.end());

    // Assign a random RGB color to each label
    vector<vector<int>> labelColors(uniqueLabels.size(), vector<int>(3));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 255);

    for (size_t i = 0; i < uniqueLabels.size(); ++i) {
        labelColors[i] = {dist(gen), dist(gen), dist(gen)}; // Random RGB color
    }

    // Write pixel colors to the file based on the labels
    for (int i = 0; i < width * height; ++i) {
        int labelIndex = find(uniqueLabels.begin(), uniqueLabels.end(), labels[i]) - uniqueLabels.begin();
        outFile << labelColors[labelIndex][0] << " "
                << labelColors[labelIndex][1] << " "
                << labelColors[labelIndex][2] << " ";

        if ((i + 1) % width == 0) {
            outFile << "\n";  // End of row
        }
    }

    outFile.close();
    cout << "Color segmentation saved to " << filename << endl;
}

#endif