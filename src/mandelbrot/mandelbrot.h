#pragma once
#ifndef MANDELBROT_H
#define MANDELBORT_H
#include <iostream>
#include <complex>
#include <vector>

using namespace std;
using namespace std::complex_literals;

class Mandelbrot{
	public:

		Mandelbrot(complex<double> initial, complex<double> seed){	
			z = initial;
			c = seed;
			NofSteps = 0;
		}

		Mandelbrot(complex<double> initial){	
			z = initial;
			c = initial;
			NofSteps = 0;
		}
		void OneStep();
		vector<complex<double>> Steps(int);
		bool IsInSet();
		complex<double> GetValue();
		double SquereAbs(complex<double>);
		int GetSteps();

	private: 
		complex<double> z;
		complex<double> c;
		int NofSteps;
};
#endif
