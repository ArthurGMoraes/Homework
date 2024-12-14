#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    vector<vector<int>> matrix;

public:
    const int height, width;

    Matrix(int height, int width) : height(height), width(width), matrix(height, vector<int>(width, 0)) {}

    void setValue(int h, int w, float weight) {
        matrix[h][w] = weight;
    }

    int getValue(int h, int w) const {
        return matrix[h][w];
    }

    vector<int>& operator[](int index) {
        return matrix[index];
    }

    const vector<int>& operator[](int index) const {
        return matrix[index];
    }

    void print() const {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif
