#include "mandelbrot.h"

void Mandelbrot::OneStep(){
	z = pow(z, 2) + c;
}

bool Mandelbrot::IsInSet(){
	return (abs(z) < 2);	
}

