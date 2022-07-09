#pragma once
#ifndef MANDELBROT_H
#define MANDELBORT_H
#include <iostream>
#include <complex>

using namespace std;
using namespace std::complex_literals;

class Mandelbrot{
	public:

		Mandelbrot(complex<double> initial){	
			z = initial;
			c = initial;
		}

		void OneStep();
		bool Steps(int);
		bool IsInSet();
		complex<double> GetValue();

	private:
	complex<double> z,c;

};
#endif
