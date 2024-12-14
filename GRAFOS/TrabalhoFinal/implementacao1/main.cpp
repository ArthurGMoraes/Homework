#include <iostream>
#include <fstream>
#include <stdexcept>

#include "code/imageToMatrix.hpp"
#include "code/Matrix.hpp"
#include "code/segment.hpp"

using namespace std;


int main(){
    try{
        Matrix image = loadPGM("pinguins.pgm");
        double k = 5000.0;

        // Perform segmentation
        vector<int> labels = segmentImagePGM(image, k);

        // Print result
        printSegmentationPPM(labels, image.width, image.height, "pinguinsK5000.ppm");
    } catch (const exception& e) {
		cerr << e.what() << '\n';
	}
}