#pragma once
#ifndef BITMAP_H
#define BITMAP_H
#include <iostream>
#include <complex>
#include <fstream>

using namespace std;
using namespace std::complex_literals;

class Bitmap{
	public:
		int size;
		Bitmap(int size){	
			this->size = size;
			arr = new int*[size];
			for(int i = 0; i <size; ++i){
				arr[i] = new int[size];
			}
		}
		void Set(int, int, int);
		int Get(int, int) const;
		friend ostream& operator<<(ostream& os, const Bitmap& dt);
		void OutputToFile(string path);
	private:
		int** arr;	
};
#endif
