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

unsigned int Bitmap::Get(int x, int y)const{
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

void Bitmap::Increse(int x, int y, int n){
	if(x < size && y < size && x >= 0 && y >= 0){
		arr[x][y] += n;
		if(arr[x][y] > max){
			max = arr[x][y];
		}
	}
}

unsigned int Bitmap::FindSmallest(){
	unsigned int smallest = Get(0,0);

	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j){
			if(smallest > Get(i,j)){
				smallest = Get(i,j);
				if(smallest == 0)
					return 0;
			}
		}
	}
	return smallest;
}

void Bitmap::OutputRGB(Bitmap& R, Bitmap& G, Bitmap& B, string path){
	ofstream img (path);
	img << "P3" << endl;
	img << R.size << " " << R.size << endl;
	img << 255 << endl;

	int r, g, b;
	int perc = -1;
	unsigned int smallestR = R.FindSmallest();
	unsigned int smallestG = G.FindSmallest();
	unsigned int smallestB = B.FindSmallest();

	cout << "outputing picture" << endl;
	for(int i = 0; i < R.size ; ++ i) {
		for(int j = 0; j < R.size; ++ j){
			//r = LinearNormalization(R.Get(j,i), R.max, 255); 
			//g = LinearNormalization(G.Get(j,i), G.max, 255); 
			//b = LinearNormalization(B.Get(j,i), B.max, 255); 

			r = LogNormalization(R.Get(j,i), R.max, 255, smallestR); 
			g = LogNormalization(G.Get(j,i), G.max, 255, smallestG); 
			b = LogNormalization(B.Get(j,i), B.max, 255, smallestB); 
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
			h = LinearNormalization(H.Get(j,i), H.max, (double)360); 
			s = LinearNormalization(S.Get(j,i), S.max, (double)100); 
			v = LinearNormalization(V.Get(j,i), V.max, (double)100); 

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

double Bitmap::LinearNormalization(unsigned int value, unsigned int max, double newMax){
	return (newMax / max) * value; 
}

double Bitmap::LogNormalization(unsigned int value, unsigned int max, double newMax, unsigned int smallest){
	if(value == 0)
		return 0;

	double a,b;

	double Dvalue, Dmax, DnewMax, Dsmallest;

	Dvalue = (double)value;
	Dmax = (double)max;
	DnewMax = (double)newMax;
	Dsmallest = (double)smallest;

	a = (-DnewMax)/log(Dsmallest/Dmax);
	b = exp((DnewMax*log(Dsmallest))/(-DnewMax));

	return a * log(Dvalue * b);
}

