#include <iostream>
#include <complex>

using namespace std;

int main ( void ) { 
	using namespace std::complex_literals;
	int width = 50;
	int height = 50;

	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			complex<double> z ((((double)j)*4/width)-2,
					  ((((double)i)*4/height)-2));

			complex<double> c (real(z), imag(z));

			for(int l = 0; l < 10; ++l){
				z = pow(z,2) + c;
			}
			cout << ((abs(z) > 2) ? " " : "X") << flush;
		}
		cout << endl;
	}
}


