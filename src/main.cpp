#include <iostream>
#include <complex>
#include <vector>
#include "mandelbrot/mandelbrot.h"
#include "bitmap/bitmap.h"

using namespace std;
using namespace std::complex_literals;

void iprintProgress(int percentage) {
	cout << "\r";
	cout << "[";
	for(int i = 0 ; i < 100; ++ i ){
		if( i < percentage)
		cout << "#";
		else
		cout << " ";
	}
	cout << "] " << percentage << "%";
	
	cout << flush;
}

int main ( void ) { 
	int width = 1024;
	int lastperc = -1;

	Bitmap bm (width);

	cout << "starting heatmap generation" << endl;

	 long long int sample = width * width * 100;
	 int iterat = 10000;

	for(long long int i = 0; i < sample; ++i){
		int max = 1000000;
		double randomy = ((double)(rand() % max) / (double)max)* 4 - 2;
		double randomx = ((double)(rand() % max) / (double)max)* 4 - 2;
		complex<double> z (randomx, randomy);

		Mandelbrot m (z);
		vector<complex<double>> path = m.Steps(iterat);

		if(!m.IsInSet()){
			for(auto & item : path){
				//je asi chyba v zaokrouhlovani 
				int x,y;
				y = ((real(item) +2 )* width)/4;
				x = ((imag(item) +2 )* width)/4;

				bm.Increse(x,y,1);
			}
		}
		
		if(lastperc != (i *100) / sample) {
			lastperc = (i * 100) / sample;
			iprintProgress(lastperc);
		}
	}
	
	iprintProgress(100);
	cout << endl << "heat map done" << endl;

	bm.OutputToFile("test.ppm");
}


