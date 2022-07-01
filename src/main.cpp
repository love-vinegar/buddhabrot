#include <iostream>
#include <complex>

#include "mandelbrot/mandelbrot.h"

using namespace std;
using namespace std::complex_literals;

int main ( void ) { 
	int width = 50;
	int height = 50;

	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			complex<double> z ((((double)j)*4/width)-2,
					((((double)i)*4/height)-2));
			Mandelbrot m (z);
			int counter = 0;
			while(m.IsInSet() && counter++ < 10){
				m.OneStep();
			}
			cout << (!(m.IsInSet()) ? " " : "X") << flush;
		}
		cout << endl;
	}
}



