#include "bitmap.h"

void Bitmap::Set(int x, int y, int item){
	if(x < size && y < size && x >= 0 && y >= 0){
		arr[x][y] = item;	
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


