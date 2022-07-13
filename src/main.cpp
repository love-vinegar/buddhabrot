#include <iostream>
#include <complex>

#include "mandelbrot/mandelbrot.h"
#include "bitmap/bitmap.h"

using namespace std;
using namespace std::complex_literals;

int main ( void ) { 
	int width = 50;
	int height = 50;

	Bitmap bm (50);
	
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			//Make coresponding complex number
			complex<double> z ((((double)j)*4/width)-2,
					((((double)i)*4/height)-2));
			//makes claculations 
			Mandelbrot m (z);
			m.Steps(10);

			//outputs
			bm.Set(i,j,m.IsInSet());
		}
	}
	cout << bm << endl;
}



