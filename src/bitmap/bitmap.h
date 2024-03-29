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
			max = 0;
			this->size = size;
			arr = new unsigned int*[size];
			for(int i = 0; i <size; ++i){
				arr[i] = new unsigned int[size];
				for(int j = 0; j < size; ++ j){
					arr[i][j] = 0;
				}
			}
			
		}

		~Bitmap(){
			for(int i = 0; i < size; ++ i){
				delete[] arr[i];
			}
			delete [] arr;
		}

		void Set(int, int, unsigned int);
		int Get(int, int) const;
		friend ostream& operator<<(ostream& os, const Bitmap& dt);
		void OutputToFile(string path);
		void Increse(int, int , int);
		static void OutputRGB(Bitmap& R, Bitmap& G, Bitmap& B, string path);
		static void OutputHSV(Bitmap& R, Bitmap& G, Bitmap& B, string path);
		unsigned int max;
	private:
		static void HSVtoRGB(double,double,double,double&,double&,double&);
		static void printProgress(int);
		unsigned int** arr;	
};
#endif
