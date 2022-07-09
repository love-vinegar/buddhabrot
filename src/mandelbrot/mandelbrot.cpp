#include "mandelbrot.h"

void Mandelbrot::OneStep(){
	z = pow(z, 2) + c;
}

bool Mandelbrot::IsInSet(){
	return (abs(z) < 2);	
}

bool Mandelbrot::Steps(int NumberOfSteps){
	for(int i = 0; i < NumberOfSteps; ++i){
		if(!IsInSet()){
			return false;
		}
		OneStep();
			
	}
	return true;
}

complex<double> Mandelbrot::GetValue(){	
	return z;
}

