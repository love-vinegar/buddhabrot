compile: src/main.cpp  bin/mandelbrot.o bin/bitmap.o
	g++ -Wall -pedantic bin/mandelbrot.o bin/bitmap.o src/main.cpp

bin/mandelbrot.o: src/mandelbrot/mandelbrot.cpp src/mandelbrot/mandelbrot.h 
	g++ -c -Wall -pedantic  src/mandelbrot/mandelbrot.cpp -o bin/mandelbrot.o

bin/bitmap.o: src/bitmap/bitmap.cpp src/bitmap/bitmap.h 
	g++ -c -Wall -pedantic  src/bitmap/bitmap.cpp -o bin/bitmap.o

vim: 
	vim -S vimfiles/*

