#include <iostream>
#include <fstream>
#include <stdexcept>

#include "code/imageToMatrix.hpp"
#include "code/Matrix.hpp"
#include "code/segment.hpp"

using namespace std;

int main(){
    try{
        Matrix image = loadPGM("pinguinsLowRes.pgm");
        float lambda = 10.0f;
        float sigma = 0.1f;

        Matrix segmented = segmentImage(image, lambda, sigma);

        // Print result
        printSegmentationPPM(segmented, "pinguinsLowRes.ppm");
        
    } catch (const exception& e) {
		cerr << e.what() << '\n';
	}   
}