
OPTS = -Wall -O3 -std=c++0x

pow2: pow2.cc
	g++ ${OPTS} -o pow2 pow2.cc 

pow2.recursiveCalls: pow2
	./pow2 > pow2.recursiveCalls

graphs: pow2.recursiveCalls pow2.gnuplot
	gnuplot pow2.gnuplot

all: pow2 pow2.recursiveCalls graphs
