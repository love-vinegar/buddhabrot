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
	int width = 128;
	int lastperc = -1;


	cout << "starting heatmap generation" << endl;

	long long int sample = width * width * 1000;
	int iterations[3]=  {500,5000,50};
	Bitmap R (width);
	Bitmap G (width);
	Bitmap B (width);
	Bitmap* bm[3] = {&R, &G, &B};

	complex<double> juliaSeed (-0.8, 0.156);

	for(int j = 0; j < 3; ++j){
		cout << endl <<  iterations[j] << " iterations" << endl;
		for(long long int i = 0; i < sample; ++i){
			int max = 1000000;
			double randomy = ((double)(rand() % max) / (double)max)* 4 - 2;
			double randomx = ((double)(rand() % max) / (double)max)* 4 - 2;
			complex<double> z (randomx, randomy);

			//Mandelbrot m (z, juliaSeed);
			Mandelbrot m (z);
			vector<complex<double>> path = m.Steps(iterations[j]);

			if(!m.IsInSet()){
				for(auto & item : path){
					int x,y;
					y = ((real(item) +2 )* width)/4;
					x = ((imag(item) +2 )* width)/4;

					bm[j]->Increse(x,y,1);
				}
			}

			if(lastperc != (i *100) / sample) {
				lastperc = (i * 100) / sample;
				iprintProgress(lastperc);
			}
		}
		iprintProgress(100);
	}

	cout << endl << "heat map done" << endl;
	
//	Bitmap::OutputRGB(R, R, R, "test.ppm");
	Bitmap::OutputRGB(R, G, B, "test.ppm");
//	Bitmap::OutputHSV(R, G, B, "test.ppm");

	//bm.OutputToFile("test.ppm");
}


