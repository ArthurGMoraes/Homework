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

        // Perform segmentation

        // Print result
        
    } catch (const exception& e) {
		cerr << e.what() << '\n';
	}   
}