#include "bitmap.h"

void Bitmap::printProgress(int percentage) {
	cout << "\r";
	cout << "[";
	for(int i = 0 ; i < 100; ++ i ){
		if( i < percentage)
		cout << "#";
		else
		cout << " ";
	}
	cout << "] " << percentage << "%";
	
	cout << flush;
}

void Bitmap::Set(int x, int y,unsigned int item){
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
	int perc = -1;
	cout << "outputing picture" << endl;
	for(int i = 0; i < size ; ++ i) {

		for(int j = 0; j < size; ++ j){
			r = g = b = (((double)255) / max) * arr[j][i]; 
			img << r << " " << g << " " << b << endl;
		}

		if(perc != (100 * i) / size){
			perc = (100 * i) / size;
			printProgress(perc);
		}
	}
	printProgress(100);
	cout << endl << "all finished" << endl;

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
void Bitmap::OutputRGB(Bitmap& R, Bitmap& G, Bitmap& B, string path){
	ofstream img (path);
	img << "P3" << endl;
	img << R.size << " " << R.size << endl;
	img << 255 << endl;

	int r, g, b;
	int perc = -1;
	cout << "outputing picture" << endl;
	for(int i = 0; i < R.size ; ++ i) {
		for(int j = 0; j < R.size; ++ j){
			r = (((double)255) / R.max) * R.Get(j,i); 
			g = (((double)255) / G.max) * G.Get(j,i); 
			b = (((double)255) / B.max) * B.Get(j,i); 
			img << r << " " << g << " " << b << endl;
		}

		if(perc != (100 * i) / R.size){
			perc = (100 * i) / R.size;
			printProgress(perc);
		}
	}
	printProgress(100);
	cout << endl << "all finished" << endl;

	string ss = "open " + path;

	system(ss.c_str()); 
}

void Bitmap::OutputHSV(Bitmap& H, Bitmap& S, Bitmap& V, string path){

	ofstream img (path);

	img << "P3" << endl;
	img << H.size << " " << H.size << endl;
	img << 255 << endl;

	double h,s,v;
	double r, g, b;
	int perc = -1;
	cout << "outputing picture" << endl;

	//H je do 360
	//S a B je do 100
	for(int i = 0; i < H.size; ++ i) {
		for(int j = 0; j < H.size; ++ j){
			h = (((double)360) / H.max) * H.Get(j,i); 
			s = (((double)100) / S.max) * S.Get(j,i); 
			v = (((double)100) / V.max) * V.Get(j,i); 
			
			h += 180;
			if(h > 360)
				h -= 360;
			
			HSVtoRGB(h,s,v,r,g,b);
			img << (int)r << " " << (int)g << " " << (int)b << endl;
		}

		if(perc != (100 * i) / H.size){
			perc = (100 * i) / H.size;
			printProgress(perc);
		}
	}

	printProgress(100);
	cout << endl << "all finished" << endl;

	string ss = "open " + path;
	system(ss.c_str()); 
}

//copied from somewhere
void Bitmap::HSVtoRGB(double H, double S,double V, double & R, double & G, double & B){

    if(H>360 || H<0 || S>100 || S<0 || V>100 || V<0){
        cout<<"The givem HSV values are not in valid range"<<endl;
        return;
    }

    double s = S/100;
    double v = V/100;
    double C = s*v;
    double X = C*(1-abs(fmod(H/60.0, 2)-1));
    double m = v-C;
    double r,g,b;

    if(H >= 0 && H < 60){
        r = C,g = X,b = 0;
    }
    else if(H >= 60 && H < 120){
        r = X,g = C,b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0,g = C,b = X;
    }
    else if(H >= 180 && H < 240){
        r = 0,g = X,b = C;
    }
    else if(H >= 240 && H < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }

    R = (r+m)*255;
    G = (g+m)*255;
    B = (b+m)*255;
}
