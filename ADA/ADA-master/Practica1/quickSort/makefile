OPTS = -Wall -O3 -std=c++0x

quickSort: quickSort.cc
	g++ ${OPTS} -o quickSort quickSort.cc	 

quickSort.CPUtimes: quickSort
	./quickSort > quickSort.CPUtimes

graphs: quickSort.CPUtimes quickSort.gnuplot
	gnuplot quickSort.gnuplot

all: quickSort quickSort.CPUtimes graphs
