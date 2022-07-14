#include <iostream>
#include <complex>

#include "mandelbrot/mandelbrot.h"
#include "bitmap/bitmap.h"

using namespace std;
using namespace std::complex_literals;

int main ( void ) { 
	int width = 1024;

	Bitmap bm (width);
	
	for(int i = 0; i < width; ++i){
		for(int j = 0; j < width; ++j){
			//Make coresponding complex number
			complex<double> z ((((double)j)*4/width)-2,
					((((double)i)*4/width)-2));

			//makes claculations 
			Mandelbrot m (z);
			m.Steps(25);

			//outputs
			bm.Set(i,j,m.IsInSet());
		}
	}
	bm.OutputToFile("test.ppm");
}



