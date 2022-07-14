#include <iostream>
#include <complex>
#include <vector>

#include "mandelbrot/mandelbrot.h"
#include "bitmap/bitmap.h"

using namespace std;
using namespace std::complex_literals;

int main ( void ) { 
	int width = 500;

	Bitmap bm (width);
	
	for(int i = 0; i < width; ++i){
		for(int j = 0; j < width; ++j){
			//Make coresponding complex number
			complex<double> z ((((double)j)*4/width)-2,
					((((double)i)*4/width)-2));

			//makes claculations 
			Mandelbrot m (z);
			vector<complex<double>> path = m.Steps(100000);

			if(!m.IsInSet()){
				for(auto & item : path){
					//cout << real(item) << " <> " << imag(item) << endl;
					int x,y;
					y = ((real(item) +2 )* width)/4;
					x = ((imag(item) +2 )* width)/4;
					//bm.Set(x, y, 1);
					bm.Increse(x,y,1);
				}


			}

			//outputs
			/*if(m.IsInSet())
				bm.Set(i,j,-1);
			else
				bm.Set(i,j,m.GetSteps());
				*/
		}
	}
	bm.OutputToFile("test.ppm");
}



