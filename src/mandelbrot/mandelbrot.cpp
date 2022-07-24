#include "mandelbrot.h"

bool Mandelbrot::IsInSet(){
	return (SquereAbs(z) < 4);	
}

vector<complex<double>> Mandelbrot::Steps(int NumberOfSteps){
	vector<complex<double>> ret;
	for(int i = 0; i < NumberOfSteps; ++i){
		ret.push_back(z);

		if(!IsInSet()){
			NofSteps = i;
			return ret;
		}
		complex<double> temp ((real(z) * real(z)) - (imag(z) * imag(z)) + real(c),
				(2 * real(z) * imag(z)) + imag(c));
		z = temp;
	}

	NofSteps = NumberOfSteps;
	return ret;
}

complex<double> Mandelbrot::GetValue(){	
	return z;
}

int Mandelbrot::GetSteps(){
	return NofSteps;
}

double Mandelbrot::SquereAbs(complex<double> x){
	return real(x) * real(x) + imag(x) * imag(x);	
}
