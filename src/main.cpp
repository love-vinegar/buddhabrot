#include <iostream>
#include <complex>
#include <vector>
#include "mandelbrot/mandelbrot.h"
#include "bitmap/bitmap.h"

using namespace std;
using namespace std::complex_literals;

int main ( void ) { 
	int width = 512;

	Bitmap bm (width);

	for(int i = 0; i < width; ++i){
		for(int j = 0; j < width; ++j){
			//Make coresponding complex number
			complex<double> z ((((double)j)*4/width)-2,
					((((double)i)*4/width)-2));

			//makes claculations 
			Mandelbrot m (z);
			vector<complex<double>> path = m.Steps(1000);

			if(!m.IsInSet()){
				for(auto & item : path){
					//je asi chyba v zaokrouhlovani 
					int x,y;
					y = ((real(item) +2 )* width)/4;
					x = ((imag(item) +2 )* width)/4;

					bm.Increse(x,y,1);
				}
			}
		}
	}
	/*
	   for( int i = 0; i < 1000; i++){
	   int max = 1000000;
	   double randomy = ((double)(rand() % max) / (double)max)* 4 - 2;
	   double randomx = ((double)(rand() % max) / (double)max)* 4 - 2;
	   complex<double> z (randomx, randomy);

	   Mandelbrot m (z);
	   vector<complex<double>> path = m.Steps(1000);

	   if(!m.IsInSet()){
	   for(auto & item : path){
	//je asi chyba v zaokrouhlovani 
	int x,y;
	y = ((real(item) +2 )* width)/4;
	x = ((imag(item) +2 )* width)/4;

	bm.Increse(x,y,1);
	}
	}
	}
	 */
	bm.OutputToFile("test.ppm");
}


