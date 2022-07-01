compile: src/main.cpp  bin/mandelbrot.o
	g++ -Wall -pedantic bin/mandelbrot.o src/main.cpp

bin/mandelbrot.o: src/mandelbrot/mandelbrot.cpp src/mandelbrot/mandelbrot.h 
	g++ -c -Wall -pedantic  src/mandelbrot/mandelbrot.cpp -o bin/mandelbrot.o

