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

		Mandelbrot(complex<double> initial){	
			z = initial;
			c = initial;
			NofSteps = 0;
		}

		void OneStep();
		vector<complex<double>> Steps(int);
		bool IsInSet();
		complex<double> GetValue();
		int GetSteps();

	private:
	complex<double> z,c;
	int NofSteps;

};
#endif
