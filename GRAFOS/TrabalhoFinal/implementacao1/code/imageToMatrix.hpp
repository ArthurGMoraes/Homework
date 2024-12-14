#ifndef IMAGE_TO_MATRIX
#define IMAGE_TO_MATRIX

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "Matrix.hpp"

using namespace std;

Matrix loadPGM(string filename) {

    ifstream file("input/"+filename, ios::binary);

    if (!file) {
	   throw runtime_error("Erro ao abrir arquivo " + filename);
    }

    string format;
    file >> format;

    if (format != "P2" && format != "P5") {
		throw runtime_error("Formato não suportado" + format);
    }

    // Read image dimensions and max value
    int width, height, maxVal;
    file >> width >> height >> maxVal;

    // Skip single whitespace
    file.ignore();

    // Prepare a matrix to hold the pixel data
    Matrix image(height, width);

	if (format == "P2") {
		// ASCII format
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				file >> image[i][j];
			}
		}
	}

	else if (format == "P5") {

		// Binary format
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				image[i][j] = file.get();
			}
		}
	}

	file.close();

	return image;
}

#endif
