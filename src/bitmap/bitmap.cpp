#include "bitmap.h"

void Bitmap::Set(int x, int y, int item){
	if(x < size && y < size && x >= 0 && y >= 0){
		arr[x][y] = item;	
		if(item > max)
			max = item;
	}
}

int Bitmap::Get(int x, int y)const{
	if(x < size && y < size && x >= 0 && y >= 0){
		return arr[x][y];	
	}
	return -1;
}

ostream& operator<<(ostream& os, const Bitmap& dt)
{
	for(int i = 0 ; i < dt.size ; ++ i){
		for(int j = 0 ; j < dt.size ; ++ j){
			os << ((dt.Get(i,j) == 0) ? " " : "X");
		}
		os << endl;
	}

	return os;
}

void Bitmap::OutputToFile(string path){

	ofstream img (path);
	img << "P3" << endl;
	img << size << " " << size << endl;
	img << 255 << endl;

	int r, g, b;

	for(int i = 0; i < size ; ++ i) {
		for(int j = 0; j < size; ++ j){

			if(arr[i][j] < 255)
				r = g = b = arr[i][j];
			else
				r = g = b = 255;

			img << r << " " << g << " " << b << endl;
		}
	}
	string ss = "open " + path;
	system(ss.c_str()); // for testing purpuces
}

void Bitmap::Increse(int x, int y, int n){
	if(x < size && y < size && x >= 0 && y >= 0){
		arr[x][y] += n;
		if(arr[x][y] > max){
			max = arr[x][y];
		}
	}
}
