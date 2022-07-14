#include "mandelbrot.h"

void Mandelbrot::OneStep(){
	z = pow(z, 2) + c;
}

bool Mandelbrot::IsInSet(){
	return (abs(z) < 2);	
}

vector<complex<double>> Mandelbrot::Steps(int NumberOfSteps){
	vector<complex<double>> ret;
	for(int i = 0; i < NumberOfSteps; ++i){
		ret.push_back(z);
		
		if(!IsInSet()){
			NofSteps = i;
			return ret;
		}
		OneStep();
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
